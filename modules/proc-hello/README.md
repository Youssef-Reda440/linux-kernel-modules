# proc-hello

A Linux kernel module that creates a `/proc/hello` entry to display a greeting message from the kernel in user space.

---

## Overview

This module demonstrates the basic lifecycle of a Linux kernel module and how to expose information to user space through the `/proc` virtual filesystem.

When loaded, the module creates `/proc/hello`. Reading this file returns the following message:

```text
Hello from the Linux Kernel via /proc!
```

When unloaded, the module removes the `/proc/hello` entry.

---

## Implementation

The module is implemented in `proc_hello.c` and uses the Linux kernel module API.

- **Initialization:** Creates the `/proc/hello` entry using `proc_create()`.
- **Read callback:** Uses the `proc_read` callback to provide the greeting message when the file is read.
- **Cleanup:** Removes the entry using `proc_remove()` when the module is unloaded.
- **File operations:** Uses `struct proc_ops` to define the callback responsible for handling read requests.

The accompanying `Makefile` uses the Linux kernel build system (Kbuild) to compile the module against the appropriate kernel headers.

---

## Requirements

- Linux system with kernel module support.
- Kernel headers matching the running kernel.
- GNU Make and a compatible C compiler.
- Root privileges or `sudo` for loading and unloading the module.

---

## Build

Navigate to the module directory:

```bash
cd modules/proc-hello
```

Build the module:

```bash
make
```

If compilation succeeds, the generated kernel module will be available as `proc_hello.ko`.

## Load and Test

Load the module:

```bash
sudo insmod proc_hello.ko
```

Read the `/proc/hello` entry:

```bash
cat /proc/hello
```

Expected output:

```text
Hello from the Linux Kernel via /proc!
```

Verify that the module is loaded:

```bash
lsmod | grep proc_hello
```

You can also inspect recent kernel messages:

```bash
sudo dmesg | tail -n 1
```

## Unload

Remove the module from the running kernel:

```bash
sudo rmmod proc_hello
```

Verify that the `/proc/hello` entry no longer exists:

```bash
ls /proc/hello
```

The command should report that the file does not exist.

## Cleanup

Remove generated build artifacts:

```bash
make clean
```

**Note:** Kernel modules execute with kernel-level privileges. Load and test them only in an environment where you have permission to modify the running kernel.
