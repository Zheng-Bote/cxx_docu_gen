/**
 * SPDX-FileComment: Main entry point
 * SPDX-FileType: SOURCE
 * SPDX-FileContributor: ZHENG Robert
 * SPDX-FileCopyrightText: 2026 ZHENG Robert
 * SPDX-License-Identifier: Apache-2.0
 *
 * @file main.cpp
 * @brief Clean main file orchestrating the tool.
 * @version 0.1.4
 * @date 2026-04-08
 *
 * @author ZHENG Robert (robert@hase-zheng.net)
 * @copyright Copyright (c) 2026 ZHENG Robert
 *
 * @license Apache-2.0
 */

#include <print>
#include <filesystem>
#include <vector>
#include <string_view>
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
    
    std::vector<fs::path> sources;
    std::vector<fs::path> includes;
    fs::path base_path = execution_root;

    // Parse arguments
    for (int i = 1; i < argc; ++i) {
        std::string_view arg = argv[i];
        if (arg == "--sources" && i + 1 < argc) {
            sources.push_back(fs::path(argv[++i]));
        } else if (arg == "--includes" && i + 1 < argc) {
            includes.push_back(fs::path(argv[++i]));
        } else if (arg.starts_with("-")) {
            std::println(stderr, "Unknown option: {}", arg);
        } else {
            base_path = fs::path(arg);
        }
    }

    if (!fs::exists(base_path)) {
        std::println(stderr, "Error: Base path '{}' does not exist.", base_path.string());
        return 1;
    }

    std::println("C++23 Documentation Generator started.");
    
    std::vector<fs::path> target_paths;
    if (sources.empty() && includes.empty()) {
        // Default behavior
        if (fs::exists(base_path / "src")) target_paths.push_back(base_path / "src");
        if (fs::exists(base_path / "include")) target_paths.push_back(base_path / "include");
    } else {
        for (const auto& p : sources) target_paths.push_back(p);
        for (const auto& p : includes) target_paths.push_back(p);
    }

    if (target_paths.empty()) {
        std::println("No directories found to process.");
        return 0;
    }

    std::vector<docu::FileDoc> all_docs;

    for (const auto& search_path : target_paths) {
        if (!fs::exists(search_path) || !fs::is_directory(search_path)) {
            std::println(stderr, "Warning: Path '{}' does not exist or is not a directory.", search_path.string());
            continue;
        }

        std::println("Processing directory: {}", search_path.string());

        try {
            for (const auto& entry : fs::recursive_directory_iterator(search_path)) {
                if (!entry.is_regular_file()) continue;

                auto ext = entry.path().extension();
                if (ext != ".cpp" && ext != ".hpp") continue;

                std::string display_path;
                try {
                    display_path = entry.path().lexically_relative(base_path).string();
                } catch (...) {
                    display_path = entry.path().string();
                }

                std::println("Parsing: {}", display_path);
                
                auto res = docu::parse_file(entry.path(), base_path);
                if (res) {
                    if (auto g = docu::generate_markdown(*res, out); !g) {
                        std::println(stderr, "Error generating MD for {}", display_path);
                    } else {
                        all_docs.push_back(*res);
                    }
                } else {
                    std::println(stderr, "Error parsing {}: {}", display_path, res.error());
                }
            }
        } catch (const fs::filesystem_error& e) {
            std::println(stderr, "Filesystem error in {}: {}", search_path.string(), e.what());
        }
    }

    if (!all_docs.empty()) {
        std::println("Generating index README.md...");
        if (auto res = docu::generate_index(all_docs, out); !res) {
            std::println(stderr, "Error generating index: {}", res.error());
        }
    }

    std::println("Documentation generation completed.");
    return 0;
}
