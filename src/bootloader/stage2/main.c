#include "stdint.h"
#include "stdio.h"

// Function to read a byte from an I/O port
uint8_t inportb(uint16_t port) {
    // Declare a variable to hold the value read from the port
    uint8_t value;

    // Perform the input operation using inline assembly
    asm volatile ("inb %1, %0" : "=a" (value) : "dN" (port));

    // Return the value read from the port
    return value;
}

void _cdecl cstart_(uint16_t bootDrive)
{
    const char far* far_str = "far string";

    puts("Hello world from C!\r\n");

}