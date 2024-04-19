 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.h
 *
 * Description: Header file for the UART Tiva C driver
 *
 * Author: Ahmed Wael Ibrahim Mohamed - 20P3343
 *
 *******************************************************************************/

#ifndef UART_H_
#define UART_H_

#include "types.h"

#define UART_MODULE_EN      0
#define UART_TRANSMIT_EN    8
#define UART_RECEIVE_EN     9
#define TX_BUFFER_FULL  	5
#define RX_BUFFER_FULL   	4  


#define PORTA_ID    0
#define PORTB_ID    1
#define PORTC_ID    2
#define PORTD_ID    3
#define PORTE_ID    4
#define PORTF_ID    5

#define PIN0_ID     0
#define PIN1_ID     1
#define PIN2_ID     2
#define PIN3_ID     3
#define PIN4_ID     4
#define PIN5_ID     5
#define PIN6_ID     6
#define PIN7_ID     7 

/*******************************************************************************
 *                      Types Definition                                    *
 *******************************************************************************/

/* Type to define the parity mode */
typedef enum{
	DISABLED,
	ODD_PARITY,
    EVEN_PARITY
}UART_ParityType;

/* Type to define the size of the stop bit */
typedef enum{
	ONE_BIT,
	TWO_BIT
}UART_StopBitType;

/* Type to define the frame size */
typedef enum{
	BIT_5,
	BIT_6,
	BIT_7,
	BIT_8,
}UART_ModeType;

typedef enum{
	UART_0,
	UART_1,
	UART_2,
	UART_3, 
	UART_4,
	UART_5,
	UART_6, 
	UART_7
}UART_ModuleNumber;


typedef struct{
	UART_ModuleNumber s_module;
	uint32 s_baud_rate;
	UART_ParityType s_parity;
	UART_StopBitType s_stop;
	UART_ModeType s_mode;
}UART_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/* !!!!!!!!! You need to add 5 seconds delay to ensure that the module has been properly initialized !!!!!!!!!
 * Description :
 * Functional responsible for Initialize the UART device by:
 * 1. Setup the Frame format like number of data bits, parity bit type and number of stop bits.
 * 2. Enable the UART.
 * 3. Setup the UART baud rate.
 */
void UART_init(const UART_ConfigType *config);

/*
 * Description :
 * Functional responsible for send byte to another UART device.
 */
void UART_sendByte(const UART_ModuleNumber module,const uint8 data);

/*
 * Description :
 * Functional responsible for receive byte from another UART device.
 */
uint8 UART_recieveByte(UART_ModuleNumber module);

/*
 * Description :
 * Send the required string through UART to the other UART device.
 */
void UART_sendString(UART_ModuleNumber module, const uint8 *Str);

/*
 * Description :
 * Receive the required string until the '#' symbol through UART from the other UART device.
 */
void UART_receiveString(UART_ModuleNumber module, uint8 *Str);


void UART_sendInteger(UART_ModuleNumber module, uint32 value);

#endif /* UART_H_ */
