/*
 * CFile1.c
 *
 * Created: 8/19/2022 2:19:09 PM
 *  Author: Diefco
 */ 

#include "avr/io.h"

void Servo_motor_angle(double angle){
	Timer1_wave_fast_PWM(1.5+(.5/90)*angle);
}