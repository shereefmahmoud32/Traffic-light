/*
 * project v1.c
 *
 * Created: 12/3/2022 3:49:15 PM
 * Author : Shereef Mahmoud
 */

#include "Application/app.h"
#include "Test/test.h"


int main(void)
{
//	app_init();
	test_init();
	
	while (1) 
    {
//	app_start();
	test_start();	
    }
}

