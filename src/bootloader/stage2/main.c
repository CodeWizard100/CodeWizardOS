#include "stdint.h"
#include "stdio.h"

// Symulacja funkcji inportb (dla celów tego przykładu)
uint8_t inportb(uint16_t port) {
    // Kod symulujący zwrócenie kodu skanowania klawiatury
    // Możesz dostosować tę funkcję do rzeczywistych warunków pracy
    static uint8_t simulated_input[] = {0x02, 0x00}; // 0x02 to przykładowy kod skanowania dla klawisza '1'
    static int index = 0;

    if (port == 0x60) {
        // Zwraca kod skanowania przy każdym wywołaniu
        return simulated_input[index++ % 2];
    } else if (port == 0x64) {
        // Zwraca 1, aby wskazać, że jest dane do odczytania
        return 0x1;
    }
    return 0;
}

void _cdecl cstart_(uint16_t bootDrive)
{
    const char far* far_str = "far string";
    char buff[256];
    uint8_t i = 0;
    uint8_t reading = 1;

    puts("Hello world from C!\r\n");

    while (reading) {
        // Sprawdzanie wejścia z portu klawiatury
        if (inportb(0x64) & 0x1) {
            uint8_t scan_code = inportb(0x60);
            // Sprawdzenie, czy jakikolwiek klawisz został naciśnięty
            if (scan_code != 0x00) {
                puts("You typed something!");
                buff[i++] = (char)scan_code; // Zapisanie kodu skanowania do buffera
            }
        }
    }

    buff[i] = '\0'; // Zakończenie stringa
    puts("Buffer content: ");
    puts(buff);
}