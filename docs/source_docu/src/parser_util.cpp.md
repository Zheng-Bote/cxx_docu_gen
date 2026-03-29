# parser_util.cpp

## File Header Information

| Field | Value |
| :--- | :--- |
| **SPDX Comment** | Implementation of the C++ parser |
| **SPDX Type** | SOURCE |
| **Contributor** | ZHENG Robert |
| **License ID** | Apache-2.0 |
| **File** | `parser_util.cpp` |
| **Description** | Regex based extraction of Doxygen comments. |
| **Version** | 0.1.1 |
| **Date** | 2026-03-29 |
| **Author** | ZHENG Robert (robert@hase-zheng.net) |
| **Copyright** | Copyright (c) 2026 ZHENG Robert |
| **License** | Apache-2.0 |

## API Documentation

### `namespace docu `

> Main namespace for the documentation extraction and generation tool.

---

### `std::expected<FileDoc, std::string> parse_file(const std::filesystem::path& path, const std::filesystem::path& root_dir) `

> Parses a single C++ file to extract documentation.

| Parameter | Description |
| --- | --- |
| `path` | The path to the file to parse. |
| `root_dir` | The root directory to calculate relative paths. |

**Returns:** std::expected<FileDoc, std::string> The parsed documentation or an error message.

---

