/*------------------------------------------------------------------------------
 *  Module      : Ultrasonic Driver
 *  File        : ultrasonic.c
 *  Description : Source file for the Ultrasonic
 *  Author      : Yousef Tantawy
 *----------------------------------------------------------------------------*/

#include "ultrasonic.h"
#include "icu.h"
#include "gpio.h"
#include "std_types.h"
#include "util/delay.h"

/*
 * timeHigh = Time that echo is active in
 * flag = Indicate end of echo
 * value = Take distance
 */
uint16 g_timeHigh = 0;
ICU_ConfigType ICU_Configurations = {F_CPU_8,RISING};
uint32 g_tick = 0;
boolean g_flag = 0;
uint16 value;

/*
 * Description:
 * Set up ICU, pass parameters using array
 * Set up Trigger to output
 * Send callback function
 */
void Ultrasonic_init(void)
{
	ICU_init(&ICU_Configurations);

	GPIO_setupPinDirection(ULTRASONIC_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, PIN_OUTPUT);

	ICU_setCallBack(Ultrasonic_edgeProcessing);
}

/*
 * Description:
 * Set trigger pin to 1 to activate ultrasonic sensor
 */
void Ultrasonic_Trigger(void)
{
	GPIO_writePin(ULTRASONIC_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(ULTRASONIC_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, LOGIC_LOW);
}

/*
 * Description:
 * Set trigger to 1 and wait till value recieved from ultrasonic sensor and retrieve value
 */
uint16 Ultrasonic_readDistance(void)
{
	Ultrasonic_Trigger();
	g_flag = 0;
	while(!g_flag);
	value = g_timeHigh/ 117.6;
	return value+1;
}

/*
 * Description:
 * Call back function for ICU
 */
void Ultrasonic_edgeProcessing(void)
{
	g_tick++;

	if(g_tick == 1)
	{
		/*
		 * Echo starts, measure until fall detected which means Echo is over
		 */
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(FALLING);
	}

	if(g_tick == 2)
	{
		/*
		 * Store value and reset ticks to 0 and edge to RISING
		 */
		g_timeHigh = ICU_getInputCaptureValue();
		g_flag = 1;
		g_tick = 0;
		ICU_setEdgeDetectionType(RISING);
	}
}
