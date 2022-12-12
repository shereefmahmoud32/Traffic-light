/*
 * LED.h
 *
 * Created: 11/17/2022 10:13:33 PM
 *  Author: Shereef Mahmoud
 */ 
#include "../../MCAL/DIO_DRIVER/DIO.h"


#ifndef LED_H_
#define LED_H_
//led initialization 
void LED_init (uint8_t LED_PIN ,uint8_t LED_PORT);

//led on 
void LED_on (uint8_t ledPin , uint8_t LED_PORT );

//led off
void LED_off (uint8_t ledPin , uint8_t LED_PORT );

//led toggle
void LED_toggle (uint8_t ledPin , uint8_t LED_PORT );

#endif /* LED_H_ */