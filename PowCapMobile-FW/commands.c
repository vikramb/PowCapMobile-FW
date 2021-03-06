#include "commands.h"
#include <stdlib.h>
#include "SPI.h"


void cb_gainC1(char *param) {		//current1 gain
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

void cb_gainV1(char *param) {		//voltage1 gain
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

void cb_gainC2(char *param) {		//current2 gain
    char *s;
    int16_t val;
    s = param;
    val = strtol(param,&s,16);
    for (int i=0;i<val;i++) {
        LEDs_ToggleLEDs(LEDS_LED1);
    }
    SELECT3();
    SPI_MaterTransmit(val);
    UNSELECT3();

}

void cb_gainV2(char *param) {		//voltage2 gain
    char *s;
    int16_t val;
    s = param;
    val = strtol(param,&s,16);
    for (int i=0;i<val;i++) {
        LEDs_ToggleLEDs(LEDS_LED1);
    }
    SELECT2();
    SPI_MaterTransmit(val);
    UNSELECT2();

}

void cb_filterV1(char *param) {		//voltage BP filter MUX decision "n" 
	char *s;
	int16_t val;
	s = param;
	val = strtol(param,&s,16);
	
	switch(val) {
	case 0:				//BP ON	
		PORTF |=(1<<4);
		LEDs_TurnOnLEDs(LEDS_LED1);
		break;
	case 1:				//BP OFF 
		PORTF &=~(1<<4);
		LEDs_TurnOffLEDs(LEDS_LED1);
		break;
	}
}

void cb_filterC1(char *param) {		//current1 BP filter MUX decision "n" 
	char *s;
	int16_t val;
	s = param;
	val = strtol(param,&s,16);
	
	switch(val) {
	case 0:					//BP OFF
		PORTF |=(1<<5);
		LEDs_TurnOnLEDs(LEDS_LED1);
		break;
	case 1:					//BP ON
		PORTF &=~(1<<5);
		LEDs_TurnOffLEDs(LEDS_LED1);	
		break;
	}
}

void cb_filterV2(char *param) {		//voltage BP filter MUX decision "n" 
	char *s;
	int16_t val;
	s = param;
	val = strtol(param,&s,16);
	
	switch(val) {
	case 0:					//BP ON
		PORTF |=(1<<6);
		LEDs_TurnOnLEDs(LEDS_LED1);
		break;
	case 1:					//BP OFF
		PORTF &=~(1<<6);
		LEDs_TurnOffLEDs(LEDS_LED1);
		break;
	}
}


void cb_filterC2(char *param) {		//current BP filter MUX decision "n" 
	char *s;
	int16_t val;
	s = param;
	val = strtol(param,&s,16);
	
	switch(val) {
	case 0:					//BP OFF
		PORTF |=(1<<7);
		LEDs_TurnOnLEDs(LEDS_LED1);
		break;
	case 1:					//BP ON
		PORTF &=~(1<<7);
		LEDs_TurnOffLEDs(LEDS_LED1);
		break;
	}
}




void cb_notchV1(char *param) {		//voltage1 60hz notch filter MUX decision "n" 
	char *s;
	int16_t val;
	s = param;
	val = strtol(param,&s,16);
	
	switch(val) {
	case 0:	
		PORTF |=(1<<0);
		LEDs_TurnOnLEDs(LEDS_LED1);
		break;
	case 1:
		PORTF &=~(1<<0);
		LEDs_TurnOffLEDs(LEDS_LED1);
		break;
	}
}


void cb_notchC1(char *param) {		//current1 60hz notch filter MUX decision 
	char *s;
	int16_t val;
	s = param;
	val = strtol(param,&s,16);
	LEDs_ToggleLEDs(LEDS_LED1);
	switch(val) {
	case 0:	
		PORTF |=(1<<1);
		LEDs_TurnOnLEDs(LEDS_LED1);
		break;
	case 1:
        	LEDs_TurnOffLEDs(LEDS_LED1);
		PORTF &=~(1<<1);
		break;
	}
}


void cb_notchV2(char *param) {		//voltage2 60hz notch filter MUX decision "n" 
	char *s;
	int16_t val;
	s = param;
	val = strtol(param,&s,16);
	
	switch(val) {
	case 0:	
		PORTE |=(1<<6);
		LEDs_TurnOnLEDs(LEDS_LED1);
		break;
	case 1:
		PORTE &=~(1<<6);
		LEDs_TurnOffLEDs(LEDS_LED1);
		break;
	}
}


void cb_notchC2(char *param) {		//current2 60hz notch filter MUX decision 
	char *s;
	int16_t val;
	s = param;
	val = strtol(param,&s,16);
	LEDs_ToggleLEDs(LEDS_LED1);
	switch(val) {
	case 0:	
		PORTD |=(1<<7);
		LEDs_TurnOnLEDs(LEDS_LED1);
		break;
	case 1:
        	LEDs_TurnOffLEDs(LEDS_LED1);
		PORTD &=~(1<<7);
		break;
	}
}
