#ifndef SYSTEM_H
#define SYSTEM_H

#include "stdint.h"

uint8_t inportb(uint16_t port);
void outportb(uint16_t port, uint8_t data);

#pragma aux inportb = \
    "in al, dx" \
    "mov byte ptr [eax], al" \
    parm [dx] \
    modify [al] \
    value [al];

#pragma aux outportb = \
    "out dx, al" \
    parm [dx] [al];

#endif // SYSTEM_H