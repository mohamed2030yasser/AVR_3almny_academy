/*
 * file.c
 *
 * Created: 8/14/2022 9:11:02 AM
 *  Author: Diefco
 */ 
#include <util/delay.h>
#include "avr/io.h"

void ULTRA_SONIC_inatialize(unsigned char port,unsigned char trig_pin){
	DIO_set_bit_dir(port,trig_pin,1);
}

unsigned long ULTRA_SONIC_read(unsigned char port,unsigned char trig_pin){
	unsigned int a=0;
	unsigned int b=0;
	unsigned long puls_width=0;
	unsigned long distance=0;
	
	
	
	DIO_write_bit(port,trig_pin,1);
	_delay_us(50);
	DIO_write_bit(port,trig_pin,0);
	
	TCCR1A=0; //normal mode
	TIFR=(1<<ICF1);
	TCCR1B=0b11000001; //no prescaling and dedict rising edge
	while((TIFR&(1<<ICF1))==0);
	a=TCNT1;
	TIFR=(1<<ICF1);
	//----------------------
	TCCR1B=0b10000001; //no prescaling and dedict faling edge
	while((TIFR&(1<<ICF1))==0);
	b=TCNT1;
	TIFR=(1<<ICF1);
	//----------------------
	
	TCCR1B=0;
	
	//--------------------------------------
	puls_width=(b-a);
	distance=(17300*puls_width*(1.0/8000000));
	
	return distance;
	
}