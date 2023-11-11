/*
 * adc.h
 *
 *  Created on: Oct 6, 2023
 *      Author: Omar
 */
#include<avr/io.h>

#include "../../General/common_macros.h"
#include "../../General/std_types.h"
#ifndef ADC_H_

#define ADC_H_
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56 // it works but Not fully correct as required


typedef enum {
	AREF_Internal_OFF,AVCC,Internal_2_56=3,
}ADC_ReferenceVolatge;

typedef enum {
	DEFAULT,P2,P4,P8,P16,P32,P64,P128
}ADC_Prescaler;


typedef struct {
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
} ADC_ConfigType;



void ADC_init(const ADC_ConfigType * Config_Ptr);
uint16 ADC_readChannel(uint8 ch_num);

#endif /* ADC_H_ */
