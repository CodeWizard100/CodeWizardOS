#include "stdint.h"
#include "stdio.h"

void _cdecl cstart_(uint16_t bootDrive)
{
    const char far* far_str = "far string";

    puts("Hello world from C!\r\n");
    
    char* vid = (char*)0xB8000;

    vid[0] = 'A';

    vid[1] = 0x07;
}