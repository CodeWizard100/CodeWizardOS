#include "stdint.h"
#include "stdio.h"
#include "keyboard.h"

void _cdecl cstart_(uint16_t bootDrive)
{
    const char far* far_str = "far string";

    puts("Hello world from C!\r\n");

   while (1) {
    getinput();
  }
}