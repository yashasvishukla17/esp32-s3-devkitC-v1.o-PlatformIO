#include <Arduino.h>

void setup()
{
    Serial.begin(115200);

    Serial1.begin(115200, SERIAL_8N1, 44, 43); //rx- 44, tx-43
    

    Serial.println("Setup complete");
}

void loop()
{
    Serial1.println("HELLO");
    delay(1000);
}