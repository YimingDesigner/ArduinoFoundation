#ifndef ARDUINO_FOUNDATION_COMMAND_H_
#define ARDUINO_FOUNDATION_COMMAND_H_

#include <Arduino.h>

#ifndef COMMAND_BUFFER_SIZE
#define COMMAND_BUFFER_SIZE 5
#endif
#ifndef SERIAL_COMMAND
#define SERIAL_COMMAND Serial
#endif
#ifndef SERIAL_DEBUG
#define SERIAL_DEBUG Serial
#endif

class _Command {
   private:
    int contentAvailable;

    int available() { return SERIAL_COMMAND.available(); }
    
    char read() {
        char c = SERIAL_COMMAND.read();
        if (c == ' ' || c == '\r' || c == '\n') {
            if (contentAvailable) {
                argc += 1;
            }
            contentAvailable = false;
        } else {
            argv[argc] += c;
            contentAvailable = true;
        }
        return c;
    }

   public:
    String argv[COMMAND_BUFFER_SIZE];
    int argc;

    _Command() {
        clear();
    };
    
    bool command() {
        if (available() > 0 && read() == '\n') {
            if (argc > 0) {
                return true;
            } else {
                printError();
            }
        }
        return false;
    }

    void clear() {
        argc = 0;
        for (int i = 0; i < COMMAND_BUFFER_SIZE; i++) {
            argv[i] = "";
        }
        contentAvailable = false;
    }

    void printError() {
        SERIAL_DEBUG.print("Command Error");
        if (argc != 0) {
            SERIAL_DEBUG.print(", argv[0]: ");
            SERIAL_DEBUG.print(argv[0]);
        }
        SERIAL_DEBUG.print(", argc: ");
        SERIAL_DEBUG.println(argc);
    }

    void printOK() {
        SERIAL_DEBUG.print("Command OK");
        if (argc != 0) {
            SERIAL_DEBUG.print(", argv[0]: ");
            SERIAL_DEBUG.print(argv[0]);
        }
        SERIAL_DEBUG.print(", argc: ");
        SERIAL_DEBUG.println(argc);
    }
};

_Command Command;

#endif