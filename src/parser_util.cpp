/**
 * SPDX-FileComment: Implementation of the C++ parser
 * SPDX-FileType: SOURCE
 * SPDX-FileContributor: ZHENG Robert
 * SPDX-FileCopyrightText: 2026 ZHENG Robert
 * SPDX-License-Identifier: Apache-2.0
 *
 * @file parser_util.cpp
 * @brief Regex based extraction of Doxygen comments.
 * @version 0.1.1
 * @date 2026-03-29
 *
 * @author ZHENG Robert (robert@hase-zheng.net)
 * @copyright Copyright (c) 2026 ZHENG Robert
 *
 * @license Apache-2.0
 */

#include "parser_util.hpp"
#include <fstream>
#include <regex>
#include <iterator>

/**
 * @namespace docu
 * @brief Main namespace for the documentation extraction and generation tool.
 */
namespace docu {

/**
 * @brief Parses a single C++ file to extract documentation.
 *
 * @param path The path to the file to parse.
 * @param root_dir The root directory to calculate relative paths.
 * @return std::expected<FileDoc, std::string> The parsed documentation or an error message.
 */
std::expected<FileDoc, std::string> parse_file(const std::filesystem::path& path, const std::filesystem::path& root_dir) {
    FileDoc doc;
    doc.file_name = path.filename().string();
    doc.relative_path = std::filesystem::relative(path, root_dir).parent_path().string();

    std::ifstream file(path);
    if (!file.is_open()) return std::unexpected("Unable to open file: " + path.string());

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    // Parse File Header (Enhanced regex for SPDX and full Doxygen fields)
    std::smatch h_match;
    std::regex h_regex(
        R"(SPDX-FileComment:\s*([^\n]+)[\s\S]*?)"
        R"(SPDX-FileType:\s*([^\n]+)[\s\S]*?)"
        R"(SPDX-FileContributor:\s*([^\n]+)[\s\S]*?)"
        R"(SPDX-FileCopyrightText:\s*([^\n]+)[\s\S]*?)"
        R"(SPDX-License-Identifier:\s*([^\n]+)[\s\S]*?)"
        R"(@file\s+([^\n]+)[\s\S]*?)"
        R"(@brief\s+([^\n]+)[\s\S]*?)"
        R"(@version\s+([^\n]+)[\s\S]*?)"
        R"(@date\s+([^\n]+)[\s\S]*?)"
        R"(@author\s+([^\n]+)[\s\S]*?)"
        R"(@copyright\s+([^\n]+)[\s\S]*?)"
        R"(@license\s+([^\n]+))"
    );

    if (std::regex_search(content, h_match, h_regex)) {
        doc.header.spdx_comment = h_match[1].str();
        doc.header.spdx_type = h_match[2].str();
        doc.header.spdx_contributor = h_match[3].str();
        doc.header.spdx_copyright_text = h_match[4].str();
        doc.header.spdx_license_id = h_match[5].str();
        doc.header.file_name = h_match[6].str();
        doc.header.description = h_match[7].str();
        doc.header.version = h_match[8].str();
        doc.header.date = h_match[9].str();
        doc.header.author = h_match[10].str();
        doc.header.copyright = h_match[11].str();
        doc.header.license = h_match[12].str();
    }

    // Parse Entries
    std::regex e_regex(R"(\/\*\*\s*([\s\S]*?)\*\/[\s\r\n]*([^\n;\{]+))");
    auto e_begin = std::sregex_iterator(content.begin(), content.end(), e_regex);
    auto e_end = std::sregex_iterator();

    for (std::sregex_iterator i = e_begin; i != e_end; ++i) {
        std::smatch match = *i;
        std::string comment = match[1].str();
        if (comment.find("@file") != std::string::npos) continue;

        DocEntry entry;
        entry.signature = match[2].str();

        std::smatch b_match;
        if (std::regex_search(comment, b_match, std::regex(R"(@brief\s+([^\n]+))"))) {
            entry.brief = b_match[1].str();
        }

        std::smatch r_match;
        if (std::regex_search(comment, r_match, std::regex(R"(@return\s+([^\n]+))"))) {
            entry.returns = r_match[1].str();
        }

        std::regex p_regex(R"(@param\s+(\w+)\s+([^\n]+))");
        for (std::sregex_iterator j(comment.begin(), comment.end(), p_regex); j != e_end; ++j) {
            entry.params.push_back({(*j)[1].str(), (*j)[2].str()});
        }
        doc.entries.push_back(entry);
    }

    return doc;
}

} // namespace docu
