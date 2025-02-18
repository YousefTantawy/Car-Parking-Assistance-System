/*------------------------------------------------------------------------------
 *  Module      : Application Driver
 *  File        : main.c
 *  Description : Source file for the main
 *  Author      : Yousef Tantawy
 *----------------------------------------------------------------------------*/

#include "led.h"
#include "lcd.h"
#include "gpio.h"
#include "buzzer.h"
#include "icu.h"
#include "avr/io.h"
#include "std_types.h"
#include "common_macros.h"
#include "util/delay.h"

int main(void)
{

	/*
	 * Variable to store the value from UltraSonic sensor
	 */
	uint16 distance;

	/*
	 * Activate the global register flag pain
	 */
	SREG = 1 << 7;

	/*
	 * Initialize all pins
	 */
	Ultrasonic_init();
	LCD_init();
	LED_init();
	BUZZER_init();

	/*
	 * Display Distance on the LCD
	 */
	LCD_displayString("Distance = ");
	LCD_moveCursor(0,14);
	LCD_displayString("cm");


	for(;;)
	{
		/*
		 * Update value on every iteration
		 */
		distance = Ultrasonic_readDistance();

		/*
		 * Activate and Deactivate peripherals based on given distance
		 */
		if(distance > 20)
		{
			LED_off(LED_RED_PIN_ID);
			LED_off(LED_GREEN_PIN_ID);
			LED_off(LED_BLUE_PIN_ID);
			BUZZER_off();
		}
		else if(distance <= 20 && distance >=16)
		{
			LED_on(LED_RED_PIN_ID);
			LED_off(LED_GREEN_PIN_ID);
			LED_off(LED_BLUE_PIN_ID);
			BUZZER_off();
		}
		else if(distance <= 15 && distance >=11)
		{
			LED_on(LED_RED_PIN_ID);
			LED_on(LED_GREEN_PIN_ID);
			LED_off(LED_BLUE_PIN_ID);
			BUZZER_off();
		}
		else if(distance <= 10 && distance >= 6)
		{
			LED_on(LED_RED_PIN_ID);
			LED_on(LED_GREEN_PIN_ID);
			LED_on(LED_BLUE_PIN_ID);
			BUZZER_off();
		}
		else
		{
			BUZZER_on();
			LED_on(LED_RED_PIN_ID);
			LED_on(LED_GREEN_PIN_ID);
			LED_on(LED_BLUE_PIN_ID);
			_delay_ms(200);
			BUZZER_off();
			LED_off(LED_RED_PIN_ID);
			LED_off(LED_GREEN_PIN_ID);
			LED_off(LED_BLUE_PIN_ID);
			_delay_ms(200);
		}



		/*
		 * Update value of distance on LCD
		 */
		LCD_moveCursor(0,11);
		LCD_intgerToString(distance);
		LCD_displayCharacter(' ');

		if(distance >= 6)
		{
			/*
			 * Remove the "Stop!!"
			*/
			LCD_moveCursor(1,3);
			LCD_displayString("            ");
		}

		else if (distance <= 5)
		{
			/*
			 * Add the "Stop!!" when too close
			 */
			LCD_moveCursor(1,3);
			LCD_displayString("Stop!!");
		}
	}
}

