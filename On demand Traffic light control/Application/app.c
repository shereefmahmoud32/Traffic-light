/*
 * app.c
 *
 * Created: 12/3/2022 3:51:00 PM
 *  Author: Shereef Mahmoud
 */ 


#include "app.h"
#include "../ECUAL/BUTTON_DRIVER/BUTTON.h"
#include "../ECUAL/LED_DRIVER/LED.h"
#include "../ServiceLayer/BIT_MATH.h"


//counters initializations
uint8_t overflow_counter_1=0;
uint8_t overflow_counter_2=0;
uint8_t Counter_seconds=0;

//flags initializations
uint8_t Cars_Signals	 =0;
uint8_t Blinking_yellow_flag	 =0;
uint8_t button_flag	 =0;

void app_init()

{

	//led initialization
	DIO_init(Green_car_pin,port_of_car,OUTPUT);
	DIO_init(Yellow_car_pin,port_of_car,OUTPUT);
	DIO_init(Rd_car_pin,port_of_car,OUTPUT);
		
	DIO_init(Green_ped_pin,port_of_ped,OUTPUT);
	DIO_init(Yellow_ped_pin,port_of_ped,OUTPUT);
	DIO_init(Red_ped_pin,port_of_ped,OUTPUT);
	
	//button initialization
	DIO_init(Button_pin,port_of_button,INPUT);


	//INTERRUPTS	
void interrupt_init(void){
	

	
	
	// global enabling
	SET_BIT(SREG,GIE); 
	
	SET_BIT(MCUCSR,ISC00);
	//to differ btwn long and short press
	CLR_BIT(MCUCSR,ISC01);  
	
	SET_BIT(GICR,INT0); //INT0 enable	
}
interrupt_init();
	
		

//overflow interrupts for timer0 and 2
	SET_BIT(TIMSK,TOIE0);
	SET_BIT(TIMSK,TOIE2); 
	

//timers 
TIMER0_0_initialization(NORMAL_MODE);
TIMER_2_initialization(NORMAL_MODE);
TIMER_0_Start(CLK_128,TIMER_0_Initial_Value);


}



void app_start()
{
	
	while (1)
	{
		//to ensure normal loop green then yellow then red
		if (Cars_Signals>Car_yellow2_signal)
		{
			Cars_Signals=Car_green_signal;
		}
		else
		{
			switch (Cars_Signals)
			{
				case Car_green_signal:
				//first green ( car green led on rest is off)
				
				LED_on(Green_car_pin,port_of_car);
				LED_off(Yellow_car_pin,port_of_car);
				LED_off(Rd_car_pin,port_of_car);
				
				
				LED_off(Green_ped_pin,port_of_ped);
				LED_off(Yellow_ped_pin,port_of_ped);
				LED_on(Red_ped_pin,port_of_ped);
				Blinking_yellow_flag=0;
				
				break;
				
				case Car_yellow1_signal: 
				
				Blinking_yellow_flag=1;
				LED_off(Green_car_pin,port_of_car);
				LED_off(Rd_car_pin,port_of_car);
				
				LED_off(Green_ped_pin,port_of_ped);
				LED_off(Red_ped_pin,port_of_ped);
				break;
				
				case Car_Red_signal:

				LED_off(Green_car_pin,port_of_car);
				LED_off(Yellow_car_pin,port_of_car);
				LED_on(Rd_car_pin,port_of_car);
				
				LED_on(Green_ped_pin,port_of_ped);
				LED_off(Yellow_ped_pin,port_of_ped);
				LED_off(Red_ped_pin,port_of_ped);
				Blinking_yellow_flag=0;
				break;
				
				case Car_yellow2_signal:
				
				Blinking_yellow_flag=1;
				LED_off(Green_car_pin,port_of_car);
				LED_on(Rd_car_pin,port_of_car);
				
				LED_off(Green_ped_pin,port_of_ped);
				LED_off(Red_ped_pin,port_of_ped);	
				break;
				
				default:
				//error handling
				break;
				
			}
		}
		
		
		
	
	}
}


ISR(TIMER0_OVF)
{
	
	if (overflow_counter_1<TIMER0__Numofoverflows)
	
	{
		overflow_counter_1++;
	}

	
	else if (overflow_counter_1>= TIMER0__Numofoverflows)
	{
		Counter_seconds++;
		
		if (Blinking_yellow_flag==1)
		{
			LED_toggle(Yellow_car_pin,port_of_car);
			LED_toggle(Yellow_ped_pin,port_of_ped);
		}
		
		
		if (Counter_seconds == 5)
		{
			Cars_Signals++;
			Counter_seconds=0;
		}
		
		
		overflow_counter_1=0;	
	}
	 
}

//timer 2 overflow isr
 ISR(TIMER_2_OVF)
{
	overflow_counter_2++;
}


//interrupt to handel logical changes in rising edge and falling edge
 ISR(EXT_INT_0)
{
	//start button flag with 1
	button_flag++;

//first button will be pressed
	switch(button_flag)
	{	
		case pressed://rising edge
			TIMER2_start(CLK_128,TIMER_2_Initial_Value);
			break;	
	
	
		case released:
			//counter overflow check if more than 0.5 sec
			if (overflow_counter_2>TIMER2__Numofoverflows)
			{
				//null 
			}
			else 
				{
					if (Cars_Signals==Car_green_signal)
						{
							Cars_Signals++;
							//reset counter
							Counter_seconds=0;
							overflow_counter_1=0;
						}
					else
						{
							//error handeling
						}
		
				}
		
	   //stop timer 2
	   TIMER2_stop();
	   //flag and counter reset
	   overflow_counter_2=0;
	   button_flag=0;
	   break;

	}
}

