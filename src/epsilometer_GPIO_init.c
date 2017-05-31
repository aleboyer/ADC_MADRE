/*
 * epsilometer_init_gpio.c
 *
 *  Created on: Jan 13, 2017
 *      Author: aleboyer
 */


#include "ep_GPIO_init.h"
#include "ep_analog.h"


/******************************************************************************
 * @name init_GPIO
 * @brief
 *   Switch on some GPIO
 * @details
 * Switch on the parts of MADRE, mainly the ADC
 *
 * @Author A. Le Boyer
 *****************************************************************************/

void init_GPIO(void) {
	GPIO_PinModeSet(gpioPortE, 13, gpioModePushPull, 1); // Enable Analog power
	GPIO_PinModeSet(gpioPortA, 2, gpioModePushPull, 1); // PA2 in output mode to send the MCLOCK  to ADC
	GPIO_PinModeSet(gpioPortB, 7, gpioModePushPull, 1);   // PB7 in output mode to send the SYNC away
	GPIO_PinModeSet(gpioPortC, 13, gpioModePushPull, 1); // and the ADA2200 amp or conductivity sensor

	// switch the ADC
	for (int i=0;i<8;i++){
    	AD7124_ChipSelect(sensors[i], LHI); // bring them all high
    }
}
