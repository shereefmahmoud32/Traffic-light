/*
 * test.h
 *
 * Created: 12/5/2022 1:39:26 AM
 *  Author: Shereef Mahmoud
 */ 


#ifndef TEST_H_
#define TEST_H_



#define port_of_car	PORT_A
#define port_of_ped	PORT_B
#define port_of_button PORT_D


#define Green_car_pin PIN_0 
#define Yellow_car_pin PIN_1
#define Rd_car_pin PIN_2

#define Green_ped_pin PIN_0
#define Yellow_ped_pin PIN_1
#define Red_ped_pin PIN_2

#define Button_pin PIN_2

#define Car_green_signal  0
#define Car_yellow1_signal 1
#define Car_Red_signal  2
#define Car_yellow2_signal 3

/* T tick = Prescaler / FCPU
		 * FCPU = 1 000 000
		 t=1 micro
		 tmax  delay
		 * One Overflow 256 microsecond      ( PRESCALER 1)
		 * One Overflow  2 048 microsecond    ( PRESCALER 8 )
		 * One Overflow 16 384 microsecond   ( PRESCALER 64 ) 
		 * One Overflow  65 536 microsecond   ( PRESCALER 256 )
		 * One Overflow 262 144 microsecond  ( PRESCALER 1024 )
		 */
		
		/*
		using 256 prescaler 
		 1 000 000 / 65536 = 16 FULL Overflows  
		 * 1 000 000 % 65536 = 16960
		 * 65536 - 16960 = 48576
		 * 48576 / 256 = 185 (Initial Value )
		 */

#define TIMER_0_Initial_Value 185
#define TIMER0__Numofoverflows 16

#define TIMER_2_Initial_Value 185
#define TIMER2__Numofoverflows 16

#define pressed 1
#define released 0



void test_init(void);
void test_start(void);


#endif /* TEST_H_ */