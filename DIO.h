/*
    AUTHOR: Ahmed Wael
    Date:   29/10/2023
*/

#ifndef DIO_H
#define DIO_H

#include "types.h"

/**************************************************************
                        PORT ID MACROS
***************************************************************/
#define PIN0_ID         0
#define PIN1_ID         1
#define PIN2_ID         2
#define PIN3_ID         3
#define PIN4_ID         4
#define PIN5_ID         5
#define PIN6_ID         6
#define PIN7_ID         7

#define PORTA_ID        0
#define PORTB_ID        1
#define PORTC_ID        2
#define PORTD_ID        3
#define PORTE_ID        4
#define PORTF_ID        5

#define NUM_OF_PORTS    6
#define NUM_OF_PINS     8

/**************************************************************
                        TYPE DECLARATION
***************************************************************/

/* Type Description:
    Variable type to facilitate the definition of pin value 
    - LOGIC_LOW = 0, LOGIC_HIGH = 1
    - In case the hardware system uses negative hardware logic, you can invert the values of the enumerations
*/
typedef enum{
    LOGIC_LOW,
    LOGIC_HIGH
}ValueType;

/* Type Description:
    Variable type to facilitate the definition of the direction of the pin
    and facilitates the readability of the code
    - PIN_INPUT = 0, PIN_OUTPUT = 1
    - These values are hardware standards mentioned in the datasheet
*/
typedef enum{
    PIN_INPUT,
    PIN_OUTPUT
}PinDirectionType;

/* Type Description:

    Variable type to facilitate the definition of the direction of the a whole port
    and facilitates the readability of the code

    !! This type is supposed to be used with a function prototype -> DIO_portInit() which performs a 
    batch setup of the port direction 

    - PORT_INPUT = 0b0000 0000      -- ALL 8 PINS ARE INPUT
    - PORT_OUTPUT = 0b1111 1111     -- ALL 8 PINS ARE OUTPUT

    - These values are hardware standards mentioned in the datasheet
*/
typedef enum{
    PORT_INPUT=0x00,
    PORT_OUTPUT=0xFF
}PortDirectionType;


/**************************************************************
                    FUNCTIONS DECLARATION
***************************************************************/

/* Function to enable a specific port in a specific pin and setup its direction 
    !! Function should be modified in the future to support the following configurations:
        - Pull-up/Pull-down configuration
*/
void DIO_Init(uint8 PortNumber, uint8 PinNumber, PinDirectionType direction);

/* Function to write a binary value in a specific pin in a specific port */
void DIO_writePin(uint8 PortNumber, uint8 PinNumber, ValueType value);

/* Function to toggle the current value in a specific pin in a specific port */
void DIO_togglePin(uint8 PortNumber, uint8 PinNumber);

/* Function to perform a batch write to all the pins in a specific port */
void DIO_writePort(uint8 PortNumber, ValueType value);

/* Function to return the value of a specific pin in a specific port */
uint8 DIO_readPin(uint8 PortNumber, uint8 PinNumber);

/* Function to return the value of a specific pin in a specific port */
uint8 DIO_readPort(uint8 PortNumber);

#endif