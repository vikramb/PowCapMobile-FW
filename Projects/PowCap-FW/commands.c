#include "commands.h"
#include <stdlib.h>
#include "SPI.h"


void cb_gain1(char *param) {
    char *s;
    int16_t val;
    s = param;
    val = strtol(param,&s,16);
    for (int i=0;i<val;i++) {
        LEDs_ToggleLEDs(LEDS_LED1);
    }
    SELECT1();
    SPI_MaterTransmit(val);
    UNSELECT1();

}

void cb_gain2(char *param) {
    char *s;
    int16_t val;
    s = param;
    val = strtol(param,&s,16);
    for (int i=0;i<val;i++) {
        LEDs_ToggleLEDs(LEDS_LED1);
    }
    SELECT0();
    SPI_MaterTransmit(val);
    UNSELECT0();

}

void cb_filter2(char *param) {		//current filter MUX decision 
   	char *s;
	int16_t val;
	s = param;
	val = strtol(param,&s,16);

    	for (int i=0;i<val;i++) {
        LEDs_ToggleLEDs(LEDS_LED1);
	}    

	
	switch(val) {			//values follow following pin code: (A2 A1 A0)
		case 0:			//1k lowpass filter (010)
			PORTF = (1<<4)|(1<<6);
			PORTF != (1<<5);
			break;

		case 1:			//1K-100K Bandpass (001)
			PORTF = (1<<4)|(1<<5);
			PORTF != (1<<6);
			break;

		case 2:			//100K-250K Bandpass (110)
			PORTF != (1<<4)|(1<<5);
			PORTF = (1<<6);
			break;

		case 3:			//250K-500K Bandpass (011)
			PORTF = (1<<4);
			PORTF != (1<<5)|(1<<6);
			break;

		case 4:			//500-2M Bandpass (100)
			PORTF != (1<<4);
			PORTF = (1<<5)|(1<<6);
			break;

		case 5:			//1M Highpass filter (101)
			PORTF != (1<<4)|(1<<6);
			PORTF = (1<<5);
			break;

		case 6:			//60Hz Notch (throughput) (000)
			PORTF = (1<<4)|(1<<5)|(1<<6);
			break;

		case 7:			//Aux input (111)
			PORTF != (1<<4)|(1<<5)|(1<<6);
			break;
	}	

}

void cb_filter1(char *param) {		//voltage filter MUX decision
	char *s;
	int16_t val;
	s = param;
	val = strtol(param,&s,16);
	
	switch(val) {			//values follow following pin code: (A2 A1 A0)
		case 0:			//1k lowpass filter (101)
			PORTF != (1<<7);
			PORTE = (1<<6);
			PORTD != (1<<7);
			break;

		case 1:			//1K-100K Bandpass (110)
			PORTF != (1<<7);
			PORTE != (1<<6);
			PORTD = (1<<7);
			break;

		case 2:			//100K-250K Bandpass (011)
			PORTF = (1<<7);
			PORTE != (1<<6);
			PORTD != (1<<7);
			break;

		case 3:			//250K-500K Bandpass (010)
			PORTF = (1<<7);
			PORTE != (1<<6);
			PORTD = (1<<7);
			break;

		case 4:			//500-2M Bandpass (001)
			PORTF = (1<<7);
			PORTE = (1<<6);
			PORTD != (1<<7);
			break;

		case 5:			//1M Highpass filter (000)
			PORTF = (1<<7);
			PORTE = (1<<6);
			PORTD = (1<<7);
			break;

		case 6:			//60Hz Notch (throughput) (100)
			PORTF != (1<<7);
			PORTE = (1<<6);
			PORTD = (1<<7);
			break;

		case 7:			//Aux input (111)
			PORTF != (1<<7);
			PORTE != (1<<6);
			PORTD != (1<<7);
			break;
	}

}
	

void cb_notch1(char *param) {		//voltage 60hz notch filter MUX decision 
	char *s;
	int16_t val;
	s = param;
	val = strtol(param,&s,16);

	switch(val) {
	case 0:	
		PORTF = (1<<0);
		break;
	case 1:
		PORTF != (1<<0);
		break;
	}
}


void cb_notch2(char *param) {		//current 60hz notch filter MUX decision 
	char *s;
	int16_t val;
	s = param;
	val = strtol(param,&s,16);

	switch(val) {
	case 0:	
		PORTF = (1<<1);
		break;
	case 1:
		PORTF != (1<<1);
		break;
	}
}
