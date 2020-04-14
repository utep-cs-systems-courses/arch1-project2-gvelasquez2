#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "assemblyCode.h"
char play_both;
char play_red;
char play_green;

int state = 0;

static char switch_update_interrupt_sense(){
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);
  P2IES &= (p2val | ~SWITCHES);
  return p2val;
}

void switch_init(){
  P2REN |= SWITCHES;
  P2IE = SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  switch_update_interrupt_sense();
  switch_interrupt_handler();
}


void switch_interrupt_handler(){
  play_both = 0;
  play_red = 0;
  play_green = 0;
  char p2val = switch_update_interrupt_sense();

  // If Statements to Cycle through states //

  if(p2val & SW1 ? 0 : 1){
    switch_state_call(1);
    play_both = 1;
  }
  if(p2val & SW2 ? 0 : 1){
    switch_state_call(2);
    play_both = 0;
    play_red = 1;
  }
  if(p2val & SW3 ? 0 : 1){
    switch_state_call(3);
    play_both = 0;
    play_red = 0;
    play_green = 1;
  }
  if(p2val & SW4 ? 0 : 1){
    switch_state_call(4);
    play_both = 0;
    play_red = 0;
    play_green =1;
  }
}
/*
void switch_state_call(int state){

  switch(state){

  case 1: // play pokemon 
      playPokemonTheme();
      play_both= 1;
      
    break;
  
  case 2: // play mario 
      playMarioTheme();
      play_both = 0;
      play_red = 1;

    break;

  case 3: // play remember me 
      playRememberMe();
      play_both = 0;
      play_green = 1;

    break;

  case 4: // just lights 
      play_both = 1;

    break;

    default:
    break;
  }
}
*/

    
