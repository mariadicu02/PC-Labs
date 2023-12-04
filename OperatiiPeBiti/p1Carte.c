#include<stdio.h>
#include<stdint.h>

/*Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
position p set to the rightmost n bits of y, leaving the other bits unchanged. 
Deci am de facut o functie care returneaza x cu cu cei n biti care incep la pozitia p setati la valoarea
la valoarea ultimilor n biti din dreapta de tot ai lui y, lasand restul bititlor neschimbati.
*/

uint32_t setbits(uint32_t x, int p, int n, uint32_t y) {
    // Create a mask to clear the bits in the specified range
    uint32_t mask = ~(~0u << n) << (p - n + 1);

    // Clear the bits in the specified range in x
    x = x & ~mask;

    // Extract the rightmost n bits from y and position them correctly
    y = (y & ~(~0u << n)) << (p - n + 1);

    // Combine the modified x and y
    return x | y;
}

void print_bit_32(uint32_t nr) {
    uint32_t mask = 0x80000000;
    int n = 0;
    for (int i = 0; i < 32; i++) {
        if ((nr & mask) == 0) {
            printf("0");
        } else {
            printf("1");
        }
        mask = mask >> 1;
        n++;
        if (n % 4 == 0)
            printf(" ");
    }
    printf("\n");
}

int main() {
    uint32_t x, y;
    int p, n;

    printf("Enter x (32 bits): ");
    scanf("%u", &x);

    printf("Enter y (32 bits): ");
    scanf("%u", &y);

    printf("Enter p: ");
    scanf("%d", &p);

    printf("Enter n: ");
    scanf("%d", &n);

    uint32_t result = setbits(x, p, n, y);

    printf("Result (binary): ");
    print_bit_32(result);

    printf("Result (decimal): %u\n", result);
    return 0;
}
