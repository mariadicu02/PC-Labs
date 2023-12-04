#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*15.Sa se scrie o functie ce primeste ca argument un intreg fara semn pe 64 biti si un nr cu valori intre 0 si 64.
Functia va returna numarul pe 64 de biti primit ca arg, rotit la dreapta pe biti de un nr de ori specificat de al
doilea nr dat ca si argument. */

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

uint64_t rotire(uint64_t nr, int n)
{
    int i = 0;
    uint64_t m2 = 0;
    for(i = 0 ; i < n ; i++)//asta ca sa parcurg cele n rotiri
    {
        m2 = nr & 1;//ma asigur ca salvez ultima pozitie din nr
        nr = nr >> 1;//scap de ultima cifra din nr
        nr = nr | (m2 << 63);// m2 << 63 o sa fie de fapt ultimu bit pus pe prima pozitie si fac cu sau ca sa salvez noul nr
    }
    return nr;
}

int main()
{
    uint64_t nr,n;
    printf("Dati un nr care doriti sa fie rotit: ");
    scanf("%lld", &nr);
    printf("Dati nr de rotiri de aplicat: ");
    scanf("%lld", &n);
    if(n<0 || n>64)
        printf("Numarul dat este prea mare sau pre mic\n");
    else
    {
        print_bit_64(nr);
        nr = rotire(nr, n);
        print_bit_64(nr);
    }
    printf("\n");
    return 0;
}

