/*
 * led.c
 *
 *  Created on: Nov 27, 2023
 *      Author: Wael
 */

#include "led.h"
#include "gpio.h"

/*
 * Description: Function to initialize and setup the pins of the LEDs
 * input: none
 * output: none
 */
void LED_init(void){
	/* Setting up the direction of the pins */
	GPIO_setupPinDirection(LED_RED_PORT_ID, LED_RED_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, PIN_OUTPUT);

	/* Initialize all pins to be off */
	GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, LOGIC_LOW);
	GPIO_writePin(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, LOGIC_LOW);
	GPIO_writePin(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, LOGIC_LOW);
}

/*
 * Description: Function to turn on the led
 * input: Color of the led to be turned on
 * output: none
 */
void LED_turnOn(Color color){
	switch(color){
	case RED:
		GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, LOGIC_HIGH);
		break;
	case GREEN:
		GPIO_writePin(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, LOGIC_HIGH);
		break;
	case BLUE:
		GPIO_writePin(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, LOGIC_HIGH);
		break;
	}
}

/*
 * Description: Function to turn off the led
 * input: Color of the led to be turned off
 * output: none
 */
void LED_turnOff(Color color){
	switch(color){
	case RED:
		GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, LOGIC_LOW);
		break;
	case GREEN:
		GPIO_writePin(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, LOGIC_LOW);
		break;
	case BLUE:
		GPIO_writePin(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, LOGIC_LOW);
		break;
	}
}
