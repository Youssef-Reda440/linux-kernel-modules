# Kernel Modules

This directory contains three Linux kernel modules developed as part of the **CSE 323: Operating Systems** course

Each module demonstrates a different concept related to Linux kernel development and the `/proc` virtual filesystem.

---

## Available Modules

| Module         | Description                                                                                | Documentation                    |
| -------------- | ------------------------------------------------------------------------------------------ | -------------------------------- |
| `proc-hello`   | Creates `/proc/hello` to display a greeting message from the Linux kernel.                 | [README](proc-hello/README.md)   |
| `proc-jiffies` | Creates `/proc/jiffies` to expose the current value of the kernel's `jiffies` counter.     | [README](proc-jiffies/README.md) |
| `proc-seconds` | Creates `/proc/seconds` to report the elapsed time in seconds since the module was loaded. | [README](proc-seconds/README.md) |

---

## General Notes

- Each module has its own source file, `Makefile`, and README.
- The modules use the Linux kernel module API and the `/proc` filesystem to expose information to user space.
- Building the modules requires the appropriate Linux kernel headers and build tools for the running kernel.
- Loading and unloading kernel modules requires appropriate privileges.

For setup, build instructions, usage examples, and expected output, refer to the README of the specific module.
