#include "timer.h"
#include "tm4c123gh6pm.h"
#include "bitwise_operation.h"

/*
    Function Description:
        1- Assign clock to the timer
        2- Init GPIO of timer
        3- Disable timer 0 - GPTM-CTL
        4- GPTM CFG
        5- Write 0x1 in TnMR 
*/
void Timer0_init(void){
   // Assign Clock to the timer
   SET_BIT(SYSCTL_RCGCTIMER_R, 0);

   /********* Initializing Timer GPIO pin *********/
   // Assign clock to Port B
   SET_BIT(SYSCTL_RCGCGPIO_R, TIMER_PORT_ID);
   // Set Timer pin as input
   CLEAR_BIT(GPIO_PORTB_DIR_R, TIMER_PIN_ID);
   // Set Timer pin as digital pin
   SET_BIT(GPIO_PORTB_DEN_R, TIMER_PIN_ID);
   // Set the pin to use alternate timer function
   SET_BIT(GPIO_PORTB_AFSEL_R, TIMER_PIN_ID);
   // Configuring PB6 for TOCCP0
   GPIO_PORTB_PCTL_R = (GPIO_PORTB_PCTL_R & ~0x0F00000) | (0x07000000);

   /********* Initializing Timer Registers *********/
   // Disable Timer0
   TIMER0_CTL_R &= ~(TIMER_CTL_TAEN);
   // Configure Timer0 to be Input Edge Time Mode
   TIMER0_CFG_R = 0x00000004;               // 16-bit timer mode
   TIMER0_TAMR_R =    (TIMER_TAMR_TACMR)    // Edge Time Mode
                    | (TIMER_TAMR_TACDIR)   // Count-up Direction
                    | (0x03);               // TAMR = BIT0 = 0x03 --- Capture Mode
   // Configure Timer to detect both edges 
   TIMER0_CTL_R |= (TIMER_CTL_TAEVENT_BOTH);

   // Enable Timer0-A 
   TIMER0_CTL_R |= (TIMER_CTL_TAEN);
}


uint16 Timer0_getPulseDuration(void){
    uint16 firstEdge, secondEdge;
    // Clear Timer0 Capture Flag
    while(1){
        TIMER0_ICR_R = 4;   
        // Wait till capture flag is set
        while((TIMER0_RIS_R & 4)==0);
        if (BIT_IS_SET(GPIO_PORTB_DATA_R, TIMER_PIN_ID)){
            // ===== Rising edge has been captured ====== //
            // Save the edge detection timestamp
            firstEdge = TIMER0_TAR_R;
            // Reset Capture flag to prepare for detecting the falling edge
            TIMER0_ICR_R = 4;
            // Wait till capture flag is set
            while((TIMER0_RIS_R & 4)==0);
            secondEdge = TIMER0_TAR_R;
            // Pulse Duration is the difference between edges timestamps
            return (secondEdge - firstEdge);
        }
    }
    


}