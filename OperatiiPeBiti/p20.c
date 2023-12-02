#include<stdio.h>
#include<stdint.h>


/*Scrieți o funcție care primește ca parametru 2 numere întregi pe 1 byte fără semn (n1 și n2)
și returnează un număr întreg pe 2 bytes (n) format din cele două numere ca și parte cea mai
semnificativă (n2) și parte mai putin semnficativă (n1)*/

uint16_t function(uint8_t a, uint8_t b)
{
    uint16_t result = 0;
    result = b << 8;
    result = result | a;
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

void print_bit_16 (uint16_t nr)
{
    uint16_t mask = 0x8000; // 0b1000000000000000
    uint16_t i = 0;
    int n=0;
    for (i = 0; i < 16; i++)
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

    uint8_t a,b;
    uint16_t result;
    printf("Introduceti numerele: \n");
    scanf("%hhd",&a);
    scanf("%hhd",&b);
    printf("Reprezentarile pe biti ale numerelor: \n");
    print_bit_8(a);
    print_bit_8(b);
    result = function ( a,b);
    printf("Rezultatul este %d \n", result);
    printf("Reprezentarea pe biti a rezultatului este: \n");
    print_bit_16(result);
    return 0;
}