/**
 * SPDX-FileComment: Data models for documentation extraction
 * SPDX-FileType: SOURCE
 * SPDX-FileContributor: ZHENG Robert
 * SPDX-FileCopyrightText: 2026 ZHENG Robert
 * SPDX-License-Identifier: Apache-2.0
 *
 * @file doc_model_type.hpp
 * @brief Definition of data structures for file and member documentation.
 * @version 0.1.1
 * @date 2026-03-29
 *
 * @author ZHENG Robert (robert@hase-zheng.net)
 * @copyright Copyright (c) 2026 ZHENG Robert
 *
 * @license Apache-2.0
 */

#ifndef DOC_MODEL_TYPE_HPP
#define DOC_MODEL_TYPE_HPP

#include <string>
#include <vector>

/**
 * @namespace docu
 * @brief Main namespace for the documentation extraction and generation tool.
 */
namespace docu {

/**
 * @brief Represents the metadata extracted from a file header.
 */
struct FileHeader {
    std::string spdx_comment;        ///< SPDX-FileComment of the file.
    std::string spdx_type;           ///< SPDX-FileType of the file.
    std::string spdx_contributor;    ///< SPDX-FileContributor of the file.
    std::string spdx_copyright_text; ///< SPDX-FileCopyrightText of the file.
    std::string spdx_license_id;     ///< SPDX-License-Identifier of the file.
    std::string file_name;           ///< File name extracted from @file.
    std::string description;         ///< Brief description extracted from @brief.
    std::string version;             ///< Version extracted from @version.
    std::string date;                ///< Date extracted from @date.
    std::string author;              ///< Author extracted from @author.
    std::string copyright;           ///< Copyright extracted from @copyright.
    std::string license;             ///< License extracted from @license.
};

/**
 * @brief Represents a single documented entity (e.g., function, method).
 */
struct DocEntry {
    std::string brief;                                       ///< Brief description of the entity.
    std::vector<std::pair<std::string, std::string>> params; ///< List of parameters and their descriptions.
    std::string returns;                                     ///< Description of the return value.
    std::string signature;                                   ///< Signature of the documented entity.
};

/**
 * @brief Represents the complete documentation extracted from a single file.
 */
struct FileDoc {
    std::string file_name;         ///< Name of the file.
    std::string relative_path;     ///< Relative path of the file to the project root.
    FileHeader header;             ///< Header metadata of the file.
    std::vector<DocEntry> entries; ///< List of documented entities in the file.
};

} // namespace docu

#endif // DOC_MODEL_TYPE_HPP
