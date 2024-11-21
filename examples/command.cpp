#include <Arduino.h>
#include "Command.h"

void setup() {
    Serial.begin(115200);
    Serial.println("Start");
}

void loop() {
    Serial.println(Command.argc);
    Serial.println("----------");
    for(int i = 0; i < Command.argc; i++) {
        Serial.print("[");
        Serial.print(i);
        Serial.print("] ");
        Serial.println(Command.argv[i]);
    }
    Command.clear();
}