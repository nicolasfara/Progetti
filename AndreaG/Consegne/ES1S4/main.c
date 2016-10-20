/*
Nome: Andrea Giulianini
Versione: 1.1
Data Inizio: 17/10/2016
Data Fine: 17/10/2016
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//Software per creare una tavola pitagorica usando i costrutti for e while, gestendo gli input dagli utenti
int main()
{
    unsigned int righe,colonne; //Inizializzo variabili che mi tonano utili
    colonne=righe=-1; //Faccio questo assegnamento per regolarmi poi con la gestione degli input

    printf("Inserimento 2 numeri interi minori o uguali a 15 divisi con uno spazio: ");
    scanf("%u %u",&righe, &colonne);
    fflush(stdin);

    //Tavola fatto con il for della moltiplicazione e somma
    if(righe>=0 && righe <= 15 && colonne>=0 && colonne<= 15 && colonne != -1 && righe != -1) //Qui gestisco che l'utente non abbia messo parametri sbagliati, scanf si blocca appena incontra qualcosa che non sia un'intero
    {
        unsigned int i, j;//Servono per fare la moltiplicazione tra righe e colonne
        puts("Tavola Pitagorica fatta dal for(moltiplicazione)");
        for (i=1; i <=righe  ; i++)//Con questo for mi sposto per le righe
        {
            for (j=1; j <= colonne ; j++)//Con questo per le colonne
            {
                printf("%u\t", (i*j));
            }
            printf("\n");
        }

        puts("Tavola Pitagorica fatta dal for(somma)");
        for (i=0; i <=righe  ; i++)//La differenze tra la somma e la moltiplicazione di farle partire da 1(moltiplicazione) e 0(somma) è solo per evitare che nella moltiplicazione avvenga una riga e una colonna di soli 0
        {
            for (j=0; j <= colonne ; j++)
            {
                printf("%u\t", (i+j));
            }
            printf("\n");
        }

        puts("Tavola pitagorica con while(moltiplicazione)");
        i = 1;
        while(i <= colonne)//Utilizzo questo while per scorrere nelle colonne
        {
            j = 1;
            while(j <= righe)//Questo per le righe
            { //Utilizziamo la funzione while per la tabella della moltiplicazione.
                printf("%d\t", i * j);
                j++;
            }
            printf("\n");
            i++;
        }

        puts("Tavola pitagorica con while(somma)");
        i = 0;
        while(i <= colonne)
        {
            j = 0;
            while(j <= righe)
            { //Utilizziamo la funzione while per la tabella della somma.
                printf("%d\t", i + j);
                j++;
            }
            printf("\n");
            i++;
        }
    }
    else
    {
        printf("Non hai inserito caratteri validi\n");
    }









    return 0;
}
