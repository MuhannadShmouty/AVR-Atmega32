/*
 * CLCD_interface.h
 *
 *  Created on: Aug 30, 2021
 *      Author: Muhannad Shmouty
 */

#ifndef HAL_CLCD_CLCD_INTERFACE_H_
#define HAL_CLCD_CLCD_INTERFACE_H_

void CLCD_voidInit(void);
void CLCD_voidSendData(u8 Copy_u8_Data);
void CLCD_voidSendCommand(u8 Copy_u8_Command);
void CLCD_voidSendString(s8 * Copy_u8_Ptr_String);


#endif /* HAL_CLCD_CLCD_INTERFACE_H_ */
