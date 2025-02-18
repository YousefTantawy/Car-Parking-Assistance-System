/*------------------------------------------------------------------------------
 *  Module      : LED Driver
 *  File        : led.h
 *  Description : Header file for the LED
 *  Author      : Yousef Tantawy
 *----------------------------------------------------------------------------*/

#ifndef LED_H_
#define LED_H_

#include "std_types.h"

/*------------------------------------------------------------------------------
 * 					 Pre-Processor Constants and Configurations
 *----------------------------------------------------------------------------*/

#define LED_PORT_ID						  PORTC_ID

#define LED_RED_PIN_ID					  PIN0_ID
#define LED_GREEN_PIN_ID				  PIN1_ID
#define LED_BLUE_PIN_ID					  PIN2_ID

/*------------------------------------------------------------------------------
 *  							Function Declarations
 *----------------------------------------------------------------------------*/

/* Description:
 * This function initializes the LED pins to become OUTPUT
 */

void LED_init(void);

/* Description:
 * This function activates a LED based on the given input
 */
void LED_on(uint8 pin_num);

/* Description:
 * This function deactivates a LED based on the given input
 */
void LED_off(uint8 pin_num);

#endif /* LED_H_ */
