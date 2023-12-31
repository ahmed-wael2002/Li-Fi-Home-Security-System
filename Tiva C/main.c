#include "types.h"
#include "uart.h"
#include "led.h"
#include "delay.h"

int main()
{
  UART_ConfigType uart_configs = {9600, DISABLED,ONE_BIT, BIT_8};
  UART_init(&uart_configs); 
  uint8 state = 0;
  uint8 data = 10;
  while(1) {
    if(state % 3 == 0) {
      UART_sendByte('S');
      _delay_ms(200);
      if(state % 2 == 0) {
        UART_sendByte('1');
        UART_sendByte('2');
        UART_sendByte('0');
      } else {
        UART_sendByte('2');
        UART_sendByte('5');
        UART_sendByte('7');
      }
    } else if (state % 3 == 1) {
      UART_sendByte('M');
      _delay_ms(200);
      if(state % 2 == 0) {
        UART_sendByte('9');
        UART_sendByte('7');
      } else {
        UART_sendByte('6');
        UART_sendByte('9');
        UART_sendByte('7');
      }
    } else {
      UART_sendByte('U');
      _delay_ms(200);
      if(state % 2 == 0) {
        UART_sendByte('1');
        UART_sendByte('0');
      } else {
        UART_sendByte('3');
        UART_sendByte('7');
      }
    }
    state += 1;
    state %= 6;
    _delay_ms(200);
  }
}