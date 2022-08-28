/*
 * SPI.c
 *
 * Created: 8/28/2022 2:09:05 PM
 *  Author: Diefco
 */ 


#include "avr/io.h"
#include "avr/interrupt.h"
#include "../DIO/std_macros.h"
#include "util/delay.h"
#define F_CPU 8000000UL

void SPI_initialize_as_MASTER(void)
{
	// set out put pin >>mosi pB5 , >>ss PB4 , >>sck PB7
	DIO_set_bit_dir('b',4,1);
	DIO_set_bit_dir('b',5,1);
	DIO_set_bit_dir('b',7,1);
	// Enable master 
	set_bit(SPCR,MSTR);
	//select prescaller fosc/16  01
	set_bit(SPCR,SPR0);
	// Enable SPI interrupt
	set_bit(SPCR,SPIE);
	// Enable SPI 
	set_bit(SPCR,SPE);
	//normal data order send MSB at first
	// normal clock polarity CPOL 0  >> leading rising , trailing faling
	// no clock phase shift CPHA
	//-----------------------------------
	// write ss high (slave active by low)
	DIO_write_bit('b',4,1);
}

void SPI_initialize_as_SLAVE(void)
{
	// Enable SPI
	set_bit(SPCR,SPE);
	// set output pin MISO>>PB6
	DIO_set_bit_dir('b',6,1);
}

unsigned char SPI_master_send_data(unsigned char data)
{
	// clr ss bin to sellect slave
	DIO_write_bit('b',4,0);
	// save data on SPDR
	SPDR=data;
	
	
	// wait until transmission finished
	while(read_bit(SPSR,SPIF)==0);
	
	// read spdr
	return SPDR;
	
}
unsigned char SPI_slave_receive_data(unsigned char data)
{
	// save data on SPDR
	SPDR=data;
	// wait until transmission finished
	while(read_bit(SPSR,SPIF)==0);
	// read spdr
	return SPDR;
}

void SPI_master_send_Strind(const char *ptr)
{
	
	while((*ptr) !=0)
	{
		SPI_master_send_data(*ptr);
		_delay_ms(300);
		ptr++;
	}
}
