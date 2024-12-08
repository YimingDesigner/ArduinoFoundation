#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial Serial2(A4, A5);
#define SERIAL_DEBUG Serial
#define SERIAL_COMMAND Serial2
#define COMMAND_BUFFER_SIZE 5
#include <Command.h>

void setup() {
    Serial.begin(115200);
    Serial.println("Start Debug");
    Serial2.begin(115200);
    Serial2.println("Start Command");
}

void loop() {
    if (Command.command()) {
        SERIAL_COMMAND.println(Command.argc);
        SERIAL_COMMAND.println("----------");
        for(int i = 0; i < Command.argc; i++) {
            SERIAL_COMMAND.print("[");
            SERIAL_COMMAND.print(i);
            SERIAL_COMMAND.print("] ");
            SERIAL_COMMAND.println(Command.argv[i]);
        }
        Command.printOK();
        Command.clear();
    }
}