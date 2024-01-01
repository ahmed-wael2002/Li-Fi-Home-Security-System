#include "led.h"
#include "DIO.h"

/*=================== Function Definitions ===================*/
void LED_init(){
    /* Setting up the direction for all pins */
    DIO_Init(LED_PORT, LED_RED_PIN, PIN_OUTPUT);
    DIO_Init(LED_PORT, LED_BLUE_PIN, PIN_OUTPUT);
    DIO_Init(LED_PORT, LED_GREEN_PIN, PIN_OUTPUT);
}

void LED_turnOn(LED_Color color){
    switch(color){
        case RED:
            DIO_writePin(LED_PORT, LED_RED_PIN, LED_ON);
            break;
        case BLUE:
            DIO_writePin(LED_PORT, LED_BLUE_PIN, LED_ON);
            break;
        case GREEN:
            DIO_writePin(LED_PORT, LED_GREEN_PIN, LED_ON);
            break;
        case WHITE:
            DIO_writePin(LED_PORT, LED_RED_PIN, LED_ON);
            DIO_writePin(LED_PORT, LED_BLUE_PIN, LED_ON);
            DIO_writePin(LED_PORT, LED_GREEN_PIN, LED_ON);
            break;
    }
}

void LED_turnOff(LED_Color color){
    switch(color){
        case RED:
            DIO_writePin(LED_PORT, LED_RED_PIN, LED_OFF);
            break;
        case BLUE:
            DIO_writePin(LED_PORT, LED_BLUE_PIN, LED_OFF);
            break;
        case GREEN:
            DIO_writePin(LED_PORT, LED_GREEN_PIN, LED_OFF);
            break;
        case WHITE:
            DIO_writePin(LED_PORT, LED_RED_PIN, LED_OFF);
            DIO_writePin(LED_PORT, LED_BLUE_PIN, LED_OFF);
            DIO_writePin(LED_PORT, LED_GREEN_PIN, LED_OFF);
            break;
    }
}

void LED_toggle(LED_Color color){
    switch(color){
        case RED:
            DIO_togglePin(LED_PORT, LED_RED_PIN);
            break;
        case BLUE:
            DIO_togglePin(LED_PORT, LED_BLUE_PIN);
            break;
        case GREEN:
            DIO_togglePin(LED_PORT, LED_GREEN_PIN);
            break;
        case WHITE:
            DIO_togglePin(LED_PORT, LED_RED_PIN);
            DIO_togglePin(LED_PORT, LED_BLUE_PIN);
            DIO_togglePin(LED_PORT, LED_GREEN_PIN);
            break;
    }
}