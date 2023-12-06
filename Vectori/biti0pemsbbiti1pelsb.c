#include <stdio.h>
#include <stdint.h>

/*functie ce primeste ca parametru un uint32_t si retunreaza un uint16_t care pe pozitia msb o sa se treaca nr de biti de 0 si pe lsb
nr de biti de 1*/

uint16_t count_bits(uint32_t n) {
    // Numără biții de 0
    int count_0 = 0;
    for (int i = 0; i < 32; i++) {
        if ((n & (1 << i)) == 0) {
            count_0++;
        }
    }

    // Numără biții de 1
    int count_1 = 32 - count_0;

    // Construiește rezultatul pe 16 biți
    uint16_t result = (count_0 << 8) | count_1;

    return result;
}

int main() {
    uint32_t n;
    printf("Introduceti n: ");
    scanf("%u", &n);

    uint16_t result = count_bits(n);

    // Afișare rezultat
    printf("Rezultat: %u\n", result);

    return 0;
}
