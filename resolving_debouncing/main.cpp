//resolving debouncing

#include <Arduino.h>
const int button_pressed=6;
int count=0;

void setup(){
  pinMode(button_pressed,INPUT_PULLUP);
  Serial.begin(115200);
}

void loop(){
  while(digitalRead(button_pressed)==HIGH){
    delay(10);
  }
  delay(20);  
  count++;
  Serial.println(count);
  
  while(digitalRead(button_pressed)==LOW){
    delay(10);
  }
  delay(20);  
}