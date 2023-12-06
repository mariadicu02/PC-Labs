#include<stdio.h>


/*Se citește un număr n (n<=10) și apoi n numere întregi. Se cere să se sorteze aceste
numere astfel încât numerele impare să fie înaintea celor pare*/


// Functie pentru citirea vectorului
void citire(int v[], int n) {
    printf("Introduceti %d numere: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
}

// Functie pentru afisarea vectorului
void afisare(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int n, aux;
    printf("Introduceti numarul de numere: ");
    scanf("%d", &n);

    if (n > 10) {
        printf("Numarul de numere depaseste limita (10).\n");
        return 1;
    }

    int v[n];
    citire(v, n);

    // Sortare: numerele impare inaintea celor pare
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] % 2 == 0 && v[j + 1] % 2 != 0) {
                // Daca numarul curent este par si urmatorul este impar, le interschimbam
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }

    // Afisare vector sortat
    printf("Vectorul sortat: ");
    afisare(v, n);

    return 0;
}
