#ifndef SYSTEM_H
#define SYSTEM_H

#include "types.h"

static inline uint8 inportb(uint16 _port) {
    uint8 rv;
    __asm__ volatile ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}

static inline void outportb(uint16 _port, uint8 _data) {
    __asm__ volatile ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

#endif // SYSTEM_H