/**
 * SPDX-FileComment: Utility for generating Markdown from documentation models
 * SPDX-FileType: SOURCE
 * SPDX-FileContributor: ZHENG Robert
 * SPDX-FileCopyrightText: 2026 ZHENG Robert
 * SPDX-License-Identifier: Apache-2.0
 *
 * @file markdown_generator_util.hpp
 * @brief Functions to format extracted documentation into Markdown files.
 * @version 0.1.2
 * @date 2026-03-29
 *
 * @author ZHENG Robert (robert@hase-zheng.net)
 * @copyright Copyright (c) 2026 ZHENG Robert
 *
 * @license Apache-2.0
 */

#ifndef MARKDOWN_GENERATOR_UTIL_HPP
#define MARKDOWN_GENERATOR_UTIL_HPP

#include "doc_model_type.hpp"
#include <filesystem>
#include <expected>
#include <vector>

/**
 * @namespace docu
 * @brief Main namespace for the documentation extraction and generation tool.
 */
namespace docu {

/**
 * @brief Generates a Markdown file from a FileDoc object.
 * @param doc The parsed documentation data.
 * @param output_base_dir The base directory for documentation output.
 * @return std::expected<void, std::string> Success or an error.
 */
[[nodiscard]] std::expected<void, std::string> generate_markdown(const FileDoc& doc, const std::filesystem::path& output_base_dir);

/**
 * @brief Generates a README.md index for all documented files.
 * @param docs The list of parsed documentation data objects.
 * @param output_base_dir The base directory for documentation output.
 * @return std::expected<void, std::string> Success or an error.
 */
[[nodiscard]] std::expected<void, std::string> generate_index(const std::vector<FileDoc>& docs, const std::filesystem::path& output_base_dir);

} // namespace docu

#endif // MARKDOWN_GENERATOR_UTIL_HPP
