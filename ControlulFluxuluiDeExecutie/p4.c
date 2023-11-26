#include<stdio.h>

/*Se citește un număr întreg n>2. Să se afișeze folosind steluțe litera N, formată cu laturile și diagonala
 unui pătrat de latură n.*/

 int main(){

    int n;

    printf("Introduceti un numar n: ");
    scanf("%d", &n);

    // Afișăm pătratul gol
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Verificăm dacă suntem pe margine sau în interior
            if (j == 0 || j == n - 1 || i == j) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");  // Trecem la următoarea linie
    }





    return 0;
 }