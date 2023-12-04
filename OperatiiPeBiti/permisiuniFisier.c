#include <stdio.h>
#include <stdint.h>

/*9.Se lucreaza la un nou sistem de operare numit Poliubuntu. Ca in orice sistem de operare, permisiunile fisierelor
este un aspect important. In acest sistem de operare, permisiunile unui fisier sunt stocate intr un numar pe 8 biti fara semn,
in 2 nibble-uri de 4 biti: primul nibble reprezinta permisiunile detinatorului(user), iar al doilea nibble reprezinta permisiunile celorlalti useri(other).
Cel mai semnificativ bit din nibble nu reprezinta nimic, iar urm 3 reprezinta in ordine dreptul de read, write, execute. De exemplu:
-rwx -rwx
0111 0100
In exemplul de mai sus, user-ul are dreptul de read, write execute, iar restul userilor pot doar citi acel fisier.
Sa se creeze urm functii:
- o functie care primeste ca parametru un nr intreg pe 8 biti reprezentand permisiunile unui fizier. Functia va afisa acele permisiuni sub forma -rwx -rwx.
De exemplu pt nr 0111 0100 se va afiza -rwx -r--.
- o functie care primeste ca parametru un tablou de astfel de permisiuni, un intreg N reprezentand nr de elem, un nr reprezentand permisiunea care va fi
resetata fiecarui nr din tablou fara a modifica restul permisiunilor, si un nr care va determina daca permisiunea se adauga la nibble ul user sau la
nibble ul other. De exemplu daca resetam dreptul de write pt other pt nr 0111 0110, el va deveni 0111 0100.
*/


// Functia care afiseaza permisiunile sub forma -rwx -rwx
void afisare_permisiuni(uint8_t permisiuni) {
    printf("-");
    // Verifica si afiseaza dreptul de read
    if (permisiuni & 0x4) {
        printf("r");
    } else {
        printf("-");
    }
    // Verifica si afiseaza dreptul de write
    if (permisiuni & 0x2) {
        printf("w");
    } else {
        printf("-");
    }
    // Verifica si afiseaza dreptul de execute
    if (permisiuni & 0x1) {
        printf("x");
    } else {
        printf("-");
    }
}

// Functia care modifica permisiunile
void modificare_permisiuni(uint8_t permisiuni[], int N, uint8_t permisiune_reset, int user_or_other) {
    for (int i = 0; i < N; ++i) {
        // Determina nibble-ul in care se va face modificarea
        uint8_t nibble;
        if (user_or_other == 0) {
            nibble = (permisiuni[i] >> 4) & 0x0F;
        } else {
            nibble = permisiuni[i] & 0x0F;
        }

        // Reseteaza permisiunea dorita in nibble-ul corespunzator
        if (permisiune_reset == 4) {
            nibble &= 0xE; // Reseteaza dreptul de read
        } else if (permisiune_reset == 2) {
            nibble &= 0xD; // Reseteaza dreptul de write
        } else if (permisiune_reset == 1) {
            nibble &= 0xB; // Reseteaza dreptul de execute
        }

        // Actualizeaza permisiunile in functie de user_or_other
        if (user_or_other == 0) {
            permisiuni[i] = (permisiuni[i] & 0x0F) | (nibble << 4);
        } else {
            permisiuni[i] = (permisiuni[i] & 0xF0) | nibble;
        }
    }
}

int main() {
    // Testare functiilor
    uint8_t permisiuni_exemplu = 0x76; // 0111 0110
    printf("Permisiuni exemplu: ");
    afisare_permisiuni(permisiuni_exemplu);
    printf("\n");

    int N = 3;
    uint8_t permisiuni[] = {0x76, 0x55, 0xA1};
    printf("Permisiuni inainte de modificare:\n");
    for (int i = 0; i < N; ++i) {
        afisare_permisiuni(permisiuni[i]);
        printf(" ");
    }
    printf("\n");

    modificare_permisiuni(permisiuni, N, 2, 1); // Reseteaza dreptul de write pentru other
    printf("Permisiuni dupa modificare:\n");
    for (int i = 0; i < N; ++i) {
        afisare_permisiuni(permisiuni[i]);
        printf(" ");
    }
    printf("\n");

    return 0;
}

