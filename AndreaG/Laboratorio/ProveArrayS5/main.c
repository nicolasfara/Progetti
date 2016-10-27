#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int main()
{
    //Inserimento nel vettore
    int array[MAX]={0};
    for(int i=0;i<MAX;i++)
    {
        scanf("%d",&array[i]);
    }
    //Output vettore
    for(int j=0;j<MAX;j++)
    {
        printf("%d\t",array[j]);
    }

    //Output al contrario
    for(int k=MAX-1; k>=0;k--)
    {
        printf("%d\t",array[k]);
    }


    //Reverse vettore
    puts("\n\n\n\n\n");
    int tmp=0;
    int ch=MAX-1;
    for(int y=0;y<MAX/2;y++)
    {
        tmp = array[y];
        array[y]=array[ch];
        array[ch]=tmp;
        ch--;
    }
    for(int j=0;j<MAX;j++)
    {
        printf("%d\n",array[j]);
    }

    //Trovare il più piccolo
    int min;
    min=array[0];
    for(int l=1;l<MAX;l++)
    {
        if(min>=array[l])
            min=array[l];
    }
    printf("\n%d\n\n\n",min);

    //Riordinarlo in ordine crescente
    int minimo,temporale;

    for(int i=0;i<MAX;i++)
    {
        minimo=i;
        for(int j=i+1;j<MAX;j++)
        {
            if(array[minimo]>array[j])
                minimo=j;
        }
        temporale=array[i];
        array[i]=array[minimo];
        array[minimo]=temporale;
        printf("%d\t",array[i]);
    }



    return 0;
}
