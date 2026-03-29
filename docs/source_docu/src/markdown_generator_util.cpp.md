# markdown_generator_util.cpp

## File Header Information

| Field | Value |
| :--- | :--- |
| **SPDX Comment** | Implementation of the Markdown generator |
| **SPDX Type** | SOURCE |
| **Contributor** | ZHENG Robert |
| **License ID** | Apache-2.0 |
| **File** | `markdown_generator_util.cpp` |
| **Description** | Generates formatted MD files. |
| **Version** | 0.1.1 |
| **Date** | 2026-03-29 |
| **Author** | ZHENG Robert (robert@hase-zheng.net) |
| **Copyright** | Copyright (c) 2026 ZHENG Robert |
| **License** | Apache-2.0 |

## API Documentation

### `namespace docu `

> Main namespace for the documentation extraction and generation tool.

---

### `std::expected<void, std::string> generate_markdown(const FileDoc& doc, const std::filesystem::path& output_base_dir) `

> Generates a Markdown file from a FileDoc object.

| Parameter | Description |
| --- | --- |
| `doc` | The parsed documentation data. |
| `output_base_dir` | The base directory for documentation output. |

**Returns:** std::expected<void, std::string> Success or an error message.

---

