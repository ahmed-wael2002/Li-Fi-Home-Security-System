#include "types.h"

/*=================== Macros ===================*/
/*  Macros to define the logic state of led_on and led_off
    change in case of using negative logic
*/
#define LED_ON      LOGIC_HIGH
#define LED_OFF     LOGIC_LOW

/*  Macros to define the pins and ports of led 
    change in case of using rgb led with different pins 
    !! all pins must be in the same PORT
*/
#define LED_PORT        PORTF_ID
#define LED_RED_PIN     PIN1_ID
#define LED_BLUE_PIN    PIN2_ID
#define LED_GREEN_PIN   PIN3_ID

/*  Enumeration to define the color of the pin to be used
*/
typedef enum{
    RED,
    BLUE,
    GREEN,
    WHITE
}LED_Color;

/*=================== Function Prototypes ===================*/
/* Function Description:
    - Initializing the pins states and directions for LED pins defined in the macros
    - INPUT: None (Configure the macros @ the beginning in the start)
    - OUTPUT: LED pins initialized
*/
void LED_init();

/*=================== Function Prototypes ===================*/
/* Function Description:
    - Turn on an led pin given the color of the channel 
    - INPUT: color (RED=red channel, 
                    BLUE=blue channel, 
                    GREEN=green channel,
                    WHITE= red+green+blue channels)
    - OUTPUT: LED pin turned on 
*/
void LED_turnOn(LED_Color color);

/* Function Description:
    - Turn off an led pin given the color of the channel 
    - INPUT: color (RED=red channel, 
                    BLUE=blue channel, 
                    GREEN=green channel,
                    WHITE= red+green+blue channels)
    - OUTPUT: LED pin turned off
*/
void LED_turnOff(LED_Color color);

/* Function Description:
    - Turn off all LED pins
    - INPUT: None
    - OUTPUT: LED pins turned off
*/
void LED_turnOffAll();

/* Function Description:
    - Toggle the state of the led pin given the color of the channel 
    - INPUT: color (RED=red channel, 
                    BLUE=blue channel, 
                    GREEN=green channel,
                    WHITE= red+green+blue channels)
    - OUTPUT: LED pin toggled
*/
void LED_toggle(LED_Color color);

