/*#include "smoke.h"
#include "led.h"
#include "DIO.h"
#include "uart.h"

int main()
{
    UART_ConfigType uart_configs = {9600,DISABLED,ONE_BIT,BIT_8};
    UART_init(&uart_configs); 
    uint8 c;
    // Module Init
    Smoke_INIT();
    LED_init();
    while(1){
      LED_turnOff(WHITE);
      if (Smoke_READ() == SMOKE_ON)
        LED_turnOn(RED);
      else
        LED_turnOn(GREEN);
    }
}
*/