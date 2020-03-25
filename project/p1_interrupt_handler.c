#include <msp430.h>
#include "switches.h"

void
__interrupt_vec(PORT1_VECTOR) Port_1(){
  if(P1IFG & SWITCHES){ // did a button caus this interrupt 
    P1IFG &= ~SWITCHES; // clear pending sw interrupts 
    switch_interrupt_handler(); // single handler for all switches 
  }
}