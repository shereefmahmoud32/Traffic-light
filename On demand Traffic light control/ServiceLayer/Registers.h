/*
 * Registers.h
 *
 * Created: 12/3/2022 4:57:17 PM
 *  Author: Shereef Mahmoud
 */ 
 

#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "TypeDefs.h"

// in this header file there will be all the micro controller registers



/************************************************************************/
/*	                      THE DIO REGISTERS                             */
/************************************************************************/


//PORTA  //8 bit output register
#define PORTA *((volatile uint8_t*)0x3B) 
#define DDRA  *((volatile uint8_t*)0x3A) 
#define PINA  *((volatile uint8_t*)0x39)


//PORTB //8 bit output register
#define PORTB *((volatile uint8_t*)0x38)
#define DDRB  *((volatile uint8_t*)0x37) 
#define PINB  *((volatile uint8_t*)0x36)

//PORTC //8 bit output register
#define PORTC *((volatile uint8_t*)0x35) 
#define DDRC  *((volatile uint8_t*)0x34) 
#define PINC  *((volatile uint8_t*)0x33) 

//PORTD //8 bit output register
#define PORTD *((volatile uint8_t*)0x32) 
#define DDRD  *((volatile uint8_t*)0x31) 
#define PIND  *((volatile uint8_t*)0x30) 


/************************************************************************/
/*							THE TIMER REGISTERS                         */
/************************************************************************/
//Timer/Counter Interrupt Flag 8 bit Register.
#define TIFR *((volatile uint8_t*)0x58)   


//timer 0 registers (8 bit register)

//prescaler setup
#define TCCR0 *((volatile uint8_t*)0x53) 
//used for tick 
#define TCNT0 *((volatile uint8_t*)0x52)

//timer 2 registers (8 bit register)

#define TCCR2 *((volatile uint8_t*)0x45) 
#define TCNT2 *((volatile uint8_t*)0x44)

//timer 1 registers (16 bit register )


//Timer/Counter1 Control Register A
#define TCCR1A  *((volatile uint8_t*)0x4F) 
#define TCCR1B  *((volatile uint8_t*)0x4E)
#define TCNT1H  *((volatile uint8_t*)0x4D)
#define TCNT1L  *((volatile uint8_t*)0x4C)


/************************************************************************/
/*						INTERUPTS REGISTERS                             */
/************************************************************************/


#define MCURC  *((volatile uint8_t*)0x55) 


#define MCUCSR *((volatile uint8_t*)0x54)


#define  GICR *((volatile uint8_t*)0x5B)


#define GIFR *((volatile uint8_t*)0x5A)



//SREG 

#define SREG *((volatile uint8_t*)0x5F)


//timsk The Timer/Counter Interrupt Mask Register - TIMSK. Bit. 7.
#define TIMSK *((volatile uint8_t*)0x59)


#endif /* REGISTERS_H_ */