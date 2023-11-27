#include<stdio.h>
#include<stdint.h>

/*O variabilă de tip char ocupă în memorie 8 biţi. Aceşti 8 biţi pot fi împărţiţi în 2 zone de câte 4 biţi.
În fiecare zonă de câte 4 biţi s-ar putea memora câte un număr între 0 şi 15. Scrieţi un program care
citeşte două numere între 1 şi 10 şi le memorează (împachetează) în cele două zone de câte 4 biţi ale
unei variabile de tip char. După memorare, programul va despacheta valorile memorate şi le va afişa.*/

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

char impachetare(uint8_t a, uint8_t b)
{
    char result;
    result = (a << 4) | b ;
    return result;
}


int main(){

    uint8_t a,b;
    printf("Introduceti numerele intre 1 si 10: \n");
    scanf("%hhd",&a);
    scanf("%hhd",&b);
    printf("Reprezentarea lor pe biti arata in felul urmator: \n");
    print_bit_8(a);
    print_bit_8(b);
    char result= impachetare(a,b);
    printf("dupa impachetare: ");
    print_bit_8(result);
    printf("Pt despachetare: ");
    printf("Am folosit numerele %hhd si %hhd", (result >> 4), (result & 0x0F));

    return 0;
}

/*
0000 0100 tre sa l shiftez la stg cu 4 pozitii => 0100 0000
apoi tre sa fac | (sau) intre a care e shiftat si b adica:
0100 0000 | 0000 0111 => 0100 0111

pt despachetare:
ca sa obtin inapoi a: shiftez result cu 4 la dreapta adica: 0100 0111 >> 4 => 0000 0100
ca sa obtin b: tre sa fac un &  cu o masca care sa nu schimbe ultimii 4 biti adica cu masca 0x0F=0000 1111
daca fac 0100 0111 & 0000 1111 => 0000 0111 adica exact fostul b

*/