#include "laser.h"
#include "uart.h"
#include "bitwise_operation.h"




// Supporting function to fix the bits
static int get_first_set_bit_position(uint8 var) {
    if (var == 0) {
        return -1; // Return -1 if no bits are set.
    }

    int position = 0;
    for (position = 7; position >= 0; position--) {
        if ((var & (1 << position)) != 0) {
            return position; // Return the position of the first set bit.
        }
    }

    return 0; // This line should never be reached.
}


void LASER_send(uint8 number){
    uint8 position = 8 - (get_first_set_bit_position(number)+1);
    number  = number << position;
    if (position != 0)
        SET_BIT(number , position-1);
    number  = ~number +1; 
    UART_sendByte(LASER_TX_UART, number);
}

void LASER_init(void){
    UART_ConfigType uart_configs = {LASER_TX_UART,9600,DISABLED,ONE_BIT,BIT_8};
    UART_init(&uart_configs); 
}