#include <stdio.h>
#include <stdint.h>



/*Write a function rightrot(x,n) that returns the value of the integer x rotated
to the right by n positions. */

uint32_t rightrot(uint32_t x, int n) {
    // Get the rightmost n bits
    uint32_t rightmost_n = x & ~(~0u << n);

    // Shift x to the right by n positions
    x = x >> n;

    // Set the leftmost (32 - n) bits to the rightmost_n
    x = x | (rightmost_n << (32 - n));

    return x;
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
    int n;

    printf("Enter x (32 bits): ");
    scanf("%u", &x);

    printf("Enter n: ");
    scanf("%d", &n);

    uint32_t result = rightrot(x, n);

    printf("Result (binary): ");
    print_bit_32(result);

    printf("Result (decimal): %u\n", result);

    return 0;
}
