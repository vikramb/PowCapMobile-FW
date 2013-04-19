#include <avr/io.h>
#include "filters.h"


void filters_MasterInit(void) {
	//Set pin values for lines to muxes
	
	//sets current MUX to 60Hz Notch passthrough  (000)
	DDRF = (1<<PF4)|(1>>PF5)|(1<<PF6); 
	
	//sets voltage MUX to 60Hz notch passthrough (100)
	DDRF != (1<<PF7);	
	DDRE = (1<<PE6);
	DDRD = (1<<PD7);	

	//sets 60Hz Notch OFF for Voltage and Current lines
	DDRF = (1<<PF0)|(1<<PF1);
}
