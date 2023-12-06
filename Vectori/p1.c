#include<stdio.h>
#include<stdint.h>

/*Să se scrie o funcție care ia un număr fără semn n și returnează numărul de segmente de biți
consecutivi egali. Exemplu: 000100 are 3 segmente: 000, 1, 00, deci programul va returna 3*/

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

int nr_segm(uint8_t n){

    int v[8];
    int count = 0;

    for(int i=0;i<8;i++){

        v[i]= n & 1;
        n = n >> 1;
    }

    for(int i = 0; i < 8; i++)
    {
        if(v[i] != v[i+1])
        {
            count ++;
        }
    }

    return count;
}


int main(){

    int n;
    printf("Introduceti n: ");
    scanf("%d",&n);
    printf("Reprezentarea pe biti ai lui n: \n");
    print_bit_8(n);
    int result;
    result = nr_segm(n);
    printf("Numarul de segmente egale este %d\n", result);


    
}


