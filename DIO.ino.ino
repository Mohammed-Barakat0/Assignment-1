#include <avr/io.h>
#include <util/delay.h>

void DIOinit(){
  PORTB = PORTB &~ (1 << 0);
  PORTB = PORTB &~ (1 << 1);
  PORTB = PORTB &~ (1 << 2);
  }
