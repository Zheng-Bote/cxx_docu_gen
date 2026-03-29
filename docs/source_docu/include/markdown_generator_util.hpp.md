# markdown_generator_util.hpp

## File Header Information

| Field | Value |
| :--- | :--- |
| **SPDX Comment** | Utility for generating Markdown from documentation models |
| **SPDX Type** | SOURCE |
| **Contributor** | ZHENG Robert |
| **License ID** | Apache-2.0 |
| **File** | `markdown_generator_util.hpp` |
| **Description** | Functions to format extracted documentation into Markdown files. |
| **Version** | 0.1.1 |
| **Date** | 2026-03-29 |
| **Author** | ZHENG Robert (robert@hase-zheng.net) |
| **Copyright** | Copyright (c) 2026 ZHENG Robert |
| **License** | Apache-2.0 |

## API Documentation

### `namespace docu `

> Main namespace for the documentation extraction and generation tool.

---

### `[[nodiscard]] std::expected<void, std::string> generate_markdown(const FileDoc& doc, const std::filesystem::path& output_base_dir)`

> Generates a Markdown file from a FileDoc object.

| Parameter | Description |
| --- | --- |
| `doc` | The parsed documentation data. |
| `output_base_dir` | The base directory for documentation output. |

**Returns:** std::expected<void, std::string> Success or an error.

---

