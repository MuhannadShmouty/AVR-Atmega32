/*
 * EXTI_config.h
 *
 *  Created on: Sep 12, 2021
 *      Author: Muhannad Shmouty
 */

#ifndef MCAL_03_EXTI_EXTI_CONFIG_H_
#define MCAL_03_EXTI_EXTI_CONFIG_H_



/*
 * OPTIONS:
 * 		Comment unneeded lines
 */

#define EXTI_LINE_0_EN
#define EXTI_LINE_1_EN
#define EXTI_LINE_2_EN



/*
 * EXTI_LINE_0_CONFIG --> OPTIONS
 *
 * 	EXTI_u8_FALLING_EDGE
	EXTI_u8_RISING_EDGE
	EXTI_u8_LOW_LEVEL
	EXTI_u8_ON_CHANGE
 */
#define EXTI_LINE_0_CONFIG	EXTI_u8_FALLING_EDGE

#define EXTI_LINE_1_CONFIG	EXTI_u8_FALLING_EDGE

#define EXTI_LINE_2_CONFIG	EXTI_u8_FALLING_EDGE

#endif /* MCAL_03_EXTI_EXTI_CONFIG_H_ */
