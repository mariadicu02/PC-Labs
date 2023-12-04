#include<stdio.h>
#include<stdint.h>

/*Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
position p set to the rightmost n bits of y, leaving the other bits unchanged.
Deci am de facut o functie care returneaza x cu cu cei n biti care incep la pozitia p setati la valoarea
la valoarea ultimilor n biti din dreapta de tot ai lui y, lasand restul bititlor neschimbati.
*/


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


uint32_t setbits(uint32_t x, int p, int n, uint32_t y) {
    // Construiește o mască pentru extragerea celor n biți din y
    uint32_t mask_y = (1u << n) - 1;

    // Extrage cei n biți din y care trebuie setați în x
    uint32_t bits_from_y = y & mask_y;

    // Construiește o mască pentru setarea celor n biți în x la poziția p
    uint32_t mask_set = mask_y << p;

    // Șterge cei n biți din x la poziția p
    x &= ~mask_set;

    // Setează cei n biți în x la poziția p cu valorile corespunzătoare din y
    x |= bits_from_y << p;

    return x;
}

int main() {
    uint32_t x = 0b110110110110;  // Exemplu: 6 biți, 3 setați
    uint32_t y = 0b101;           // Exemplu: 3 biți, 2 setați
    int p = 5;                     // Poziția de start (0-indexed)
    int n = 3;                     // Numărul de biți de modificat

    printf("x: 0x%x\n", x);
    printf("y: 0x%x\n", y);
    printf("setbits result: 0x%x\n", setbits(x, p, n, y));

    return 0;
}
