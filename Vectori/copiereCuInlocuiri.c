#include <stdio.h>
#include <stdint.h>

/*Sa se scrie o functie care primeste ca argumente doua tablouri, sursa si destinatie, de numere intregi pe 16 biti fara semn(uint16_t),
de aceeasi dimensiune, dimensiunea lor, precum si doua numere n si m, tot pe 16 biti fara semn. Functia va copia tabloul sursa in tabloul destinatie.
Peste tot unde in tabloul sursa se intalneste nr n, acesta se va inlocui in destinatie cu nr m. Totodata se vor inlocui cu m vecinii stang si drept ai nr gasit.
Functia va returna nr total de inlocuiri*/

// Functia returneaza numarul total de inlocuiri
uint16_t copiereCuInlocuiri(uint16_t *sursa, uint16_t *destinatie, size_t dimensiune, uint16_t n, uint16_t m) {
    uint16_t numarInlocuiri = 0;

    for (size_t i = 0; i < dimensiune; i++) {
        if (sursa[i] == n) {
            // Inlocuim elementul n cu m in destinatie
            destinatie[i] = m;
            numarInlocuiri++;

            // Verificam vecinul stang
            if (i > 0) {
                destinatie[i - 1] = m;
                numarInlocuiri++;
            }

            // Verificam vecinul drept
            if (i < dimensiune - 1) {
                destinatie[i + 1] = m;
                numarInlocuiri++;
            }
        } else {
            // Daca elementul nu este n, il copiem direct in destinatie
            destinatie[i] = sursa[i];
        }
    }

    return numarInlocuiri;
}

int main() {
    // Exemplu de utilizare
    uint16_t sursa[] = {1, 2, 3, 4, 5};
    uint16_t destinatie[5];
    size_t dimensiune = sizeof(sursa) / sizeof(sursa[0]);
    uint16_t n = 3;
    uint16_t m = 9;

    uint16_t rezultat = copiereCuInlocuiri(sursa, destinatie, dimensiune, n, m);

    printf("Vectorul destinatie: ");
    for (size_t i = 0; i < dimensiune; i++) {
        printf("%d ", destinatie[i]);
    }

    printf("\nNumarul total de inlocuiri: %d\n", rezultat);

    return 0;
}
