#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>


/*Sa se implementeze o functie care primeste ca parametru un tablou de intregi fara semn pe 16 biti A, un intreg N reprezentand nr de
elem si un intreg pe 8 biti fara semn x. Functia va returna cate elemente din tablou au cei mai putin semnificativi 8 biti
identici cu valoarea x.
Testarea se va face cu un tablou generat cu nr aleat din intervalul 0..600000*/

uint16_t numarElementeIdentice(uint16_t A[], int N, uint8_t x) {
    uint16_t count = 0;

    for (int i = 0; i < N; i++) {
        // Extragem cei mai putin semnificativi 8 biti
        uint8_t lsb = (uint8_t)(A[i] & 0xFF);

        // Verificăm dacă cei mai puțin semnificativi 8 biti sunt identici cu x
        if (lsb == x) {
            count++;
        }
    }

    return count;
}

int main() {
    srand(time(NULL));

    // Generăm un tablou cu numere aleatoare pe 16 de biți
    int N = 10; // Modifică dimensiunea tabloului la nevoie
    uint16_t A[N];
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 600001; // Generăm numere aleatoare între 0 și 600000
    }

    // Afișăm tabloul generat
    printf("Tabloul generat:\n");
    for (int i = 0; i < N; i++) {
        printf("0x%04X ", A[i]);
    }
    printf("\n\n");

    // Alegem o valoare x aleatoare pe 8 de biți
    uint8_t x = rand() % 256;

    // Apelăm funcția și afișăm rezultatul
    uint16_t rezultat = numarElementeIdentice(A, N, x);

    printf("Numarul de elemente cu cei mai putin semnificativi 8 biti identici cu 0x%02X este: %d\n", x, rezultat);

    return 0;
}
