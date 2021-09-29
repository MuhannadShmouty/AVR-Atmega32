/*
 * CLCD_program.c
 *
 *  Created on: Aug 30, 2021
 *      Author: Muhannad Shmouty
 */

#include "../../Services/STD_TYPES.h"
#include "../../Services/BIT_MATH.h"
#include "../../MCAL/01-DIO/DIO_interface.h"

#include <util/delay.h>
#include "../01-CLCD/CLCD_config.h"
#include "../01-CLCD/CLCD_interface.h"
#include "../01-CLCD/CLCD_private.h"

void CLCD_voidInit(void) {
	DIO_voidSetPortDirection(CLCD_DATA_PORT, DIO_u8_PORT_OUTPUT);
	DIO_voidSetPinDirection(CLCD_RS_PIN, DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(CLCD_EN_PIN, DIO_u8_OUTPUT);

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

void CLCD_voidSendData(u8 Copy_u8_Data) {
	DIO_voidSetPortValue(CLCD_DATA_PORT, Copy_u8_Data);
	DIO_voidSetPinValue(CLCD_RS_PIN, DIO_u8_HIGH);

	// Applying Falling Edge on EN pin
	DIO_voidSetPinValue(CLCD_EN_PIN, DIO_u8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(CLCD_EN_PIN, DIO_u8_LOW);
	_delay_ms(1);
}

void CLCD_voidSendCommand(u8 Copy_u8_Command) {
	DIO_voidSetPortValue(CLCD_DATA_PORT, Copy_u8_Command);
	DIO_voidSetPinValue(CLCD_RS_PIN, DIO_u8_LOW);

	// Applying Falling Edge on EN pin
	DIO_voidSetPinValue(CLCD_EN_PIN, DIO_u8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(CLCD_EN_PIN, DIO_u8_LOW);
	_delay_ms(1);

}

void CLCD_voidSendString(s8 *Copy_u8_Ptr_String) {
	u8 LOC_u8_Iterator = 0;
	while (Copy_u8_Ptr_String[LOC_u8_Iterator] != '\0') {
		CLCD_voidSendData(Copy_u8_Ptr_String[LOC_u8_Iterator]);
		LOC_u8_Iterator++;
	}
}

void CLCD_voidSendNumber(u64 Copy_u64Number) {
	u64 LOC_u64Reversed = 1;
	if (Copy_u64Number == 0)
	{
		CLCD_voidSendData('0');
	}
	else
	{
		while (Copy_u64Number != 0) {
			LOC_u64Reversed = (LOC_u64Reversed * 10) + (Copy_u64Number % 10);
			Copy_u64Number /= 10;
		}

		while (LOC_u64Reversed != 1) {
			CLCD_voidSendData((LOC_u64Reversed % 10) + '0');
			LOC_u64Reversed /= 10;
		}
	}
}

void CLCD_voidSetCursor(u8 Copy_u8Row, u8 Copy_u8Coloumn)
{
	if (Copy_u8Row == CLCD_u8_ROW_00)
	{
		CLCD_voidSendCommand(CLCD_u8DDRAM_OFFSET + Copy_u8Coloumn);
	}
	else
	{
		CLCD_voidSendCommand(CLCD_u8DDRAM_OFFSET + Copy_u8Coloumn + CLCD_u8DDRAM_ROW_SHIFT);
	}
}

void CLCD_voidSendExtraChar(void)
{
	CLCD_voidSendCommand(CLCD_u8_CGRAM_OFFSET);
	u8 LOC_u8Iterator;
	for (LOC_u8Iterator = 0; LOC_u8Iterator < (sizeof(LOC_u8StaticArray) / sizeof(LOC_u8StaticArray[0])); LOC_u8Iterator++)
	{
		CLCD_voidSendData(LOC_u8StaticArray[LOC_u8Iterator]);
	}

}

void CLCD_CLearLCD(void)
{
	CLCD_voidSendCommand(CLCD_u8_CLEAR_LCD_COMMAND);
}
