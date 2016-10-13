/*
Andrea Giulianini
Lab1
Versione:1.0
Data Inizio:6/10/2026
Data Ultimo Aggiornamento:6/10/2016
*/
#include <stdio.h> //Include è una Direttiva, esaguita dal precompilatore. Se troviamo i ""
#include <stdlib.h>

#define MINIMO 0  //E' una costante
#define MASSIMO 10
#define PAUSA system("pause") //Non solo numeri nelle costanti ma anche altre righe di codice da riutilizzare dette MACRO

/* Scopriremo solo vivendo lo scopo di questo software*/
int main()
{

    //Impariamo ad usare system
    printf("1\n");
    printf("2\n");
    system("type C:\\Users\\Giulio\\Documents\\C\\Lab1\\main.c");
    printf("3\n");
    printf("4\n");

    //Dichiarazione e Assegnamento
    int a,b;
    const int c = 5; //E' una costante, secondo modo di crearle
    a=6;
    b=12;
    b=a*MASSIMO;
    PAUSA;
    printf("Costante:%d\n",MINIMO);

    //Valore di ritorno printf e scanf
    int num,letti;
    num = printf("Prova caratteri\n");
    printf("Caratteri: %d\n",num);
    num = scanf("%d",&letti); //Mette in num solo i caratteri letti corretamente
    printf("Caratteri letti: %d\n",num);

    //Random grazie a rand() e srand()
    srand(time(NULL));//Serve per far venir casuali i numeri ad ogni esecuzione del programma

    for(int i=0;i<10;i++)
    {
        printf("Numero casuale da 0 a 5: %d\n",rand() % 5+1);
    }

    //Stringhe
    /*
    char stringa[100];
    scanf("%s",&stringa);
    printf("Hai scritto:%s",stringa);*/

    char stringa1[100];
    scanf("%[^\n]",&stringa1); //Il cappello dice quali caratteri escludere, senza diciamo solo quelli da prendere, il - serve ad indicare il range es: %[a-zA-Z0-9]
    printf("Hai scritto:%s",stringa1);

    return 0;
}
