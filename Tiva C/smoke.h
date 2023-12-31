#ifndef _SMOKE_H
#define _SMOKE_H
#include "types.h"

#define SMOKE_PORTID PORTD_ID
#define SMOKE_PIN_ID PIN0_ID
#define SMOKE_ON LOGIC_LOW
#define SMOKE_OFF LOGIC_HIGH

void Smoke_INIT(void);
uint8 Smoke_READ(void);
#endif