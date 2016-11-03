#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r,c,somma;
    puts("Inserire numero righe e colonne");
    scanf("%d %d",&r,&c);
    fflush(stdin);
    int matr[r][c];

    for(int l=0;l<r;l++)
    {
        for(int k=0;k<c;k++)
        {
            puts("Inserire valori matrice:");
            scanf("%d",&matr[l][k]);
        }
    }

    somma=0;
    for(int m=0;m<r;m++)
    {
        for(int p=0;p<c;p++)
        {
            somma+=matr[m][p];
        }
        printf("Somma delle righe:%d\n",somma);
        somma=0;
    }

    somma=0;
    for(int m=0;m<r;m++)
    {
        for(int p=0;p<c;p++)
        {
            somma+=matr[p][m];
        }
        printf("Somma delle colonne:%d\n",somma);
        somma=0;
    }


    return 0;
}
