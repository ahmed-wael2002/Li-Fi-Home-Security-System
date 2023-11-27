/*
 * led.h
 *
 *  Created on: Nov 27, 2023
 *      Author: Wael
 */

#ifndef LED_H_
#define LED_H_

/*******************************************************************************
 *                      Hardware Configuration                                    *
 *******************************************************************************/

#define LED_RED_PORT_ID 	PORTC_ID
#define LED_RED_PIN_ID		PIN0_ID

#define LED_GREEN_PORT_ID 	PORTC_ID
#define LED_GREEN_PIN_ID	PIN1_ID

#define LED_BLUE_PORT_ID 	PORTC_ID
#define LED_BLUE_PIN_ID		PIN2_ID

/*******************************************************************************
 *                      Types Definition                                    *
 *******************************************************************************/

typedef enum{
	RED,
	GREEN,
	BLUE
}Color;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/*
 * Description: Function to initialize and setup the pins of the LEDs
 * input: none
 * output: none
 */
void LED_init(void);

/*
 * Description: Function to turn on the led
 * input: Color of the led to be turned on
 * output: none
 */
void LED_turnOn(Color color);

/*
 * Description: Function to turn off the led
 * input: Color of the led to be turned off
 * output: none
 */
void LED_turnOff(Color color);

/*
 * Description: Function to toggle the status of the led
 * input: Color of the led to be toggled
 * output: none
 */
void LED_toggle(Color color);

#endif /* LED_H_ */
