#include<stdio.h>
#include<stdint.h>

/*Se citește de la tastatură un număr fără semn. Să se seteze biții săi cu indecșii 0,2,3, 
să se reseteze biții cu indecșii 1,5,6 și să se complementeze biții cu indecșii 4,7. Se vor 
afișa în binar atât numărul inițial cât și cel final.*/

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

void setare(uint8_t n){
    uint8_t mask=1;
    n= n | (mask << 0);
    n= n | (mask << 2);
    n= n | (mask << 3);

    print_bit_8(n);
}

void resetare(uint8_t n){
    uint8_t mask =1;
    n= n & ~(mask << 1);
    n= n & ~(mask << 5);
    n= n & ~(mask << 6);

    print_bit_8(n);
}

void complementare(uint8_t n){
    uint8_t mask =1;
    n= n ^ (mask << 4);
    n= n ^ (mask << 7);

    print_bit_8(n);
}


int main(){

    uint8_t n;
    printf("Introduceti numarul: ");
    scanf("%hhd",&n);
    printf("Numarul initial: ");
    print_bit_8(n);
    printf("Numarul dupa setare: ");
    setare(n);
    printf("Numarul dupa resetare: ");
    resetare(n);
    printf("Numarul dupa complementare: ");
    complementare(n);
    

    return 0;
}