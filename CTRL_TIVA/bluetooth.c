#include "bluetooth.h"
#include "uart.h"


/* Initializing Bluetooth Module */
void BLUETOOTH_init(void){
    UART_ConfigType uart_configs = {BLUETOOTH_UART_MODULE,9600,DISABLED,ONE_BIT,BIT_8};
    UART_init(&uart_configs); 
}

/* Transmitting Characters */
void BLUETOOTH_sendChar(const uint8 character){
    UART_sendByte(BLUETOOTH_UART_MODULE, character);
}

uint8 BLUETOOTH_receiveChar(void){
    return UART_recieveByte(BLUETOOTH_UART_MODULE);
}

/* Transmitting Strings */
void BLUETOOTH_sendString(const uint8* str){
    UART_sendString(BLUETOOTH_UART_MODULE, str);
}
void BLUETOOTH_receiveString(uint8* str){
    UART_receiveString(BLUETOOTH_UART_MODULE, str);
}