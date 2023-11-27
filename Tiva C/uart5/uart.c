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
    SET_BIT(SYSCTL_RCGCUART_R,5);
    SET_BIT(SYSCTL_RCGCGPIO_R ,4);

    _delay_ms(50);

     /* UART0 initialization */
    UART5_CTL_R = 0;         /* UART5 module disbable */
    UART5_IBRD_R = 104;      /* for 9600 baud rate, integer = 104 */
    UART5_FBRD_R = 11;       /* for 9600 baud rate, fractional = 11*/
    UART5_CC_R = 0;          /*select system clock*/
    //UART5_LCRH_R = 0x60;     /* data lenght 8-bit, not parity bit, no FIFO */
    UART5_LCRH_R =    ((config->s_mode)<<5)
                    | ((config->s_stop)<<3)
                    | ((config->s_parity)<<2);
    //UART5_CTL_R = 0x301;     /* Enable UART5 module, Rx and Tx */
    /* Enable UART Receive/Transmit and UART module enable */
    SET_BIT(UART5_CTL_R, UART_TRANSMIT_EN);  /* Enable UART0 Transmit */
    SET_BIT(UART5_CTL_R, UART_RECEIVE_EN);   /* Enable UART0 Receive */
    SET_BIT(UART5_CTL_R, UART_MODULE_EN);    /* Enable UART0 Module */

     /* UART5 TX5 and RX5 use PE4 and PE5. Configure them digital and enable alternate function */
    GPIO_PORTE_DEN_R = 0x30;      /* set PE4 and PE5 as digital */
    GPIO_PORTE_AFSEL_R = 0x30;    /* Use PE4,PE5 alternate function */
    GPIO_PORTE_AMSEL_R = 0;    /* Turn off analg function*/
    GPIO_PORTE_PCTL_R = 0x00110000;     /* configure PE4 and PE5 for UART */
}

/*
 * Description :
 * Functional responsible for send byte to another UART device.
 */
void UART_sendByte(const uint8 data)
{
	/* UART5 TX FIFO FULL FLAG is set indicating that the FIFO is full
        so wait till the FIFO is empty then fill it with new data
	 */
//	while(BIT_IS_SET(UART5_FR_R,TX_BUFFER_FULL)){}

	/*
	 * Put the required data in the UDR register and it also clear the UDRE flag as
	 * the UDR register is not empty now
	 */
//	UART5_DR_R = data;

/*-----------------------NEW CODE-------------------------------------*/

 while((UART5_FR_R & 0x20) != 0); /* wait until Tx buffer not full */
    UART5_DR_R = data;                  /* before giving it another byte */
}

/*
 * Description :
 * Functional responsible for receive byte from another UART device.
 */
uint8 UART_recieveByte(void)
{
	/* UART5 RX FIFO FULL FLAG is set indicating that the FIFO is full
        so wait till the FIFO is empty then read the newly filled data
	 */
  //  while(BIT_IS_SET(UART5_FR_R,RX_BUFFER_FULL)){}

	/*
	 * Read the received data from the Rx buffer (UDR)
	 * The RXC flag will be cleared after read the data
	 */
   // return UART5_DR_R;	

   /*--------------------NEW CODE---------------------------*/
    char data;
    while((UART5_FR_R & (1<<4)) != 0); /* wait until Rx buffer is not full */
    data = UART5_DR_R ;  	/* before giving it another byte */
    return (uint8) data; 
}

/*
 * Description :
 * Send the required string through UART to the other UART device.
 */
void UART_sendString(const uint8 *Str)
{
	uint8 i = 0;

	/* Send the whole string */
	while(Str[i] != '\0')
	{
		UART_sendByte(Str[i]);
		i++;
	}
}

/*
 * Description :
 * Receive the required string until the '#' symbol through UART from the other UART device.
 */
void UART_receiveString(uint8 *Str)
{
	uint8 i = 0;

	/* Receive the first byte */
	Str[i] = UART_recieveByte();

	/* Receive the whole string until the '#' */
	while(Str[i] != '#')
	{
		i++;
		Str[i] = UART_recieveByte();
	}

	/* After receiving the whole string plus the '#', replace the '#' with '\0' */
	Str[i] = '\0';
}
