/*
 * Autore: Nicolas Farabegoli
 * Data creazione: 24/10/2016
 * Data ultima modifica: 27/10/2016
 * Versione: 1.0.3
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

//Descrizione progetto
/*
Scrivere un programma C che, preso in ingresso un valore intero n,
ne effettui la conversione nel corrispondente numero binario e lo memorizzi in un vettore.
Se si decide di effettuare limitazioni al valore di ingresso n,
assicurarsi che le stesse siano gestite a livello di programma.
Corredare il programma degli opportuni commenti.
*/

int main()
{
    //Dichiarazioni variabili
    int inputDecimal = 0;
    int arrayBinary[16] = {0};
    int contSize = 0;
    char restart = 'Y';
    int controllo;
    unsigned int twoComplements = 0;

    do
    {
        //Azzero variabili per il ciclo successivo
        inputDecimal = 0;
        contSize = 0;
        system("cls"); //Pulisco la console
        printf("===================================\n");
        printf("|  Convertitore Decimale-Binario  |\n");
        printf("===================================\n\n");
        printf("Inserisci un numero decimale intero 0 - 65535 (negativi da -32768 - 0): ");
        fflush(stdin); //Pulisco il buffer di tastiera
        controllo = scanf("%d", &inputDecimal); //Acquisisco il dato decimale
        printf("\n");

        //Controllo il data entery del dato che non deve > 65535, ne < -32768
        if(inputDecimal > 65535 || inputDecimal < -32768)
        {
            printf("Hai inserito un numero non consentito\n");
            //Mostro il messaggio per 2 secondi poi viene rieseguito il ciclo
            Sleep(2000);
        }
        //Controllo se la scanf ha acquisisto un carattere non valido
        else if(controllo == 0)
        {
            printf("Hai inserito una lettera o un carattere speciale\n");
            //Mostro il messaggio per 2 secondi poi viene rieseguito il ciclo
            Sleep(2000);
        }
        else if(inputDecimal < 0)
        {
            //Eseguo il calcolo per il complemento a 2
            /*
                Il complemento a 2 di un numero può essere calcolato prendendo il modulo del numero,
                negare tutti i bit e successivamente sommare 1. Questa è una alternativa di calcolo
                rspetto a quella vista a lezione.
            */
            printf("Numero rappresentato in complemento a 2\n");
            //Calcolo il modulo del numero moltiplicando per -1
            twoComplements = inputDecimal * -1;
            //Nego tutti i bit con l'operatore ~ e poi sommo 1
            twoComplements = (~twoComplements) + 1;
            //Eseguo il calcolo per la conversione in binario
            while(contSize < 16)
            {
                //Calcolo resto divisione
                arrayBinary[contSize] = twoComplements % 2;
                //Divido il numero
                twoComplements /= 2;
                //Aumento la posizione del vettore
                contSize++;
            }
            printf("Numero binario: ");
            //Stampo il vettore al contrario
            for(int a = contSize - 1 ; a >= 0 ; a--)
            {
                printf("%d", arrayBinary[a]);
            }
            printf("\n\n");

            printf("Per eseguire nuovamente il programma premi Y (qualsiasi tasto per terminare) ");
            fflush(stdin); //Pulisco il buffer di tastiera
            scanf("%c", &restart);
            //Converto in maiuscolo
            restart = toupper(restart);
        }
        else
        {
            //Numero positivo compreso nel range accettabile
            printf("Numero binario: ");

            //Se il numero inserito è 0 non necessito di conversioni
            if (inputDecimal == 0)
            {
                printf("0");
            }

            while(inputDecimal > 0)
            {
                //Calcolo resto divisione
                arrayBinary[contSize] = inputDecimal % 2;
                //Divido il numero per 2
                inputDecimal /= 2;
                //Incremento posizione vettore
                contSize++;
            }
            //Stampo vettore al contrario
            for(int a = contSize - 1 ; a >= 0 ; a--)
            {
                printf("%d", arrayBinary[a]);
            }
            printf("\n\n");

            printf("Per eseguire nuovamente il programma premi Y (qualsiasi tasto per terminare) ");
            fflush(stdin); //Pulisco buffer tastiera
            scanf("%c", &restart);
            //Converto in maiuscolo
            restart = toupper(restart);
        }

    }while(restart == 'Y' || inputDecimal > 65535); //Rincomincio il ciclo se è inserito Y oppure se il numero è > 65535

    return 0;
}
