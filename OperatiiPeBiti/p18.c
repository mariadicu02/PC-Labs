#include<stdio.h>
#include<stdint.h>

/*Să se scrie o funcție care primește ca argument un număr pe 32 de biți fără semn (nr),
un număr pe 8 biți fără semn (n) și o poziție (p). Funcția va returna numărul (nr) în
care octetul de pe poziția p va fi inlocuit cu numărul n. Octeții se numără se la dreapta
(cel mai puțin semnificativ, poziția 0) spre stanga*/

void print_bit_32 (uint32_t nr)
{
    uint32_t mask = 0x8000; // 0b1000000000000000
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

uint32_t inlocuire_octet(uint32_t nr, uint8_t n, int p) {
    // Verifică dacă poziția p este validă (0-3 pentru un număr pe 32 de biți)
    if (p < 0 || p > 3) {
        return nr;  // Returnează numărul original în caz de eroare
    }

    // Actualizează numărul cu n pe poziția p
    return (nr & ~(0xFFu << (p * 8))) | ((uint32_t)n << (p * 8));
}

int main() {
    uint32_t nr;
    uint8_t n;
    int p;

    printf("Introduceți numărul pe 32 de biți: ");
    scanf("%u", &nr);

    printf("Reprezentarea in binar: \n");
    print_bit_32(nr);

    printf("Introduceți numărul pe 8 biți: ");
    scanf("%hhu", &n);

    printf("Reprezentarea in binar: \n");
    print_bit_8(n);

    printf("Introduceți poziția (0-3): ");
    scanf("%d", &p);

    uint32_t rezultat = inlocuire_octet(nr, n, p);

    printf("Numărul rezultat: %u\n", rezultat);

    printf("Reprezentarea in binar a rezultatului: \n");
    print_bit_32(rezultat);

    return 0;
}
