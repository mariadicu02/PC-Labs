#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*15.Sa se scrie o functie ce primeste ca argument un intreg fara semn pe 64 biti si un nr cu valori intre 0 si 64. Functia va returna
numarul pe 64 de biti primit ca arg, rotit la dreapta pe biti de un nr de ori specificat de al doilea nr dat ca si argument. */

void showBits(unsigned a){
    int i;
    for(i=sizeof(a)*8-1;i>=0;i--)
        printf("%d",(a>>i)&1);
    printf("\n");
}

uint64_t rotire(uint64_t n, uint64_t p)
{
    int mask =1;
    int primStg =0;
    int psdPrim =0;
    for( int i=0;i<p;i++)
    {
        primStg= n & mask;
        n = n >> 1;
        psdPrim = primStg << 7;
        n = n|psdPrim;
        //showBits(n);
    }
    return n;
}

int main()
{
    uint64_t n, p;
    scanf("%hhd", &n);
    scanf("%hhd", &p);
    showBits(n);
    printf("Rezultat dupa rotire: \n");
    showBits(rotire(n, p));
    printf("\n");
    return 0;
}

/*#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*15.Sa se scrie o functie ce primeste ca argument un intreg fara semn pe 64 biti si un nr cu valori intre 0 si 64. Functia va returna
numarul pe 64 de biti primit ca arg, rotit la dreapta pe biti de un nr de ori specificat de al doilea nr dat ca si argument.

void showBits(unsigned a){
    int i;
    for(i=sizeof(a)*8-1;i>=0;i--)
        printf("%d",(a>>i)&1);
    printf("\n");
}

uint64_t rotire(uint64_t nr, int n)
{
    int i=0;
    uint64_t m2=0;
    for(i=0;i<n;i++)
    {
        m2= nr & 1;
        nr = nr >> 1;
        nr = nr |(m2 << 63);
    }
    return nr;
}

int main()
{
    uint64_t nr,n;
    printf("Dati un nr care doriti sa fie rotit: ");
    scanf("%ld", &nr);
    printf("Dati nr de rotiri de aplicat: ");
    scanf("%ld", &n);
    if(n<0 || n>64)
        printf("Numarul dat este prea mare sau pre mic\n");
    else
    {
        showBits(nr);
        nr = rotire(nr, n);
        showBits(nr);
    }
    printf("\n");
    return 0;
}
*/
