#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*7.Sa se scrie o functie cu urm antet:
uint64_t invert(uint64_t x, uint8_t p, uint8_t n);
Functia va returna numarul x cu n biti incepand cu pozitia p inversati(ceilalti biti raman neschimbati). Functia va testa 
corectitudinea arg si va returna
0 in caz de eroare.
 */


uint64_t invert(uint64_t x, uint8_t p, uint8_t n) {
    // Verifică dacă poziția p și n sunt valide
    if (p >= 64 || n > 64 || p + n > 64) {
        printf("Eroare: Parametrii invalizi.\n");
        return 0;
    }

    // Creează o mască pentru a inversa n biți începând de la poziția p
    uint64_t mask = ~(~0ULL << n) << p;

    // Aplică inversarea folosind XOR
    return x ^ mask;
}

int main() {
    // Testare funcție
    uint64_t numar = 0xABCDEF0123456789; // Un număr oarecare pe 64 de biți
    uint8_t pozitie = 16; // Exemplu: Inversăm începând de la poziția 16
    uint8_t lungime = 8; // Exemplu: Inversăm 8 biți

    printf("Numarul original: 0x%016llX\n", numar);
    uint64_t rezultat = invert(numar, pozitie, lungime);

    if (rezultat != 0) {
        printf("Numarul dupa inversare: 0x%016llX\n", rezultat);
    }

    return 0;
}

