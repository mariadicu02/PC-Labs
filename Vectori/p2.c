#include<stdio.h>

/*Să se afișeze minimul elementelor din vectorul {7, -5, 4, 3, -9, 2, -8}.*/

int minim_vector(int v[7]){

    int minim = v[0];
    for(int i=0;i<7;i++)
    {
        
        if(v[i] < minim){
            minim = v[i];
        }
    }
    return minim;
}

int main(){

    int v[7] ={7, -5, 4, 3, -9, 2, -8};
    int minim = minim_vector( v );
    printf("Minimul din vector este %d\n", minim);

    return 0;
}