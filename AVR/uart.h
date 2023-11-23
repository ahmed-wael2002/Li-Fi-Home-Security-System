 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.h
 *
 * Description: Header file for the UART AVR driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef UART_H_
#define UART_H_

#include "std_types.h"

/*******************************************************************************
 *                      Types Definition                                    *
 *******************************************************************************/

/* Type to define the parity mode */
typedef enum{
	DISABLED,
	EVEN_PARITY=2,
	ODD_PARITY
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
	BIT_9=3
}UART_ModeType;

typedef struct{
	uint32 s_baud_rate;
	UART_ParityType s_parity;
	UART_StopBitType s_stop;
	UART_ModeType s_mode;
}UART_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
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
void UART_sendByte(const uint8 data);

/*
 * Description :
 * Functional responsible for receive byte from another UART device.
 */
uint8 UART_recieveByte(void);

/*
 * Description :
 * Send the required string through UART to the other UART device.
 */
void UART_sendString(const uint8 *Str);

/*
 * Description :
 * Receive the required string until the '#' symbol through UART from the other UART device.
 */
void UART_receiveString(uint8 *Str); // Receive until #

#endif /* UART_H_ */
