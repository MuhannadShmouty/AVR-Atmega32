/*
 * main.c
 *
 *  Created on: Aug 30, 2021
 *      Author: Muhannad Shmouty
 */

#include "../Services/BIT_MATH.h"
#include "../Services/STD_TYPES.h"

#include "../HAL/CLCD/CLCD_interface.h"
#include <util/delay.h>


int main(void){
	// Initialize the LCD
	CLCD_voidInit();
	while (1){
		CLCD_voidSendExtraChar();
		CLCD_voidSetCursor(CLCD_u8_ROW_00, CLCD_u8_COL_12);
		CLCD_voidSendData(3);
		CLCD_voidSendData(2);
		CLCD_voidSendData(1);
		CLCD_voidSendData(0);
		_delay_ms(500);
		CLCD_CLearLCD();
	}
}
