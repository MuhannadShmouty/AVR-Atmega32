/*
 * CLCD_interface.h
 *
 *  Created on: Aug 30, 2021
 *      Author: Muhannad Shmouty
 */

#ifndef HAL_01_CLCD_CLCD_INTERFACE_H_
#define HAL_01_CLCD_CLCD_INTERFACE_H_
// Rows
#define CLCD_u8_ROW_00 0
#define CLCD_u8_ROW_01 1

// Coloumns
#define CLCD_u8_COL_00 0
#define CLCD_u8_COL_01 1
#define CLCD_u8_COL_02 2
#define CLCD_u8_COL_03 3
#define CLCD_u8_COL_04 4
#define CLCD_u8_COL_05 5
#define CLCD_u8_COL_06 6
#define CLCD_u8_COL_07 7
#define CLCD_u8_COL_08 8
#define CLCD_u8_COL_09 9
#define CLCD_u8_COL_10 10
#define CLCD_u8_COL_11 11
#define CLCD_u8_COL_12 12
#define CLCD_u8_COL_13 13
#define CLCD_u8_COL_14 14
#define CLCD_u8_COL_15 15


void CLCD_voidInit(void);
void CLCD_voidSendData(u8 Copy_u8_Data);
void CLCD_voidSendCommand(u8 Copy_u8_Command);
void CLCD_voidSendString(s8 * Copy_u8_Ptr_String);
void CLCD_voidSendNumber(u64 Copy_u64Number);
void CLCD_voidSetCursor(u8 Copy_u8Row, u8 Copy_u8Coloumn);
void CLCD_voidSendExtraChar(void);
void CLCD_CLearLCD(void);


#endif /* HAL_01_CLCD_CLCD_INTERFACE_H_ */
