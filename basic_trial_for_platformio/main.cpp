#include <Arduino.h>

void setup()
{
    Serial.begin(115200);
    delay(2000);

    Serial.println("ESP32-S3 is working");
}

void loop()
{
    Serial.println("Loop running");
    delay(1000);
}