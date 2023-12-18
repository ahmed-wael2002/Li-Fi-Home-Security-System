#include "DIO.h"
#include "smoke.h"
/*=================== Function Definitions ===================*/
void Smoke_INIT(void){
    DIO_Init(SMOKE_PORTID,SMOKE_PIN_ID,PIN_INPUT);
}

uint8 Smoke_READ(void){
     return DIO_readPin(SMOKE_PORTID,SMOKE_PIN_ID);
}