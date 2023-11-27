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
void SysTick_Init(void) {
    // Disable SysTick during setup
    NVIC_ST_CTRL_R = 0;                  
    
    // Set the reload value for a 1ms interrupt
    NVIC_ST_RELOAD_R = PROCESSOR_FREQUENCY / 1000 - 1;
    
    // Set the clock source to system clock and enable the SysTick timer
    NVIC_ST_CTRL_R |= (NVIC_ST_CTRL_CLK_SRC | NVIC_ST_CTRL_ENABLE);

}

void SysTick_Delay(uint32 delay_ms) {
    // Load the delay value into the reload register
    NVIC_ST_RELOAD_R = (PROCESSOR_FREQUENCY / 1000 * delay_ms) - 1;
    
    // Start the SysTick timer and wait until the COUNT flag is set
    NVIC_ST_CTRL_R |= NVIC_ST_CTRL_ENABLE;
    while ((NVIC_ST_CTRL_R & NVIC_ST_CTRL_COUNT) == 0) {}
    
    // Disable the SysTick timer
    NVIC_ST_CTRL_R &= ~NVIC_ST_CTRL_ENABLE;
}

void SysTick_Delay_Seconds(uint32 seconds) {
    // Convert seconds to milliseconds and call the SysTick_Delay function
    SysTick_Delay(seconds * 1000);
}

void _delay_sec(uint32 seconds){
    seconds *= PROCESSOR_FREQUENCY;
    for(uint32 i=0; i<(seconds/5); i++);
}

void _delay_ms(uint32 milliseconds){
    milliseconds *= (PROCESSOR_FREQUENCY/1000);
    for(uint32 i=0; i<(milliseconds/5); i++);
}