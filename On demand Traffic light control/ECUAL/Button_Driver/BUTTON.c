/*
 * BUTTON.c
 *
 * Created: 11/18/2022 4:19:37 PM
 *  Author: Shereef Mahmoud
 */ 

#include "BUTTON.h"

void BUTTON_init(uint8_t buttonPin , uint8_t buttonPort)
{
	
	DIO_init(buttonPin,buttonPort,INPUT);
}

void BuTTON_read(uint8_t buttonPin ,uint8_t buttonPort ,uint8_t *value)
{
	DIO_read(buttonPin,buttonPort,value);
}
