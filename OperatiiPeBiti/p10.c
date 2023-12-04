#include<stdio.h>
#include<stdint.h>

/*Se citește o valoare de tip int. Se cere să se afișeze valoarea bitului de semn. Nu se cunoaște
a priori dimensiunea tipului de date int.*/

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


void sign_bit(uint8_t n){

    uint8_t mask=0x1;
    for(int i=0;i<sizeof(n)*8-1;i++)
    {
        n = n >> 1;
    }

    if(( n & mask) == 0)
    {
        printf("numarul este pozitiv");
    }
    else{
        printf("Numarul este negativ");
    }

}

int main(){

    uint8_t n;
    printf("introduceti numarul: ");
    scanf("%hhd",&n);
    printf("Reprezentarea in binar este: ");
    print_bit_8(n);
    sign_bit(n);

    return 0;
}

/*
deci la asta ar trb in felu urmator:
tre sa shiftez la dreapta cu n-1 pozitii ca sa mi mai ramana doar primu bit din numar
si apoi folosesc o masca ca sa verific valoarea bitului ramas

*/