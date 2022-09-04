/*
 * I2C.c
 *
 * Created: 9/4/2022 4:34:00 PM
 *  Author: Diefco
 */ 

#include "avr/io.h"
#include "I2C.h"
#include "../DIO/std_macros.h"

#define F_CPU 8000000UL
#define prescaler 1

//------------------------------- master --------------------------------------------

void I2C_master_initialize(unsigned long scl_clock)
{
	TWBR=(unsigned char) (((F_CPU/scl_clock)-16) / (2*prescaler));
	if (prescaler==1)
	{
		TWSR=0;
	}
	else if (prescaler==4)
	{
		TWSR=1;
	}
	else if (prescaler==16)
	{
		TWSR=2;
	}
	else if (prescaler==64)
	{
		TWSR=3;
	}
}


void I2C_start(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	while(read_bit(TWCR,TWINT)==0); //wait to finish
	while((TWSR & 0xf8) != 0x08); //start condition transmitted
	
}

void I2C_write_adress(unsigned char adress_plus_read_or_write)
{
	TWDR=adress_plus_read_or_write;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(read_bit(TWCR,TWINT)==0);
	while((TWSR & 0xf8) != 0x18); //SLA+RW transmitted and ACH receaved
}

void I2C_write_data(unsigned char data)
{
	TWDR=data;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(read_bit(TWCR,TWINT)==0);
	while((TWSR & 0xf8) != 0x28); //SLA+RW transmitted and ACH receaved
}

void I2C_stop(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

// ---------------------------------- slave ------------------------------------------

void I2C_set_adress(unsigned char adress)
{
	TWAR=adress;
}

unsigned char I2C_slave_read(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(read_bit(TWCR,TWINT)==0);
	while((TWSR & 0xf8) != 0x60); //own SLA+RW received and ACH transmitted 
	
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(read_bit(TWCR,TWINT)==0);
	while((TWSR & 0xf8) != 0x80); //own data received and ACH transmitted
	return TWDR;
	
}
