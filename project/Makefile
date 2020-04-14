COMMON_OBJECTS 	=
CPU		= msp430g2553
CFLAGS		= -mmcu=${CPU} -I../h
LDFLAGS		= ../project/lib/libTimer.a -L/opt/ti/msp430_gcc/include


CC		= msp430-elf-gcc
AS		= msp430-elf-as

all: buzzerBlink.elf

buzzerBlink.elf:${COMMON_OBJECTS} main.o p1_interrupt_handler.o switches.o led.o assemblyCode.o buzzer.o ../project/lib/libTimer.a
	${CC} $(CFLAGS) $^ $(LDFLAGS) -o $@

load: buzzerBlink.elf
	msp430loader.sh buzzerBlink.elf

clean:
	rm -f *.o *.elf

main.c: buzzer.h led.h switches.h
switches.c: switches.h assemblyCode.h
led.c: led.h
buzzer.c: buzzer.h
p1_interrupt_handler.c: switches.h
assemblyCode.s: switches.h led.h
