#include <stdio.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    int num = rand() % 10+1;
    int var=0;
    int contatore=0;
    while(var != num)
    {
        printf("Indovina il numeroda 1 a 10: ");
        int check=scanf("%d",&var);
        if(check==0)
        {
            printf("Carattere non valido.\n");
            break;
        }
        if(contatore==2)
        {
            printf("Finiti i tentativi.\n");
            break;
        }
        if(var==num)
        {
            printf("Hai indovinato.\n");
        }
        else
        {
            printf("Non hai indovinato.Ritenta\n");
            contatore++;
        }
    }
    return 0;
}
