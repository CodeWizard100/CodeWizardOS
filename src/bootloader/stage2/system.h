#ifndef SYSTEM_H
#define SYSTEM_H

#include "stdint.h"

uint8_t inportb(uint16_t port) {
    uint8_t value;

    // Use #pragma aux to define inline assembly block
    #pragma aux inport = \
        "in al, dx"   /* Assembly instruction to read from port */ \
        "mov byte ptr [value], al" /* Move result to value */ \
        parm [dx] \
        value [al];

    // Call the inline assembly function
   

    // Return the value read from the port
    return value;
}

void outportb(uint16_t port, uint8_t data) {
  // Function definition using Watcom      inline assembly
  #pragma aux outport = \
    "out dx, al"   /* Assembly   instruction to write to port */ \
    parm [dx] [al];
}


#endif // SYSTEM_H