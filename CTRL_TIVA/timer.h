#include "types.h"

#define TIMER_PORT_ID           1
#define TIMER_PIN_ID            6
#define TIMER_NUMBER            0
#define TIMER_CAPTURE_FLAG_PIN  2

typedef enum{
    TIMER0,
    TIMER1,
    TIMER2,
    TIMER3,
    TIMER4,
    TIMER5
}TIMER_SelectionType;

typedef enum{
    TIMERA,
    TIMERB,
    BOTH
}TIMER_Width;

void Timer0_init(void);
uint16 Timer0_getPulseDuration(void);