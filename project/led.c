#include <msp430.h>
#include "led.h"
#include "switches.h"

void led_init(){
  P1DIR |= LEDS;
  P1OUT = !LED_RED;
  P1OUT = !LED_GREEN;
  if(switch_state_changed){ // if we press a button flash the lights 
    LightShow();
  }
  switch_state_changed = 0; // back to off 
}

void LightShow(){ // flash green and red with different delays  
  int i = 0;
  for(int i = 0; i <5; i++){
    P1OUT = LED_RED;
    __delay_cycles(4000000);
    P1OUT = LED_GREEN;
    __delay_cycles(8000000);
    P1OUT = !LED_RED;
    __delay_cycles(4000000);
    P1OUT = !LED_GREEN;
    __delay_cycles(8000000);
    P1OUT = LED_RED;
    __delay_cycles(1000000);
    P1OUT = !LED_RED;
    __delay_cycles(1000000);
    P1OUT = LED_GREEN;
    __delay_cycles(1000000);
    P1OUT = !LED_GREEN;
    __delay_cycles(1000000);
    P1OUT = LED_GREEN;
    __delay_cycles(2000000);
    P1OUT = LED_GREEN;
    __delay_cycles(2000000);
    P1OUT = LED_RED;
    __delay_cycles(20000000);
    P1OUT = LED_RED;
    __delay_cycles(2000000);
  }
}

void redLightShow(){ // flash red only
  for(int i = 0; i < 10; i++){
    P1OUT = LED_RED;
    __delay_cycles(1000000);
    P1OUT = !LED_RED;
    __delay_cycles(1000000);
  }
}

void greenLightShow(){ // flash green only 
  for(int i = 0; i < 10; i++){
    P1OUT = LED_GREEN;
    __delay_cycles(1000000);
    P1OUT = !LED_GREEN;
    __delay_cycles(1000000);
  }
}
