/*
 * Autore: Nicolas Farabegoli
 * Data creazione: 26/10/2016
 * Data ultima modifica: 26/10/2016
 * Versione: 1.0.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Descrizione progetto
/*
    Due colleghi intendono fissare una riunione,
    pertanto devono identiicare i giorni nei quali
    sono entrambi liberi da impegni.
    A tal scopo, si realizzi un programma C che permetta
    a ciuscuno di immettere le proprie disponibilita',
    e che identifichi i giorni nei quali entrambi sono liberi.
    In particolare, in una prima fase il programma deve
    acquisisre un elenco di numeri interi che indicano i
    giorni del mese in cui essi sono disponibilie nella
    seconda fase il programma deve identificare e
    stampare i giorni in cui entrambi i colleghi sono disponibili.
    Corredare il programma degli opportuni commenti.
*/

int main()
{
    //Dichiarazioni variabili
    int inputDay = 0;
    int primoCollega[31] = {0};
    int secondoCollega[31] = {0};
    int comDays = 0;
    char restart;
    int elemFirst = 0, elemSec = 0;
    int cont1 = 0, cont2 = 0;
    int check;

    do
    {
        system("cls");
        elemFirst = 0;
        elemSec = 0;
        comDays = 0;
        //**********************************************************************************************
        //Acquisiszione giorni per UTENTE 1
        printf("Inserisci i giorni disponibili per questo mese, per terminare inserisci 0 (zero)\n");
        printf("Inserisci i giorni in ordine crescente\n");
        do
        {
            fflush(stdin);
            printf("Inserisci giorno disponibile: ");
            check = scanf("%d", &inputDay);
            //Controllo che il numero inserito non sia negativo o maggiore di 31, oppure la scanf non abbia letto correttamente il valore
            if(inputDay < 0 || inputDay > 31 || check == 0)
            {
                printf("Giorno non corretto, inserisci nuovamente.\n");
                elemFirst--;
            }
            //eseguo l'else if solo se il numero inserito è compreso tra 1 - 31 e diverso da 0
            else if(inputDay != 0 && (inputDay > 0 || inputDay <32))
            {
                //Controllo che il dato inserito non sia già stato inserito oppure sia minore del precedente
                //Controllo anche che elemSec sia > 1 per inserire il primo dato, altrimenti veniva controllato il vettore con indice -1
                //in questo modo controllo a partire dal secondo inserimento
                if(primoCollega[elemFirst - 1] >= inputDay && elemFirst >= 1)
                {
                    printf("Hai inserito un giorno minore di quello precedente, inserisci nuovamente.\n");
                    //Decremento la variabile per non saltare una cella del vettore lasciandola vuota alla porossima esecuzione
                    elemFirst--;
                }
                else
                {
                    //Inserisco il dato nel vettore
                    primoCollega[elemFirst] = inputDay;
                }
            }
            /*Se il numero in input è 0 non deve essere registrato nel vettore,
              ma anche se il controllo sulla scanf è 0;
              di conseguenza non incremento il numero degli elementi*/
            if(inputDay != 0 || check == 0)
                elemFirst++;
        }
        while(inputDay != 0 || check == 0);
        //Fine acquisiszione UTENTE 1
        //**********************************************************************************************

        inputDay = 0;
        check = 0;

        //**********************************************************************************************
        //Acquisiszione giorni per UTENTE 2
        printf("\n\nInserisci i giorni disponibili per questo mese, per terminare inserisci 0 (zero)\n");
        do
        {
            fflush(stdin);
            printf("Inserisci giorno disponibile: ");
            check = scanf("%d", &inputDay);
            //Controllo che il numero inserito non sia negativo o maggiore di 31, oppure la scanf non abbia letto correttamente il valore
            if(inputDay < 0 || inputDay > 31 || check == 0)
            {
                printf("Giorno non corretto, inserisci nuovamente.\n");
                elemSec--;
            }
            //eseguo l'else if solo se il numero inserito è compreso tra 1 - 31 e diverso da 0
            else if(inputDay != 0 && (inputDay > 0 || inputDay <32))
            {
                //Controllo che il dato inserito non sia già stato inserito oppure sia minore del precedente
                //Controllo anche che elemSec sia > 1 per inserire il primo dato, altrimenti veniva controllato il vettore con indice -1
                //in questo modo controllo a partire dal secondo inserimento
                if(secondoCollega[elemSec - 1] >= inputDay && elemSec >= 1)
                {
                    printf("Hai inserito un giorno minore di quello precedente, inserisci nuovamente.\n");
                    //Decremento la variabile per non saltare una cella del vettore lasciandola vuota alla porossima esecuzione
                    elemSec--;
                }
                else
                {
                    //Inserisco il dato nel vettore
                    secondoCollega[elemSec] = inputDay;
                }
            }
            /*Se il numero in input è 0 non deve essere registrato nel vettore,
              ma anche se il controllo sulla scanf è 0;
              di conseguenza non incremento il numero degli elementi*/
            if(inputDay != 0 || check == 0)
                elemSec++;
        }
        while(inputDay != 0 || check == 0); //Ripeto finchè inputDay è divero da 0 e finchè check è 0
        //Fine acquisiszione UTENTE 2
        //**********************************************************************************************

        printf("\n\nGiorni disponibili ad entrambi: ");

        //**********************************************************************************************
        //Controllo giorni disponibili in comune
        for(cont1 = 0; cont1 < elemFirst; cont1++)
        {
            for(cont2 = 0; cont2 < elemSec; cont2++)
            {
                //Controllo se sono presenti elementi in comune
                if(primoCollega[cont1] == secondoCollega[cont2])
                {
                    //Stampo a schermo il giorno in comune
                    printf("%d ", primoCollega[cont1]);
                    comDays++; //Incremento i giorni in comune
                }
            }
        }
        //Se i giorni in comune sono 0, scrivo non sono stati trovati giorni in comune
        if(!comDays)
        {
            printf("Non sono stati trovati giorni in comune\n\n");
        }
        else
        {
            printf("\n\n");
        }
        //Istruzioni per rincominciare l'esecuzione
        printf("Per rincominciare il programma premi Y, per uscire premi un qualsiasi tasto: ");
        fflush(stdin); //Pulisco il buffer tastiera
        scanf("%c", &restart); //Acquisisco il dato
        restart = toupper(restart); //Lo converto in maiuscolo

    }
    while(restart == 'Y'); //Ripeto se il carattere inserito è 'Y'

    return 0;
}
