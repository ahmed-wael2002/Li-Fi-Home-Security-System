/*
 * timer1.c
 *
 *  Created on: Oct 24, 2023
 *      Author: Wael
 */

#include "timer1.h"
#include <avr/interrupt.h>
#include "common_macros.h"
#include <avr/io.h>

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_callBackPtr)(void) = NULL_PTR;

/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/

ISR(TIMER1_COMPA_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}

ISR(TIMER1_OVF_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}

/*******************************************************************************
 *                       Function Definitions                            *
 *******************************************************************************/
/*
 * Description: Function to initialize Timer1 module.
 * 1- Setting Timer1 initial value
 * 2- Setting Timer1 Compare value
 * 3- Adjusting Timer1 operation mode
 * 4- Adjusting the prescaler value of timer1 clock
 */
void Timer1_init(const Timer1_ConfigType *Config_ptr){
	/* Setting the initial value of Timer1 */
	TCNT1 = Config_ptr->initial_value;

	/* Setting the compare value of Timer1
	 * -- OCR1A is used ONLY! */
	OCR1A = Config_ptr->compare_value;

	/* TCCR1A Register Bits Description:
	 * 		OC1A, OC1B are disconnected for NON-PWM modes
	 * - COM1A1:0 = 0
	 * - COM1B1:0 = 0
	 * - FOC1A = 1		Force output compare = 1 @ Non-pwm modes
	 * - FOC1B = 0		Using Timer1A only
	 * - WGM11:0 = 0	@ Both modes WGM11:0 are zeroes
	 *  */
	TCCR1A = (1<<FOC1A);

	/* TCCR1B Register Bits Description:
	 * - OC1A, OC1B are disconnected -- Non-PWM modes
	 * - ICNC1 = 0	No Input Capture Configuration
	 * - ICES1 = 0	Input Capture Edge Select = 0 - Disabling Input Capture
	 * - WGM13:2	WGM12=1 only in case of CTC
	 * - CS12:0 = prescaler	Clock select obtained from configurations pointer
	 *  */
	TCCR1B = ((Config_ptr->prescaler)<<CS10);

	/* TIMSK Register Bits Description:
	 * - OCIE1A = Enabling Output Interrupt
	 * - TOIE1  = Enabling Timer1 Overflow Interrupt
	 * */
	if (Config_ptr->mode == CTC){
		TCCR1B |= (1<<WGM12);
		TIMSK |= (1<<OCIE1A);
	} else{
		TIMSK |= (1<<TOIE1);
	}
}

void Timer1_deinit(void){
	/* Clear All Timer1/ICU Registers */
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1 = 0;
	ICR1 = 0;

	/* Disable the timer interrupt */
	TIMSK &= ~(1<<OCIE1A);
	TIMSK &= ~(1<<TOIE1);

	/* Reset the global pointer value */
	g_callBackPtr = NULL_PTR;
}


/*
 * Description: Function to set the Call Back function address.
 */
void Timer1_setCallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_callBackPtr = a_ptr;
}
