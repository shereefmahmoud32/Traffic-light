/*
 * Timers.c
 *
 * Created: 12/8/2022 9:53:14 PM
 *  Author: Shereef Mahmoud
 */ 

#include "Timers.h"
#include "../Interrupts/interrupts.h"
#include "../../ServiceLayer/BIT_MATH.h"
//timer 0 initialization

void TIMER0_0_initialization(uint8_t TimerMode)
{
	switch(TimerMode)

	{
		case NORMAL_MODE:
		TCCR0 =0x00;
		break;
		
		case PHASE_CORRECT_MODE:
		TCCR0=0x40;
		break;
		
		case CTC_MODE:
		TCCR0=0x08;
		break;
		
		case FAST_PWM_MODE:
		TCCR0=0x48;
		break;
		
		default:
		{
			//error handeling
		}
	}

}

//timer 0 start

void TIMER_0_Start(uint8_t Prescalerr , uint8_t Timer_Initial_Value)
{
	TCNT0 =Timer_Initial_Value;
	
	if(Prescalerr <= CLK_1024)
	{
		switch(Prescalerr)
		{
			case NO_PRESCALER:

				SET_BIT(TCCR0,CS00);
				CLR_BIT(TCCR0,CS01);
				CLR_BIT(TCCR0,CS02);
				break;
			
			case CLK_8:
				CLR_BIT(TCCR0,CS00);
				SET_BIT(TCCR0,CS01);
				CLR_BIT(TCCR0,CS02);
				break;
			
			case CLK_64:
				SET_BIT(TCCR0,CS00);
				SET_BIT(TCCR0,CS01);
				CLR_BIT(TCCR0,CS02);
				break;
			
			case CLK_128:
				CLR_BIT(TCCR0,CS00);
				CLR_BIT(TCCR0,CS01);
				SET_BIT(TCCR0,CS02);
				break;
			
			
			case CLK_1024:
				SET_BIT(TCCR0,CS00);
				CLR_BIT(TCCR0,CS01);
				SET_BIT(TCCR0,CS02);
				break;
			
			default:
			{
				//error handling
				break;
			}
		}	
	}
	
	
	
}

//timer stop
void TIMER0_stop (void){
		TCCR0 = 0x00;
}


//timer 0 delay
void TIMER0_delay (uint8_t Prescalerr , uint8_t Timer_Initial_Value ,uint8_t Timer_num_Of_OverFlows)
{
		// Reset The Over Flow Counter
uint32_t overFlowCounter   = 0;
		
		// Start TIMER 0
TIMER_0_Start(Prescalerr, Timer_Initial_Value);
		 
	
	while(overFlowCounter<Timer_num_Of_OverFlows)
	{
		while(GET_BIT(TIFR,TOV0)==0);
		
		CLR_BIT(TIFR,TOV0);
		
		overFlowCounter++;
	}
	
overFlowCounter=0;
TIMER0_stop();
}





//timer 2 initialization
void TIMER_2_initialization(uint8_t timerMode)
{
	switch(timerMode)

	{
		case NORMAL_MODE:
		TCCR2 =0x00;
		break;
		
		case PHASE_CORRECT_MODE:
		TCCR2=0x40;
		break;
		
		case CTC_MODE:
		TCCR2=0x08;
		break;
		
		case FAST_PWM_MODE:
		TCCR2=0x48;
		break;
		
		default:
		{
			//error handeling
		}
	}
}


//timer 2 start
void TIMER2_start(uint8_t Prescalerr , uint8_t Timer_Initial_Value)
{
	TCNT2 =Timer_Initial_Value;
	
	switch(Prescalerr)
	{
		case NO_PRESCALER:
							SET_BIT(TCCR2,CS20);
							CLR_BIT(TCCR2,CS21);
							CLR_BIT(TCCR2,CS22);
							break;
		
		case CLK_8:
							CLR_BIT(TCCR2,CS20);
							SET_BIT(TCCR2,CS21);
							CLR_BIT(TCCR2,CS22);
							break;
		
		case CLK_64:
							SET_BIT(TCCR2,CS20);
							SET_BIT(TCCR2,CS21);
							CLR_BIT(TCCR2,CS22);
							break;
		
		case CLK_128:
							CLR_BIT(TCCR2,CS20);
							CLR_BIT(TCCR2,CS21);
							SET_BIT(TCCR2,CS22);
							break;
		
		
		case CLK_1024:
							SET_BIT(TCCR2,CS20);
							CLR_BIT(TCCR2,CS21);
							SET_BIT(TCCR2,CS22);
							break;
		
		default:
		{
			//error handling
		}
	}
	
}


//timer stop
void TIMER2_stop (void)
{
		TCCR2 = 0x00;

}


//timer 2 delay
void TIMER2_delay (uint8_t Prescalerr , uint8_t Timer_Initial_Value ,uint8_t Timer_num_Of_OverFlows)
{
	uint32_t overFlowCounter = 0;
	
	// Start TIMER 2
	TIMER2_start(Prescalerr, Timer_Initial_Value);
	
	while(overFlowCounter<Timer_num_Of_OverFlows)
	{
		while(GET_BIT(TIFR,TOV2)==0);
		
		CLR_BIT(TIFR,TOV2);
		
		overFlowCounter++;
	}
	
	overFlowCounter=0;
	TIMER2_stop();
}