/*------------------------------------------------------------------------------
 *  Module      : Ultrasonic Driver
 *  File        : ultrasonic.h
 *  Description : Header file for the Ultrasonic
 *  Author      : Yousef Tantawy
 *----------------------------------------------------------------------------*/


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "std_types.h"

/*------------------------------------------------------------------------------
 * 					 Pre-Processor Constants and Configurations
 *----------------------------------------------------------------------------*/

extern uint32 g_tick;
extern uint16 g_timeHigh;
extern boolean g_flag;

#define ULTRASONIC_PORT_ID						PORTD_ID
#define ULTRASONIC_TRIGGER_PIN_ID				PIN7_ID
#define ULTRASONIC_ECHO_PIN_ID					PIN6_ID

/*------------------------------------------------------------------------------
 *  							Function Declarations
 *----------------------------------------------------------------------------*/

void Ultrasonic_init(void);

void Ultrasonic_Trigger(void);

uint16 Ultrasonic_readDistance(void);

void Ultrasonic_edgeProcessing(void);



#endif /* ULTRASONIC_H_ */
