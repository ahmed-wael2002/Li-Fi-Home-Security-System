/*===============================================*/
/*             Including Libraries               */
/*===============================================*/
/***** Supporting Libraries *****/
#include <stdio.h>
#include "protocol.h"
/***** Including MCAL *****/
#include "DIO.h"
#include "types.h"
#include "delay.h"
/***** Including HAL *****/
#include "magnet.h"
#include "mq2.h"
#include "bluetooth.h"
#include "ultrasonic.h"
#include "led.h"
#include "laser.h"

/*===============================================*/
/*             Function Prototypes               */
/*===============================================*/
void Magnet_code(void);

int main()
{
    /*========== System Inits ==========*/
    // Initializing Hall Effect (Magnetic Sensor)
    MAGNET_init();
    MAGNET_setCallBack(Magnet_code);
    // Initializing Ultrasonic Sensor
    ULTRASONIC_init();
    // Initialzing MQ2 (Smoke Sensor)  
    MQ2_init();
    // Initializing Bluetooth Module 
    BLUETOOTH_init();
    // Initializing LED 
    LED_init();
    // Initializing Laser Module for LIFI Transmission
    LASER_init();

    /*========== System Variables ==========*/
    uint16 smoke_reading = 0;
    uint16 ultra_reading = 0;
    char str[50];

    
    
    /*========== System Application ==========*/
    while(1){
      /* Green LED indicates system is safe */
      LED_turnOff(WHITE);
      LED_turnOn(GREEN);
      
      /* Processing Ultrasonic */
      // Sending Reading to application
      ultra_reading = ULTRASONIC_getDistance();
      sprintf(str, "U %d;", ultra_reading);
      BLUETOOTH_sendString(str);
      // Sending alerts to HMI
      if(ultra_reading<15){
        LASER_send(DISTANCE_ALERT);
      }
      _delay_ms(100);
      /* Processing Smoke */
      // Sending Reading to application
      smoke_reading = MQ2_readAnalogValue();
      sprintf(str, "S %d;", smoke_reading);
      BLUETOOTH_sendString(str);
      // Sending alerts to HMI
      if(smoke_reading>700){
        LASER_send(FIRE_ALERT);
      }
      _delay_ms(150);

    }
}


/*===============================================*/
/*             Function Definitions              */
/*===============================================*/
void Magnet_code(void){
  LED_turnOff(WHITE);
  LED_turnOn(RED);
  BLUETOOTH_sendString("D;");
  _delay_ms(100);
  LASER_send(DOOR_OPENED_ALERT);
}
