#include<stdio.h>

/*Se citește un număr întreg n>1. Să se afișeze seria ”1+2+3+4+…+n=s”, unde s=suma(1...n).*/

int main(){
    int n, s=0;
    printf("Introduceti n: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("%d +", i);
        s=s+i;
    }
    printf(" %d = %d", n, s);




    return 0;
}