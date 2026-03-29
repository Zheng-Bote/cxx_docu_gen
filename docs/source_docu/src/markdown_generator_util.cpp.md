# markdown_generator_util.cpp

## File Header Information

| Field            | Value                                    |
| :--------------- | :--------------------------------------- |
| **SPDX Comment** | Implementation of the Markdown generator |
| **SPDX Type**    | SOURCE                                   |
| **Contributor**  | ZHENG Robert                             |
| **License ID**   | Apache-2.0                               |
| **File**         | `markdown_generator_util.cpp`            |
| **Description**  | Generates formatted MD files.            |
| **Version**      | 0.1.3                                    |
| **Date**         | 2026-03-29                               |
| **Author**       | ZHENG Robert (robert@hase-zheng.net)     |
| **Copyright**    | Copyright (c) 2026 ZHENG Robert          |
| **License**      | Apache-2.0                               |

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- END doctoc generated TOC please keep comment here to allow auto update -->

## API Documentation

### `namespace docu `

> Main namespace for the documentation extraction and generation tool.

---

### `std::expected<void, std::string>`

> Generates a Markdown file from a FileDoc object.

| Parameter         | Description                                  |
| ----------------- | -------------------------------------------- |
| `doc`             | The parsed documentation data.               |
| `output_base_dir` | The base directory for documentation output. |

**Returns:** std::expected<void, std::string> Success or an error message.

---

### `std::expected<void, std::string>`

> Generates a README.md index for all documented files.

| Parameter         | Description                                    |
| ----------------- | ---------------------------------------------- |
| `docs`            | The list of parsed documentation data objects. |
| `output_base_dir` | The base directory for documentation output.   |

**Returns:** std::expected<void, std::string> Success or an error message.

---
