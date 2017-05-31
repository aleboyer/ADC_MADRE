/*
 * ep_menu.h
 *
 *  Created on: Apr 25, 2017
 *      Author: aleboyer
 */

#ifndef INC_EP_MENU_H_
#define INC_EP_MENU_H_

/*standard c library */
#include "stdint.h"
#include "stdio.h"

/*energy micro library */
#include "em_device.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "em_usart.h"
#include "em_chip.h"

/* local library */
#include "ep_common.h"
#include "ep_analog.h"
#include "ep_CMU_init.h"
#include "ep_GPIO_init.h"
#include "ep_TIMER_init.h"


void MADRE_Config(void);
enum States0 MADRE_resume_sampling(void);


#endif /* INC_EP_MENU_H_ */
