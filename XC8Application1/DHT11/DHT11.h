/*
 * DHT11.h
 *
 * Created: 9/5/2022 1:00:01 PM
 *  Author: Diefco
 */ 

void DHT11_initialize(unsigned char port,unsigned char pin);
void DHT11_send_start_signal(unsigned char port,unsigned char pin);
void DHT11_receive_response_signal(unsigned char port,unsigned char pin);
unsigned char DHT11_read_byte(unsigned char port,unsigned char pin);
void DHT11_stop(unsigned char port,unsigned char pin);