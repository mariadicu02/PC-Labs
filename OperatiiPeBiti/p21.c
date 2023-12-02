#include<stdio.h>
#include<stdint.h>

/*Scrieți o funcție care primește ca și argumente 4 numere întregi pe 1 byte fără semn (n3, n2, n1, n0)
și returnează un număr întreg pe 4 bytes (n) format din cele 4 numere unde n3 este partea cea mai semnificativă
și n0 partea cea mai puțin semnficativă
exemplu: n3 = 1111 0000, n2 = 0011 1100, n1 = 1010 0011, n0 = 0010 1101 -> n = 1111 0000 0011 1100 1010 0011 0010 1101*/

uint32_t function(uint8_t n3, uint8_t n2, uint8_t n1, uint8_t n0)
{
    uint32_t result = 0, aux3=0, aux2=0, aux1=0;
    aux3 = n3 << 24;
    aux2 = n2 << 16;
    aux1 = n1 << 8;
    result = aux3 | aux2 | aux1 | n0;
    return result;
}

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

void print_bit_32 (uint32_t nr)
{
    uint32_t mask = 0x80000000; // 0b1000000000000000
    uint32_t i = 0;
    int n=0;
    for (i = 0; i < 32; i++)
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

int main(){

    uint8_t a,b,c,d;
    uint32_t result;
    printf("Introduceti numerele: \n");
    scanf("%hhd",&a);
    scanf("%hhd",&b);
    scanf("%hhd",&c);
    scanf("%hhd",&d);
    printf("Reprezentarile pe biti ale numerelor: \n");
    print_bit_8(a);
    print_bit_8(b);
    print_bit_8(c);
    print_bit_8(d);
    result = function ( a,b,c,d);
    printf("Rezultatul este %d \n", result);
    printf("Reprezentarea pe biti a rezultatului este: \n");
    print_bit_32(result);



    return 0;
}