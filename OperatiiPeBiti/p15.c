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

int count_segm(uint8_t n){

    int count = 1;
    int aux;
    aux = n & 1;//ca sa iau mereu ultima cifra din n
    do{
        if ( ( n & 1) != aux)//verific daca actuala ultima cifra e diferita cu fosta ult cifra
        {
            count++;//daca e dif inseamna ca am trecut la alt segm de biti
            aux = n & 1;//reactualizez auxu sa ia din nou ult cifra
        }
        n = n >> 1;
    }while(n != 0);
    count++;
    return count;
}


int main(){

    uint8_t n;
    printf("introduceti numarul: ");
    scanf("%hhd",&n);
    printf("Reprezentarea pe biti a numarului: ");
    print_bit_8(n);
    int result;
    result = count_segm(n);
    printf("Numarul are %d segmente de biti egali\n", result);


    return 0;
}




