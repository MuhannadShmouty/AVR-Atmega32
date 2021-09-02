/*
 * main.c
 *
 *  Created on: Aug 30, 2021
 *      Author: Muhannad Shmouty
 */

#include "../Services/BIT_MATH.h"
#include "../Services/STD_TYPES.h"

#include "../HAL/CLCD/CLCD_interface.h"


int main(void){
	// Initialize the LCD
	CLCD_voidInit();

	CLCD_voidSendString("9");
}
