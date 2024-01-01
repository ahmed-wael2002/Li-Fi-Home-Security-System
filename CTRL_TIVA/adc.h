#ifndef  _ADC_H
#define _ADC_H

#include "types.h"
#include "tm4c123gh6pm.h"

#define PORTA_ID    0
#define PORTB_ID    1
#define PORTC_ID    2
#define PORTD_ID    3
#define PORTE_ID    4
#define PORTF_ID    5

#define PIN0_ID     0
#define PIN1_ID     1
#define PIN2_ID     2
#define PIN3_ID     3
#define PIN4_ID     4
#define PIN5_ID     5
#define PIN6_ID     6
#define PIN7_ID     7 


/*********************************
 *       TYPES DECLARATION
 *********************************/
typedef enum{
    ADC0,
    ADC1
}ADC_ModuleNumber;

typedef enum{
    CHANNEL_0,
    CHANNEL_1,
    CHANNEL_2,
    CHANNEL_3,
    CHANNEL_4,
    CHANNEL_5,
    CHANNEL_6,
    CHANNEL_7,
    CHANNEL_8,
    CHANNEL_9,
    CHANNEL_10,
    CHANNEL_11,
}ADC_ChannelType;

typedef enum{
    SS0,
    SS1,
    SS2,
    SS3,
}ADC_SampleSequencerType;

typedef struct{
    ADC_ModuleNumber number;
    ADC_ChannelType channel;
    ADC_SampleSequencerType ss;
}ADC_Config;

/*********************************
 *        GLOBAL VARIABLE
 *********************************/
/** ONLY used in INTERRUPT_MODE **/
extern volatile uint16 ADC_data;

/*********************************
 *       FUNCTION PROTOTYPES
 *********************************/
void ADC_init(const ADC_Config * config_ptr);
uint16 ADC_readChannel(ADC_ModuleNumber adc, ADC_ChannelType channel, ADC_SampleSequencerType ss);


#endif