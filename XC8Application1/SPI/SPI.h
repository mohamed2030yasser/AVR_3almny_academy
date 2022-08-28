/*
 * SPI.h
 *
 * Created: 8/28/2022 2:09:20 PM
 *  Author: Diefco
 */ 


//-----------------------------------------------------------------------------------------------

void SPI_initialize_as_MASTER(void);
void SPI_initialize_as_SLAVE(void);
unsigned char SPI_master_send_data(unsigned char data);
unsigned char SPI_slave_receive_data(unsigned char data);
void SPI_master_send_Strind(const char *ptr);

//-----------------------------------------------------------------------------------------------