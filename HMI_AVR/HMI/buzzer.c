/*
 * buzzer.c
 *
 *  Created on: Oct 27, 2023
 *      Author: Wael
 */

#include "buzzer.h"
#include "gpio.h"

/*
 * Function Description:
 * Initializing the Buzzer pin
 * 1- Setup the pin direction
 * 2- Initialize the pin with Buzzer_off
 */
void Buzzer_init(void){
	/* Setting the buzzer pin as output */
	GPIO_setupPinDirection(BUZZER_PORT_ID, BUZZER_PIN_ID, PIN_OUTPUT);
	/* Initializing the buzzer to be off */
	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, BUZZER_OFF);
}

/*
 * Function Description:
 * Setting the buzzer to be ON
 * 1- Write the pin to be Buzzer_on
 */
void Buzzer_on(void){
	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, BUZZER_ON);
}

/*
 * Function Description:
 * Setting the buzzer to be OFF
 * 1- Write the pin to be Buzzer_off
 */
void Buzzer_off(void){
	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, BUZZER_OFF);
}

