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
#include "LED/LED.h"
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
#include "SPI/SPI.h"
#define dummy_data 0xff





int main(void)
{
	//------------TX-----------
	SPI_initialize_as_MASTER();
	KeyPad_intialize('a');
	LED_initialize('d',0);
	sei();
	unsigned char x=0;
	
	while(1)
	{
		if (KeyPad_read('a')!=0xff)
		{
			x=KeyPad_read('a');
			while(KeyPad_read('a')!=0xff);
			SPI_master_send_data(x);
		}
	}
	
	
	/*	//---------------RX--------
	unsigned char x;
	LCD_inatialize('a','b',0,'b',1);
	SPI_initialize_as_SLAVE();
	
	
	
	while(1)
	{
		x=SPI_slave_receive_data(dummy_data);
		LCD_send_char(x,'a','b',0,'b',1);
	
	}*/
	
	
}

ISR(SPI_STC_vect)
{
	_delay_ms(100);
	LED_tog('d',0);
}
