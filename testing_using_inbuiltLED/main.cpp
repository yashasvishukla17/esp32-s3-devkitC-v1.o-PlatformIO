#include <Arduino.h>
const int led=46;

void setup() {
  pinMode(led,OUTPUT);

  digitalWrite(led,HIGH);
  neopixelWrite(48,0,0,0);
}

void loop() {
}