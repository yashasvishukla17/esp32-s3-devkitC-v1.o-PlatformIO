// LED
#include <Arduino.h>



const int LED=16;
const int pot=20;

void setup(){
pinMode(LED,OUTPUT);
pinMode(pot, INPUT);
Serial.begin(115200);
}

void loop(){
  
 int bright= analogRead(pot)/16; //4095/16=256 for the led to read- SCALING
 
  analogWrite(LED,bright);
  Serial.println(bright);

Serial.println("LED IS GLOWING");
}

