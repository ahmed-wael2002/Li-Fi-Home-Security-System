/*
 * int.h
 *
 *  Created on: Nov 27, 2023
 *      Author: Wael
 */

#ifndef INT_H_
#define INT_H_

#include "std_types.h"

/*******************************************************************************
 *                       Type Definition                            *
 *******************************************************************************/

typedef enum{
	FALLING=2,
	RISING
}Edge;


/*******************************************************************************
 *                       Interrupt (0) Functions                            *
 *******************************************************************************/

/* Description: Function to initialize interrupt 0 pin */
void INT0_init(Edge edge);

/* Description: Function to set the Call Back function address for interrupt 0 */
void INT0_setCallback(void(*a_ptr)(void));

/*******************************************************************************
 *                       Interrupt (1) Functions                            *
 *******************************************************************************/

/* Description: Function to initialize interrupt 0 pin */
void INT1_init(Edge edge);

/* Description: Function to set the Call Back function address for interrupt 0 */
void INT1_setCallback(void(*a_ptr)(void));



#endif /* INT_H_ */
