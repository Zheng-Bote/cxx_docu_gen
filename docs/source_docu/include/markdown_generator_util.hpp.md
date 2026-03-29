<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**

- [markdown_generator_util.hpp](#markdown_generator_utilhpp)
  - [File Header Information](#file-header-information)
  - [API Documentation](#api-documentation)
    - [`namespace docu `](#namespace-docu-)
    - [`[[nodiscard]] std::expected<void, std::string> generate_markdown(const FileDoc& doc, const std::filesystem::path& output_base_dir)`](#nodiscard-stdexpectedvoid-stdstring-generate_markdownconst-filedoc-doc-const-stdfilesystempath-output_base_dir)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

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
| **Version** | 0.1.2 |
| **Date** | 2026-03-29 |
| **Author** | ZHENG Robert (robert@hase-zheng.net) |
| **Copyright** | Copyright (c) 2026 ZHENG Robert |
| **License** | Apache-2.0 |

<!-- START doctoc -->
<!-- END doctoc -->

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

### `[[nodiscard]] std::expected<void, std::string> generate_index(const std::vector<FileDoc>& docs, const std::filesystem::path& output_base_dir)`

> Generates a README.md index for all documented files.

| Parameter | Description |
| --- | --- |
| `docs` | The list of parsed documentation data objects. |
| `output_base_dir` | The base directory for documentation output. |

**Returns:** std::expected<void, std::string> Success or an error.

---

