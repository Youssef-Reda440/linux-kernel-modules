# Linux Kernel Modules

A collection of Linux kernel module development projects implemented in C as part of the **CSE 323: Operating Systems** course at the Faculty of Engineering, Zagazig University.

The repository demonstrates fundamental Linux kernel programming concepts through practical modules that interact with the kernel and expose information to user space using the `/proc` filesystem.

---

## Project Overview

Linux kernel modules are pieces of code that can be loaded into and removed from a running Linux kernel without rebuilding or restarting the entire kernel. They provide a flexible way to extend kernel functionality and explore operating system internals.

This project focuses on developing and managing kernel modules, understanding their lifecycle, and creating custom `/proc` entries that allow users to retrieve kernel-related information through standard Linux commands.

---

## Project Objectives

- Understand the fundamentals of Linux kernel module development.
- Implement module initialization and cleanup routines.
- Compile kernel modules using the Linux kernel build system.
- Load and unload modules dynamically.
- Explore the `/proc` filesystem as an interface for exposing kernel information to user space.
- Work with kernel timing information through `jiffies` and `HZ`.

---

## Repository Structure

```text
linux-kernel-modules/
├── assets/
├── modules/
│   ├── proc-hello/
│   ├── proc-jiffies/
│   ├── proc-seconds/
│   └── README.md
├── report/
│   ├── report.tex
│   └── report.pdf
├── .gitignore
├── LICENSE
└── README.md
```

- **`modules/`** — Contains the source code, Makefiles, and documentation for each kernel module.
- **`assets/`** — Stores project screenshots and supporting visual materials.
- **`report/`** — Contains the LaTeX source and compiled PDF of the project report.
- **`.gitignore`** — Excludes generated build files and other files that should not be tracked by Git.
- **`LICENSE`** — Defines the terms under which the project can be used and distributed.

---

## Modules

The repository currently contains three kernel modules, each demonstrating a different concept related to kernel information and the `/proc` filesystem.

For an overview of the available modules and links to their individual documentation, see the [Modules README](modules/README.md).

---

## Technologies Used

- **C** — Kernel module implementation.
- **Linux Kernel Module API** — Module initialization, cleanup, and kernel interaction.
- **GNU Make and Kbuild** — Building external kernel modules.
- **LaTeX** — Preparing the project report.

---

## Building and Running

Each module is maintained in its own directory and includes a dedicated `Makefile` and `README.md` with its build instructions and usage details.

Before building a module, ensure that the appropriate kernel headers and build tools are installed for your running kernel.

Refer to the documentation for the specific module you want to build and run.

> **Note:** Loading and unloading kernel modules requires appropriate privileges. Since kernel modules execute in kernel space, test them carefully and preferably in a virtual machine or another controlled environment.

---

## Project Report

The project report documents the fundamentals of Linux kernel modules and describes the implementation and behavior of the three modules.

- [View the PDF Report](report/report.pdf)
- [View the LaTeX Source](report/report.tex)

---

## License

This project is licensed under the GNU General Public License v2.0 (GPL-2.0-only). See the [LICENSE](LICENSE) file for details.
