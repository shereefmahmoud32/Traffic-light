/*
 * app.h
 *
 * Created: 12/3/2022 3:51:00 PM
 *  Author: Shereef Mahmoud
 */


#ifndef APP_H_
#define APP_H_

#define port_of_car		PORT_A
#define port_of_ped		PORT_B
#define port_of_button  PORT_D


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

#define TIMER_0_Initial_Value 185
#define TIMER0__Numofoverflows 16

#define TIMER_2_Initial_Value 185
#define TIMER2__Numofoverflows 16

#define pressed 1
#define released 0


void interrupt_init(void);
void app_init(void);
void app_start(void);

#endif /* APP_H_ */