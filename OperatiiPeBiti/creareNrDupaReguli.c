#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

/*4.Scrieti o functie ce primeste doua numere naturale pe n biti si returneaza un numar natural dupa urm reguli:
- bitii de rang(0;p)(bitul cel mai din dreapta are rangul 0) sa fie ultimii biti p ai primului numar
- bitii de rang[p;n) sa fie primii p biti celui de al doilea numar
unde p, n sunt nr naturale pozitive si p<n.
Sa se afiseze folosind operatiile pe biti, prin intermediul unei functii , bitii primului nr, celui de al doilea nr si al rezultatului.

ex:
daca n=8, p=4
si
primul nr este 00011000 atunci primii p biti sunt 1000, iar ultimii p biti sunt 0001
si
al doilea numar este 00001000 atunci primii p biti sunt 1000, iar ultimii p biti sunt 0000

atunci rezultatul este 10000001;
*/

void showBits(int a)
{
    int i;
    for(i=sizeof(a)*8-1;i>=0;i--)
        printf("%d",(a>>i)&1);
    printf("\n");
}

void functie(uint8_t a, int b, int p)
{
    uint8_t m1, m2;
    showBits(a);
    printf("\n");
    showBits(b);
    printf("\n");

    m1= a>>p;
    //showBits(m1);
    //printf("\n");

    m2= b<<p;
    //showBits(m2);
    //printf("\n");

    uint8_t r=0;
    r = m1 | m2;
    showBits(r);
    printf("\n");
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
