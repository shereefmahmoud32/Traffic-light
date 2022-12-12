/*
 * test.c
 *
 * Created: 12/5/2022 1:34:01 AM
 *  Author: Shereef Mahmoud
 */ 



#include "../MCAL/DIO_Driver/DIO.h"
#include "../MCAL/Timer_Driver/Timers.h"
#include "../ServiceLayer/BIT_MATH.h"

void test_init()

{

	DIO_init(PIN_2, PORT_A, OUTPUT);
	TIMER0_0_initialization(NORMAL_MODE);


}

void test_start()
{
	
	while (1)
	{
		
		DIO_write(PIN_2,PORT_A,HIGH);
		TIMER0_delay(CLK_64,120,21);
		DIO_write(PIN_2,PORT_A,LOW);
		TIMER0_delay(CLK_64,120,21);
		
		
		
		
		
	}
}