#include<stdio.h>
#include<stdint.h>

/*Se citește o valoare. Să se afișeze suma primilor săi 4 biți LSB (cei mai din dreapta)*/

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

int nr_biti_1 (uint8_t nr)
{
    uint8_t mask = 0x80; // 0b1000000000000000
    int contor=0;
    for (int i = 0; i < 8; i++)
    {
    if ((nr & mask) != 0)
        {
            contor++;
        }
      mask = mask >> 1; // mask >>= 1;
    }
    return contor;
}

int suma_lsb(uint8_t n){

    int result = nr_biti_1(n & 0x0F);
    return result;

}

int main(){

    uint8_t n;
    printf("Introduceti numarul: ");
    scanf("%hhd",&n);
    printf("Reprezentarea pe biti a numarului este: ");
    print_bit_8(n);
    
    int result = suma_lsb(n);
    printf("Suma ultimilor 4 LSB este: %d", result);
    return 0;
}

