#include "stdint.h"
#include "stdio.h"

// Function to read a byte from an I/O port using Watcom inline assembly
uint8_t inportb(uint16_t port) {
    uint8_t value;

    // Use #pragma aux to define inline assembly block
    #pragma aux inportb = \
        "in al, dx"   /* Assembly instruction to read from port */ \
        "mov byte ptr [value], al" /* Move result to value */ \
        parm [dx] \
        value [al];

    // Call the inline assembly function
   

    // Return the value read from the port
    return value;
}

void _cdecl cstart_(uint16_t bootDrive)
{
    const char far* far_str = "far string";

    puts("Hello world from C!\r\n");

}