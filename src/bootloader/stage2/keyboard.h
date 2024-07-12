#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "system.h"
#include "stdint.h"
#include "stdio.h"

void getinput() {
  char buff;
  char* buffstr;
  uint8_t i = 0;
  uint8_t reading = 1;

  while(reading)
  {
    if (inportb(0x64) & 0x1) {
      puts("I think you clicked something");
    }
    else {
      if (inportb(0x64)) {puts("ok\r\n");}
      else {if (0x1) { puts("okok\r\n"); } else { puts("okokok\r\n"); }}
    }
  }
}

#endif // KEYBOARD_H