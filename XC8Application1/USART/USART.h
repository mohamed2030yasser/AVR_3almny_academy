/*
 * USART.h
 *
 * Created: 8/21/2022 10:13:07 PM
 *  Author: Diefco
 */ 


#define F_CPU 8000000UL

void USART_intialize (unsigned long baud_rate);
void USART_send_data (unsigned char data);
unsigned char USART_read_data(void);
void USART_send_string(unsigned char *ptr);