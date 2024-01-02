/*
    Author: Ahmed Wael Ibrahim 
    Type: Driver definitions
    Date: 24/12/2023
    Description: Configurable ADC driver that enables developer to initialize and define 
                all modules and channels and sample sequencers of the tm4c123 microcontroller
*/
#include "adc.h"
#include "tm4c123gh6pm.h"
#include "bitwise_operation.h"

void ADC_init(const ADC_Config * config_ptr){
    uint8 PortNumber, PinNumber, SampleSequencer;
    /*
        AIN0:  PE3
        AIN1:  PE2
        AIN2:  PE1
        AIN3:  PE0
        AIN4:  PD3
        AIN5:  PD2
        AIN6:  PD1
        AIN7:  PD0
        AIN8:  PE5
        AIN9:  PE4
        AIN10: PB4
        AIN11: PB5
    */
    // Choosing pin and port numbers for channel
    switch(config_ptr -> channel){
        case CHANNEL_0:
            PortNumber = PORTE_ID;
            PinNumber = PIN3_ID;
            break;
            
        case CHANNEL_1:
            PortNumber = PORTE_ID;
            PinNumber = PIN2_ID;
            break;
            
        case CHANNEL_2:
            PortNumber = PORTE_ID;
            PinNumber = PIN1_ID;
            break;
            
        case CHANNEL_3:
            PortNumber = PORTE_ID;
            PinNumber = PIN0_ID;
            break;
            
        case CHANNEL_4:
            PortNumber = PORTD_ID;
            PinNumber = PIN3_ID;
            break;
            
        case CHANNEL_5:
            PortNumber = PORTD_ID;
            PinNumber = PIN2_ID;
            break;
            
        case CHANNEL_6:
            PortNumber = PORTD_ID;
            PinNumber = PIN1_ID;
            break;
            
        case CHANNEL_7:
            PortNumber = PORTD_ID;
            PinNumber = PIN0_ID;
            break;
            
        case CHANNEL_8:
            PortNumber = PORTE_ID;
            PinNumber = PIN5_ID;
            break;
            
        case CHANNEL_9:
            PortNumber = PORTE_ID;
            PinNumber = PIN4_ID;
            break;
            
        case CHANNEL_10:
            PortNumber = PORTB_ID;
            PinNumber = PIN4_ID;
            break;
            
        case CHANNEL_11:
            PortNumber = PORTB_ID;
            PinNumber = PIN5_ID;
            break;
    }
    
    // Enable Clock to GPIO Port
    SET_BIT(SYSCTL_RCGCGPIO_R, PortNumber);

    // Configuring GPIO Pin for Analog Input
    switch(PortNumber){
        case PORTB_ID:
            SET_BIT(GPIO_PORTB_AFSEL_R, PinNumber);
            CLEAR_BIT(GPIO_PORTB_DEN_R, PinNumber);
            SET_BIT(GPIO_PORTB_AMSEL_R, PinNumber);
            break;

        case PORTD_ID:
            SET_BIT(GPIO_PORTD_AFSEL_R, PinNumber);
            CLEAR_BIT(GPIO_PORTD_DEN_R, PinNumber);
            SET_BIT(GPIO_PORTD_AMSEL_R, PinNumber);
            break;      

        case PORTE_ID:
            SET_BIT(GPIO_PORTE_AFSEL_R, PinNumber);
            CLEAR_BIT(GPIO_PORTE_DEN_R, PinNumber);
            SET_BIT(GPIO_PORTE_AMSEL_R, PinNumber);
            break;
    }

    /***** Configuring ADC *****/
    // ADC Clock Enable
    SET_BIT(SYSCTL_RCGCADC_R, config_ptr->number);
	SampleSequencer = config_ptr->ss;

    // Configuring ADC0 Registers
    if(config_ptr->number == ADC0){
        CLEAR_BIT(ADC0_ACTSS_R, SampleSequencer);
        ADC0_EMUX_R &= ~0xF000;
        switch(SampleSequencer){
            case 0:
                ADC0_SSMUX0_R = config_ptr->channel;
                ADC0_SSCTL0_R |= (1<<1) | (1<<2);
                break;
            case 1:
                ADC0_SSMUX1_R = config_ptr->channel;
                ADC0_SSCTL1_R |= (1<<1) | (1<<2);
                break;
            case 2:
                ADC0_SSMUX2_R = config_ptr->channel;
                ADC0_SSCTL2_R |= (1<<1) | (1<<2);
                break;
            case 3:
                ADC0_SSMUX3_R = config_ptr->channel;
                ADC0_SSCTL3_R |= (1<<1) | (1<<2);
                break;
        }
        SET_BIT(ADC0_ACTSS_R, SampleSequencer);
    }

    // Configuring ADC1 registers
    else{
        CLEAR_BIT(ADC1_ACTSS_R, SampleSequencer);
        ADC1_EMUX_R &= ~0xF000;
        switch(SampleSequencer){
            case 0:
                ADC1_SSMUX0_R = config_ptr->channel;
                ADC1_SSCTL0_R |= (1<<1) | (1<<2);
                break;   
            case 1:
                ADC1_SSMUX1_R = config_ptr->channel;
                ADC1_SSCTL1_R |= (1<<1) | (1<<2);
                break;
            case 2:
                ADC1_SSMUX2_R = config_ptr->channel;
                ADC1_SSCTL2_R |= (1<<1) | (1<<2);
                break; 
            case 3:
                ADC1_SSMUX3_R = config_ptr->channel;
                ADC1_SSCTL3_R |= (1<<1) | (1<<2);
                break;
        }
        SET_BIT(ADC1_ACTSS_R, SampleSequencer);
    }
}

uint16 ADC_readChannel(ADC_ModuleNumber adc, ADC_ChannelType channel, ADC_SampleSequencerType ss){
    if (adc==0){
        SET_BIT(ADC0_PSSI_R, ss);
        while((ADC0_RIS_R & 8) == 0);
        ADC0_ISC_R = 8;
        switch(ss){
            case 0:
                return ADC0_SSFIFO0_R;
            case 1:
                return ADC0_SSFIFO1_R;
            case 2:
                return ADC0_SSFIFO2_R;
            case 3:
                return ADC0_SSFIFO3_R;
        }
    }
    else{
        SET_BIT(ADC1_PSSI_R, ss);
        while((ADC1_RIS_R & 8) == 0);
        ADC1_ISC_R = 8;
        switch(ss){
            case 0:
                return ADC1_SSFIFO0_R;
            case 1:
                return ADC1_SSFIFO1_R;
            case 2:
                return ADC1_SSFIFO2_R;
            case 3:
                return ADC1_SSFIFO3_R;
        }   
    }
}