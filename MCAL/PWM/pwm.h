/*
 * pwm.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Omar
 */

#ifndef MCAL_PWM_PWM_H_
#define MCAL_PWM_PWM_H_

#include "../../General/std_types.h"
#include "../../MCAL/GPIO/gpio.h"
#include "avr/io.h"

void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* MCAL_PWM_PWM_H_ */
