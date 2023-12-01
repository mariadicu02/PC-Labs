#include<stdio.h>
#include<stdint.h>

/*Scrieti si testati cu date de la intrare o functie care ia ca parametri doua numere intregi
si returneaza suma lor, folosind operatori pe biti. Calculati suma bit cu bit, cu propagarea
transportului, cu algoritmul de adunare pe hartie pencil-and-paper, fara a folosi operatori aritmetici.*/

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

int suma(int x, int y)//daca iau a = 0000 0010 si b= 0000 0011
{
    while(y!= 0)
    {
        unsigned carry = x & y;//carry = 0000 0010, carry = 0000 0100 & 1111 1100 = 0000 0100
        x = x ^ y; //x= 0000 0010 ^ 0000 0011 = 1111 1100, x= 1111 1100 ^ 0000 0100 = 1111 0111
        y = carry << 1;//y = 0000 0100, y= 0000 1000
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
    printf("Suma numerelor este: %d\n",suma(a,b));
    printf("Reprezentarea pe biti a sumei este: \n");
    print_bit_8(suma(a,b));




    return 0;
}