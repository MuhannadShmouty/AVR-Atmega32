/*
 * CLCD_program.c
 *
 *  Created on: Aug 30, 2021
 *      Author: Muhannad Shmouty
 */

#include "../../Services/STD_TYPES.h"
#include "../../Services/BIT_MATH.h"
#include "../../MCAL/01-DIO/DIO_interface.h"

#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"
#include <util/delay.h>


void CLCD_voidInit(void)
{
	DIO_voidSetPortDirection(CLCD_DATA_PORT, DIO_u8_PORT_OUTPUT);
	DIO_voidSetPinDirection(CLCD_CONTROL_PORT, CLCD_RS_PIN, DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(CLCD_CONTROL_PORT, CLCD_EN_PIN, DIO_u8_OUTPUT);


	_delay_ms(50); // Wait for more than 30ms after Vdd rises to 4.5 Volt


	// Function Set
	CLCD_voidSendCommand(CLCD_u8_8_BIT_MODE);
	// Wait more than 39 microseconds
	_delay_ms(1);

	// Display ON/OFF Control
	CLCD_voidSendCommand(CLCD_u8_DISPLAY_CONTROL);
	// Wait more than 39 microseconds
	_delay_ms(1);

	// Display Clear
	CLCD_voidSendCommand(CLCD_u8_DISPLAY_CLEAR);
	// Wait for more than 1.53 ms
	_delay_ms(5);


	// Entry Mode Set
	CLCD_voidSendCommand(CLCD_u8_ENTRY_MODE);

}

void CLCD_voidSendData(u8 Copy_u8_Data)
{
	DIO_voidSetPortValue(CLCD_DATA_PORT, Copy_u8_Data);
	DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_RS_PIN, DIO_u8_HIGH);

	// Applying Falling Edge on EN pin
	DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_EN_PIN, DIO_u8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_EN_PIN, DIO_u8_LOW);
	_delay_ms(1);
}

void CLCD_voidSendCommand(u8 Copy_u8_Command)
{
	DIO_voidSetPortValue(CLCD_DATA_PORT, Copy_u8_Command);
	DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_RS_PIN, DIO_u8_LOW);

	// Applying Falling Edge on EN pin
	DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_EN_PIN, DIO_u8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_EN_PIN, DIO_u8_LOW);
	_delay_ms(1);

}

void CLCD_voidSendString(s8 * Copy_u8_Ptr_String){
	u8 LOC_u8_Iterator = 0;
	while (Copy_u8_Ptr_String[LOC_u8_Iterator] != '\0')
	{
		CLCD_voidSendData(Copy_u8_Ptr_String[LOC_u8_Iterator]);
		LOC_u8_Iterator++;
	}
}
