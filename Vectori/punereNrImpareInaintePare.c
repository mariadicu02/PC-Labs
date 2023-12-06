#include<stdio.h>

int main()
{
    int n, v[5];
    int aux;
    printf("n= ");
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%d", &v[i]);
    }

    for(int i=0, j=n-1;i<j; )
    {
        if((v[i] %2 == 0) && (v[j] % 2 != 0))
        {
           
            aux=v[i];
            v[i]=v[j];
            v[j] = aux;
            i++;
            j--;
        }
        else
        if(v[i] % 2 != 0)
        {
            i++;
        }
        else
        if(v[j] % 2 == 0 )
        {
            j--;
        }

    }
    for(int i=0;i<n;i++)
    {
        printf("%d ", v[i]);
    }


    return 0;
}