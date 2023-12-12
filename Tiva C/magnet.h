#ifndef _MAGNET_H
#define _MAGNET_H
#include "types.h"
/*= == == == == == == == == == Macros == == == == == == == == == = * /
/*  Macros to define the pin and port of magnet */
#define MAGNET_PORT_ID  PORTD_ID
#define MAGNET_PIN_ID   PIN0_ID


/*  Macros to define the logic state of MAGNET_ON and MAGNET_OFF */
#define MAGNET_ON       LOGIC_HIGH
#define MAGNET_OFF      LOGIC_LOW
/*=================== Function Prototypes ===================*/
/* Function Description:
    - Initializing the pins states and directions for magnet connected pin defined in the macros
    - INPUT: None (Configure the macros @ the beginning in the start)
    - OUTPUT: magnet pin initialized
*/
void Magnet_INIT(void);
/* Function Description:
    - Read the state of the magnet pin
    - INPUT: None
    - OUTPUT: magnet pin state
*/
uint8 Magnet_Read(void);
#endif