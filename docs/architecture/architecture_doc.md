<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**

- [Architecture Documentation](#architecture-documentation)
  - [Component Diagram](#component-diagram)
  - [Class Diagram](#class-diagram)
  - [Sequence Diagram (Execution Flow)](#sequence-diagram-execution-flow)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# Architecture Documentation

## Component Diagram
```mermaid
graph TD
    subgraph App [docu_gen Application]
        MO[Main Orchestrator]
        PU[Parser Utility]
        MG[Markdown Generator]
        DM[Doc Models]
        
        MO --> PU
        MO --> MG
        PU --> DM
        MG --> DM
    end
```

## Class Diagram
```mermaid
classDiagram
    class FileHeader {
        +string spdx_comment
        +string spdx_type
        +string spdx_contributor
        +string spdx_copyright_text
        +string spdx_license_id
        +string file_name
        +string description
        +string version
        +string date
        +string author
        +string copyright
        +string license
    }
    class DocEntry {
        +string brief
        +string signature
        +vector params
        +string returns
    }
    class FileDoc {
        +string file_name
        +string relative_path
        +FileHeader header
        +vector entries
    }
    FileDoc "1" *-- "1" FileHeader
    FileDoc "1" *-- "many" DocEntry
```

## Sequence Diagram (Execution Flow)
```mermaid
sequenceDiagram
    participant U as User
    participant M as Main
    participant S as Scanner
    participant P as Parser
    participant G as Generator

    U->>M: run(path)
    M->>S: find_files(path/src, path/include)
    S-->>M: list of .cpp/.hpp
    loop for each file
        M->>P: parse_file(file)
        P-->>M: FileDoc object
        M->>G: generate_markdown(FileDoc)
        G-->>M: Success/Error
    end
    M-->>U: Done
```
