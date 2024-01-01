/*
 * protocol.h
 *
 *  Created on: Nov 2, 2023
 *      Author: Wael
 */

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

/*
 * This header file contains the Protocol commands
 * that govern the communication between the microcontrollers
 *
 */

/* ============================================== */
/*                 UART Commands                  */
/* ============================================== */

/* Smoke Sensor Commands */
#define FIRE_ALERT		'A'
#define DOOR_OPENED_ALERT	'B'
#define DOOR_CLOSED_ALERT	'C'
#define DISTANCE_ALERT		'D'


#endif /* PROTOCOL_H_ */
