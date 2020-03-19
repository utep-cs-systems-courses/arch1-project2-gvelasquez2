#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include <stdio.h>
#include <stdlib.h>


// Note Frequencies //
#define A3 2273
#define G3 2551
#define E3 3033
#define C3 3846
#define F3 2863
#define As3 2145





void buzzer_init(){
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= BIT7; // BUZZER OFF 
  P2SEL |= BIT6; // BUZZER ON 
  P2DIR = BIT6; // OUTPUT TO SPEAKER P2.6
}

void buzzer_set_period(short cycles){
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}

void playPokemonTheme(){
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2DIR = BIT6;
  P2SEL |= BIT6;
  int song[] = {A3,0,A3,A3,0,A3,0,A3,0,G3,E3,0,C3,0,C3,0,A3,A3,0,G3,F3,0,G3,0,F3,As3,0,As3,0,As3,0,
		A3,0,G3,0,F3,0,F3,0,A3,0,A3,0,G3,0,F3,0,A3,0};
  int keys = 0;
  for(int i = 0; i <42; i++){
    keys = song[i];
    buzzer_set_period(keys);
    __delay_cycles(2500000);
    P2SEL &= ~BIT7;
  }
  P2DIR &= ~BIT6;
}


// void Song2(){}//
// void Song3(){}//
// void Song4(){}//
