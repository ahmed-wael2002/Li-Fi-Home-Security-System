/*
 * timer1.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Wael
 */

#ifndef TIMER1_H_
#define TIMER1_H_

#include "std_types.h"

/*******************************************************************************
 *                      Types Definition                                    *
 *******************************************************************************/
/* Enumeration Description:
 * - Define the prescaler type of the timer module
 * - The 0 mode is neglected
 * - Each enumeration is mapped to number used in the hardware configuration
 */
typedef enum{
	F_CPU_1=1,
	F_CPU_8,
	F_CPU_64,
	F_CPU_256,
	F_CPU_1024,
	EXTERNAL_FALLING,
	EXTERNAL_RISING
}Timer1_Prescaler;

/* Enumeration Description:
 * - Define the operation mode of the timer module
 * - Only Normal and Compare modes are supported
 * - The remaining modes are neglected in this module
 * - Each enumeration is mapped to number used in the hardware configuration
 */
typedef enum{
	NORMAL=0,
	CTC=4
}Timer1_Mode;

/* Structure Description:
 * - Define the operation mode of the timer module
 * - Only Normal and Compare modes are supported
 * - The remaining modes are neglected in this module
 * - Each enumeration is mapped to number used in the hardware configuration
 */
typedef struct{
	uint16 initial_value;
	uint16 compare_value;
	Timer1_Prescaler prescaler;
	Timer1_Mode mode;
}Timer1_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initializing the timer driver:
 */
void Timer1_init(const Timer1_ConfigType *Config_ptr);

/*
 * Description :
 * Function responsible for disabling timer1:
 */
void Timer1_deinit(void);

/*
 * Description :
 * Function to set the call back function address
 */
void Timer1_setCallBack(void(*a_ptr)(void));


#endif /* TIMER1_H_ */
