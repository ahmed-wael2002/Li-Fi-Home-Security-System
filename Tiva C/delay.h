 /******************************************************************************
 *
 * Module: DELAY
 *
 * File Name: delay.h
 *
 * Description: Header file for the delay functions
 *
 * Author: Ahmed Wael Ibrahim Mohamed
 *
 *******************************************************************************/

#ifndef DELAY_H_
#define DELAY_H_

#define PROCESSOR_FREQUENCY 16000000

#include "tm4c123gh6pm.h"
#include "types.h"

/* ===================== SysTick Fucntion Prototypes ======================== */
void SysTick_Init(void);
void SysTick_Delay(uint32 delay_ms);
void SysTick_Delay_Seconds(uint32 seconds);

/* ===================== Fucntion Prototypes ======================== */
void _delay_sec(uint32 seconds);
void _delay_ms(uint32 milliseconds);

#endif