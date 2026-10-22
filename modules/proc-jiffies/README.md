# proc-jiffies

A Linux kernel module that creates a `/proc/jiffies` entry to expose the current value of the kernel's `jiffies` counter.

---

## Overview

The `jiffies` counter represents the number of timer ticks that have occurred since the system booted. Its value increases over time according to the kernel's timer frequency.

When loaded, this module creates `/proc/jiffies`. Reading this file returns the current value of the kernel's `jiffies` counter.

---

## Implementation

The module is implemented in `proc_jiffies.c` and uses the Linux kernel module API.

- **Initialization:** Creates the `/proc/jiffies` entry using `proc_create()`.
- **Read callback:** Returns the current `jiffies` counter when the file is read.
- **Cleanup:** Removes the `/proc/jiffies` entry using `proc_remove()` when the module is unloaded.
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
cd modules/proc-jiffies
```

Build the module:

```bash
make
```

If compilation succeeds, the generated kernel module will be available as `proc_jiffies.ko`.

## Load and Test

Load the module:

```bash
sudo insmod proc_jiffies.ko
```

Read the `/proc/jiffies` entry:

```bash
cat /proc/jiffies
```

Expected output:

```text
123456789
```

The value above is illustrative. The actual output depends on the system's current `jiffies` counter.

Verify that the module is loaded:

```bash
lsmod | grep proc_jiffies
```

Inspect recent kernel messages if needed:

```bash
sudo dmesg | tail -n 1
```

## Unload

Remove the module:

```bash
sudo rmmod proc_jiffies
```

Verify that the `/proc/jiffies` entry has been removed:

```bash
ls /proc/jiffies
```

The command should report that the file does not exist.

## Cleanup

Remove generated build artifacts:

```bash
make clean
```

**Note:** The `jiffies` value is a kernel timer-tick counter, not a value expressed directly in seconds. Its relationship to elapsed time depends on the kernel's `HZ` frequency.
