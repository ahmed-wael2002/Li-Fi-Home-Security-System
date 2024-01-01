#include "types.h"

#define ULTRASONIC_TRIGGER_PORT PORTA_ID
#define ULTRASONIC_TRIGGER_PIN  PIN4_ID

#define ULTRASONIC_ECHO_PORT    PORTB_ID
#define ULTRASONIC_ECHO_PIN     PIN6_ID

void ULTRASONIC_init(void);
void ULTRASONIC_trigger(void);
uint16 ULTRASONIC_getDistance(void);