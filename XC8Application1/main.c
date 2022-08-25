/*
 * main.c
 *
 * Created: 6/30/2022 12:49:43 PM
 *  Author: Diefco
 */ 



#include <util/delay.h>
#include <avr/interrupt.h>

#define F_CPU 8000000UL
#include "BUTTON/BUTTON.h"
#include "DIO/DIO.h"
#include "LED/LED.h".
#include "DIO/std_macros.h"
#include "LCD/LCD.h"
#include "KeyPad/KeyPad.h"
#include "ADC/ADC.h"
#include "EEPROM/EEPROM.h"
#include "7_SEG/7_SEG.h"
#include "TIMERS/TIMERS.h"
#include "Ultra_Sonic/Ultra_Sonic.h"
#include "Motors/Motors.h"
#include "USART/USART.h"





int main(void)
{
	//------------TX-----------
	
	USART_intialize(9600);
	_delay_ms(300);
	USART_send_string("mohamed yasser");
	
	/* //---------------RX--------
	unsigned char x;
	LCD_inatialize('a','b',0,'b',1);
	USART_intialize(9600);
	while(1)
	{
		x=USART_read_data();
		LCD_send_char(x,'a','b',0,'b',1);
	
	}
	*/
	
}

