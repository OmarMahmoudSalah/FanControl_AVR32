/*
 * pwm.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Omar
 */

#include "pwm.h"


void PWM_Timer0_Start(uint8 duty_cycle) {
	//Timer 0
	//REG Name  : TCCR0
	//FOC0 WGM00 COM01 COM00 WGM01 CS02 CS01 CS00

	// • Bit 7 – FOC0: Force Output Compare -0
	//• Bit 6, 3 – WGM01:0: Waveform Generation Mode
	// 1 1 Fast PWM

	//➢ Setup the PWM mode with Non-Inverting.
	//COM01 COM00
	//1 	0

	// CS02 CS01 CS00 Description
	//010 clkI/O/8 (From prescaler)
	TCNT0 = 0;
	OCR0 = duty_cycle;
	TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS01);
	// Setup the direction for OC0 as output pin through the GPIO driver
	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);

}
