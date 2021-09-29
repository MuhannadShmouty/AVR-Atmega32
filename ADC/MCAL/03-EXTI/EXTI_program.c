/*
 * EXTI_program.c
 *
 *  Created on: Sep 12, 2021
 *      Author: Muhannad Shmouty
 */



#include "../../Services/BIT_MATH.h"
#include "../../Services/STD_TYPES.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"



void EXTI_voidInit(void) {

	/*INTERRUPT LINE 0*/
#ifdef EXTI_LINE_0_EN
	/*INTERRUPT LINE 0 - FALLING EDGE*/

#if EXTI_LINE_0_CONFIG == EXTI_u8_FALLING_EDGE
	set_bit(MCUCR , ISC01);
	clear_bit(MCUCR , ISC00);
#endif
	// INTERRUPT LINE 0 - RISING EDGE

#if EXTI_LINE_0_CONFIG == EXTI_u8_RISING_EDGE
	set_bit(MCUCR , ISC01);
	set_bit(MCUCR , ISC00);
#endif

	// INTERRUPT LINE 0 - ON CHANGE

#if EXTI_LINE_0_CONFIG == EXTI_u8_ON_CHANGE
	clear_bit(MCUCR , ISC01);
	set_bit(MCUCR , ISC00);
#endif

	// INTERRUPT LINE 0 - LOW LEVEL

#if EXTI_LINE_0_CONFIG == EXTI_u8_LOW_LEVEL
	clear_bit(MCUCR , ISC01);
	clear_bit(MCUCR , ISC00);
#endif

	// SET PIE OF INTERRUPT LINE 0
	set_bit(GICR,INT0);

#endif

	/*INTERRUPT LINE 1*/

#ifdef EXTI_LINE_1_EN
	// INTERRUPT LINE 1 - FALLING EDGE

#if EXTI_LINE_1_CONFIG == EXTI_u8_FALLING_EDGE
	set_bit(MCUCR, ISC11);
	clear_bit(MCUCR, ISC10);
#endif
	// INTERRUPT LINE 1 - RISING EDGE

#if EXTI_LINE_1_CONFIG == EXTI_u8_RISING_EDGE
	set_bit(MCUCR , ISC11);
	set_bit(MCUCR , ISC10);
#endif

	// INTERRUPT LINE 1 - ON CHANGE

#if EXTI_LINE_1_CONFIG == EXTI_u8_ON_CHANGE
	clear_bit(MCUCR , ISC11);
	set_bit(MCUCR , ISC10);
#endif

	// INTERRUPT LINE 1 - LOW LEVEL

#if EXTI_LINE_1_CONFIG == EXTI_u8_LOW_LEVEL
	clear_bit(MCUCR , ISC11);
	clear_bit(MCUCR , ISC10);
#endif

	// SET PIE OF INTERRUPT LINE 1
	set_bit(GICR,INT1);

#endif

	/*INTERRUPT LINE 2*/
#ifdef EXTI_LINE_2_EN
	// INTERRUPT LINE 2 - FALLING EDGE

#if EXTI_LINE_0_CONFIG == EXTI_u8_FALLING_EDGE
	clear_bit(MCUCSR , ISC2);

#endif
	// INTERRUPT LINE 2 - RISING EDGE

#if EXTI_LINE_0_CONFIG == EXTI_u8_RISING_EDGE
	set_bit(MCUCSR , ISC2);
#endif

	// SET PIE OF INTERRUPT LINE 2
	set_bit(GICR,INT2);
#endif
}

void EXTI_voidEnable(u8 Copy_u8Line , u8 Copy_u8SenseMode){
	/* Enable Internal Interrupt */
	switch(Copy_u8Line)
	{
		case EXTI_u8_LINE0:
			// check which mode to enable
			switch(Copy_u8SenseMode)
			{
				case EXTI_u8_FALLING_EDGE:
					clear_bit(MCUCR, ISC00);
					set_bit(MCUCR, ISC01);
					break;
				case EXTI_u8_RISING_EDGE:
					set_bit(MCUCR, ISC00);
					set_bit(MCUCR, ISC01);
					break;
				case EXTI_u8_LOW_LEVEL:
					clear_bit(MCUCR, ISC00);
					clear_bit(MCUCR, ISC01);
					break;
				case EXTI_u8_ON_CHANGE:
					set_bit(MCUCR, ISC00);
					clear_bit(MCUCR, ISC01);
					break;
			}

			// SET PIE OF INTERRUPT LINE 0
			set_bit(GICR,INT0);

			break;

		case EXTI_u8_LINE1:
			// check which mode to enable
			switch(Copy_u8SenseMode)
			{
				case EXTI_u8_FALLING_EDGE:
					clear_bit(MCUCR, ISC10);
					set_bit(MCUCR, ISC11);
					break;
				case EXTI_u8_RISING_EDGE:
					set_bit(MCUCR, ISC10);
					set_bit(MCUCR, ISC11);
					break;
				case EXTI_u8_LOW_LEVEL:
					clear_bit(MCUCR, ISC10);
					clear_bit(MCUCR, ISC11);
					break;
				case EXTI_u8_ON_CHANGE:
					set_bit(MCUCR, ISC10);
					clear_bit(MCUCR, ISC11);
					break;
			}

			// SET PIE OF INTERRUPT LINE 1
			set_bit(GICR,INT1);

			break;

		case EXTI_u8_LINE2:
			// check which mode to enable (INT2 supports 2 Modes only)
			switch (Copy_u8SenseMode)
			{
				case EXTI_u8_FALLING_EDGE:
					clear_bit(MCUCSR, ISC2);
					break;
				case EXTI_u8_RISING_EDGE:
					clear_bit(MCUCSR, ISC2);
					break;
			}

			// SET PIE OF INTERRUPT LINE 2
			set_bit(GICR, INT2);
			break;

	}

}


void EXTI_voidDisable(u8 Copy_u8Line)
{
	// Clear the PIE bit of the corresponding interrupt line
	switch (Copy_u8Line) {
		case EXTI_u8_LINE0:
			clear_bit(GICR, INT0);
			break;
		case EXTI_u8_LINE1:
			clear_bit(GICR, INT1);
			break;
		case EXTI_u8_LINE2:
			clear_bit(GICR, INT2);
			break;
		}
}


void EXTI_voidClearFlag(u8 Copy_u8Line)
{
	// The flag can be cleared by writing a logical one to it
	switch (Copy_u8Line) {
		case EXTI_u8_LINE0:
			set_bit(GIFR, INT0);
			break;
		case EXTI_u8_LINE1:
			set_bit(GIFR, INT1);
			break;
		case EXTI_u8_LINE2:
			set_bit(GIFR, INT2);
			break;
		}
}

void EXTI_voidCallBack(void (*Copy_pvoidCallBack)(void), u8 Copy_u8Line) {
	if (Copy_pvoidCallBack != NULL) {
		EXTI_CallBack[Copy_u8Line] = Copy_pvoidCallBack;
	}
}

/*INTERRUPT LINE 0 ISR*/

void __vector_1(void) {
	if (EXTI_CallBack[EXTI_u8_LINE0] != NULL) {
		EXTI_CallBack[EXTI_u8_LINE0]();
	}
	/*CLEAR THE FLAG*/
}

/*INTERRUPT LINE 1 ISR*/

void __vector_2(void) {
	if (EXTI_CallBack[EXTI_u8_LINE1]) {
		EXTI_CallBack[EXTI_u8_LINE1]();

	}

}

/*INTERRUPT LINE 2 ISR*/

void __vector_3(void) {
	if (EXTI_CallBack[EXTI_u8_LINE2]) {
		EXTI_CallBack[EXTI_u8_LINE2]();
	}
}
