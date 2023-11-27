#include<stdio.h>
#include<stdint.h>

/*Scrieţi o funcție care ia ca parametru un întreg fără semn şi returnează numărul de biţi de 1 din reprezentarea sa.*/

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

int main(){

    uint8_t n;
    printf("Introduceti numarul n: ");
    scanf("%hhd",&n);
    printf("Reprezentarea numarului in binar: ");
    print_bit_8(n);
    printf("Numarul de biti de 1 este: %d", nr_biti_1(n));


    return 0;
}