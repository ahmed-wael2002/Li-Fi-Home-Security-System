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
#include "tm4c123gh6pm.h"

void _delay_sec(uint32 seconds){
    /* Configuring 24-bit Systick Timer */
    // Polling method is used
    NVIC_ST_CTRL_R |= (NVIC_ST_CTRL_CLK_SRC)     // Use system timer
                    | (NVIC_ST_CTRL_ENABLE);     // Enable Systick Timer
    seconds = (seconds * PROCESSOR_FREQUENCY) - 1;

    // Inserting Reload value into Systick Reload Register
    // Reload value should be 24-bits
    NVIC_ST_RELOAD_R = (NVIC_ST_RELOAD_R & ~0x00FFFFFF) | (seconds & 0x00FFFFFF);
    
    // Wait till timeout
    while((NVIC_ST_CTRL_R & NVIC_ST_CTRL_COUNT) == 0);
}

void _delay_ms(uint32 milliseconds){
    /* Configuring 24-bit Systick Timer */
    // Polling method is used
    NVIC_ST_CTRL_R |= (NVIC_ST_CTRL_CLK_SRC)     // Use system timer
                    | (NVIC_ST_CTRL_ENABLE);     // Enable Systick Timer
    milliseconds = (milliseconds * PROCESSOR_FREQUENCY)/1000 - 1;

    // Inserting Reload value into Systick Reload Register
    // Reload value should be 24-bits
    NVIC_ST_RELOAD_R = (NVIC_ST_RELOAD_R & ~0x00FFFFFF) | (milliseconds & 0x00FFFFFF);

    // Wait till timeout
    while((NVIC_ST_CTRL_R & NVIC_ST_CTRL_COUNT) == 0);
}