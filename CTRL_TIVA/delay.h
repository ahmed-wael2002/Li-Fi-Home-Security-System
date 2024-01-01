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

#include "types.h"

/* ===================== Fucntion Prototypes ======================== */
void _delay_sec(uint32 seconds);
void _delay_ms(uint32 milliseconds);

#endif