/*
 * DHT11.c
 *
 * Created: 9/5/2022 12:59:48 PM
 *  Author: Diefco
 */ 

#include "../DIO/DIO.h"
#include "util/delay.h"

void DHT11_initialize(unsigned char port,unsigned char pin)
{
	DIO_set_bit_dir(port,pin,1);
	//DIO_write_bit(port,pin,1);
}

void DHT11_send_start_signal(unsigned char port,unsigned char pin)
{
	DIO_set_bit_dir(port,pin,1);
	DIO_write_bit(port,pin,0);
	_delay_ms(20);
	DIO_write_bit(port,pin,1);
}

void DHT11_receive_response_signal(unsigned char port,unsigned char pin)
{
	DIO_set_bit_dir(port,pin,0);
	while(DIO_read_bit_u8(port,pin)==1);
	while(DIO_read_bit_u8(port,pin)==0);
	while(DIO_read_bit_u8(port,pin)==1);
}

unsigned char DHT11_read_byte(unsigned char port,unsigned char pin)
{
	unsigned char data=0;
	for (unsigned char i=0 ; i<8 ; i++)
	{
		while(DIO_read_bit_u8(port,pin)==0);
		_delay_us(77);
		//---------------------------------------
		if (DIO_read_bit_u8(port,pin)==1)
		{
			data=(data<<1)|(0x01);
		}
		else
		{
			data=(data<<1);
		}
		while(DIO_read_bit_u8(port,pin)==1);
	}
	return data;
}

void DHT11_stop(unsigned char port,unsigned char pin)
{
	DIO_set_bit_dir(port,pin,1);
	DIO_write_bit(port,pin,0);
}