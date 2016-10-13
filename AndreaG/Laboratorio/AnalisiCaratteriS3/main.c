#include <stdio.h>
#include <stdlib.h>

int main()
{
    char carattere;
    scanf("%c",&carattere);
    if(carattere>=48 && carattere<=57)
        printf("E' un numero\n");
    else if(carattere=='A'||carattere=='a'||carattere=='E'||carattere=='e'||carattere=='I'||carattere=='i'||carattere=='O'||carattere=='o'||carattere=='U'||carattere=='u')
        printf("E' una vocale");
    else if(carattere>=65 && carattere<=90)
        printf("E' una consonante");
    else if(carattere>=97 && carattere<=122)
        printf("E' una consonante");
    else
        printf("E' qualcos'altro");

    return 0;
}
