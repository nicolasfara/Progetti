/*
 * Autore: Nicolas Farabegoli
 * Data creazione: 21/10/2016
 * Data ultima modifica: 21/10/2016
 * Versione: 1.0.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Descrizione progetto
/*
Scrivere un programma C che, preso in input un valore riga e un valore colonna,
stampi a video la tavola pitagorica della moltiplicazione e quella dell’addizione,
utilizzando una volta il costrutto for e una volta il costrutto while
(quindi sia for che while per la somma, sia for che while per la moltiplicazione).
Inserire nel codice il controllo sull’input dell’utente.
*/

//Define in cui è specificato il numero massimo di colonne e righe
#define MAX_INPUT_ROW 10
#define MAX_INPUT_COLUMN 10


int main()
{
    //Dichiarazioni variabili
    int inputRow = 0;
    int inputColumn = 0;
    char restart;
    int contFor = 0;
    int contWhile = 0;
    int contFor2 = 0;
    int contWhile2 = 0;



    do
    {
        system("cls"); //clear console
        fflush(stdin); //pulisco il buffer
        printf("Tavola pitagorica della somma e della moltiplicazione\n");
        printf("Inserisci numero di colonne (MAX 10): ");
        scanf("%d", &inputColumn); //Acquisisco numero colonne
        fflush(stdin); //pulisco il buffer nel caso prima sia stato inserito un carattere
        printf("Inserisci numero di righe (MAX 10): ");
        scanf("%d", &inputRow); //Acquisisco numero righe
        printf("\n");

        //Controllo Data Entry
        if(inputColumn <= 0 || inputColumn > MAX_INPUT_COLUMN || inputRow <= 0 || inputRow > MAX_INPUT_ROW || isalpha(inputColumn) || isalpha(inputRow))
        {
            printf("Caratteri inseriti non validi\n");
        }
        else
        {
            printf("Tavola pitagorica moltiplicazione (while)\n\n");
            contWhile = 1;
            contWhile2 = 1;
            while(contWhile <= inputColumn)
            {
                while(contWhile2 <= inputRow)
                {
                    printf("%d\t", contWhile * contWhile2); //eseguo il prodotto tra colonna e riga corrente
                    contWhile2++;
                }
                contWhile2 = 1; //Resetto variabile a 1 per il prossimo ciclo
                printf("\n\n");
                contWhile++;
            }
            printf("\n\n");

            //tavola pitagorica somma (while)
            printf("Tavola pitagorica somma (while)\n\n");
            contWhile = 0;
            contWhile2 = 0;
            while(contWhile <= inputColumn)
            {
                while(contWhile2 <= inputRow)
                {
                    printf("%d\t", contWhile + contWhile2); //eseguo somma tra colonna e riga corrente
                    contWhile2++;
                }
                contWhile2 = 0; //Azzero variabile per ciclo successivo
                printf("\n\n");
                contWhile++;
            }
            printf("\n\n");

            printf("Tavola pitagorica moltiplicazione (for)\n\n");
            for(contFor = 1 ; contFor <= inputColumn ; contFor++)
            {
                for(contFor2 = 1 ; contFor2 <= inputRow ; contFor2++)
                {
                    printf("%d\t", contFor * contFor2); //eseguo il prodotto tra colonna e riga corrente
                }
                printf("\n\n");
            }
            printf("\n\n");

            printf("Tavola pitagorica somma (for)\n\n");
            for(contFor = 0 ; contFor <= inputColumn ; contFor++)
            {
                for(contFor2 = 0 ; contFor2 <= inputRow ; contFor2++)
                {
                    printf("%d\t", contFor + contFor2); //eseguo la somma tra colonna e riga corrente
                }
                printf("\n\n");
            }
            printf("\n\n");
        }

        //Lettura per un nuovo ciclo
        printf("Vuoi rincominciare (y/n)? ");
        fflush(stdin); //pulisco il buffer
        scanf("%c", &restart); //Acquisisco il carattere
        restart = toupper(restart); //Lo converto in maiuscolo

    }while(restart == 'Y');

    return 0;
}
