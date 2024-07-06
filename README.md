[![QTAPP_CI](https://github.com/bobis33/QtApp-Sandbox/actions/workflows/QtApp-Sandbox.yml/badge.svg)](https://github.com/bobis33/QtApp-Sandbox/actions/workflows/QtApp-Sandbox.yml)
![GitHub repo size](https://img.shields.io/github/repo-size/bobis33/QtApp-Sandbox)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)

**ACTUALLY WORKING ON IT!**

- [Description](#description)
- [Prerequisites](#prerequisites)
- [Usage](#usage)
- [Commit Norms](#commit-norms)
- [License](#license)
- [Acknowledgements](#acknowledgements)


## Description

This project is a simple application that uses the Qt library, look like a sandbox for me, ill use it to test some stuff and improve my skills in C++ and Qt.


## Prerequisites

- [CMake](https://cmake.org/download/)
- [C++20](https://en.cppreference.com/w/cpp/20)
- [Qt](https://www.qt.io/download)


## Usage

### Build

```bash
$> ./build.sh build
[...]
```
> if it doesn't work, try the following command:
```bash
$> ./build.sh clean && ./build.sh build
[...]
```

### Run

```bash
$> ./qtsandbox
[...]
```


## Commit Norms

| Commit Type | Description                                                                                                               |
|:------------|:--------------------------------------------------------------------------------------------------------------------------|
| build       | Changes that affect the build system or external dependencies (npm, make, etc.)                                           |
| ci          | Changes related to integration files and scripts or configuration (Travis, Ansible, BrowserStack, etc.)                   |
| feat        | Addition of a new feature                                                                                                 |
| fix         | Bug fix                                                                                                                   |
| perf        | Performance improvements                                                                                                  |
| refactor    | Modification that neither adds a new feature nor improves performance                                                     |
| style       | Change that does not affect functionality or semantics (indentation, formatting, adding space, renaming a variable, etc.) |
| docs        | Writing or updating documentation                                                                                         |
| test        | Addition or modification of tests                                                                                         |


## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.


## Acknowledgements
