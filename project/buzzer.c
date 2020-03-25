#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include <stdio.h>
#include <stdlib.h>


// Note Frequencies //
#define A3 2273
#define B3 2025
#define G3 2551
#define E3 3033
#define C3 3846
#define F3 2863
#define As3 2145
#define C4 1911
#define D4 1703
#define E4 1517
#define F4 1432
#define G4 1276
#define A4 1136
#define B4 1012
#define C5 956




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
  timerAUpmode();    /* used to drive Speaker */
  P2SEL2 &= ~(BIT6 | BIT7);
  P2DIR = BIT6;
  P2SEL |= BIT6;

  // Array of Notes for song //
  int song[] = {A3,0,A3,A3,0,A3,0,A3,0,G3,E3,0,C3,0,C3,0,A3,A3,0,G3,F3,0,G3,0,F3,As3,0,As3,0,As3,0,
		A3,0,G3,0,F3,0,F3,0,A3,0,A3,0,G3,0,F3,0,A3,0,A3,0,A3,A3,0,A3,G3,0,E3,0,C3,0,A3,A3,
		0,0,G3,0,F3,0,G3,0,As3,0,As3,As3,As3,0,As3,0,A3,G3,F3,0,F3,0,A3,A3,0,G3,0,F3,A3,0,
		A3,C4,D4,0,A3,A3,0,C4,0,D4,0,D4,C4,0,C4,0,C4,0,D4,0,D4,C4,0,C4,0,D4,0,E4,0,F4,0,E4,
	       D4,C4,0,A3,C4,D4,0,D4,0,D4,0,C4,0,A3,0,F3,0,F3,0,G3,0,A3,0,A3,0,G3,0,F3,A3,0,A3,C4};
  
  int keys = 0;
  for(int i = 0; i <100; i++){ // iterate through song 
    keys = song[i];
    buzzer_set_period(keys);
    __delay_cycles(2500000);
    P2SEL &= ~BIT7; // off 
  }
  P2DIR &= ~BIT6; // stop 
}


void playMarioTheme(){
  timerAUpmode(); // used to drive speaker 
  P2SEL2 &= ~(BIT6 | BIT7);
  P2DIR = BIT6;
  P2SEL |= BIT6;
  int song[] = {E4,0,E4,0,E4,0,C4,0,E4,0,G4,0,G3,0,C4,0,G3,0,E3,0,A3,0,B3,0,As3,0,A3,0,G3,0,E4,0,
		G4,0,A4,0,F4,0,G4,E4,E4,C4,D4,B3,C4};
		

  int keys = 0;
  for(int i =0; i < 45; i++){
    keys = song[i];
    buzzer_set_period(keys);
    __delay_cycles(2500000);
    P2SEL &= ~BIT7; // off 
  }
  P2DIR &= ~BIT6; // stop 
}



void playRememberMe(){
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2DIR = BIT6;
  P2SEL |= BIT6;
  int song[] = {A4,B4,G4,0,D4,0,0,D4,0,B3,0,C4,0,G4,0,G4,0,A4,A4,B4,B4,A4,0,D4,B4,0,C5,0,B4,0,
		B4,0,A4,A4};
  int keys = 0;
  for(int i = 0; i < 30; i++){
    keys = song[i];
    buzzer_set_period(keys);
    __delay_cycles(2500000);
    P2SEL &= ~BIT7; // off 
  }
  P2DIR &= ~BIT6; // stop 
}
