#include<stdio.h>
#include<stdint.h>

/*Scrieti si testati cu date de la intrare o functie care ia ca parametri doua numere intregi
si returneaza diferenta lor, folosind operatori pe biti. Calculati diferenta bit cu bit, cu
propagarea transportului, cu algoritmul de scadere pe hartie pencil-and-paper, fara a folosi
operatori aritmetici.*/

void print_bit_8 (uint8_t nr)
{
    uint8_t mask = 0x80; // 0b1000000000000000
    uint8_t i = 0;
    int n=0;
    for (i = 0; i < 8; i++)
    {
    if ((nr & mask) == 0)
        {
            printf ("0");
        }
    else
        {
            printf ("1");
        }
      mask = mask >> 1; // mask >>= 1;
        n++;
        if(n%4 == 0)
        printf(" ");
    }
    printf ("\n");
}


int scadere(int x, int y)
{
    while (y != 0) {
        int borrow = (~x) & y;
        x = x ^ y;
        y = borrow << 1;
    }

    return x;
}

int main(){

    int a, b;
    printf("Introduceti numerele: \n");
    scanf("%d",&a);
    scanf("%d",&b);
    printf("Reprezentarea pe biti a numerelor este: \n");
    print_bit_8(a);
    print_bit_8(b);
    printf("Diferenta numerelor este: %d\n",scadere(a,b));
    printf("Reprezentarea pe biti a diferentei este: \n");
    print_bit_8(scadere(a,b));


    return 0;
}