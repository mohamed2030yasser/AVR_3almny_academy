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





int main(void)
{
	LCD_inatialize('a','b',0,'b',1);
	LCD_send_string("angle : ",'a','b',0,'b',1);
	while(1)
	{
		
		Servo_motor_angle(30);
		LCD_move_cursor(1,8,'a','b',0,'b',1);
		LCD_send_Snum(30,'a','b',0,'b',1);
		_delay_ms(5000);
		Servo_motor_angle(-30);
		LCD_move_cursor(1,8,'a','b',0,'b',1);
		LCD_send_string("-",'a','b',0,'b',1);
		LCD_send_Snum(30,'a','b',0,'b',1);
		_delay_ms(5000);
		//LCD_send_cmd(cmd_clr_lcd,'a','b',0,'b',1);
		//LCD_send_string("angle : ",'a','b',0,'b',1);
		Servo_motor_angle(50);
		LCD_move_cursor(1,8,'a','b',0,'b',1);
		LCD_send_Snum(50 ,'a','b',0,'b',1);
		_delay_ms(5000);
		
		
		
	}
	
}

