/*
 * BUTTON.h
 *
 * Created: 11/18/2022 4:19:37 PM
 *  Author: Shereef Mahmoud
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO_DRIVER/DIO.h"
#include "../../MCAL/TIMER_DRIVER/Timers.h"
#include "../../MCAL/Interrupts/interrupts.h"


//button values
#define LOW  0
#define HIGH 1


//functions prototypes 

void BUTTON_init(uint8_t buttonPin , uint8_t buttonPort);

void BuTTON_read(uint8_t buttonPin ,uint8_t buttonPort ,uint8_t *value);


#endif /* BUTTON_H_ */