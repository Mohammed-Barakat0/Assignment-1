#include <avr/io.h>
#include <util/delay.h>

void ADCinit()
{
  ADCSRA = ADCSRA|(1<<7);
  ADCSRA = ADCSRA|(1<<2);
  ADCSRA = ADCSRA|(1<<1);
  ADCSRA = ADCSRA|(1<<0);
  ADMUX = ADMUX&~(1<<7);
  ADMUX = ADMUX|(1<<6);
}

int ADC_READ(int channel)
{
  ADMUX = ADMUX &~ (1<<0);
  ADMUX = ADMUX &~ (1<<1);
  ADMUX = ADMUX &~ (1<<2);
  ADMUX = ADMUX &~ (1<<3);
  ADMUX = ADMUX &~ (1<<4);
  ADMUX = ADMUX | channel;
  int status;
  do {
    status = ADCSRA|(1<<6) !=0;
  }while(status);
   
   return ADC;
}
