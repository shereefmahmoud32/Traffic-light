/*
 * LED.c
 *
 * Created: 11/17/2022 10:13:22 PM
 *  Author: Shereef Mahmoud
 */ 
#include "LED.h"
void LED_init (uint8_t LED_PIN ,uint8_t LED_PORT)
{
	DIO_init(LED_PIN,LED_PORT,OUTPUT);
}

//led on
void LED_on (uint8_t LED_PIN , uint8_t LED_PORT )
{
	DIO_write(LED_PIN,LED_PORT,HIGH);
	
}

//led off
void LED_off (uint8_t LED_PIN , uint8_t LED_PORT )
{
	DIO_write(LED_PIN,LED_PORT,LOW);
}

//led toggle
void LED_toggle (uint8_t LED_PIN , uint8_t LED_PORT )
{
	DIO_toggle(LED_PIN,LED_PORT);
}