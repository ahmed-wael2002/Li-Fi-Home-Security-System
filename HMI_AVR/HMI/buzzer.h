/*
 * buzzer.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Wael
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "std_types.h"

/*******************************************************************************
 *                      Macro Definitions                                   *
 *******************************************************************************/
#define BUZZER_PORT_ID	PORTC_ID
#define BUZZER_PIN_ID	PIN5_ID

#define BUZZER_ON		LOGIC_HIGH
#define BUZZER_OFF		LOGIC_LOW

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initializing the buzzer io pins:
 */
void Buzzer_init(void);

/*
 * Description :
 * Function responsible for turning on the buzzer
 */
void Buzzer_on(void);

/*
 * Description :
 * Function responsible for turning off the buzzer
 */
void Buzzer_off(void);

#endif /* BUZZER_H_ */
