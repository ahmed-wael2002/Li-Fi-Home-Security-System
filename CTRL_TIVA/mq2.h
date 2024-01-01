#ifndef _MQ1_H
#define _MQ1_H

#include "types.h"

/***********-*--**-*********** Digital Configurations ********************/
#define MQ2_DO_PORT_ID  PORTD_ID
#define MQ2_DO_PIN_ID   PIN0_ID
#define ALERT           LOGIC_LOW
#define SAFE            LOGIC_HIGH

/******************** Analog Configurations ********************/
#define MQ2_ADC_CHANNEL             CHANNEL_0
#define MQ2_ADC_MODULE              ADC0
#define MQ2_ADC_SAMPLE_SEQUENCER    SS3

/* ============================================*/
/*             Function Prototypes             */
/* ============================================*/
void MQ2_init(void);

uint16 MQ2_readAnalogValue(void);

uint8 MQ2_readDigitalValue(void);



#endif-*-----**--+