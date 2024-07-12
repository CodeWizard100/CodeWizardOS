#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "system.h"
#include "stdint.h"
#include "stdio.h"
#include "dos.h" // for delay()

void getinput() {
  uint8_t reading = 1;

  while (reading) {
    uint8_t status = inportb(0x64);
    printf("Status port: 0x64 = %x\n", status); // Print the status port value

    if (status & 0x1) {
      uint8_t scancode = inportb(0x60);
      printf("Scancode: %x\n", scancode);
      reading = 0; // Exit after reading one key press
    } else {
      puts("No data yet");
    }
    delay(100); // Add a short delay to avoid flooding the output
  }
}

#endif // KEYBOARD_H