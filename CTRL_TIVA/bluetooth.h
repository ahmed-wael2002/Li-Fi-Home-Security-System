#ifndef _BLUETOOTH_H
#define _BLUETOOTH_H

#include "types.h"

#define BLUETOOTH_UART_MODULE   UART_5

/* Initializing Bluetooth Module */
void BLUETOOTH_init(void);

/* Transmitting Characters */
void BLUETOOTH_sendChar(const uint8 character);
uint8 BLUETOOTH_receiveChar(void);

/* Transmitting Strings */
void BLUETOOTH_sendString(const uint8* str);
void BLUETOOTH_receiveString(uint8* str);

#endif