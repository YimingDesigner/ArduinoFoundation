# Arduino Foundation

A fundamental Arduino library for general projects.

![C++](https://img.shields.io/badge/C++-C++11-blue)
![Framework](https://img.shields.io/badge/Framework-Arduino-red)
![Board](https://img.shields.io/badge/Board-all-brightgreen)
![Platform (ISA)](https://img.shields.io/badge/Platform%20(ISA)-all-yellow)

## Array

`Array` supports dynamic memory management which automatically allocates and frees just suitable memory space for the data needs.

## Command

`Command.h` is designed to interact with user commands via Serial Communication. Please refer to `examples/command.cpp` and `examples/command_with_debug.cpp` for how to use it.

It supports two communication pipelines: command and debug, by define` SERIAL_COMMAND` and ` SERIAL_DEBUG`. Both default to `Serial`. User interaction happends on `SERIAL_COMMAND`, while printing debug information happens on `SERIAL_DEBUG`.

The default buffer size is 3, which means maximum 3 strings each command is allowed. To change it: `#define COMMAND_BUFFER_SIZE 5`

```c++
#include <SoftwareSerial.h>

SoftwareSerial Serial2(A4, A5);
#define SERIAL_DEBUG Serial
#define SERIAL_COMMAND Serial2
#define COMMAND_BUFFER_SIZE 5
#include <Command.h>
```

