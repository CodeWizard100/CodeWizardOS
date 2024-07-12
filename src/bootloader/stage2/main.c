#include "stdint.h"
#include "stdio.h"

void example_function() {
    int value = 10;
    __asm__ volatile (
        "movl %0, %%eax;"
        "addl $5, %%eax;"
        : /* output operands */
        : "r" (value)
        : "%eax" /* clobbered registers */
    );

    printf("Result: %d\n", value);
}

void _cdecl cstart_(uint16_t bootDrive)
{
example_function();
    const char far* far_str = "far string";

    puts("Hello world from C!\r\n");

}