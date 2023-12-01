#include<stdio.h>
#include<stdint.h>

/*Un nibble este un grup de 4 biti. Să se scrie un program care primește un număr fără semn n și această funcție
a) returnează valoarea acestui număr cu ordinea inversă a nibble-urilor
b) returnează valoarea acestui număr cu biții din fiecare nibble în ordine inversă*/

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

/*deci aici iterez prin biti, din 4 in 4 ca atat e un nibble*/
void invert_nibble(uint8_t n)
{
    uint8_t n2 = 0;
    for (int i = 0; i < 8; i = i + 4)//de aia aici e i+4
    {
        uint8_t aux = (n >> i) & 0x0F;//aici shiftez cu i pozitii(intai cu 0 apoi cu 4 pozitii, ca sa iau primu sau al 2 lea nibble)
        n2 = n2 | (aux << (4 - i));//dupa ce am luat nibble ul il salvez in variabila n2 pe prima sau pe a doua pozitie
    }
    printf("Inverted nibbles: \n");
    print_bit_8(n2);//apoi returnez numaru
}



void invert_bits(uint8_t n)
{
    uint8_t n2=0;
    for(int i=0;i<8;i=i+4)//parcurg numaru din nibble in nibble
    {
        int aux = n >> i;
        aux = aux & 15;//iau ultimii 4 biti din n sa zicem ca ramane 0000 0101
        {
            int a,b,c,d;
            a = aux & 1;//aici salvez in a fix ultimu bit
            b = aux & 2;//aici salvez penultimu bit
            c = aux & 4;//aici salvez al treilea bit
            d = aux & 8;//aici salvez al 4 lea bit
            a = a << 3;//pun a pe poz 4
            b = b << 1;//b pe poz 3
            c = c >> 1;//c pe poz 2
            d = d >> 3;//d pe poz 1
            aux = aux & 0;
            aux = aux | a;//le salvez pe toate in aux
            aux = aux | b;
            aux = aux | c;
            aux = aux | d;
        }
        n2 = n2 | ( aux << (8-4-i) );
    }
   printf("Inverted bits in nibbles: \n");
   print_bit_8(n2);
}

int main(){

    uint8_t n;
    printf("Introduceti numarul n: ");
    scanf("%hhd",&n);
    printf("Reprezentarea numarului in binar: ");
    print_bit_8(n);
    invert_nibble(n);
    invert_bits(n);

    return 0;
}