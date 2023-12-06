#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 7

/*3.Creati un tablou A de dimensiune N(dimensiunea maxima a vectorului sa fie configurabila prin #define).
Apoi sa se populeze vectorul cu elemente aleatorii din intervalul [0, 60000].
Apoi scrieti o functie care sa returneze paritatea pe biti a intregului tablou, NU returneaza paritatea fiecarui element din tablou.*/

void populare(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%60001;
    }
}

void printare(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\n", a[i]);
    }
}

int paritate(int a[], int n)
{
    int p = 0, count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < sizeof(int) * 8; j++)
        {
            if ((a[i] & (1 << j)) != 0)
                count++;
        }
    }

    if (count % 2 == 1)
        p = 0; // paritatea impara
    else
        p = 1; // paritate para
    return p;
}


int main()
{
    int a[N];
    srand(time(NULL));
    populare(a,N);
    printare(a,N);
    printf("Paritatea intregului tablou e %d\n", paritate(a,N));

    return 0;
}
