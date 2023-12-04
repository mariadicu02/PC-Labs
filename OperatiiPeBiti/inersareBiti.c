#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*7.Sa se scrie o functie cu urm antet:
uint64_t invert(uint64_t x, uint8_t p, uint8_t n);
Functia va returna numarul x cu n biti incepand cu pozitia p inversati(ceilalti biti raman neschimbati). Functia va testa corectitudinea arg si va returna
0 in caz de eroare.
 */

uint64_t invert(uint64_t x, uint8_t p, uint8_t n)
{
    int a=x;
    if(p >= sizeof(int)*8 || n >= sizeof(int)*8)
    {
        printf("EROARE!\n");
        return 0;
    }
    while( p < (sizeof(int)*16 -1))
    {
        a = a & ~(1<<p);
        p++;
    }
    return a;
}

void afisare(uint64_t r, uint64_t n)
{
    int i;
    for(i = n-1;i >= 0; i--)
    {
        if((r & (1<<i)) != 0)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}


int main()
{
    int x, n, p, r;
    printf("x = ");
    scanf("%d", &x);
    printf("p = ");
    scanf("%d", &p);
    printf("n = ");
    scanf("%d", &n);

    r= invert(x, p, n);
    afisare(r, n);


    printf("\n");
    return 0;
}
