/*
 * lm35.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Omar
 */

#ifndef HAL_LM35_LM35_H_
#define HAL_LM35_LM35_H_


#include "../../General/std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SENSOR_CHANNEL_ID         2
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void);


#endif /* HAL_LM35_LM35_H_ */
