//LED brightness using PWM
#include <Arduino.h>
const int LED_PIN=15;
const int button_pressed=6;
void setup(){
  pinMode(LED_PIN,OUTPUT);
  pinMode(button_pressed,INPUT_PULLUP);
}

void loop(){
  
  if (digitalRead(button_pressed) == LOW) {
    for (int i = 0; i < 256; i++) {
      analogWrite(LED_PIN, i);
      delay(5);
    }
    
    for (int i = 255; i > 0; i--) {
      analogWrite(LED_PIN, i);
      delay(5);
    }
  }
}
