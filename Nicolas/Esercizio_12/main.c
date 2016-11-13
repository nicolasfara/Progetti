/*
 * Autore: Nicolas Farabegoli
 * Data creazione: 13/11/2016
 * Data ultima modifica: 13/11/2016
 * Versione: 1.0.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
   Scrivere un programma C che legga una stringa immessa dall'utente
   e la visualizzi dopo aver rimosso dalla stessa tutti gli spazi
   e i segni di punteggiatura. Tutte le operazioni devono usare puntatori.
*/
//Define numero massimo di caratteri della stringa
#define MAX_INPUT_CHAR 20

//Prototipo funzione
void readString(char *inputString, unsigned int elements);

int main()
{
    //Dichiarazioni variabili
    char str[MAX_INPUT_CHAR + 1] = {0};
    char *ptr;  //Puntatore per lo shifting del vettore
    char *posPtr;   //Puntatore per la prima posizione del vettore

    //Acquisisco la stringa
    readString(str, MAX_INPUT_CHAR);
    //Memorizzo la prima posizione del vettore nel puntatore
    posPtr = &str[0];
    //Shifto il vettore se incontro un segno di punteggiatura o uno spazio
    for (unsigned int i = 0; posPtr[i] != '\0'; i++)
        //Se è diverso da un carattere alfabetico
        if (!isalpha(posPtr[i]))
        {
            //registro la posizione del carattere non consentito nel puntatore
            ptr = &str[i];
            //Shifto il vettore
            for (unsigned int c = 0; ptr[c] != '\0'; c++)
                ptr[c] = ptr[c + 1];
            /*Mi riporto nella posizione precedente, serve se shiftando nella
              posizione precedente finisce un carattere non consentito. */
            i--;
        }

    printf("\nStringa senza spazi e punteggiatura: %s\n", str);

    return 0;
}

void readString(char *inputString, unsigned int elements)
{
     printf("Inserisci una parola senza spazi di massimo %d caratteri: ", MAX_INPUT_CHAR);

     //Eseguo un acquisizione sicura con la funzione fgets() limitando il numero massimo di caratteri
     if(fgets(inputString, elements, stdin) == NULL)
         printf("Errore, hai inserito un caratterne non valido\n");

     //Ciclo per individuale il carattere \n acquisito da fgets() e lo sotituisco con \0 (terminatore)
     for (unsigned int i = 0; i < strlen(inputString); i++)
         if (inputString[i] == '\n')
             inputString[i] = '\0';

}//END READSTRING
