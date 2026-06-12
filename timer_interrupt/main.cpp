#include <Arduino.h>

// LED pin- external LED
const int LED_PIN = 15;

// Hardware timer pointer
hw_timer_t *timer = NULL;

// This variable is changed inside ISR,
// so we use volatile
volatile bool ledState= false;

/*
  ISR = Interrupt Service Routine

  This function automatically runs whenever
  the timer interrupt happens.

  IRAM_ATTR keeps ISR in fast memory.
*/
void IRAM_ATTR onTimer()
{
    // Toggle LED state
    ledState = !ledState;

    // Write new state to LED
    digitalWrite(LED_PIN, ledState);
}

void setup()
{
    Serial.begin(115200);
    delay(1000);

    Serial.println("ESP32-S3 Timer Interrupt Started");

    pinMode(LED_PIN, OUTPUT);

    /*
      timerBegin(timer number, prescaler, count up)

      ESP32 timer clock = 80 MHz

      Prescaler = 80

      80,000,000 / 80 = 1,000,000 ticks/sec

      So:
      1 tick = 1 microsecond
    */
    timer = timerBegin(1, 80, true);

    /*
      Attach the interrupt function to the timer.

      true = edge interrupt
    */
    timerAttachInterrupt(timer, &onTimer, true);

    /*
      timerAlarmWrite(timer, alarm value, autoreload)

      1,000,000 microseconds = 1 second

      true = repeat again and again
    */
    timerAlarmWrite(timer, 1000000, true);

    // Enable/start the timer alarm
    timerAlarmEnable(timer);

    Serial.println("Timer configured successfully");
}

void loop()
{
    /*
      Main loop is free.

      LED blinking is happening through timer interrupt,
      not because of delay().
    */
    
    Serial.println("Main loop running...");
    delay(1000);
    
}