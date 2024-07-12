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
      puts("I think ypu clicked something");
    }
  }
}

#endif // KEYBOARD_H