/*
 * TIMERS.c
 *
 * Created: 8/4/2022 6:25:39 PM
 *  Author: Diefco
 */ 

#include "../DIO/DIO.h"
#include "avr/interrupt.h"
#include "avr/io.h"

/*---------------------------------------timer0--------------*/


void Timer0_initaialize_CTC_mode_interrupt(void){
	/*-----------[select ctc mode]--------------*/
	clr_bit(TCCR0,WGM00);
	set_bit(TCCR0,WGM01);
	
	/*-----------[set prescaler 1024>>101]--------------*/
	set_bit(TCCR0,CS00);
	clr_bit(TCCR0,CS01);
	set_bit(TCCR0,CS02);
	
	/*-----------[load value in compare reg OCR0]--------------*/
	OCR0=30;
	
	/*-----------[enable OCIEi0 nterrupt]--------------*/
	sei();
	set_bit(TIMSK,OCIE0);
	
}

void Timer0_wave_NON_PWM(void){
	/*-----------[set pin oc0 output]--------------*/
	DIO_set_bit_dir('b',3,1);
	/*-----------[select ctc mode]--------------*/
	clr_bit(TCCR0,WGM00);
	set_bit(TCCR0,WGM01);
	
	/*-----------[set prescaler 1024>>101]--------------*/
	set_bit(TCCR0,CS00);
	clr_bit(TCCR0,CS01);
	set_bit(TCCR0,CS02);
	
	/*-----------[load value in compare reg OCR0]--------------*/
	OCR0=234.375;
	/*-----------[select togle ]--------------*/
	set_bit(TCCR0,COM00);
	clr_bit(TCCR0,COM01);
}


void Timer0_wave_Fast_PWM(void){
	/*-----------[set pin oc0 output]--------------*/
	DIO_set_bit_dir('b',3,1);
	/*-----------[select Fast_PWM mode]--------------*/
	set_bit(TCCR0,WGM00);
	set_bit(TCCR0,WGM01);
	
	/*-----------[set prescaler 1024>>101]--------------*/
	set_bit(TCCR0,CS00);
	clr_bit(TCCR0,CS01);
	set_bit(TCCR0,CS02);
	
	/*-----------[load value in compare reg OCR0]--------------*/
	OCR0=64;
	/*-----------[select non inverting mode]--------------*/
	clr_bit(TCCR0,COM00);
	set_bit(TCCR0,COM01);
}

void Timer0_wave_Phase_Correct_PWM(void){
	/*-----------[set pin oc0 output]--------------*/
	DIO_set_bit_dir('b',3,1);
	/*-----------[select Phase_Correct_PWM mode]--------------*/
	set_bit(TCCR0,WGM00);
	clr_bit(TCCR0,WGM01);
	
	/*-----------[set prescaler 1024>>101]--------------*/
	set_bit(TCCR0,CS00);
	clr_bit(TCCR0,CS01);
	set_bit(TCCR0,CS02);
	
	/*-----------[load value in compare reg OCR0]--------------*/
	OCR0=64;
	/*-----------[select set clear! mode]--------------*/
	set_bit(TCCR0,COM00);
	set_bit(TCCR0,COM01);
}


/*---------------------------------------timer2--------------*/

void Timer2_initaialize_CTC_mode_interrupt(void){
	/*-----------[select ctc mode]--------------*/
	clr_bit(TCCR2,WGM20);
	set_bit(TCCR2,WGM20);
	
	/*-----------[set prescaler 1024>>101]--------------*/
	set_bit(TCCR2,CS20);
	set_bit(TCCR2,CS21);
	set_bit(TCCR2,CS22);
	
	/*-----------[load value in compare reg OCR0]--------------*/
	OCR2=7.8125;
	
	/*-----------[enable OCIEi0 nterrupt]--------------*/
	sei();
	set_bit(TIMSK,OCIE2);
	
}

void Timer2_initaialize_OVF_mode_interrupt(void){
	/*-----------[select ctc mode]--------------*/
	clr_bit(TCCR2,WGM20);
	clr_bit(TCCR2,WGM20);
	
	/*-----------[set prescaler 128>>101]--------------*/
	set_bit(TCCR2,CS20);
	clr_bit(TCCR2,CS21);
	set_bit(TCCR2,CS22);
	
	/*-----------[set as0 drystal 32768 hz]--------------*/
	set_bit(ASSR,AS2);
	
	/*-----------[enable OCIEi0 nterrupt]--------------*/
	sei();
	set_bit(TIMSK,TOIE2);
	
}


void Timer2_wave_NON_PWM(void){
	/*-----------[set pin oc0 output]--------------*/
	DIO_set_bit_dir('d',7,1);
	/*-----------[select ctc mode]--------------*/
	clr_bit(TCCR2,WGM20);
	set_bit(TCCR2,WGM21);
	
	/*-----------[set prescaler 1024>>101]--------------*/
	set_bit(TCCR2,CS20);
	set_bit(TCCR2,CS21);
	set_bit(TCCR2,CS22);
	
	/*-----------[load value in compare reg OCR0]--------------*/
	OCR2=234.375;
	/*-----------[select togle ]--------------*/
	set_bit(TCCR2,COM20);
	clr_bit(TCCR2,COM21);
}


void Timer2_wave_Fast_PWM(void){
	/*-----------[set pin oc0 output]--------------*/
	DIO_set_bit_dir('d',7,1);
	/*-----------[select Fast_PWM mode]--------------*/
	set_bit(TCCR2,WGM20);
	set_bit(TCCR2,WGM21);
	
	/*-----------[set prescaler 1024>>101]--------------*/
	set_bit(TCCR2,CS20);
	set_bit(TCCR2,CS21);
	set_bit(TCCR2,CS22);
	
	/*-----------[load value in compare reg OCR0]--------------*/
	OCR2=64;
	/*-----------[select non inverting mode]--------------*/
	set_bit(TCCR2,COM20);
	set_bit(TCCR2,COM21);
}

void Timer2_wave_Phase_Correct_PWM(void){
	/*-----------[set pin oc0 output]--------------*/
	DIO_set_bit_dir('d',7,1);
	/*-----------[select Phase_Correct_PWM mode]--------------*/
	set_bit(TCCR2,WGM20);
	clr_bit(TCCR2,WGM21);
	
	/*-----------[set prescaler 1024>>101]--------------*/
	set_bit(TCCR2,CS20);
	set_bit(TCCR2,CS21);
	set_bit(TCCR2,CS22);
	
	/*-----------[load value in compare reg OCR0]--------------*/
	OCR2=64;
	/*-----------[select set clear! mode]--------------*/
	set_bit(TCCR2,COM20);
	set_bit(TCCR2,COM21);
}

/*---------------------------------------timer1--------------*/

void Timer1_wave_fast_PWM(double value){
	
	DIO_set_bit_dir('d',5,1);
	//select fwst pwm mode 1110 -------------
	clr_bit(TCCR1A,WGM10);
	set_bit(TCCR1A,WGM11);
	set_bit(TCCR1B,WGM12);
	set_bit(TCCR1B,WGM13);
	//select clr on compare set on top 10-------------
	clr_bit(TCCR1A,COM1A0);
	set_bit(TCCR1A,COM1A1);
	// load value on ocr1a , icr1-------
	OCR1A=1000*(value);
	ICR1=19999;
	// set clock div/8 ---- 010
	clr_bit(TCCR1B,CS10);
	set_bit(TCCR1B,CS11);
	clr_bit(TCCR1B,CS12);
	
}
/*------------------------------------ICU-------------------
TCCR1A=0; //normal mode
TIFR=(1<<ICF1);
TCCR1B=0b11000010; //no prescaling and dedict rising edge
while((TIFR&(1<<ICF1))==0);
a=TCNT1;
TIFR=(1<<ICF1);
//----------------------
TCCR1B=0b10000010; //no prescaling and dedict faling edge
while((TIFR&(1<<ICF1))==0);
b=TCNT1;
TIFR=(1<<ICF1);
//----------------------
TCCR1B=0b11000010; //no prescaling and dedict rising edge
while((TIFR&(1<<ICF1))==0);
c=TCNT1;
TIFR=(1<<ICF1);

TCCR1B=0;
----------------------------------------------------------*/
