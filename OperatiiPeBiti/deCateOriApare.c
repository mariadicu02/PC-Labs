#include <stdio.h>
#include <stdint.h>

/*10.Sa se scrie o functie ce primeste ca argumente un intreg pe 64 biti si un nr intreg fara semn pe 8 biti care va avea
cel mult valoarea maxima reprezentabila pe 4 biti. Functia returneaza de cate ori configuratia binara(pe 4 biti) din
numarul dat
ca si al doilea argument se gaseste in numarul dat ca si prim argument(chiar daca se suprapune).
exemplu:
primul nr 1110 1010 0101 0001 (zec: 59985), al doilea nr 1010 (zec 10). Functia va returna 3 deoarece configuratia
1010 se gaseste de 3 ori in
nr initial.*/


int countConfigurations(uint64_t numar64, uint8_t numar8) {
    // Verifică dacă numărul pe 8 biți nu depășește valoarea maximă reprezentabilă pe 4 biți
    if (numar8 > 15) {
        printf("Eroare: Numărul pe 8 biți trebuie să fie maxim 15.\n");
        return 0;
    }

    // Convertirea numărului pe 8 biți la o configurație binară de 4 biți
    uint8_t configBinar = numar8 & 0x0F;  // Asigurare că sunt considerați doar primii 4 biți

    // Inițializarea contorului
    int count = 0;

    // Parcurgerea fiecărui grup de 4 biți în numărul pe 64 de biți
    for (int i = 0; i <= 60; i += 4) {
        // Obținerea grupului de 4 biți în configurație binară din numărul pe 64 de biți
        uint8_t configNumar64 = (numar64 >> i) & 0x0F;

        // Verificarea dacă configurația din numărul pe 64 de biți corespunde cu cea dată
        if (configNumar64 == configBinar) {
            count++;
        }
    }

    return count;
}

int main() {
    // Testare funcție
    uint64_t numar64 = 59985; // Exemplu: 1110 1010 0101 0001 (zecimal: 59985)
    uint8_t numar8 = 10;     // Exemplu: 1010 (zecimal: 10)

    printf("Numarul pe 64 de biti: %llu\n", numar64);
    printf("Numarul pe 8 biti: %u\n", numar8);

    int rezultat = countConfigurations(numar64, numar8);

    printf("Configuratia se gaseste de %d ori in numarul pe 64 de biti.\n", rezultat);

    return 0;
}

