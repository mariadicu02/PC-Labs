#include <stdio.h>
#include <stdint.h>



/*Write a function invert(x,p,n) that returns x with the n bits that begin at
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.*/


uint32_t invert(uint32_t x, int p, int n) {
    // Create a mask with 1s in the inverted range
    uint32_t invert_mask = ~(~0u << n) << (p - n + 1);

    // XOR the inverted bits in the range with x
    return x ^ invert_mask;
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
    uint32_t x;
    int p, n;

    printf("Enter x (32 bits): ");
    scanf("%u", &x);

    printf("Enter p: ");
    scanf("%d", &p);

    printf("Enter n: ");
    scanf("%d", &n);

    uint32_t result = invert(x, p, n);

    printf("Result (binary): ");
    print_bit_32(result);

    printf("Result (decimal): %u\n", result);

    return 0;
}
