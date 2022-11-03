#include <avr/io.h>
#include <util/delay.h>
#include "ADC.h"
#include "uart.h"
#include "DIO.h"

void init();

int main(void)
{
  init();
  while(1)
  {
    DDRC = DDRC &~ (1<<2);          
    float reading;                  //value for adc data to be stored in 
    reading =  ADC_READ(2);         //ADC data
    if (reading>1000){
      PORTB = PORTB | (1 << 0);     //Turn on LED
      PORTB = PORTB | (1 << 1);     //Turn on LED
      PORTB = PORTB | (1 << 2);     //Turn on LED
      uart_transmit (reading);      //Send data to PC
      char uart_recieve();          //PC recives data
    }
    else
    { PORTB = PORTB & ~ (1 << 0);   //LED off
      PORTB = PORTB & ~ (1 << 1);   //LED off
      PORTB = PORTB & ~ (1 << 2);   //LED off
      uart_transmit (reading);      //Send data to PC
      char uart_recieve();          //PC recives data
      }
    
     
  }
  return 0;
}

void init()
{
  ADCinit();                                        //Initializing ADC
  uart_init (9600);                                 //Initializing UART
  void uart_SetBaudRate(int baud);                  //Set Baud Rate
  void DIOinit();                                   //Initializing DIO
}
