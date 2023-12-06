#include <stdio.h>
#include <stdlib.h>

#define MAX 7

void citire(int *A, int N) {
    printf("Introduceti %d numere: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
}

void afisare(int *A, int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int maxim(int *A, int N) {
    int maxim = A[0];
    for (int i = 1; i < N; i++) {
        if (A[i] > maxim) {
            maxim = A[i];
        }
    }
    return maxim;
}

int minim(int *A, int N) {
    int minim = A[0];
    for (int i = 1; i < N; i++) {
        if (A[i] < minim) {
            minim = A[i];
        }
    }
    return minim;
}

void interschimbareMinMax(int *A, int N) {
    int valoareMaxima = maxim(A, N);
    int valoareMinima = minim(A, N);

    for (int i = 0; i < N; i++) {
        if (A[i] == valoareMaxima) {
            A[i] = valoareMinima;
        } else if (A[i] == valoareMinima) {
            A[i] = valoareMaxima;
        }
    }
}

int main() {
    int N;
    printf("Introduceti numarul de elemente (<= %d): ", MAX);
    scanf("%d", &N);

    if (N > MAX || N <= 0) {
        printf("Eroare! Numarul de elemente trebuie sa fie intre 1 si %d.\n", MAX);
        return -1;
    }

    int vector[MAX];
    citire(vector, N);

    printf("Vectorul initial: ");
    afisare(vector, N);

    interschimbareMinMax(vector, N);

    printf("Vectorul cu valorile minime si maxime interschimbate: ");
    afisare(vector, N);

    return 0;
}
