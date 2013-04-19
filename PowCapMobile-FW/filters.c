#include <avr/io.h>
#include "filters.h"


void filters_MasterInit(void) {

	//Turn off JTAG by switching JTD pin high (twice within 4 cycles)
	//-this gives us access to i/o pins PF4, PF5, PF6, and PF7 on the atmega16u4
	MCUCR |= (1<<7);
	MCUCR |= (1<<7);
	
	
	//sets voltage and current BP MUX to passthrough/OFF (PSU line)	
	PORTF &= ~(1<<PF4);
	PORTF &= ~(1<<PF5);	
    //PORTF |= (1<<PF4);
	//PORTF |= (1<<PF5);	

	//sets voltage and current BP MUX to passthrough/OFF (alt line)	
	PORTF &= ~(1<<PF6);
	PORTF &= ~(1<<PF7);

	//sets 60Hz Notch OFF for Voltage and Current lines (PSU input)
	//PORTF |= ((1<<PF0)|(1<<PF1));	
	PORTF &= ~(1<<PF0);
	PORTF &= ~(1<<PF1);

	//sets 60Hz Notch OFF for V and I lines (alternate input)
	PORTE &= ~(1<<PE6);
	PORTD &= ~(1<<PD7);

/*
	//sets voltage MUX to 60Hz Notch passthrough  (001)
	PORTF &= ~(1<<PF4);	
	PORTF &= ~(1<<PF5);
	PORTF |= (1<<PF6);
	//sets current MUX to 60Hz notch passthrough (000)	
	PORTF &= ~(1<<PF7); 
	PORTE &= ~(1<<PE6);
	PORTD &= ~(1<<PD7);
*/

}
