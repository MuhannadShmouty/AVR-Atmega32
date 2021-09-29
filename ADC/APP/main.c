/*
 * main.c
 *
*  Created on: Sep 12, 2021
 *      Author: Muhannad Shmouty
 */


#include "../Services/STD_TYPES.h"
#include "../Services/BIT_MATH.h"
#include "../MCAL/01-DIO/DIO_interface.h"
#include "../HAL/01-CLCD/CLCD_interface.h"
#include "../MCAL/04-ADC/ADC_Inteface.h"



#include <util/delay.h>

int main(void){
	CLCD_voidInit();
	ADC_voidInit();

	DIO_voidSetPortDirection(DIO_u8_PORTC, DIO_u8_PORT_OUTPUT);
	DIO_voidSetPortValue(DIO_u8_PORTC, DIO_u8_LOW);

	while(1){
		CLCD_voidSetCursor(0, 0);
		u16 Result = ADC_u16GetChannelResult(0);
		f32 analogResult = (Result * 5.0)/ 1023.0;
		CLCD_voidSendNumber(analogResult);
		CLCD_voidSendString(".");
		CLCD_voidSendNumber(((int)(analogResult*10))%10);
		CLCD_voidSendString("  Volt");
	}
}



