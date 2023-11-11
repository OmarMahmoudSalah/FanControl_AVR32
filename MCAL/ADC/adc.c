/*
 * adc.c
 *
 *  Created on: Oct 6, 2023
 *      Author: Omar
 */

#include "adc.h"
void ADC_init(const ADC_ConfigType *Config_Ptr) {
	ADMUX = (ADMUX & 0XE0); // Channel 0 as initial value
	ADCSRA = (ADCSRA & 0XF8) | (Config_Ptr->prescaler); // Configuration of Prescaler
	ADMUX = (ADMUX) | ((Config_Ptr->ref_volt) << 6);
	CLEAR_BIT(ADCSRA, ADIE); // Bit 3 – ADIE: ADC Interrupt Enable
	SET_BIT(ADCSRA, ADEN); // Bit 7 – ADEN: ADC Enable
}

//REFS1 REFS0
//ADPS2 ADPS1 ADPS0

uint16 ADC_readChannel(uint8 ch_num) {
	uint16 data;
	ADMUX = (ADMUX & 0XE0) | ch_num;
	SET_BIT(ADCSRA, ADSC);
	while (BIT_IS_CLEAR(ADCSRA, ADIF))
		;
	SET_BIT(ADCSRA, ADIF);
	data = ADC;
	return data;
}
