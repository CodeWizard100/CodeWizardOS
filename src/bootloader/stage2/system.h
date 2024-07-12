
#ifndef SYSTEM_H
#define SYSTEM H

#include "types.h"

uint8 inportb (uint16_port)
{
uint8 rv;
_asm__volatile ("inb %1, %0" : "=a" (rv):"dN" (_port)); 
return rv;
}

void outportb (uint16 _port, uint8_data)
{
asm _volatile ("outb %1, %0": : "dN" (_port), "a" (_data));
}

#endif
