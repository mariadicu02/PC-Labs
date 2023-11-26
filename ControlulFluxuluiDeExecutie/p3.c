#include<stdio.h>

/*Se citește un număr n>1. Să se afișeze folosind steluțe un pătrat gol, având latura de n steluțe.*/

/*
i == 0 verifică dacă suntem pe prima linie a matricei.
i == n - 1 verifică dacă suntem pe ultima linie a matricei.
j == 0 verifică dacă suntem pe prima coloană a matricei.
j == n - 1 verifică dacă suntem pe ultima coloană a matricei.*/


int main() {
    int n;

    printf("Introduceți un număr n: ");
    scanf("%d", &n);

    // Afișăm pătratul gol
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Verificăm dacă suntem pe margine sau în interior
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");  // Trecem la următoarea linie
    }

    return 0;
}
