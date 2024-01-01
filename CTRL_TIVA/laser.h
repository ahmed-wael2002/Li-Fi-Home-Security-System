#include "types.h"

#define LASER_TX_UART   UART_4

// Function to initialize Laser and UART module
void LASER_init(void);

// Function to send data using laser transmitter to be captured by laser receiver TX
void LASER_send(uint8 number);