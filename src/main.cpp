#include <Arduino.h>
#include "task100.h"
#include "task1000.h"
#include <EEPROM.h>

const unsigned long interval100 = 100;
const unsigned long interval1000 = 1000;
unsigned long previousMillis100 = 0;
unsigned long previousMillis1000 = 0;



void setup() {
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);  // Set built-in LED as output
    int value = 42;
    EEPROM.write(0,value);
    int storedValue = EEPROM.read(0);  // Read value from address 0

  Serial.print("Stored EEPROM value: ");
  Serial.println(storedValue);
}

void loop() {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis100 >= interval100) {
        previousMillis100 = currentMillis;
        Task100();
    }

    if (currentMillis - previousMillis1000 >= interval1000) {
        previousMillis1000 = currentMillis;
        Task1000();
    }
}