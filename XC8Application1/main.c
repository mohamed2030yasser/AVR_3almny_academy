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
#include "I2C/I2C.h"
#define dummy_data 0xff





int main(void)
{
	/*//------------TX-----------
	I2C_master_initialize(50000);
	KeyPad_intialize('a');
	LED_initialize('d',0);
	unsigned char x=0;
	
	while(1)
	{
		if (KeyPad_read('a')!=0xff)
		{
			x=KeyPad_read('a');
			while(KeyPad_read('a')!=0xff);
			I2C_start();
			I2C_write_adress(0b11111110);
			I2C_write_data(x);
			I2C_stop();
			
		}
	}*/
	
	
		//---------------RX--------
	unsigned char x;
	LCD_inatialize('a','b',0,'b',1);
	I2C_set_adress(0b11111110);
	
	
	while(1)
	{
		x=I2C_slave_read();
		LCD_send_char(x,'a','b',0,'b',1);
	
	}
	
	
}

