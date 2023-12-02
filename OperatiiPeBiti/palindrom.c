#include <stdio.h>
#include <stdint.h>

/*scrieti o functie care primeste ca parametru un nr intreg pe 4 bytes si returneaza valoarea 0 daca nr primit
ca parametru este palindrom dpdv a reprezentarii binare respectiv 1 daca numarul nu este palindrom.
in vederea validarii daca numarul este palindrom se vor utiliza operatorii pe biti studiati.*/

void print_bit_32 (uint32_t nr)
{
    uint32_t mask = 0x80000000; // 0b1000000000000000
    uint32_t i = 0;
    int n=0;
    for (i = 0; i < 32; i++)
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

int palindrom(uint32_t num) {
    int left_bit, right_bit;

    for (int i = 0; i < (sizeof(num) * 8) / 2; i++)//parcurg numarul pana la jumatate
    {
        left_bit = (num >> i) & 1;
        right_bit = (num >> ((sizeof(num) * 8 - 1) - i)) & 1;

        if (left_bit != right_bit) {
            return 1;
        }
    }
    return 0;
}

    int main() {
    uint32_t n;
    printf("Introduceti numarul: ");
    scanf("%lu", &n);  // %lu pentru uint32_t
    printf("Reprezentarea pe biti a numarului este: \n");
    print_bit_32(n);
    int result = palindrom(n);

    if (result == 0) {
        printf("Numarul este palindrom\n");
    } else {
        printf("Numarul nu este palindrom\n");
    }
    return 0;
}

