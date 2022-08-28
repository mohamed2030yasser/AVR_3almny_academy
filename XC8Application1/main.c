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





int main(void)
{
	//------------TX-----------
	unsigned char x=0;
	SPI_initialize_as_MASTER();
	//_delay_ms(300);
	while(x<10)
	{
		SPI_master_send_data(x);
		_delay_ms(300);
		x++;
	}
	
	
	/*	//---------------RX--------
	unsigned char x=0;
	unsigned char z=0;
	LCD_inatialize('a','b',0,'b',1);
	SPI_initialize_as_SLAVE();
	
	
	while(z<10)
	{
		x=SPI_slave_receive_data(x);
		LCD_send_char(x+48,'a','b',0,'b',1);
		z++;
	
	}*/
	
	
}

