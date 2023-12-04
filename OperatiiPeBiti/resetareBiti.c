#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*Sa se scrie o functie cu urmatorul antet
uint64_t resetBits(uint64_t x, uint8_t p, uint8_t n)
Functia va returna numarul x cu n biti incepand cu pozitia p resetati la 0(ceilalti biti raman neschimbati).
Functia va testa corectitudinea argumentelor si va returna 0 in caz de eroare. Pt functionalitate se va impl o functie
ce va afisa nr pe biti.*/


void print_bit_64(uint64_t nr) {
    uint64_t mask = 0x8000000000000000; // Masca pentru primul bit (cel mai semnificativ)
    int n = 0;

    for (int i = 0; i < 64; i++) {
        if ((nr & mask) == 0) {
            printf("0");
        } else {
            printf("1");
        }

        mask = mask >> 1; // Deplasare masca la dreapta
        n++;

        if (n % 4 == 0) {
            printf(" ");
        }
    }

    printf("\n");
}

uint64_t resetBits(uint64_t x, uint8_t p, uint8_t n) {
    // Verifică corectitudinea argumentelor
    if (p >= 64 || n > 64 || p + n > 64) {
        printf("Eroare: Argumente invalide.\n");
        return 0;
    }

    // Construiește masca pentru resetare
    uint64_t resetMask = ~(1 << n) << p;

    // Resetare biti în x utilizând masca
    return x & ~resetMask;
}

int main() {
    uint64_t x, result;
    uint8_t p, n;

    // Introducere valori
    printf("Introduceti numarul x (uint64_t): ");
    scanf("%llu", &x);

    printf("Introduceti pozitia p (0-63): ");
    scanf("%hhu", &p);

    printf("Introduceti numarul de biti n (1-64): ");
    scanf("%hhu", &n);

    // Apelare functie resetBits
    result = resetBits(x, p, n);

    // Afișare rezultat
    printf("Numarul x in binar:\n");
    print_bit_64(x);

    printf("Rezultat dupa resetare:\n");
    print_bit_64(result);

    return 0;
}

