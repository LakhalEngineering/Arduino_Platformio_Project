
#include <Arduino.h>
#include <MyMath.h>
#include <tOn_tOff.h>
#include "task100.h"

#define LED_BULTIN 13  // Use built-in LED on pin 13


float fTest = 1.57; 
float result;
double Time_ms;

void Task100() {
    //Serial.println("Task100 executed");

    Time_ms = millis();
    //bTest = tOn_tOff(1000,5000,Time_ms);
    //digitalWrite(LED_BULTIN, bTest);  // Turn on LED
   
   // Test Grad2Rad and Rad2Grad
    result = Rad2Grad(fTest);
    Serial.print(result);
}