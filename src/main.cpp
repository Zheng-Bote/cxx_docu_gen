/**
 * SPDX-FileComment: Main entry point
 * SPDX-FileType: SOURCE
 * SPDX-FileContributor: ZHENG Robert
 * SPDX-FileCopyrightText: 2026 ZHENG Robert
 * SPDX-License-Identifier: Apache-2.0
 *
 * @file main.cpp
 * @brief Clean main file orchestrating the tool.
 * @version 0.1.2
 * @date 2026-03-29
 *
 * @author ZHENG Robert (robert@hase-zheng.net)
 * @copyright Copyright (c) 2026 ZHENG Robert
 *
 * @license Apache-2.0
 */

#include <print>
#include <filesystem>
#include <vector>
#include "parser_util.hpp"
#include "markdown_generator_util.hpp"

namespace fs = std::filesystem;

/**
 * @brief Main function of the documentation tool.
 * @param argc Argument count.
 * @param argv Argument values.
 * @return int Exit code.
 */
int main(int argc, char* argv[]) {
    const fs::path execution_root = fs::current_path();
    const fs::path out = execution_root / "docs" / "source_docu";
    
    // Determine base path: Use command line argument or current path
    fs::path base_path = (argc > 1) ? fs::path(argv[1]) : execution_root;

    if (!fs::exists(base_path)) {
        std::println(stderr, "Error: Path '{}' does not exist.", base_path.string());
        return 1;
    }

    std::println("C++23 Documentation Generator started.");
    std::println("Base path: {}", fs::absolute(base_path).string());
    std::println("Targeting only 'src' and 'include' directories.");

    const std::vector<std::string> target_subdirs = {"src", "include"};
    bool found_any = false;

    for (const auto& subdir : target_subdirs) {
        fs::path search_path = base_path / subdir;
        
        if (!fs::exists(search_path) || !fs::is_directory(search_path)) {
            continue;
        }

        std::println("Processing directory: {}", subdir);
        found_any = true;

        try {
            for (const auto& entry : fs::recursive_directory_iterator(search_path)) {
                if (!entry.is_regular_file()) continue;

                auto ext = entry.path().extension();
                if (ext != ".cpp" && ext != ".hpp") continue;

                // Calculate path relative to base_path for display and structure
                std::string display_path;
                try {
                    display_path = entry.path().lexically_relative(base_path).string();
                } catch (...) {
                    display_path = entry.path().string();
                }

                std::println("Parsing: {}", display_path);
                
                // Pass base_path to maintain original directory structure in docs
                auto res = docu::parse_file(entry.path(), base_path);
                if (res) {
                    if (auto g = docu::generate_markdown(*res, out); !g) {
                        std::println(stderr, "Error generating MD for {}", display_path);
                    }
                } else {
                    std::println(stderr, "Error parsing {}: {}", display_path, res.error());
                }
            }
        } catch (const fs::filesystem_error& e) {
            std::println(stderr, "Filesystem error in {}: {}", subdir, e.what());
        }
    }

    if (!found_any) {
        std::println("No 'src' or 'include' folders found to process.");
    }

    std::println("Documentation generation completed.");
    return 0;
}
