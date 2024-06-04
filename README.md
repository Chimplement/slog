# Slog
Slog is a recreation of [strace](https://strace.io/) the linux utility for tracing signals and syscalls.

## Features
Slog implements a couple of features of `strace`, mainly the usage without options where it will list all system calls called and all signals received by the tracee.

There is also the option to run Slog with the `-c` flag which will give a summary at the end similar to the one given by strace.

## Using
Using Slog to trace for example `ls` is relatively simple:
```bash
./slog ls
```
and will give you a similar result to:
```bash
execve(0x5621aab191a0, 0x7ffd575f2c50, 0x7ffd575f2c60) = 0
brk(0) = 94824348532736
mmap(0, 8192, 3, 140711493732402, 4294967295, 0) = 140711493591040
access(0x7ff9f29a1340, 4) = -2
openat(-100, 0x7ff9f29a020c, 524288, -224819542) = 3
...
write(1, 0x563e039c4500, 42Makefile  obj  README.md  slog	src  tools
) = 42
close(1) = 0
close(2) = 0
exit_group(0) = ?
+++ exited with 0 +++
```
if instead you want a summary you simply run:
```bash
./slog -c ls
```

### Building
To build Slog you just run make:
```bash
git clone https://github.com/Chimplement/nettena.git nettena
cd nettena
make
```

## Why
