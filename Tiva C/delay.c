 /******************************************************************************
 *
 * Module: DELAY
 *
 * File Name: delay.c
 *
 * Description: Source file for the delay functions
 *
 * Author: Ahmed Wael Ibrahim Mohamed
 *
 *******************************************************************************/

#include "delay.h"

void _delay_sec(uint32 seconds){
    seconds *= PROCESSOR_FREQUENCY;
    for(uint32 i=0; i<seconds; i++);
}

void _delay_ms(uint32 milliseconds){
    milliseconds *= (PROCESSOR_FREQUENCY/1000);
    for(uint32 i=0; i<milliseconds; i++);
}