#include<stdio.h>
#include<stdint.h>
#include<ctype.h>


#define SIZE 5


/*
maxim 30000 de elem
uint16_t tab[30000];
int read_array_stdin(uint16_t *a, int size);
    if(scanf("%d",&a[i]) != 1)
void print_array(uint16_t *a, int size)
uint16_t max_array(uint16_t *a, int size)
uint16_t min_array(uint16_t *a, int size)
void sort_array()
void double_array()

*/
int read_array_stdin(uint16_t *a, int size){
    int count=0;
    for(int i=0;i<size;i++){
        if(scanf("%hd",(a+i)) == 1)
        {
            count++;
        }
    }
    return count;
}

void print_array(uint16_t *a, int size){
    for(int i=0;i<size;i++)
    {
        printf("a[%d]= %d\n", i, *(a+i));
    }

}

uint16_t max_array(uint16_t *a, int size){
    int maxim;
    maxim = *a;
    for(int i=0;i<=size;i++)
    {
        if(*(a+i) > maxim)
            maxim = *(a+i);
    }
    return maxim;
}

uint16_t min_array(uint16_t *a, int size){
    int minim;
    minim = *a;
    for(int i=0;i<=size;i++)
    {
        if(*(a+i) < minim)
            minim=*(a+i);
    }
    return minim;
}

void sort_array(uint16_t *a, int size)
{
	int s,i,aux;
	do{
		s = 0;
		for (i = 1; i < size; i++)
		{
            	if (*(a+i-1) > *(a+i))
			{
				
				aux = *(a+i-1);
				*(a+i-1) = *(a+i);
				*(a+i) = aux;
				s = 1;
			}
		}
	} while (s);
}

void double_array(uint16_t *a, int size)
{
    for(int i=0;i<2*size;i++){
        for(int j=2*size;j>i;j--)
            {
              *(a+j)=*(a+j-1);
            }

    *(a+i)=*(a+i) * 2;
    size++;
    i++;+
    }
}

int main(){
    uint16_t tab[2*SIZE];
    int count=0;
    count = read_array_stdin(tab, SIZE);
    printf("Nr de elem: %d \n", count);
    print_array(tab, SIZE);
    
    printf("%hd e maximul\n", max_array(tab, count));
    printf("%hd e minimul\n", min_array(tab, SIZE));
    sort_array(tab, SIZE);

    printf("Vectorul sortat: \n");
    print_array(tab, SIZE);
    
    printf("Vectorul dublat: \n");
    double_array(tab, SIZE);
    print_array(tab, SIZE);
    return 0;
}