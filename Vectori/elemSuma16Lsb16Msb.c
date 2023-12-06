#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

/*Sa se implementeze o functie care primeste ca parametru un tablou de intregi fara semn pe 32 de biti A si un intreg N reprezentand nr de elemente. Functia va
inlocui fiecare element din tablou cu suma dintre nr pe 16 biti formate din cei mai semnificativi si cei mai putin semnificativi 16 biti ai nr de pe poz curenta.
Exemplu:
pe poz i se afla nr 0x11223344 se va inlocui cu 0x1122 + 0x3344=0x4466.
Testarea programului se va realiza printr un tablou generat cu nr aleatoare din intervalul 0...1000000*/

void inlocuireSuma(uint32_t A[], int N) {
    for (int i = 0; i < N; i++) {
        // Extragem cei mai semnificativi 16 biti
        uint16_t msb = (uint16_t)(A[i] >> 16);
        // Extragem cei mai putin semnificativi 16 biti
        uint16_t lsb = (uint16_t)(A[i] & 0xFFFF);
        
        // Calculăm suma și actualizăm elementul în tablou
        A[i] = msb + lsb;
    }
}

int main() {
    srand(time(NULL));

    // Generăm un tablou cu numere aleatoare pe 32 de biți
    int N = 10; // Modifică dimensiunea tabloului la nevoie
    uint32_t A[N];
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 1000001; // Generăm numere aleatoare între 0 și 1000000
    }

    // Afișăm tabloul înainte de modificare
    printf("Tabloul inainte de modificare:\n");
    for (int i = 0; i < N; i++) {
        printf("0x%08X ", A[i]);
    }
    printf("\n\n");

    // Apelăm funcția de înlocuire a sumei
    inlocuireSuma(A, N);

    // Afișăm tabloul după modificare
    printf("Tabloul dupa modificare:\n");
    for (int i = 0; i < N; i++) {
        printf("0x%08X ", A[i]);
    }
    printf("\n");

    return 0;
}
