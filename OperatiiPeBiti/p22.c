#include<stdio.h>
#include<stdint.h>

/*Scrieți o funcție similară cu funcțiile realizate la aplicații anterioare în care se primesc
ca argumente 8 numere pe 8 biți fără semn (n7, n6, ... n0) și returnează un numă de 64 de biți
fără semn format din cele 8 numere primite ca și argumente în care n7 devine cel mai semnificativ
byte și n0 cel mai puțin semnificativ byte*/

uint64_t function(uint8_t n7, uint8_t n6, uint8_t n5, uint8_t n4, uint8_t n3, uint8_t n2, uint8_t n1, uint8_t n0)
{
    uint64_t result = 0, aux7=0, aux6 =0, aux5 =0, aux4=0, aux3=0, aux2=0, aux1=0;
    aux7 = (uint64_t)n7 << 56;
    aux6 = (uint64_t)n6 << 48;
    aux5 = (uint64_t)n5 << 40;
    aux4 = (uint64_t)n4 << 32;
    aux3 = (uint64_t)n3 << 24;
    aux2 = (uint64_t)n2 << 16;
    aux1 = (uint64_t)n1 << 8;
    result = aux7 | aux6 | aux5 | aux4 | aux3 | aux2 | aux1 | n0;
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

void print_bit_64 (uint64_t nr)
{
    uint64_t mask = 0x8000000000000000; // 0b1000000000000000
    uint64_t i = 0;
    int n=0;
    for (i = 0; i < 64; i++)
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

    uint8_t a,b,c,d,e,f,g,h;
    uint64_t result;
    printf("Introduceti numerele: \n");
    scanf("%hhd",&a);
    scanf("%hhd",&b);
    scanf("%hhd",&c);
    scanf("%hhd",&d);
    scanf("%hhd",&e);
    scanf("%hhd",&f);
    scanf("%hhd",&g);
    scanf("%hhd",&h);
    printf("Reprezentarile pe biti ale numerelor: \n");
    print_bit_8(a);
    print_bit_8(b);
    print_bit_8(c);
    print_bit_8(d);
    print_bit_8(e);
    print_bit_8(f);
    print_bit_8(g);
    print_bit_8(h);
    result = function ( a,b,c,d,e,f,g,h);
    printf("Rezultatul este %lld \n", result);
    printf("Reprezentarea pe biti a rezultatului este: \n");
    print_bit_64(result);
    return 0;
}