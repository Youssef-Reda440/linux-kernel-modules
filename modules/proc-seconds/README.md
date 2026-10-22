# proc-seconds

A Linux kernel module that creates a `/proc/seconds` entry to report the number of seconds elapsed since the module was loaded.

---

## Overview

This module demonstrates how kernel timing information can be used to measure elapsed time.

When loaded, the module records the current `jiffies` value as its starting point. Reading `/proc/seconds` returns the elapsed time in seconds, calculated from the difference between the current `jiffies` value and the recorded starting value.

---

## Implementation

The module is implemented in `proc_seconds.c` and uses the Linux kernel module API.

- **Initialization:** Records the initial `jiffies` value and creates the `/proc/seconds` entry using `proc_create()`.
- **Read callback:** Calculates the elapsed time using `(jiffies - start_jiffies) / HZ` and returns the result.
- **Cleanup:** Removes the `/proc/seconds` entry using `proc_remove()` when the module is unloaded.
- **File operations:** Uses `struct proc_ops` to register the callback that handles read requests.

The accompanying `Makefile` uses Kbuild to compile the module against the appropriate Linux kernel headers.

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
cd modules/proc-seconds
```

Build the module:

```bash
make
```

If compilation succeeds, the generated kernel module will be available as `proc_seconds.ko`.

## Load and Test

Load the module:

```bash
sudo insmod proc_seconds.ko
```

Read the `/proc/seconds` entry:

```bash
cat /proc/seconds
```

Example output:

```text
5
```

The output represents the elapsed time in seconds since the module was loaded. The actual value depends on when the file is read.

Read the file again after a short delay:

```bash
sleep 3
cat /proc/seconds
```

The reported value should increase as time passes, subject to the kernel timer resolution and integer division used in the calculation.

Verify that the module is loaded:

```bash
lsmod | grep proc_seconds
```

## Unload

Remove the module:

```bash
sudo rmmod proc_seconds
```

Verify that the `/proc/seconds` entry has been removed:

```bash
ls /proc/seconds
```

The command should report that the file does not exist.

## Cleanup

Remove generated build artifacts:

```bash
make clean
```

**Note:** `HZ` represents the kernel timer frequency in ticks per second. Dividing the elapsed `jiffies` count by `HZ` converts the tick difference into whole seconds.
