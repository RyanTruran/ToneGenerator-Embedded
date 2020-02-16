// main.c
// Runs on LM4F120/TM4C123
// Test main for Lab 11
// January 15, 2016

// this connection occurs in the USB debugging cable
// U0Rx (PA0) connected to serial port on PC
// U0Tx (PA1) connected to serial port on PC
// Ground connected ground in the USB cable

#include "UART.h"
#include "TExaS.h"
#include "Sound.h"
#include "Piano.h"

int reset;
void EnableInterrupts(void);  // Enable interrupts
void delay(unsigned long msec);
unsigned long current;
// do not edit this main
// your job is to implement the UART_OutUDec UART_OutDistance functions 
int main(void){ unsigned long n;
  TExaS_Init();             // initialize grader, set system clock to 80 MHz
  UART_Init();							// initialize UART
	Piano_Init();
	Sound_Init();
  EnableInterrupts();       // needed for TExaS
	UART_OutString("Connected to Tone Generator\r\n");
	reset = 1;
  while(1){
    n = UART_InChar();
		switch(n){
			case 'C': 
				UART_OutString("Playing C Tone\r\n");
				Sound_Tone(2389);
				reset = 0;
				break;
			case 'B':
				UART_OutString("Playing B Tone\r\n");
				Sound_Tone(2531);
   			reset = 0;
				break;
			case 'A': 
				UART_OutString("Playing A Tone\r\n");
				Sound_Tone(2841);
				reset = 0;		
				break;
			case 'G': 
				UART_OutString("Playing G Tone\r\n");
				Sound_Tone(3189);
				reset = 0;
				break;
			case 'F': 
				UART_OutString("Playing F Tone\r\n");
				Sound_Tone(3579);
				reset = 0;
				break;
			case 'E': 
				UART_OutString("Playing E Tone\r\n");
				Sound_Tone(3792);
				reset = 0;
				break;
			case 'D':
				UART_OutString("Playing D Tone\r\n");
				Sound_Tone(4257);
				reset = 0;
				break;
			default:
				break;
		}
		reset++;
		delay(40);
		if (reset > 4){
			Sound_Off();
		}		
  }
}

void delay(unsigned long msec){ 
  unsigned long count;
  while(msec > 0 ) {  // repeat while there are still delay
    count = 16000;    // about 1ms
    while (count > 0) { 
      count--;
    } // This while loop takes approximately 3 cycles
    msec--;
  }
}
