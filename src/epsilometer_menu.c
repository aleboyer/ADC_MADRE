/*
 * epsilometer_menu.c
 *
 *  Created on: Apr 24, 2017
 *      Author: aleboyer
 */



#include "ep_menu.h"

/******************************************************************************
 * @name MADRE_Config
 * @brief
 *   Configure and switch on the needed part on MADRE
 * @details
 *   init the clock management
 *   init the GPIO port (switch the ADC)
 *   set up UART the communication port between the ADC and the MCU
 *   set up the GPIO interrupt controled by the ADC
 *   configure the ADC
 *
 * @Author A. Le Boyer
 *****************************************************************************/



void MADRE_Config(void) {
	/* Use 20 MHZ HFRCO as core clock frequency*/
    /* use of an interrupt on CMU to trigger the Oscillator when ready */
    init_CMU();
	// define GPIO pin mode for ADC and the 485, PA2 to send MCLOCK (for ADCs), and PE7 to send SYNC
    init_GPIO();

	init_SPI();     // Initialize the SPI interface for the Analog front end
	AD7124_Reset(); // Place devices into a known state
	setupGpioInt(); // Setup GPIO Interrupt but leave disabled
	define_ADC_configuration(); // set up and send the registers for the ADC

	// set variable
	byte_per_sample       = boardsetup_ptr->number_sensor*3+boardsetup_ptr->timestamp_flag*4;          // 3 bytes per channel * number of channel. (ADC resolution 24 bits = 3 bytes)
	buffer_size       = boardsetup_ptr->maximum_samples*byte_per_sample;                                //
	uint32_t coreclock_cycle   = boardsetup_ptr->core_clock/boardsetup_ptr->master_clock_frequency/2-1;    //
	uint32_t timer1_phase_shift = .5 * coreclock_cycle;

	// uint32 array where data are stored and from where data are sent to the serial port
    dataBuffer       = malloc(sizeof(uint8_t)*buffer_size);

    //set up timer MCLOCK and SYNC
	init_TIMER(coreclock_cycle,timer1_phase_shift);

}


/******************************************************************************
 * @name CMU_IRQHandler
 * @brief
 *   enable the HF external Xal
 * @details
 *   interrupt enabling an external Xtal. first select the cristal HFXO,
 *   then enable it.
 *   IT IS EXTREMELY IMPORTANT TO SET BY HAND THE FREQUENCY OF THE NEW XTAL IN
 *   CMSIS/EFM32WG/system_efm32wg.c #define EFM32_HFXO_FREQ (20000000UL).
 *   I did not look for a way to make it user friendly :(
 * @Author A. Le Boyer
 *****************************************************************************/



enum States0 MADRE_resume_sampling(void){

    // define foreground and background counter
	volatile uint32_t pending_samples = 0; 	 // samples from ADC

	// start conversion: send SYNC signal and enable the sampling interrupt
	//TODO change sensors[0] to sensors(master) where master is define in common.h. imply changes in epsilometer_analog.c
    AD7124_Start_conversion(sensors[0]);
	State = Sampling;
	return State;
}

