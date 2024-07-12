#include "stdint.h"
#include "stdio.h"

// Symulacja funkcji inportb (dla celów tego przykładu)
uint8_t inportb(uint16_t port) {
    // Kod symulujący zwrócenie kodu skanowania klawiatury
    // Na przykład dla klawisza '1' można użyć wartości odpowiadającej jego kodowi skanowania
    static uint8_t simulated_input[] = {0x02, 0x00}; // 0x02 to kod skanowania dla '1'
    static int index = 0;

    if (port == 0x60) {
        // Zwraca kod skanowania przy każdym wywołaniu
        return simulated_input[index++ % 2];
    } else if (port == 0x64) {
        // Zwraca 1, aby wskazać, że jest dane do odczytania
        // co każde drugie wywołanie symuluje brak danych wejściowych
        return (index % 2 == 0) ? 0x1 : 0x0;
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