
#include <Arduino.h>
#include <MyMath.h>
#include <tOn_tOff.h>
#include "task100.h"

#define LED_BULTIN 13  // Use built-in LED on pin 13

/*
float fTest;
float fTest1;
float fTest2;
*/
bool bTest;
double Time_ms;

void Task100() {
    //Serial.println("Task100 executed");
    Time_ms = millis();
    bTest = tOn_tOff(1000,5000,Time_ms);
    digitalWrite(LED_BULTIN, bTest);  // Turn on LED
    /*
    //Test CalcY function

    fTest = CalcY_2(15,10,20,100,200);
    fTest1 = CalcY_3(15,0,10,20,100,200,300);
    fTest2 = CalcY_4(30,0,10,20,30,100,200,300,400);

    Serial.println("CalcY_2");
    Serial.print(fTest);
    Serial.println("\n");
    Serial.println("CalcY_3");
    Serial.print(fTest1);
    Serial.println("\n");
    Serial.println("CalcY_4");
    Serial.print(fTest2);
    Serial.println("\n");
    */
   
}