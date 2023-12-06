#include<stdio.h>
#include<stdlib.h>

/*Să se citească de la tastatură un număr n<=10 iar apoi n valori de tip int. Să se \
afișeze dacă toate valorile pozitive sunt pare.*/


int main(){

    int n,a;
    printf("Introduceti numarul de valori: ");
    scanf("%d",&n);
    printf("Introdu numerele: \n");
    while(n!=0){

        scanf("%d",&a);
        if(a > 0){
            if(a % 2 != 0){
                printf("NU toate numerele pozitive sunt si pare\n");
                break;
            }
            }
            n--;
        }
        
    printf("DA, toate numerele pozitive sunt pare\n");
    return 0;
}