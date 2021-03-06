


#ifndef __SPI_H_
#define __SPI_H_


#include <avr/io.h>

#define DD_MOSI DDB2  //SPI PINS available on PortB

#define DD_SCK DDB1  //SCK pin is PB1

#define DD_SS DDB0  //SS pin is PB0

#define DD_SS2 DDB4 //SS2 pin is PB4

#define DD_SS3 DDB5 //SS3 pin is PB5

#define DD_SS4 DDB6 //SS4 pin is PB6

#define PSS PORTB0  //SS pin is PB00

#define PSS2 PORTB4

#define PSS3 PORTB5

#define PSS4 PORTB6

#define DDR_SPI DDRB //Data direction port for SPI is PortB 

#define PORT_SPI PORTB

#define SELECT0()   (PORT_SPI &=~(_BV(PSS)))
#define SELECT1()   (PORT_SPI &=~(_BV(PSS2)))
#define UNSELECT0()    (PORT_SPI |= _BV(PSS))
#define UNSELECT1()    (PORT_SPI |= _BV(PSS2))

#define SELECT2()   (PORT_SPI &=~(_BV(PSS3)))
#define SELECT3()   (PORT_SPI &=~(_BV(PSS4)))
#define UNSELECT2()    (PORT_SPI |= _BV(PSS3))
#define UNSELECT3()    (PORT_SPI |= _BV(PSS4))
 
void SPI_MasterInit(void);
void SPI_MaterTransmit(char cData); 

#endif

