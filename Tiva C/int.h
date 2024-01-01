#include "types.h"


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

#define INTERRUPT_PRIORITY_LEVEL 0x3


// Function to initialize the interrupt 
void INT_init(uint8 portNumber, uint8 pinNumber);

// Function to set the callback function
void INT_setCallBack(void(*a_ptr)(void));


