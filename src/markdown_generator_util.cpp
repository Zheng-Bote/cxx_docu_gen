/**
 * SPDX-FileComment: Implementation of the Markdown generator
 * SPDX-FileType: SOURCE
 * SPDX-FileContributor: ZHENG Robert
 * SPDX-FileCopyrightText: 2026 ZHENG Robert
 * SPDX-License-Identifier: Apache-2.0
 *
 * @file markdown_generator_util.cpp
 * @brief Generates formatted MD files.
 * @version 0.1.1
 * @date 2026-03-29
 *
 * @author ZHENG Robert (robert@hase-zheng.net)
 * @copyright Copyright (c) 2026 ZHENG Robert
 *
 * @license Apache-2.0
 */

#include "markdown_generator_util.hpp"
#include <fstream>
#include <filesystem>

/**
 * @namespace docu
 * @brief Main namespace for the documentation extraction and generation tool.
 */
namespace docu {

/**
 * @brief Generates a Markdown file from a FileDoc object.
 *
 * @param doc The parsed documentation data.
 * @param output_base_dir The base directory for documentation output.
 * @return std::expected<void, std::string> Success or an error message.
 */
std::expected<void, std::string> generate_markdown(const FileDoc& doc, const std::filesystem::path& output_base_dir) {
    auto target_dir = output_base_dir / doc.relative_path;
    std::filesystem::create_directories(target_dir);

    std::ofstream out(target_dir / (doc.file_name + ".md"));
    if (!out) return std::unexpected("Could not create file");

    out << "# " << doc.file_name << "\n\n";
    out << "## File Header Information\n\n";
    out << "| Field | Value |\n";
    out << "| :--- | :--- |\n";
    out << "| **SPDX Comment** | " << doc.header.spdx_comment << " |\n";
    out << "| **SPDX Type** | " << doc.header.spdx_type << " |\n";
    out << "| **Contributor** | " << doc.header.spdx_contributor << " |\n";
    out << "| **License ID** | " << doc.header.spdx_license_id << " |\n";
    out << "| **File** | `" << doc.header.file_name << "` |\n";
    out << "| **Description** | " << doc.header.description << " |\n";
    out << "| **Version** | " << doc.header.version << " |\n";
    out << "| **Date** | " << doc.header.date << " |\n";
    out << "| **Author** | " << doc.header.author << " |\n";
    out << "| **Copyright** | " << doc.header.copyright << " |\n";
    out << "| **License** | " << doc.header.license << " |\n\n";

    out << "## API Documentation\n\n";
    for (const auto& e : doc.entries) {
        out << "### `" << e.signature << "`\n\n";
        out << "> " << e.brief << "\n\n";
        if (!e.params.empty()) {
            out << "| Parameter | Description |\n| --- | --- |\n";
            for (const auto& [n, d] : e.params) out << "| `" << n << "` | " << d << " |\n";
            out << "\n";
        }
        if (!e.returns.empty()) out << "**Returns:** " << e.returns << "\n\n";
        out << "---\n\n";
    }

    return {};
}

} // namespace docu
