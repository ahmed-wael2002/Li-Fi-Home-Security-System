 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.c
 *
 * Description: Source file for the UART Tiva driver
 *
 * Author: Ahmed Wael Ibrahim Mohamed - 20P3343
 *
 *******************************************************************************/

#include "uart.h"
#include "tm4c123gh6pm.h"
#include "bitwise_operation.h"
#include "delay.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*
 * Description :
 * Functional responsible for Initialize the UART device by:
 * 1. Setup the Frame format like number of data bits, parity bit type and number of stop bits.
 * 2. Enable the UART.
 * 3. Setup the UART baud rate.
 */
void UART_init(const UART_ConfigType *config)
{
    // Mapping of RX Pins
    int pinNumber, portNumber, pctl_val;
    // Calculating Baud Rate Values
    float fbrd = CLK_FREQUENCY / (16.0 * (float)config->s_baud_rate);
    int ibrd = (int)fbrd;
    fbrd -= ibrd;
    fbrd = (int)(fbrd * 64 + 0.5);
    switch(config->s_module){
        case UART_0:
            portNumber = PORTA_ID;
            pinNumber = 0;
            pctl_val = 0x00000011;  // Mux Control Value for Pin0,1
            break;
        case UART_1:
            portNumber = PORTC_ID;
            pinNumber = 4;
            pctl_val = 0x00110000;  // Mux Control Value for Pin0,1
            break;
        case UART_2:
            portNumber = PORTD_ID;
            pinNumber = 6;
            pctl_val = 0x11000000;  // Mux Control Value for Pin0,1
            break;
        case UART_3:
            portNumber = PORTC_ID;
            pinNumber = 6;
            pctl_val = 0x11000000;  // Mux Control Value for Pin0,1
            break;
        case UART_4:
            portNumber = PORTC_ID;
            pinNumber = 4;
            pctl_val = 0x00110000;  // Mux Control Value for Pin0,1
            break;
        case UART_5:
            portNumber = PORTE_ID;
            pinNumber = 4;
            pctl_val = 0x00110000;  // Mux Control Value for Pin0,1
            break;
        case UART_6:
            portNumber = PORTD_ID;
            pinNumber = 4;
            pctl_val = 0x00110000;  // Mux Control Value for Pin0,1
            break;
        case UART_7:
            portNumber = PORTE_ID;
            pinNumber = 0;
            pctl_val = 0x00000011;  // Mux Control Value for Pin0,1
            break;
    }

    SET_BIT(SYSCTL_RCGCUART_R,config->s_module);
    SET_BIT(SYSCTL_RCGCGPIO_R ,portNumber);
    _delay_ms(50);

    // Configuring Pins
    /* UART5 TX5 and RX5 use PE4 and PE5. Configure them digital and enable alternate function */
    switch(portNumber){
        case PORTA_ID:
            // Enabling digital pins for RX & TX
            SET_BIT(GPIO_PORTA_DEN_R, pinNumber);
            SET_BIT(GPIO_PORTA_DEN_R, pinNumber+1);

            // Enabling alternate functions for RX & TX
            SET_BIT(GPIO_PORTA_AFSEL_R, pinNumber);
            SET_BIT(GPIO_PORTA_AFSEL_R, pinNumber+1);

            // Enabling alternate functions for RX & TX
            CLEAR_BIT(GPIO_PORTA_AMSEL_R, pinNumber);
            CLEAR_BIT(GPIO_PORTA_AMSEL_R, pinNumber+1);

            // Configuring Mux Control for pin0,1
            GPIO_PORTA_PCTL_R |= pctl_val;
            break;
        case PORTC_ID:
            // Enabling digital pins for RX & TX
            SET_BIT(GPIO_PORTC_DEN_R, pinNumber);
            SET_BIT(GPIO_PORTC_DEN_R, pinNumber+1);
            // Enabling alterCate functions for RX & TX
            SET_BIT(GPIO_PORTC_AFSEL_R, pinNumber);
            SET_BIT(GPIO_PORTC_AFSEL_R, pinNumber+1);

            // Enabling alternate functions for RX & TX
            CLEAR_BIT(GPIO_PORTC_AMSEL_R, pinNumber);
            CLEAR_BIT(GPIO_PORTC_AMSEL_R, pinNumber+1);

            // Configuring Mux Control for pin0,1
            GPIO_PORTC_PCTL_R |= pctl_val;
            break;
        case PORTD_ID:
            // Enabling digital pins for RX & TX
            SET_BIT(GPIO_PORTD_DEN_R, pinNumber);
            SET_BIT(GPIO_PORTD_DEN_R, pinNumber+1);
            // Enabling alterDate functions for RX & TX
            SET_BIT(GPIO_PORTD_AFSEL_R, pinNumber);
            SET_BIT(GPIO_PORTD_AFSEL_R, pinNumber+1);

            // Enabling alternate functions for RX & TX
            CLEAR_BIT(GPIO_PORTD_AMSEL_R, pinNumber);
            CLEAR_BIT(GPIO_PORTD_AMSEL_R, pinNumber+1);

            // Configuring Mux Control for pin0,1
            GPIO_PORTD_PCTL_R |= pctl_val;
            break;
        case PORTE_ID:
            // Enabling digital pins for RX & TX
            SET_BIT(GPIO_PORTE_DEN_R, pinNumber);
            SET_BIT(GPIO_PORTE_DEN_R, pinNumber+1);
            // Enabling alterEate functions for RX & TX
            SET_BIT(GPIO_PORTE_AFSEL_R, pinNumber);
            SET_BIT(GPIO_PORTE_AFSEL_R, pinNumber+1);

            // Enabling alternate functions for RX & TX
            CLEAR_BIT(GPIO_PORTE_AMSEL_R, pinNumber);
            CLEAR_BIT(GPIO_PORTE_AMSEL_R, pinNumber+1);

            // Configuring Mux Control for pin0,1
            GPIO_PORTE_PCTL_R |= pctl_val;
            break;
    }

    switch(config->s_module){
        case UART_0:  
            /* UART0 initialization */
            UART0_CTL_R = 0;         /* UART5 module disbable */
            UART0_IBRD_R = ibrd;      /* for 9600 baud rate, integer = 104 */
            UART0_FBRD_R = fbrd;       /* for 9600 baud rate, fractional = 11*/
            UART0_CC_R = 0;          /*select system clock*/
            //UA0T5_LCRH_R = 0x60;     /* data lenght 8-bit, not parity bit, no FIFO */
            UART0_LCRH_R =    ((config->s_mode)<<5)
                            | ((config->s_stop)<<3)
                            | ((config->s_parity)<<2);
            //UART5_CTL_R = 0x301;     /* Enable UART5 module, Rx and Tx */
            /* Enable UART Receive/Transmit and UART module enable */
            UART0_CTL_R |= (UART_CTL_UARTEN) | (UART_CTL_RXE) | (UART_CTL_TXE);
            break;

        case UART_1:  
            /* UART0 initialization */
            UART1_CTL_R = 0;         /* UART5 module disbable */
            UART1_IBRD_R = ibrd;      /* for 9600 baud rate, integer = 104 */
            UART1_FBRD_R = fbrd;       /* for 9600 baud rate, fractional = 11*/
            UART1_CC_R = 0;          /*select system clock*/
            //UA0T5_LCRH_R = 0x60;     /* data lenght 8-bit, not parity bit, no FIFO */
            UART1_LCRH_R =    ((config->s_mode)<<5)
                            | ((config->s_stop)<<3)
                            | ((config->s_parity)<<2);
            //UART5_CTL_R = 0x301;     /* Enable UART5 module, Rx and Tx */
            /* Enable UART Receive/Transmit and UART module enable */
            UART1_CTL_R |= (UART_CTL_UARTEN) | (UART_CTL_RXE) | (UART_CTL_TXE);
            break;

        case UART_2:  
            /* UART0 initialization */
            UART2_CTL_R = 0;         /* UART5 module disbable */
            UART2_IBRD_R = ibrd;      /* for 9600 baud rate, integer = 104 */
            UART2_FBRD_R = fbrd;       /* for 9600 baud rate, fractional = 11*/
            UART2_CC_R = 0;          /*select system clock*/
            //UA2T5_LCRH_R = 0x60;     /* data lenght 8-bit, not parity bit, no FIFO */
            UART2_LCRH_R =    ((config->s_mode)<<5)
                            | ((config->s_stop)<<3)
                            | ((config->s_parity)<<2);
            //UART5_CTL_R = 0x301;     /* Enable UART5 module, Rx and Tx */
            /* Enable UART Receive/Transmit and UART module enable */
            UART2_CTL_R |= (UART_CTL_UARTEN) | (UART_CTL_RXE) | (UART_CTL_TXE);
            break;

        case UART_3:  
            /* UART0 initialization */
            UART3_CTL_R = 0;         /* UART5 module disbable */
            UART3_IBRD_R = ibrd;      /* for 9600 baud rate, integer = 104 */
            UART3_FBRD_R = fbrd;       /* for 9600 baud rate, fractional = 11*/
            UART3_CC_R = 0;          /*select system clock*/
            //UA3T5_LCRH_R = 0x60;     /* data lenght 8-bit, not parity bit, no FIFO */
            UART3_LCRH_R =    ((config->s_mode)<<5)
                            | ((config->s_stop)<<3)
                            | ((config->s_parity)<<2);
            //UA3T5_CTL_R = 0x301;     /* Enable UART5 module, Rx and Tx */
            /* E3able UART Receive/Transmit and UART module enable */
            UART3_CTL_R |= (UART_CTL_UARTEN) | (UART_CTL_RXE) | (UART_CTL_TXE);
            break;

        case UART_4:  
            /* UART0 initialization */
            UART4_CTL_R = 0;         /* UART5 module disbable */
            UART4_IBRD_R = ibrd;      /* for 9600 baud rate, integer = 104 */
            UART4_FBRD_R = fbrd;       /* for 9600 baud rate, fractional = 11*/
            UART4_CC_R = 0;          /*select system clock*/
            //UA4T5_LCRH_R = 0x60;     /* data lenght 8-bit, not parity bit, no FIFO */
            UART4_LCRH_R =    ((config->s_mode)<<5)
                            | ((config->s_stop)<<3)
                            | ((config->s_parity)<<2);
            //UA4T5_CTL_R = 0x301;     /* Enable UART5 module, Rx and Tx */
            /* E4able UART Receive/Transmit and UART module enable */
            UART4_CTL_R |= (UART_CTL_UARTEN) | (UART_CTL_RXE) | (UART_CTL_TXE);
            break;

        case UART_5:  
            /* UART0 initialization */
            UART5_CTL_R = 0;         /* UART5 module disbable */
            UART5_IBRD_R = ibrd;      /* for 9600 baud rate, integer = 104 */
            UART5_FBRD_R = fbrd;       /* for 9600 baud rate, fractional = 11*/
            UART5_CC_R = 0;          /*select system clock*/
            //UA5T5_LCRH_R = 0x60;     /* data lenght 8-bit, not parity bit, no FIFO */
            UART5_LCRH_R =    ((config->s_mode)<<5)
                            | ((config->s_stop)<<3)
                            | ((config->s_parity)<<2);
            //UA5T5_CTL_R = 0x301;     /* Enable UART5 module, Rx and Tx */
            /* E5able UART Receive/Transmit and UART module enable */
            UART5_CTL_R |= (UART_CTL_UARTEN) | (UART_CTL_RXE) | (UART_CTL_TXE);
            break;

        case UART_6:  
            /* UART0 initialization */
            UART6_CTL_R = 0;         /* UART5 module disbable */
            UART6_IBRD_R = ibrd;      /* for 9600 baud rate, integer = 104 */
            UART6_FBRD_R = fbrd;       /* for 9600 baud rate, fractional = 11*/
            UART6_CC_R = 0;          /*select system clock*/
            //UA6T5_LCRH_R = 0x60;     /* data lenght 8-bit, not parity bit, no FIFO */
            UART6_LCRH_R =    ((config->s_mode)<<5)
                            | ((config->s_stop)<<3)
                            | ((config->s_parity)<<2);
            //UA6T5_CTL_R = 0x301;     /* Enable UART5 module, Rx and Tx */
            /* E6able UART Receive/Transmit and UART module enable */
            UART6_CTL_R |= (UART_CTL_UARTEN) | (UART_CTL_RXE) | (UART_CTL_TXE);
            break;

        case UART_7:  
            /* UART0 initialization */
            UART7_CTL_R = 0;         /* UART5 module disbable */
            UART7_IBRD_R = ibrd;      /* for 9600 baud rate, integer = 104 */
            UART7_FBRD_R = fbrd;       /* for 9600 baud rate, fractional = 11*/
            UART7_CC_R = 0;          /*select system clock*/
            //UA7T5_LCRH_R = 0x60;     /* data lenght 8-bit, not parity bit, no FIFO */
            UART7_LCRH_R =    ((config->s_mode)<<5)
                            | ((config->s_stop)<<3)
                            | ((config->s_parity)<<2);
            //UA7T5_CTL_R = 0x301;     /* Enable UART5 module, Rx and Tx */
            /* E7able UART Receive/Transmit and UART module enable */
            UART7_CTL_R |= (UART_CTL_UARTEN) | (UART_CTL_RXE) | (UART_CTL_TXE);
            break;
    }
   
}

/*
 * Description :
 * Functional responsible for send byte to another UART device.
 */
void UART_sendByte(const UART_ModuleNumber module,const uint8 data)
{
    switch(module){
        case UART_0:
            while((UART0_FR_R & 0x20) != 0); /* wait until Tx buffer not full */
            UART0_DR_R = data;                  /* before giving it another byte */
            break;
        case UART_1:
            while((UART1_FR_R & 0x20) != 0); /* wait until Tx buffer not full */
            UART1_DR_R = data;                  /* before giving it another byte */
            break;
        case UART_2:
            while((UART2_FR_R & 0x20) != 0); /* wait until Tx buffer not full */
            UART2_DR_R = data;                  /* before giving it another byte */
            break;
        case UART_3:
            while((UART3_FR_R & 0x20) != 0); /* wait until Tx buffer not full */
            UART3_DR_R = data;                  /* before giving it another byte */
            break;
        case UART_4:
            while((UART4_FR_R & 0x20) != 0); /* wait until Tx buffer not full */
            UART4_DR_R = data;                  /* before giving it another byte */
            break;
        case UART_5:
            while((UART5_FR_R & 0x20) != 0); /* wait until Tx buffer not full */
            UART5_DR_R = data;                  /* before giving it another byte */
            break;
        case UART_6:
            while((UART6_FR_R & 0x20) != 0); /* wait until Tx buffer not full */
            UART6_DR_R = data;                  /* before giving it another byte */
            break;
        case UART_7:
            while((UART7_FR_R & 0x20) != 0); /* wait until Tx buffer not full */
            UART7_DR_R = data;                  /* before giving it another byte */
            break;
    }

}

/*
 * Description :
 * Functional responsible for receive byte from another UART device.
 */
uint8 UART_recieveByte(UART_ModuleNumber module)
{
    char data;

    switch(module){
        case UART_0:
            while((UART0_FR_R & (1<<4)) != 0); /* wait until Rx buffer is not full */
            data = UART0_DR_R ;  	/* before giving it another byte */
            break;
        case UART_1:
            while((UART1_FR_R & (1<<4)) != 0); /* wait until Rx buffer is not full */
            data = UART1_DR_R ;  	/* before giving it another byte */
            break;
        case UART_2:
            while((UART2_FR_R & (1<<4)) != 0); /* wait until Rx buffer is not full */
            data = UART2_DR_R ;  	/* before giving it another byte */
            break;
        case UART_3:
            while((UART3_FR_R & (1<<4)) != 0); /* wait until Rx buffer is not full */
            data = UART3_DR_R ;  	/* before giving it another byte */
            break;
        case UART_4:
            while((UART4_FR_R & (1<<4)) != 0); /* wait until Rx buffer is not full */
            data = UART4_DR_R ;  	/* before giving it another byte */
            break;
        case UART_5:
            while((UART5_FR_R & (1<<4)) != 0); /* wait until Rx buffer is not full */
            data = UART5_DR_R ;  	/* before giving it another byte */
            break;
        case UART_6:
            while((UART6_FR_R & (1<<4)) != 0); /* wait until Rx buffer is not full */
            data = UART6_DR_R ;  	/* before giving it another byte */
            break;
        case UART_7:
            while((UART7_FR_R & (1<<4)) != 0); /* wait until Rx buffer is not full */
            data = UART7_DR_R ;  	/* before giving it another byte */
            break;
    }

    return (uint8) data; 
}

/*
 * Description :
 * Send the required string through UART to the other UART device.
 */
void UART_sendString(UART_ModuleNumber module, const uint8 *Str)
{
	uint8 i = 0;

	/* Send the whole string */
	while(Str[i] != '\0')
	{
		UART_sendByte(module, Str[i]);
		i++;
	}
}

/*
 * Description :
 * Receive the required string until the '#' symbol through UART from the other UART device.
 */
void UART_receiveString(UART_ModuleNumber module, uint8 *Str)
{
	uint8 i = 0;

	/* Receive the first byte */
	Str[i] = UART_recieveByte(module);

	/* Receive the whole string until the '#' */
	while(Str[i] != '#')
	{
		i++;
		Str[i] = UART_recieveByte(module);
	}

	/* After receiving the whole string plus the '#', replace the '#' with '\0' */
	Str[i] = '\0';
}

/*
 * Description :
 * Send the required integer through UART to the other UART device.
 */
void UART_sendInteger(UART_ModuleNumber module, uint32 value){
    uint8 uDigits[20];
    signed char uCounter = 0;

    /* Send the negative sign in case of negative numbers */
    if (value < 0)
    {
        UART_sendByte(module, '-');
        value *= -1;
    }

    /* Convert the number to an array of characters */
    do
    {
        uDigits[uCounter++] = value % 10 + '0'; /* Convert each digit to its corresponding ASCI character */
        value /= 10; /* Remove the already converted digit */
    }
    while (value != 0);

    /* Send the array of characters in a reverse order as the digits were converted from right to left */
    for( uCounter--; uCounter>= 0; uCounter--)
    {
        UART_sendByte(module, uDigits[uCounter]);
    } 
}
