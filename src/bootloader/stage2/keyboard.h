#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "system.h"
#include "stdint.h"
#include "stdio.h"

void getinput() {
  uint8_t reading = 1;

  while (reading) {
    uint8_t status = inportb(0x64);
    printf("Status port: 0x64 = %x\r\n", status); // Print the status port value

    if (status & 0x1) {
      uint8_t scancode = inportb(0x60);
      printf("Scancode: %x\r\n", scancode);
      reading = 0; // Exit after reading one key press
    } else {
      puts("No data yet\r\n");
    }
    
  }
}

#endif // KEYBOARD_H