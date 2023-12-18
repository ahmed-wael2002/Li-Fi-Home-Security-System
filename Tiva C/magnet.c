#include "DIO.h"
#include "magnet.h"
/*=================== Function Definitions ===================*/
void Magnet_INIT(void){
    DIO_Init(MAGNET_PORT_ID,MAGNET_PIN_ID,PIN_INPUT);
}
uint8 Magnet_Read(void){
    return DIO_readPin(MAGNET_PORT_ID, MAGNET_PIN_ID);
}
