#ifndef switches_included
#define switches_included

#define SWITCHES (SW1 | SW2 | SW3 | SW4)

#define SW1 BIT0 // P2.0 = S1
#define SW2 BIT1 // P2.1 = S2
#define SW3 BIT2 // P2.2 = S3
#define SW4 BIT3 // P2.3 = S4

void switch_init();
void switch_interrupt_handler();

extern char switch_state_changed;
#endif
