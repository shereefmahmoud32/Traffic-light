/*
 * DIO.h
 *
 * Created: 12/3/2022 3:51:00 PM
 *  Author: Shereef Mahmoud
 */ 

#ifndef DIO_H_
#define DIO_H_
#include "../../ServiceLayer/typedefs.h"
#include "../../ServiceLayer/Registers.h"

//all driver macros
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

// PIN Macros
#define PIN_0  0 
#define PIN_1  1
#define PIN_2  2


//direction defines
#define INPUT  0
#define OUTPUT 1

// value defines
#define LOW   0
#define HIGH  1


/************************************************************************/
/*                       ALL Driver Function Prototypes                 */
/************************************************************************/ 

//DIO PIN Direction Initialization 
void DIO_init (uint8_t Cr_pin_number, uint8_t Cr_Port_Number , uint8_t DDRiction );
//Write On DIO PIN
void DIO_write (uint8_t pinNumber ,uint8_t portNumber , uint8_t value );
//Toggle The DIO PIN 
void DIO_toggle (uint8_t pinNumber , uint8_t portNumber ); 
//Read The DIO PIN value 
void DIO_read (uint8_t pinNumber , uint8_t portNumber ,uint8_t *value);






#endif /* DIO_H_ */