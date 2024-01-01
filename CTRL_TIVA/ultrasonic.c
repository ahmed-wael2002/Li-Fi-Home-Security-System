#include "ultrasonic.h"
#include "timer.h"
#include "DIO.h"
#include "delay.h"

void ULTRASONIC_init(void){
    Timer0_init();
    DIO_Init(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_TRIGGER_PIN, PIN_OUTPUT);
}

void ULTRASONIC_trigger(void){
    DIO_writePin(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_TRIGGER_PIN, LOGIC_LOW);
    _delay_ms(10);
    DIO_writePin(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_TRIGGER_PIN, LOGIC_HIGH);
    _delay_ms(10);
    DIO_writePin(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_TRIGGER_PIN, LOGIC_LOW);
}

uint16 ULTRASONIC_getDistance(void){
    __asm("CPSID I\n");   // Enable System Interrupts
    ULTRASONIC_trigger();
    uint16 time = Timer0_getPulseDuration();   
    __asm("CPSIE I\n");   // Enable System Interrupts
    uint16 distance = (time * 10625)/10000000;  // Distance in centimeters
    return distance;
}