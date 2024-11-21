#ifndef ARDUINO_FOUNDATION_COMMAND_H_
#define ARDUINO_FOUNDATION_COMMAND_H_

#ifndef COMMAND_BUFFER_SIZE
#define COMMAND_BUFFER_SIZE 5
#endif

#include <Arduino.h>

class _Command {
   private:
    int contentAvailable;

    int available() { return Serial.available(); }
    
    char read() {
        char c = Serial.read();
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
        Serial.print("Command Error");
        if (argc != 0) {
            Serial.print(", argv[0]: ");
            Serial.print(argv[0]);
        }
        Serial.print(", argc: ");
        Serial.println(argc);
    }
};

_Command Command;

#endif