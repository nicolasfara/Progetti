#include <stdio.h>
#include <stdlib.h>

int cont;
void calcolo(char);

int main()
{
    char y;

    printf("Domanda1\n");
    scanf("%c",&y);
    fflush(stdin);
    calcolo(y);

    printf("Domanda2\n");
    scanf("%c",&y);
    fflush(stdin);
    calcolo(y);

    printf("Domanda3\n");
    scanf("%c",&y);
    fflush(stdin);
    calcolo(y);

    printf("Punteggio fatto:%d",cont);

    return 0;
}

void calcolo(char y)
{
    if(y=='a'|| y=='A')
        cont++;
    else if(y=='b'|| y=='B')
        cont+=2;
    else if(y=='c'|| y=='C')
        cont+=3;
    else
        cont+=0;
}
