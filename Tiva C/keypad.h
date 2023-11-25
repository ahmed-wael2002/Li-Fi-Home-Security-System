#ifndef _KEYPAD_H
#define _KEYPAD_H

#include "types.h"

/*==============================================================*/
/*                        Module Macros                         */
/*==============================================================*/

/* The module is configured for a 4x5 keypad
    -- Configure the macros for a different keypad */
#define NUM_OF_COLS 4
#define NUM_OF_ROWS 5

/* -- Configure these macros for a different ports and pins */
#define ROWS_PORT_ID        PORTA_ID
#define FIRST_ROW_PIN_ID    PIN2_ID

#define COLS_PORT_ID        PORTE_ID
#define FIRST_COL_PIN_ID    PIN1_ID

/* -- Configure these for Pull-up/Pull-down configurations */
#define KEY_PRESSED         LOGIC_LOW
#define KEY_RELEASED        LOGIC_HIGH

#define ROW_ON              (DIO_readPin(ROWS_PORT_ID, FIRST_ROW_PIN_ID+row) == KEY_PRESSED)


/*==============================================================*/
/*                     Function Prototypes                      */
/*==============================================================*/

/*
    Function Description: Initialize keypad pins 
    -- Input: None
    -- Output: Keypad Pins are fully configured
*/
void KEYPAD_init(void);

/*
    Function Description: Function to get the pressed key in keypad
    -- Input: None 
    -- Output: 1 character of corresponding key pressed in the keypad
                all numbers are returned as character
*/
uint8 KeyPad_Read(void);

#endif