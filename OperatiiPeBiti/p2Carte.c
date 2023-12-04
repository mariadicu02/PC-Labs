#include <stdio.h>
#include <stdint.h>

/*Write a function invert(x,p,n) that returns x with the n bits that begin at
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
Scrie o functie invert care returneaza x cu cei n biti incepand cu pozitia p inversati adica negati.
*/

uint32_t invert_bits(uint32_t x, int p, int n) {
    // Create a mask with 1s in the inverted positions
    uint32_t mask = ((1u << n) - 1) << p;

    // Invert the selected bits in x using XOR
    return x ^ mask;
}

int main() {
    uint32_t x, result;
    int p, n;

    // Input values
    printf("Enter an integer x: ");
    scanf("%u", &x);

    printf("Enter the starting position p: ");
    scanf("%d", &p);

    printf("Enter the number of bits to invert n: ");
    scanf("%d", &n);

    // Call the invert_bits function
    result = invert_bits(x, p, n);

    // Display the result
    printf("Original number: %u\n", x);
    printf("Result after inverting bits: %u\n", result);

    return 0;
}
