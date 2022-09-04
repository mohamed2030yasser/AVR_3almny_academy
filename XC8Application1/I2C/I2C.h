/*
 * I2C.h
 *
 * Created: 9/4/2022 4:34:12 PM
 *  Author: Diefco
 */ 


void I2C_master_initialize(unsigned long scl_clock);
void I2C_start(void);
void I2C_write_adress(unsigned char adress_plus_read_or_write);
void I2C_write_data(unsigned char data);
void I2C_stop(void);
void I2C_set_adress(unsigned char adress);
unsigned char I2C_slave_read(void);