#include <Arduino.h>
#include "Array.h"

Array<int> arr;

void setup() {
    Serial.begin(115200);
    Serial.println("Start");

    for (int i = 0; i < 10; i++) {
        arr.append(10);
    }

    arr[3] = 20;
    Serial.println(arr[3]);
}

void loop() { }
