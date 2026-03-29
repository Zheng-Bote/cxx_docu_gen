/**
 * SPDX-FileComment: Utility for parsing C++ files for Doxygen comments
 * SPDX-FileType: SOURCE
 * SPDX-FileContributor: ZHENG Robert
 * SPDX-FileCopyrightText: 2026 ZHENG Robert
 * SPDX-License-Identifier: Apache-2.0
 *
 * @file parser_util.hpp
 * @brief Functions to extract documentation blocks and headers.
 * @version 0.1.1
 * @date 2026-03-29
 *
 * @author ZHENG Robert (robert@hase-zheng.net)
 * @copyright Copyright (c) 2026 ZHENG Robert
 *
 * @license Apache-2.0
 */

#ifndef PARSER_UTIL_HPP
#define PARSER_UTIL_HPP

#include "doc_model_type.hpp"
#include <filesystem>
#include <expected>

/**
 * @namespace docu
 * @brief Main namespace for the documentation extraction and generation tool.
 */
namespace docu {

/**
 * @brief Parses a single C++ file to extract documentation.
 * @param path The path to the file.
 * @param root_dir The root directory to calculate relative paths.
 * @return std::expected<FileDoc, std::string> The parsed documentation or an error.
 */
[[nodiscard]] std::expected<FileDoc, std::string> parse_file(const std::filesystem::path& path, const std::filesystem::path& root_dir);

} // namespace docu

#endif // PARSER_UTIL_HPP
