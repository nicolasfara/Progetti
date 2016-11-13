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

#define MAX_INPUT_CHAR 20

void readString(char *inputString, unsigned int elements);

int main()
{
    //Dichiarazioni variabili
    char str[MAX_INPUT_CHAR + 1] = {0};
    char *ptr;

    readString(str, MAX_INPUT_CHAR);

    ptr = &str[0];

    for (unsigned int i = 0; str[i] != '\0'; i++)
    {
        if (!isalpha(ptr[i]))
        {
            ptr = &str[i];
            for (unsigned int c = 0; str[c] != '\0'; c++)
                ptr[c] = ptr[c + 1];
            i--;
        }
    }

    printf("%s\n", str);



    return 0;
}

void readString(char *inputString, unsigned int elements)
{
     printf("Inserisci una parola senza spazi di massimo 30 caratteri: ");

     //Eseguo un acquisizione sicura con la funzione fgets() limitando il numero massimo di caratteri
     if(fgets(inputString, elements, stdin) == NULL)
         printf("Errore, hai inserito un caratterne non valido\n");

     //Ciclo per individuale il carattere \n acquisito da fgets() e lo sotituisco con \0 (terminatore)
     for (unsigned int i = 0; i < strlen(inputString); i++)
         if (inputString[i] == '\n')
             inputString[i] = '\0';


}//END READSTRING
