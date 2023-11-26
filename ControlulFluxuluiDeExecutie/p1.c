#include<stdio.h>
/*Se citește un număr întreg n>10. Să se afișeze toată seria de numere începând cu n,
următorul număr fiind obținut prin scăderea din cel anterior a n/10, atâta timp cât n>10.*/

int main(){

    int n;
    printf("Introduceti n: ");
    scanf("%d",&n);
    do
    {
        printf("%d ", n);
        n= n- n/10;
    }while(n>10);



    return 0;
}