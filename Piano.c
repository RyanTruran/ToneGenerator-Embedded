// Piano.c
// Runs on LM4F120 or TM4C123, 
// edX lab 13 
// There are four keys in the piano
// Daniel Valvano
// December 29, 2014

// Port E bits 3-0 have 4 piano keys

#include "Piano.h"
#include "..//tm4c123gh6pm.h"

#define PE0  (*(volatile unsigned long *)0x40024004)
#define PE1  (*(volatile unsigned long *)0x40024008)
#define PE2  (*(volatile unsigned long *)0x40024010)
#define PE3  (*(volatile unsigned long *)0x40024020)
#define keys (*(volatile unsigned long *)0x4002403C)

// **************Piano_Init*********************
// Initialize piano key inputs
// Input: none
// Output: none
void Piano_Init(void){ 
	unsigned long volatile delay;
	//initialize Port E Pins
	SYSCTL_RCGC2_R |= 0x00000010; 		// Activate port E
	delay = SYSCTL_RCGC2_R;						// Delay
  GPIO_PORTE_AMSEL_R &= ~0x0F;      // No Analog
  GPIO_PORTE_PCTL_R &= ~0x0000FFFF; // Regular Function
	GPIO_PORTE_DIR_R &= ~0x0F;				// make PE0-3 in
  GPIO_PORTE_AFSEL_R &= ~0x0F;  		// disable alt funct on PE0-3
  GPIO_PORTE_DEN_R |= 0x0F;     		// enable digital I/O on PE0-3
	GPIO_PORTE_PDR_R |= 0x0F;     		// pull-down on PE0-3
}
// **************Piano_In*********************
// Input from piano key inputs
// Input: none 
// Output: 0 to 15 depending on keys
// 0x01 is key 0 pressed, 0x02 is key 1 pressed,
// 0x04 is key 2 pressed, 0x08 is key 3 pressed
unsigned long keyBit;
unsigned long Piano_In(void){
	keyBit=keys;
  return keyBit; // remove this, replace with input
}
