/*
 * USART.c
 *
 * Created: 8/21/2022 10:12:53 PM
 *  Author: Diefco
 */ 

#include "USART.h"
#include "avr/io.h"
#include "../DIO/std_macros.h"
#include "util/delay.h"

void USART_intialize (unsigned long baud_rate)
{
	// set baud rate
	unsigned short UBRR;
	UBRR=(F_CPU/(16*baud_rate))-1;
	UBRRH=(unsigned char)(UBRR>>8);
	UBRRL=(unsigned char) UBRR;
	
	// enable tx , rx in UCSRB
	set_bit(UCSRB,TXEN);
	set_bit(UCSRB,RXEN);
	
	/*
	// select 8bit char_zize 011 UCSZ2:0
	set_bit(UCSRC,UCSZ0);
	set_bit(UCSRC,UCSZ1);
	clr_bit(UCSRB,UCSZ2);
	
	//select Asynchronous mode
	clr_bit(UCSRC,UMSEL);
	
	//disable parity mode 00
	clr_bit(UCSRC,UPM0);
	clr_bit(UCSRC,UPM1);
	*/
	
	UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);

}

void USART_send_data (unsigned char data)
{
	
	while(read_bit(UCSRA,UDRE)==0);
	UDR=data;
}

unsigned char USART_read_data(void)
{
	while(read_bit(UCSRA,RXC)==0);
	return UDR;
}

void USART_send_string(const char *ptr)
{
	while(*ptr !=0)
	{
		USART_send_data(*ptr);
		ptr++;
		_delay_ms(100);
	}
}