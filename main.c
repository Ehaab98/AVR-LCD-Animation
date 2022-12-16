/*
 * main.c
 *
 *  Created on: Sep 21, 2022
 *      Author: moham
 */


#include <avr/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include"LCD_Interface.h"
#include "LCD_Cfg.h"


int main (void)
{

	/*Initialize LCD*/
	LCD_VidLCDInit();
	LCD_VidSendCommand(0b00001100);


	u8 she[]= "She";
	u8 said[]= "Said";
	u8 yes[]= "Yes";

	u8 Man_Stand [8] = {(0b00001110),
			(0b00001010),
			(0b00001110),
			(0b00000101),
			(0b00011111),
			(0b00010100),
			(0b00001010),
			(0b00010001),

								};
	u8 Woman_Stand [8] = {(0b00001110),
				(0b00001010),
				(0b00001110),
				(0b00000100),
				(0b00011111),
				(0b00000100),
				(0b00001010),
				(0b00010001),

									};
	u8 Woman_Shy [8] = {(0b00001110),
			(0b00001010),
			(0b00001110),
			(0b00010101),
			(0b00011111),
			(0b00000100),
			(0b00001010),
			(0b00010001),

									};

	u8 Man_onKnee [8] = {(0b00001110),
									(0b00001010),
									(0b00001110),
									(0b00000100),
									(0b00011111),
									(0b00010100),
									(0b00000111),
									(0b00011101),
									};
	u8 Ring [8] = {(0b00010010),
			(0b00010111),
			(0b00010101),
			(0b00010101),
			(0b00011111),
			(0b00000000),
			(0b00000000),
			(0b00000000),
										};

	u8 heart [8] = {(0b00000000),
			(0b00001010),
			(0b00011111),
			(0b00011111),
			(0b00011111),
			(0b00001110),
			(0b00000100),
			(0b00000000),

										};

	while(1)
	{

		for(u32 i = 0; i<7; i++)
				{
					LCD_SendSpecialChar(Man_Stand, 0, 0, i);
					LCD_VidCursorPosition(0,i+1);
					LCD_SendSpecialChar(Woman_Stand, 1, 0, 10);
					_delay_ms(700);
					LCD_VidSendCommand(LCD_CLEAR);
				}
		LCD_SendSpecialChar(Man_onKnee, 0, 0, 7);
		LCD_SendSpecialChar(Ring, 2, 0, 8);
		LCD_VidCursorPosition(0,9);

		LCD_SendSpecialChar(Woman_Stand, 1, 0, 10);
		_delay_ms(2000);
		LCD_SendSpecialChar(Woman_Shy, 3, 0, 10);
		_delay_ms(2000);

		LCD_VidSendCommand(LCD_CLEAR);

		LCD_SendSpecialChar(Woman_Stand, 1, 0, 8);
		LCD_SendSpecialChar(Woman_Stand, 1, 0, 9);
		_delay_ms(2000);

		LCD_VidCursorPosition(1,2);
		 for (u8 i = 0; she[i] !='\0'; i++)
		  {
		    LCD_VidSendData(she[i]);
		    _delay_ms(300);
		  }
		 LCD_VidSendData(' ');
		 for (u8 i = 0; said[i] !='\0'; i++)
		  {
			 LCD_VidSendData(said[i]);
		 	 _delay_ms(300);
		   }
		 LCD_VidSendData(' ');
		 for (u8 i = 0; yes[i] !='\0'; i++)
		 {
		   LCD_VidSendData(yes[i]);
		   _delay_ms(300);
		   }
		 for(u32 i = 0; i<2; i++)
		 {
			LCD_SendSpecialChar(heart, 4, 1, i);
		 	LCD_SendSpecialChar(heart, 4, 1, i+14);
		 	_delay_ms(300);

		 }
		 for(u32 i = 0; i<2; i++)
			 {
			 LCD_VidCursorPosition(1,i);
			 LCD_VidSendData(' ');
			 LCD_VidCursorPosition(1,i+14);
			 LCD_VidSendData(' ');
			 }
		 _delay_ms(300);

		 for(u8 counter = 0; counter<10; counter++)
		 {
			 for(u32 i = 0; i<2; i++)
			 {
				 LCD_SendSpecialChar(heart, 4, 1, i);
				 LCD_SendSpecialChar(heart, 4, 1, i+14);


			 }
			 _delay_ms(300);
			 for(u32 i = 0; i<2; i++)
			 {
			 	LCD_VidCursorPosition(1,i);
			 	LCD_VidSendData(' ');
			 	LCD_VidCursorPosition(1,i+14);
			 	LCD_VidSendData(' ');


			 }
			 _delay_ms(300);
		 }
		LCD_VidSendCommand(LCD_CLEAR);
	}
}
