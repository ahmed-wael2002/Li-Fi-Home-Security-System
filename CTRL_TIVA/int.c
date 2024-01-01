#include "tm4c123gh6pm.h"
#include "bitwise_operation.h"
#include "int.h"

/*===============================================================================*/
/*                         FUNCTION DEFINITIONS                                  */
/*===============================================================================*/
void GPIOD_Handler(void);

/* Function to initialize Magnet Pin */
void INT_init(uint8 portNumber, uint8 pinNumber)
{
    switch (portNumber)
    {
    case PORTA_ID:
        SET_BIT(GPIO_PORTA_IM_R, pinNumber);
        CLEAR_BIT(GPIO_PORTA_IS_R, pinNumber);
        SET_BIT(GPIO_PORTA_IEV_R, pinNumber);
        CLEAR_BIT(GPIO_PORTA_IBE_R, pinNumber);
        NVIC_PRI0_R = (NVIC_PRI0_R & 0xFFFFFF1F) | ((INTERRUPT_PRIORITY_LEVEL & 0x07) << 5);
        SET_BIT(NVIC_EN0_R, INT_GPIOA - 16);
        break;

    case PORTB_ID:
        SET_BIT(GPIO_PORTB_IM_R, pinNumber);
        CLEAR_BIT(GPIO_PORTB_IS_R, pinNumber);
        SET_BIT(GPIO_PORTB_IEV_R, pinNumber);
        CLEAR_BIT(GPIO_PORTB_IBE_R, pinNumber);
        NVIC_PRI0_R = (NVIC_PRI0_R & 0xFFFF1FFF) | ((INTERRUPT_PRIORITY_LEVEL & 0x07) << 13);
        SET_BIT(NVIC_EN0_R, INT_GPIOB - 16);
        break;

    case PORTC_ID:
        SET_BIT(GPIO_PORTC_IM_R, pinNumber);
        CLEAR_BIT(GPIO_PORTC_IS_R, pinNumber);
        SET_BIT(GPIO_PORTC_IEV_R, pinNumber);
        CLEAR_BIT(GPIO_PORTC_IBE_R, pinNumber);
        NVIC_PRI0_R = (NVIC_PRI0_R & 0xFF1FFFFF) | ((INTERRUPT_PRIORITY_LEVEL & 0x07) << 21);
        SET_BIT(NVIC_EN0_R, INT_GPIOC - 16);
        break;

    case PORTD_ID:
        CLEAR_BIT(GPIO_PORTD_ICR_R, pinNumber);                                               // clears the int flag (if any
        SET_BIT(GPIO_PORTD_IM_R, pinNumber);                                                  // enables int for the pin
        CLEAR_BIT(GPIO_PORTD_IS_R, pinNumber);                                                // edge or level ?
        SET_BIT(GPIO_PORTD_IEV_R, pinNumber);                                                 // +ve or -ve ?
        CLEAR_BIT(GPIO_PORTD_IBE_R, pinNumber);                                               // both ?
        NVIC_PRI0_R = (NVIC_PRI0_R & 0x1FFFFFFF) | ((INTERRUPT_PRIORITY_LEVEL & 0x07) << 29); // Priotiy ?
        SET_BIT(NVIC_EN0_R, INT_GPIOD - 16);
        break;

    case PORTE_ID:
        SET_BIT(GPIO_PORTE_IM_R, pinNumber);
        CLEAR_BIT(GPIO_PORTE_IS_R, pinNumber);
        SET_BIT(GPIO_PORTE_IEV_R, pinNumber);
        CLEAR_BIT(GPIO_PORTE_IBE_R, pinNumber);
        NVIC_PRI1_R = (NVIC_PRI1_R & 0xFFFFFF1F) | ((INTERRUPT_PRIORITY_LEVEL & 0x07) << 5);
        SET_BIT(NVIC_EN0_R, INT_GPIOE - 16);
        break;

    case PORTF_ID:
        SET_BIT(GPIO_PORTF_IM_R, pinNumber);
        CLEAR_BIT(GPIO_PORTF_IS_R, pinNumber);
        SET_BIT(GPIO_PORTF_IEV_R, pinNumber);
        CLEAR_BIT(GPIO_PORTF_IBE_R, pinNumber);
        NVIC_PRI1_R = (NVIC_PRI1_R & 0xFFFF1FFF) | ((INTERRUPT_PRIORITY_LEVEL & 0x07) << 13);
        SET_BIT(NVIC_EN0_R, INT_GPIOF - 16);
        break;
    default:
        break;
    }
}

static volatile void (*callBackPtr)(void) = NULL;

/* Function to set call back */
void INT_setCallBack(void (*a_ptr)(void))
{
    /* Save the address of the Call back function in a global variable */
    callBackPtr = a_ptr;
}

/*===============================================================================*/
/*                             INTERRUPT HANDLERS                                */
/*===============================================================================*/

void GPIOD_Handler(void)
{
    if (callBackPtr != NULL)
    {
        /* Call the Call Back function in the application after the edge is detected */
        (*callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
        SET_BIT(GPIO_PORTD_ICR_R, PIN1_ID);
    }
}


