/*
Interrupt + LED Patterns

One button, one LED.
Each button press changes mode:

Mode 0: OFF
Mode 1: Blink slow
Mode 2: Blink fast
Mode 3: ON

*/

#include<Arduino.h>

//ALLL THE VARIABLES
const int led=17;
const int button=4;
hw_timer_t *timer=NULL;
volatile bool ledState=false;
volatile int currentMode=0;
volatile unsigned long prevDebounce=0;
const int debounceDelay=200;
unsigned long SLOW_BLINK_INTERVAL=600000;
unsigned long FAST_BLINK_INTERVAL=100000;

// What should timer ISR do?
void IRAM_ATTR OnTimer(){
    //mode 1
    if(currentMode==1){
        ledState=!ledState;
        digitalWrite(led,ledState);
    }
    //mode 2
    else if(currentMode==2){
        ledState=!ledState;
        digitalWrite(led,ledState);
    }
}

//mode0
void IRAM_ATTR mode0(){
    ledState=false;
    digitalWrite(led,LOW);
}

 //mode1- slow blink
void IRAM_ATTR mode1(){
    ledState=true;
    digitalWrite(led,HIGH);
    timerAlarmWrite(timer,SLOW_BLINK_INTERVAL,true);
}

//mode2- fast blink
void IRAM_ATTR mode2(){
    ledState=true;
    digitalWrite(led,HIGH);
    timerAlarmWrite(timer, FAST_BLINK_INTERVAL,true);
}

//mode3- ON state
void IRAM_ATTR mode3(){
    ledState=true;
    digitalWrite(led, HIGH);
}

//for button- debounce check
void IRAM_ATTR handlebuttonpress(){
    unsigned long currentTime=millis();
    if(currentTime-prevDebounce<debounceDelay){
        return;
    }
    prevDebounce=currentTime;
    // %--remainder
    currentMode=(currentMode+1)%4;
    
    //stopping all the other modes' timers
    timerAlarmDisable(timer);

    //executing the modes
    if(currentMode==0){
        mode0();
    }
    else if(currentMode==1){
        mode1();
        timerAlarmEnable(timer);
    }
    else if(currentMode==2){
        mode2();
        timerAlarmEnable(timer);
    }
    else if(currentMode==3){
        mode3();
    }
}

void setup(){
    pinMode(led, OUTPUT);
    pinMode(button,INPUT_PULLUP);

    digitalWrite(led, LOW);
    timer=timerBegin(0,80,true); //using timer number 0
    timerAttachInterrupt(timer,&OnTimer,true);
    timerAlarmDisable(timer);
    attachInterrupt(digitalPinToInterrupt(button),handlebuttonpress,FALLING);

}

void loop(){
    
}