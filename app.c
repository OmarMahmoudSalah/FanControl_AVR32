/*
 * app.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Omar
 */

#include"HAL/DCMotor/dcmotor.h"
#include"HAL/LCD/lcd.h"
#include"HAL/LM35/lm35.h"
#include"MCAL/ADC/adc.h"
#include<util/delay.h>

int main() {
	LCD_init();
	DcMotor_Init();
	ADC_ConfigType ADCData = { Internal_2_56, P8 };
	ADC_init(&ADCData);
	LCD_displayStringRowColumn(0, 2, "Edges Diploma ");
	LCD_displayStringRowColumn(1, 2, "Eng.Omar Salah");
	_delay_ms(2000);
	LCD_clearScreen();
	LCD_displayStringRowColumn(0, 2, "FAN IS OFF     ");
	LCD_displayStringRowColumn(1, 2, "Temp=    C");

	while (1) {
		 uint8 temp = LM35_getTemperature();

		if (temp < 30) {
			DcMotor_Rotate(STOP, 0);
			LCD_displayStringRowColumn(0, 2, "FAN IS OFF     ");
			LCD_displayCharacter(' ');
			LCD_moveCursor(1, 8);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');

		}

		else if (temp >= 30 && temp < 60) {
			DcMotor_Rotate(CW, 25);
			LCD_displayStringRowColumn(0, 2, "FAN IS ON 25%");
			LCD_displayCharacter(' ');
			LCD_moveCursor(1, 8);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');

		}

		else if (temp >= 60 && temp < 90) {
			DcMotor_Rotate(CW, 50);
			LCD_displayStringRowColumn(0, 2, "FAN IS ON 50%");
			LCD_displayCharacter(' ');
			LCD_moveCursor(1, 8);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');

		}

		else if (temp >= 90 && temp < 120) {
			DcMotor_Rotate(CW, 75);
			LCD_displayStringRowColumn(0, 2, "FAN IS ON 75%");
			LCD_displayCharacter(' ');
			LCD_moveCursor(1, 8);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');

		} else if (temp >= 120) {
			DcMotor_Rotate(CW, 100);
			LCD_displayStringRowColumn(0, 2, "FAN IS ON 100%");
			LCD_displayCharacter(' ');
			LCD_moveCursor(1, 8);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');

		}

	}
}
