<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**

- [Changelog](#changelog)
  - [[1.0.0] - 2026-03-29](#100---2026-03-29)
    - [Added](#added)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.1.0] - 2026-03-29

### Added
- Automatic generation of `README.md` index in `docs/source_docu/`.
- Sorting and grouping of documented files by directory in the index.
- Descriptions for documented files in the index derived from file headers.

## [1.0.0] - 2026-03-29

### Added
- Initial release of the C++23 Documentation Generator.
- Support for recursive scanning of `src/` and `include/` directories.
- Extraction of SPDX file headers and Doxygen comments.
- Markdown generation with relative path preservation.
- Optional command-line argument for source directory input.
- C++23 features integration (`std::print`, `std::expected`, `std::filesystem`).
