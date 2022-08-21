/*
 * Ultra_Sonic.h
 *
 * Created: 8/14/2022 9:11:45 AM
 *  Author: Diefco
 */ 


void ULTRA_SONIC_inatialize(unsigned char port,unsigned char trig_pin);
unsigned long ULTRA_SONIC_read(unsigned char port,unsigned char trig_pin);