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

/*
    Given the Processor Frequency:
    1 second delay takes up a number of instructions equals the PROCESSOR_FREQUENCY
    we can create a system delay by wasting that amount of clock cycles
    However, the for-loop takes up 5 unit instructions as follows:
     1- COMPARE 
     2- BRANCH 
     3- LOAD
     4- STORE
     5- ADD
    so to waste the right amount of clock cycles we need to divide the calculated number by the number
        of unit instructions in for-loop
*/
void _delay_sec(uint32 seconds){
    seconds *= PROCESSOR_FREQUENCY;
    for(uint32 i=0; i<(seconds/5); i++);
}

void _delay_ms(uint32 milliseconds){
    milliseconds *= (PROCESSOR_FREQUENCY/1000);
    for(uint32 i=0; i<(milliseconds/5); i++);
}