/*
 * ApplicationCode.h
 *
 *  Created on: Dec 30, 2023
 *      Author: Xavion
 * 
 *  Modified on: Dec 3, 2025
 * 		Author: Alex
 */

#include "LCD_Driver.h"
#include "stm32f4xx_hal.h"
#include "GameDriver.h"

#include <stdio.h>


#ifndef INC_APPLICATIONCODE_H_
#define INC_APPLICATIONCODE_H_


void ApplicationInit(void);


// placeholder for gamedriver_init










void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);



void LCD_Visual_Demo(void);

#if (COMPILE_TOUCH_FUNCTIONS == 1) && (COMPILE_TOUCH_INTERRUPT_SUPPORT == 0)
void LCD_Touch_Polling_Demo(void);
#endif // (COMPILE_TOUCH_FUNCTIONS == 1) && (COMPILE_TOUCH_INTERRUPT_SUPPORT == 0)


#endif /* INC_APPLICATIONCODE_H_ */
