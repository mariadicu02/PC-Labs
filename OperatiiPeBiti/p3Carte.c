#include <stdio.h>
#include <stdint.h>

/*Write a function rightrot(x,n) that returns the value of the integer x rotated
to the right by n positions. */



uint32_t rightrot(uint32_t x, int n) {
    // Determine the number of bits in an unsigned integer
    int num_bits = sizeof(x) * 8;

    // Make sure n is within the valid range
    n = n % num_bits;

    // Perform the right rotation
    return (x >> n) | (x << (num_bits - n));
}

int main() {
    uint32_t x, result;
    int n;

    // Input values
    printf("Enter an integer x: ");
    scanf("%u", &x);

    printf("Enter the number of positions to rotate right n: ");
    scanf("%d", &n);

    // Call the rightrot function
    result = rightrot(x, n);

    // Display the result
    printf("Original number: %u\n", x);
    printf("Result after right rotation: %u\n", result);

    return 0;
}

