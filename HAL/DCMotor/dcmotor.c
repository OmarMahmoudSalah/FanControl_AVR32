/*
 * dcmotor.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Omar
 */

#include "dcmotor.h"
#include "../../General/std_types.h"

void DcMotor_Init(void) {
	GPIO_setupPinDirection(MOTOR_PORT, IN1, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_PORT, IN2, PIN_OUTPUT);
	GPIO_writePin(MOTOR_PORT, IN1, LOGIC_LOW);
	GPIO_writePin(MOTOR_PORT, IN2, LOGIC_LOW);

}

void DcMotor_Rotate(DcMotor_State state, uint8 speed) {
	///SPEED  0 -> 100
	//Duty Cycle 0-> 255

	PWM_Timer0_Start((uint8)(((uint16) MAX_PWM * speed) / (100)));

	switch (state) {
	default:
	case 0:
		GPIO_writePin(MOTOR_PORT, IN1, LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT, IN2, LOGIC_LOW);
		break;
	case 1:
		GPIO_writePin(MOTOR_PORT, IN1, LOGIC_HIGH);
		GPIO_writePin(MOTOR_PORT, IN2, LOGIC_LOW);
		break;

	case 2:
		GPIO_writePin(MOTOR_PORT, IN1, LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT, IN2, LOGIC_HIGH);
		break;
	}

}

