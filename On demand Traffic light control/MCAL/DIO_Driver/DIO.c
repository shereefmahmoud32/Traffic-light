/*
 * DIO.c
 *
 * Created: 12/3/2022 3:50:46 PM
 *  Author: Shereef Mahmoud
 */ 
#include "DIO.h"
#include "../../ServiceLayer/BIT_MATH.h"



/************************************************************************/
/*            //DIO PIN Direction Initialization                                                          */
/************************************************************************/
void DIO_init (uint8_t Cr_pin_number, uint8_t Cr_Port_Number , uint8_t DDRiction )
	
	{
	switch(Cr_Port_Number)
	{
	
		case PORT_A:
		if (DDRiction==OUTPUT)
		{
			SET_BIT(DDRA,Cr_pin_number);
		}
		else if (DDRiction==INPUT)
		{
			CLR_BIT(DDRA,Cr_pin_number);
		}
		
		else
		{
			//error handling
		}
		break;
		
		//******* PORT B  ********//
		case PORT_B:
		if(DDRiction==OUTPUT)
		{
			SET_BIT(DDRB,Cr_pin_number);
		}
		
		else if (DDRiction==INPUT)
		{
			CLR_BIT(DDRB,Cr_pin_number);
		}
		else
		{
			//error handling
		}
		break;
		
		//******* PORT c  ********//
		case PORT_C:
		if (DDRiction==OUTPUT)
		{
			SET_BIT(DDRC,Cr_pin_number);
		}
		else if (DDRiction==INPUT)
		{
			CLR_BIT(DDRC,Cr_pin_number);
		}
		else
		{
			//error handling
		}
		break;

		//******* PORT D  ********//
	
		case PORT_D:
		if (DDRiction==OUTPUT)
		{
			SET_BIT(DDRD,Cr_pin_number);	
		}
		
		else if (DDRiction==INPUT)
		{
			CLR_BIT(DDRD,Cr_pin_number);
		}
		
		else
		{
			//error handling
		}
	
	}
	
	
	
	
	
}


//Write On DIO PIN
void DIO_write (uint8_t Cr_pin_number ,uint8_t Cr_Port_Number , uint8_t value )

	{
	switch (Cr_Port_Number)
	{

		//******* PORT A  ********//

		case PORT_A:
		if (value==HIGH)
		{
			SET_BIT(PORTA,Cr_pin_number);
		}
		else if (value==LOW)
		{
			CLR_BIT(PORTA,Cr_pin_number);
		}
		
		else
		{
		//error handling	
		}
		break;
		
		//******* PORT B  ********//

		case PORT_B:
		if (value==HIGH)
		{
			SET_BIT(PORTB,Cr_pin_number);
		}
		else if (value==LOW)
		{
			CLR_BIT(PORTB,Cr_pin_number);
		}
		
		else
		{
			//error handling
		}
		break;
		
		
		//******* PORT C  ********//

		case PORT_C:
		if (value==HIGH)
		{
			SET_BIT(PORTC,Cr_pin_number);
		}
		else if (value==LOW)
		{
			CLR_BIT(PORTC,Cr_pin_number);
		}
		
		else
		{
			//error handling
		}
		break;
	
		//******* PORT D  ********//

		case PORT_D:
		if (value==HIGH)
		{
			SET_BIT(PORTD,Cr_pin_number);
		}
		else if (value==LOW)
		{
			CLR_BIT(PORTD,Cr_pin_number);
		}
		
		else
		{
			//error handling
		}
		break;	
	}
	
	
}


//Toggle The DIO PIN
void DIO_toggle (uint8_t Cr_pin_number , uint8_t Cr_Port_Number )
	
	{

		switch(Cr_Port_Number)
		{
			case PORT_A:
			TOGGLE_BIT(PORTA,Cr_pin_number);
			break;
			
			case PORT_B:
			TOGGLE_BIT(PORTB,Cr_pin_number);
			break;
			
			
			case PORT_C:
			TOGGLE_BIT(PORTC,Cr_pin_number);
			break;
			
			
			case PORT_D:
			TOGGLE_BIT(PORTD,Cr_pin_number);
			break;
			
			default:
			//error handling
			break;
			
			
			
		}
	
	}


//Read The DIO PIN value
void DIO_read (uint8_t Cr_pin_number , uint8_t Cr_Port_Number ,uint8_t *value)
	
	{
	switch(Cr_Port_Number)
	{
		case PORT_A:
		*value =GET_BIT(PINA,Cr_pin_number);
		break;
		
		case PORT_B:
		*value =GET_BIT(PINB,Cr_pin_number);
		break;
		
		case PORT_C:
		*value= GET_BIT(PINC,Cr_pin_number);
		break;
		
		case PORT_D:
		*value= GET_BIT(PIND,Cr_pin_number);
		break;
		
		default:
		//error handling
		break;
	}
}

