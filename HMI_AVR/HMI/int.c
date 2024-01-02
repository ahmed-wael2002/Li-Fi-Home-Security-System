/*
 * int.c
 *
 *  Created on: Nov 27, 2023
 *      Author: Wael
 */
#include "int.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include "common_macros.h"

/* Global variables to hold the address of the call back function in the application */
static volatile void (*int0_callBackPtr)(void) = NULL_PTR;


/*******************************************************************************
 *                       Interrupt (0) Functions                            *
 *******************************************************************************/

// Interrupt Service Routine
ISR(INT0_vect)
{
	if(int0_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*int0_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}


// Set call back function
void INT0_setCallback(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	int0_callBackPtr = a_ptr;
}

// Initialization Function
void INT0_init(Edge edge)
{
	DDRD  &= (~(1<<PD2));               // Configure INT0/PD2 as input pin
	// Configure interrupt generation according to chosen edge
	MCUCR = (MCUCR & 0xFC) | (edge << ISC00);
	GICR  |= (1<<INT0);                 // Enable external interrupt pin INT0
	SREG  |= (1<<7);                    // Enable interrupts by setting I-bit
}




/*******************************************************************************
 *                       Interrupt (1) Functions                            *
 *******************************************************************************/

/* Global variables to hold the address of the call back function in the application */
static volatile void (*int1_callBackPtr)(void) = NULL_PTR;

// Interrupt Service Routine
ISR(INT1_vect)
{
	if(int1_callBackPtr != NULL_PTR)
	{
		CLEAR_BIT(SREG, 7);
		/* Call the Call Back function in the application after the edge is detected */
		(*int1_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
		SET_BIT(SREG, 7);
	}
}


// Set call back function
void INT1_setCallback(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	int1_callBackPtr = a_ptr;
}

// Initialization Function
void INT1_init(Edge edge)
{
	DDRD  &= (~(1<<PD3));               // Configure INT0/PD2 as input pin
	// Configure interrupt generation according to chosen edge
	MCUCR = (MCUCR & 0xF3) | (edge << ISC10);
	GICR  |= (1<<INT1);                 // Enable external interrupt pin INT0
	SREG  |= (1<<7);                    // Enable interrupts by setting I-bit
}


