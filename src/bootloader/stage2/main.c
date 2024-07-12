#include "stdint.h"
#include "stdio.h"

void _cdecl cstart_(uint16_t bootDrive)
{
    const char far* far_str = "far string";

    puts("Hello world from C!\r\n");
    
    char* vidmem = (char*)0xB8000;

    vidmem[0] = 'A';

    vidmem[1] = 0x07;
}