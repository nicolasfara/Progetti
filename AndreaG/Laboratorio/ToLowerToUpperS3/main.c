#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Inserire una lettera maiuscola\n");
    char carattere;
    scanf("%c",&carattere);
    if(carattere >= 65 && carattere <=90)
    {
        carattere += 32;
        printf("Trasformata: %c\n",carattere);
    }

    printf("Inserire una lettera minuscola\n");
    char carattere1;
    fflush(stdin);
    scanf("%c",&carattere1);
    if(carattere1 >= 97 && carattere1 <=122)
    {
        carattere1 -= 32;
        printf("Trasformata: %c",carattere1);
    }




    return 0;
}
