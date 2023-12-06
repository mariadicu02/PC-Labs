#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>


/*Sa se implementeze o functie care primeste ca parametru un tablou de intregi fara semn pe 32 biti src,
un tablou de intregi fara semn pe 16 biti dst_msw si dimensiunea comuna a acestora.
Functia va sparge fiecare element din tabloul src in cei mai semnificativi 16 biti si cei mai putin semnificativi 16 biti
si va scrie cele 2 numere pe 16 biti rezultate in tabloul destinatie dst_msw respectiv dst_lsw.
Exemplu:
pe pozitia i din src se afla nr 0x11223344, pe pozitia i din dst_msb se va scrie 0x1122 iar pe pozitia i din dst_lsb se va scrie 0x3344.
Tablou generat cu nr aleat din intervalul 0 1000000.*/



void spargereElemente(uint32_t src[], uint16_t dst_msw[], uint16_t dst_lsw[], int dimensiune) {
    for (int i = 0; i < dimensiune; i++) {
        // Extragem cei mai semnificativi 16 biti
        dst_msw[i] = (uint16_t)(src[i] >> 16);
        // Extragem cei mai putin semnificativi 16 biti
        dst_lsw[i] = (uint16_t)(src[i] & 0xFFFF);
    }
}

int main() {
    srand(time(NULL));

    // Generăm un tablou cu numere aleatoare pe 32 de biți
    int dimensiune = 10; // Modifică dimensiunea tabloului la nevoie
    uint32_t src[dimensiune];
    for (int i = 0; i < dimensiune; i++) {
        src[i] = rand() % 1000001; // Generăm numere aleatoare între 0 și 1000000
    }

    // Afișăm tabloul generat
    printf("Tabloul generat:\n");
    for (int i = 0; i < dimensiune; i++) {
        printf("0x%08X ", src[i]);
    }
    printf("\n\n");

    // Declaram tablourile destinatie
    uint16_t dst_msw[dimensiune];
    uint16_t dst_lsw[dimensiune];

    // Apelăm funcția de spargere a elementelor
    spargereElemente(src, dst_msw, dst_lsw, dimensiune);

    // Afișăm rezultatele
    printf("Tabloul dst_msw:\n");
    for (int i = 0; i < dimensiune; i++) {
        printf("0x%04X ", dst_msw[i]);
    }
    printf("\n\n");

    printf("Tabloul dst_lsw:\n");
    for (int i = 0; i < dimensiune; i++) {
        printf("0x%04X ", dst_lsw[i]);
    }
    printf("\n");

    return 0;
}
