/*
    AUTHOR: Ahmed Wael
    Date:   29/10/2023
*/

#include "tm4c123gh6pm.h"
#include "DIO.h"
#include "bitwise_operation.h"

/* Function Description:
1- Initialize Clock for the needed port & pin
2- Buzy Wait for clock using Port Ready Register
3- Unlock Register (if needed)
4- Set the Commit Register
5- Set the pin direction 
6- Set the PUR or PDR for the pins 
7- Enable pins using digital Enable Register
*/
void DIO_Init(uint8 PortNumber, uint8 PinNumber, PinDirectionType direction){
    /* Activating the clock of the MCU to Port */
    SET_BIT(SYSCTL_RCGCGPIO_R, PortNumber);

    /* Polling Busy wait for Port to be ready */
    while(GET_BIT(SYSCTL_PRGPIO_R, PortNumber) == 0);

    /* Adjusting Ports Registers */
    switch(PortNumber){
        case PORTA_ID:
            /* Adjusting the commit register for the wanted pin */
            SET_BIT(GPIO_PORTA_CR_R, PinNumber);
            
            /* Adjusting the direction of the pin */
            if (direction == PIN_OUTPUT)
                SET_BIT(GPIO_PORTA_DIR_R, PinNumber);
            else
                CLEAR_BIT(GPIO_PORTA_DIR_R, PinNumber);

            /* By assuming Pull-up resistor config is used 
               -- NEEDS CHANGE @ Dynamic Configurations Structure */
            /* Adjusting Pull-up resistor configurations */
            SET_BIT(GPIO_PORTA_PUR_R, PinNumber);

            /* Enabling the needed Pin */
            SET_BIT(GPIO_PORTA_DEN_R, PinNumber);
            break;

        case PORTB_ID:
            /* Adjusting the commit register for the wanted pin */
            SET_BIT(GPIO_PORTB_CR_R, PinNumber);
            
            /* Adjusting the direction of the pin */
            if (direction == PIN_OUTPUT)
                SET_BIT(GPIO_PORTB_DIR_R, PinNumber);
            else{
                CLEAR_BIT(GPIO_PORTB_DIR_R, PinNumber);
                /* By assuming Pull-up resistor config is used 
                -- NEEDS CHANGE @ Dynamic Configurations Structure */
                /* Adjusting Pull-up resistor configurations */
                SET_BIT(GPIO_PORTB_PUR_R, PinNumber);
            }

            /* Enabling the needed Pin */
            SET_BIT(GPIO_PORTB_DEN_R, PinNumber);
            break;

        case PORTC_ID:
            /* Unlocking locked port */
            GPIO_PORTC_LOCK_R = 0x4C4F434B;

            /* Adjusting the commit register for the wanted pin */
            SET_BIT(GPIO_PORTC_CR_R, PinNumber);
            
            /* Adjusting the direction of the pin */
            if (direction == PIN_OUTPUT)
                SET_BIT(GPIO_PORTC_DIR_R, PinNumber);
            else
                CLEAR_BIT(GPIO_PORTC_DIR_R, PinNumber);

            /* By assuming Pull-up resistor config is used 
               -- NEEDS CHANGE @ Dynamic Configurations Structure */
            /* Adjusting Pull-up resistor configurations */
            SET_BIT(GPIO_PORTC_PUR_R, PinNumber);

            /* Enabling the needed Pin */
            SET_BIT(GPIO_PORTC_DEN_R, PinNumber);
            break;

        case PORTD_ID:
            /* Unlocking locked port */
            GPIO_PORTD_LOCK_R = 0x4C4F434B;

            /* Adjusting the commit register for the wanted pin */
            SET_BIT(GPIO_PORTD_CR_R, PinNumber);
            
            /* Adjusting the direction of the pin */
            if (direction == PIN_OUTPUT)
                SET_BIT(GPIO_PORTD_DIR_R, PinNumber);
            else
                CLEAR_BIT(GPIO_PORTD_DIR_R, PinNumber);

            /* By assuming Pull-up resistor config is used 
               -- NEEDS CHANGE @ Dynamic Configurations Structure */
            /* Adjusting Pull-up resistor configurations */
            SET_BIT(GPIO_PORTD_PUR_R, PinNumber);

            /* Enabling the needed Pin */
            SET_BIT(GPIO_PORTD_DEN_R, PinNumber);
            break;

        case PORTE_ID:
            /* Adjusting the commit register for the wanted pin */
            SET_BIT(GPIO_PORTE_CR_R, PinNumber);
            
            /* Adjusting the direction of the pin */
            if (direction == PIN_OUTPUT)
                SET_BIT(GPIO_PORTE_DIR_R, PinNumber);
            else
                CLEAR_BIT(GPIO_PORTE_DIR_R, PinNumber);

            /* By assuming Pull-up resistor config is used 
               -- NEEDS CHANGE @ Dynamic Configurations Structure */
            /* Adjusting Pull-up resistor configurations */
            SET_BIT(GPIO_PORTE_PUR_R, PinNumber);

            /* Enabling the needed Pin */
            SET_BIT(GPIO_PORTE_DEN_R, PinNumber);
            break;

        case PORTF_ID:
            /* Unlocking locked port */
            GPIO_PORTF_LOCK_R = 0x4C4F434B;
            
            /* Adjusting the commit register for the wanted pin */
            SET_BIT(GPIO_PORTF_CR_R, PinNumber);
            
            /* Adjusting the direction of the pin */
            if (direction == PIN_OUTPUT)
                SET_BIT(GPIO_PORTF_DIR_R, PinNumber);
            else
                CLEAR_BIT(GPIO_PORTF_DIR_R, PinNumber);

            /* By assuming Pull-up resistor config is used 
               -- NEEDS CHANGE @ Dynamic Configurations Structure */
            /* Adjusting Pull-up resistor configurations */
            SET_BIT(GPIO_PORTF_PUR_R, PinNumber);

            /* Enabling the needed Pin */
            SET_BIT(GPIO_PORTF_DEN_R, PinNumber);
            break;
    }
}

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void DIO_writePin(uint8 PortNumber, uint8 PinNumber, ValueType value){
    if((PortNumber >= NUM_OF_PORTS) || (PinNumber >= NUM_OF_PINS)){
        /* Do Nothing !! */
        /* This section will be used for error reporting */
    }
    else {
        switch (PortNumber){
            case PORTA_ID:
                if(value==LOGIC_HIGH)
                  SET_BIT(GPIO_PORTA_DATA_R, PinNumber);
                else
                  CLEAR_BIT(GPIO_PORTA_DATA_R, PinNumber);
                
                break;

            case PORTB_ID:
                if(value==LOGIC_HIGH)
                  SET_BIT(GPIO_PORTB_DATA_R, PinNumber);
                else
                  CLEAR_BIT(GPIO_PORTB_DATA_R, PinNumber);
                break;

            case PORTC_ID:
                if(value==LOGIC_HIGH)
                  SET_BIT(GPIO_PORTC_DATA_R, PinNumber);
                else
                  CLEAR_BIT(GPIO_PORTC_DATA_R, PinNumber);
                break;

            case PORTD_ID:
                if(value==LOGIC_HIGH)
                  SET_BIT(GPIO_PORTD_DATA_R, PinNumber);
                else
                  CLEAR_BIT(GPIO_PORTD_DATA_R, PinNumber);
                break;

            case PORTE_ID:
                if(value==LOGIC_HIGH)
                  SET_BIT(GPIO_PORTE_DATA_R, PinNumber);
                else
                  CLEAR_BIT(GPIO_PORTE_DATA_R, PinNumber);
                break;

            case PORTF_ID:
                if(value==LOGIC_HIGH)
                  SET_BIT(GPIO_PORTF_DATA_R, PinNumber);
                else
                  CLEAR_BIT(GPIO_PORTF_DATA_R, PinNumber);
                break;
        }
    }
}

/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
void DIO_writePort(uint8 PortNumber, ValueType value){
    if(PortNumber >= NUM_OF_PORTS){
        /* Do Nothing !! */
        /* This section will be used for error handling */
    }
    else{
        switch(PortNumber){
            case PORTA_ID:
                if (value == LOGIC_HIGH)
                    GPIO_PORTA_DATA_R = 0xFF;
                else
                    GPIO_PORTA_DATA_R = 0x00;
                break;

            case PORTB_ID:
                if (value == LOGIC_HIGH)
                    GPIO_PORTB_DATA_R = 0xFF;
                else
                    GPIO_PORTB_DATA_R = 0x00;
                break;

            case PORTC_ID:
                if (value == LOGIC_HIGH)
                    GPIO_PORTC_DATA_R = 0xFF;
                else
                    GPIO_PORTC_DATA_R = 0x00;
                break;

            case PORTD_ID:
                if (value == LOGIC_HIGH)
                    GPIO_PORTD_DATA_R = 0xFF;
                else
                    GPIO_PORTD_DATA_R = 0x00;
                break;
            case PORTE_ID:
                if (value == LOGIC_HIGH)
                    GPIO_PORTE_DATA_R = 0xFF;
                else
                    GPIO_PORTE_DATA_R = 0x00;
                break;

            case PORTF_ID:
                if (value == LOGIC_HIGH)
                    GPIO_PORTF_DATA_R = 0xFF;
                else
                    GPIO_PORTF_DATA_R = 0x00;
                break;
        }
    }
}

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
uint8 DIO_readPin(uint8 PortNumber, uint8 PinNumber){
    uint8 pin_value = LOGIC_LOW;

    if ((PortNumber >= NUM_OF_PORTS) || (PinNumber >= NUM_OF_PINS)){
        /* Do Nothing! */
    }
    else {
        switch(PortNumber){
            case PORTA_ID:
                if (BIT_IS_SET(GPIO_PORTA_DATA_R, PinNumber))
                    pin_value = LOGIC_HIGH;
                else
                    pin_value = LOGIC_LOW;
                break;
                
            case PORTB_ID:
                if (BIT_IS_SET(GPIO_PORTB_DATA_R, PinNumber))
                    pin_value = LOGIC_HIGH;
                else
                    pin_value = LOGIC_LOW;
                break;
                
            case PORTC_ID:
                if (BIT_IS_SET(GPIO_PORTC_DATA_R, PinNumber))
                    pin_value = LOGIC_HIGH;
                else
                    pin_value = LOGIC_LOW;
                break;
                
            case PORTD_ID:
                if (BIT_IS_SET(GPIO_PORTD_DATA_R, PinNumber))
                    pin_value = LOGIC_HIGH;
                else
                    pin_value = LOGIC_LOW;
                break;
                
            case PORTE_ID:
                if (BIT_IS_SET(GPIO_PORTE_DATA_R, PinNumber))
                    pin_value = LOGIC_HIGH;
                else
                    pin_value = LOGIC_LOW;
                break;
                
            case PORTF_ID:
                if (BIT_IS_SET(GPIO_PORTF_DATA_R, PinNumber))
                    pin_value = LOGIC_HIGH;
                else
                    pin_value = LOGIC_LOW;
                break;
                
        }
    }
}

/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
uint8 DIO_readPort(uint8 PortNumber){
    uint8 port_value = LOGIC_LOW;
    if (PortNumber >= NUM_OF_PORTS){
        /* Do Nothing ! */
    }
    else {
        switch(PortNumber){
            case PORTA_ID:
                port_value = GPIO_PORTA_DATA_R;
                break;

            case PORTB_ID:
                port_value = GPIO_PORTB_DATA_R;
                break;

            case PORTC_ID:
                port_value = GPIO_PORTC_DATA_R;
                break;

            case PORTD_ID:
                port_value = GPIO_PORTD_DATA_R;
                break;

            case PORTE_ID:
                port_value = GPIO_PORTE_DATA_R;
                break;

            case PORTF_ID:
                port_value = GPIO_PORTF_DATA_R;
                break;
        }
        return port_value;
    }
}

/* Function to toggle the current value in a specific pin in a specific port */
void DIO_togglePin(uint8 PortNumber, uint8 PinNumber){
    if((PortNumber >= NUM_OF_PORTS) || (PinNumber >= NUM_OF_PINS)){
        /* Do Nothing !! */
        /* This section will be used for error reporting */
    }
    else {
        switch (PortNumber){
            case PORTA_ID:
                TOGGLE_BIT(GPIO_PORTA_DATA_R, PinNumber);
                break;

            case PORTB_ID:
                TOGGLE_BIT(GPIO_PORTB_DATA_R, PinNumber);
                break;

            case PORTC_ID:
                TOGGLE_BIT(GPIO_PORTC_DATA_R, PinNumber);
                break;

            case PORTD_ID:
                TOGGLE_BIT(GPIO_PORTD_DATA_R, PinNumber);
                break;

            case PORTE_ID:
                TOGGLE_BIT(GPIO_PORTE_DATA_R, PinNumber);
                break;

            case PORTF_ID:
                TOGGLE_BIT(GPIO_PORTF_DATA_R, PinNumber);
                break;
        }
    }
}
