
#include <Arduino.h>
#include <MyMath.h>
#include "task100.h"

#define LED_BULTIN 13  // Use built-in LED on pin 13

float fTest;
float fTest1;

void Task100() {
    //Serial.println("Task100 executed");
    
    fTest = CalcY_2(15,10,20,100,200);
    fTest1 = CalcY_3(15,0,10,20,100,200,300);
   //digitalWrite(LED_BULTIN, Output);  // Turn on LED
    Serial.print(fTest1);
    Serial.println("\n");
}