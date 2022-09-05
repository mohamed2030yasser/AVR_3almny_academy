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
#include "DHT11/DHT11.h"
#define dummy_data 0xff





int main(void)
{
	unsigned char int_temp=0 , fraction_temp=0 , int_h=0 , fraction_h=0 , sum =0;
	LCD_inatialize('a','b',0,'b',1);
	//DHT11_initialize('b',2);
	LCD_send_string("TEMP : ",'a','b',0,'b',1);
	LCD_move_cursor(2,1,'a','b',0,'b',1);
	LCD_send_string("HUM : ",'a','b',0,'b',1);
	
	_delay_ms(2000);
	
	
	while(1)
	{
		
		DHT11_send_start_signal('b',2);
		DHT11_receive_response_signal('b',2);
		int_h=DHT11_read_byte('b',2);
		fraction_h=DHT11_read_byte('b',2);
		int_temp=DHT11_read_byte('b',2);
		fraction_temp=DHT11_read_byte('b',2);
		sum=DHT11_read_byte('b',2);
		DHT11_stop('b',2);
		//--------------
		
		//------------------------------
		LCD_move_cursor(1,8,'a','b',0,'b',1);
		LCD_send_Snum(int_temp,'a','b',0,'b',1);
		LCD_send_char(',','a','b',0,'b',1);
		LCD_send_Snum(fraction_temp,'a','b',0,'b',1);
		//-----------------------------
		LCD_move_cursor(2,7,'a','b',0,'b',1);
		LCD_send_Snum(int_h,'a','b',0,'b',1);
		LCD_send_char(',','a','b',0,'b',1);
		LCD_send_Snum(fraction_h,'a','b',0,'b',1);
		
		_delay_ms(100);
		
	}
	
	
}

