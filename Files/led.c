/*------------------------------------------------------------------------------
 *  Module      : LED Driver
 *  File        : led.c
 *  Description : Source file for the LED
 *  Author      : Yousef Tantawy
 *----------------------------------------------------------------------------*/

#include "common_macros.h"
#include "led.h"
#include "gpio.h"

/* Description:
 * This function initializes the LED pins to become OUTPUT
 */

void LED_init(void){
	GPIO_setupPinDirection(LED_PORT_ID, LED_RED_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LED_PORT_ID, LED_GREEN_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LED_PORT_ID, LED_BLUE_PIN_ID, PIN_OUTPUT);
}

/* Description:
 * This function activates a LED based on the given input
 */
void LED_on(uint8 pin_num){
	GPIO_writePin(LED_PORT_ID, pin_num, LOGIC_HIGH);
}

/* Description:
 * This function deactivates a LED based on the given input
 */
void LED_off(uint8 pin_num){
	GPIO_writePin(LED_PORT_ID, pin_num, LOGIC_LOW);
}


