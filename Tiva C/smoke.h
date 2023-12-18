#ifndef _SMOKE_H
#define _SMOKE_H
#include "types.h"
/*= == == == == == == == == == Macros == == == == == == == == == = * /
/*  Macros to define the pin and port of smoke */
#define SMOKE_PORTID PORTD_ID
#define SMOKE_PIN_ID PIN0_ID

/*  Macros to define the logic state of SMOKE_ON and SMOKE_OFF */
#define SMOKE_ON LOGIC_LOW
#define SMOKE_OFF LOGIC_HIGH
/*=================== Function Prototypes ===================*/
/* Function Description:
    - Initializing the pins states and directions for smoke connected pin defined in the macros
    - INPUT: None (Configure the macros @ the beginning in the start)
    - OUTPUT: smoke pin initialized
*/
void Smoke_INIT(void);
/* Function Description:
    - Read the state of the smoke pin
    - INPUT: None
    - OUTPUT: smoke pin state
*/
uint8 Smoke_READ(void);
#endif