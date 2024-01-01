#include "DIO.h"
#include "magnet.h"
#include "tm4c123gh6pm.h"
#include "bitwise_operation.h"
#include "int.h"

/*===============================================================================*/
/*                         FUNCTION DEFINITIONS                                  */
/*===============================================================================*/

static volatile void (*callBackPtr)(void) = NULL;

/* Function to set call back */
void MAGNET_setCallBack(void(*a_ptr)(void))
{
    INT_setCallBack(a_ptr);
}

/* Function to initialize Magnet Pin */
void MAGNET_init(void)
{
    DIO_Init(MAGNET_PORT_ID, MAGNET_PIN_ID, PIN_INPUT);
    GPIO_PORTD_LOCK_R=0x0;
    INT_init(MAGNET_PORT_ID, MAGNET_PIN_ID);
}

/* Function to read the current status of the magnet sensor */
uint8 MAGNET_read(void)
{
    return DIO_readPin(MAGNET_PORT_ID, MAGNET_PIN_ID);
}
