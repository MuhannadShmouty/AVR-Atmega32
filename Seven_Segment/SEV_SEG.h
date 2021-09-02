/*
 * SEV_SEG.h
 *
 *  Created on: Aug 28, 2021
 *      Author: Muhannad Shmouty
 */

#ifndef SEV_SEG_H_
#define SEV_SEG_H_

#define deg_0 1
#define deg_1 0

u8 digits[11] = {
//  a  b  c  d  e  f  g  .
  0b11111100,  // 0
  0b01100000,  // 1
  0b11011010,  // 2
  0b11110010,  // 3
  0b01100110,  // 4
  0b10110110,  // 5
  0b10111110,  // 6
  0b11100000,  // 7
  0b11111110,  // 8
  0b11110110,  // 9
  0b00000001   // .
};

#endif /* SEV_SEG_H_ */
