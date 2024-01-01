#include "mq2.h"
#include "DIO.h"
#include "adc.h"

void MQ2_init(void){
    /* Configuring Digital Input Pin */
    DIO_Init(MQ2_DO_PORT_ID, MQ2_DO_PIN_ID, PIN_INPUT);

    /* Configuring Analog Input Pin*/
    ADC_Config configurations = {MQ2_ADC_MODULE, MQ2_ADC_CHANNEL, MQ2_ADC_SAMPLE_SEQUENCER};
    ADC_init(&configurations);
}

uint16 MQ2_readAnalogValue(void){
    uint16 data = ADC_readChannel(MQ2_ADC_MODULE, MQ2_ADC_CHANNEL, MQ2_ADC_SAMPLE_SEQUENCER);
    return data;
}

uint8 MQ2_readDigitalValue(void){
    return DIO_readPin(MQ2_DO_PORT_ID, MQ2_DO_PIN_ID);
}