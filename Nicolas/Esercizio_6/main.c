/**
 *
 * Autore: Nicolas Farabegoli
 * Data creazione 18/10/2016
 * Data ultima modifica: 21/10/2016
 * Versione: 1.0.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Descrizione
/**

Scrivere un programma C che, preso in input un valore numero_studenti,
permetta l’inserimento da tastiera del voto di ciascuno degli studenti
e ne calcoli la media utilizzando sia il costrutto for che il costrutto while.
Visualizzare poi un commento in base al voto medio della classe come mostrato in tabella:

< 6: MEDIA INSUFFICIENTE

6-7: MEDIA SUFFICIENTE

7-8: MEDIA DISCRETA

8-9: MEDIA BUONA

9-10: MEDIA OTTIMA

Inserire nel codice il controllo sull’input dell’utente.

 */

int main()
{
    //Dichiarazione variabili
    int numeroStudenti = 0;
    float inputVoto = 0;
    float sommaVoti = 0;
    float media = 0;
    int cont = 0;
    char restart;

    do
    {
        //Calcolo media mediante costrutto for
        printf("Calcolo media voti con ciclo for\nInserisci il numero di studenti (MAX 15): ");
        scanf("%d", &numeroStudenti); //Acquisisco il numero di studenti

        //Controllo del Data Entery: controllo che il numero non sia <= 0, maggiore di 15 o un carattere
        if(numeroStudenti <= 0 || numeroStudenti > 15 || isalpha(numeroStudenti))
        {
            printf("Hai inserito un valore o un carattere non valido...\n\n");
        }
        else
        {
            for(cont = 0 ; cont < numeroStudenti ; cont++)
            {
                printf("Inserisci voto: ");
                scanf("%f", &inputVoto); //Acquisisco il voto
                //Controllo il Data Entery: il numero non deve essere <= 0 e maggiore di 30
                if(inputVoto <= 0 || inputVoto > 30)
                {
                    printf("Voto inserito non valido...\n");
                    cont--; //Decremento la variabile per non considerare il dato sbagliato inserito
                }
                else
                {
                    //Data Entery corretto, quindi sommo i voti
                    sommaVoti += inputVoto;
                }
            }
            media = sommaVoti / numeroStudenti; //Calcolo la media
            printf("Media: %.2f\n\n", media);

        }


        //Calcolo della media tramite costrutto for
        printf("Calcolo media voti con ciclo while\nInserisci il numero di studenti (MAX 15): ");
        scanf("%d", &numeroStudenti); //Acquisisco il numero di studenti

        //Controllo del Data Entery: controllo che il numero non sia <= 0, maggiore di 15 o un carattere
        if(numeroStudenti <= 0 || numeroStudenti > 15 || isalpha(numeroStudenti))
        {
            printf("Hai inserito un valore o un carattere non valido...\n\n");
        }
        else
        {
            //Azzero le variabili usate precedentemente
            cont = 0;
            media = 0;
            inputVoto = 0;
            while(cont < numeroStudenti)
            {
                printf("Inserisci voto: ");
                scanf("%f", &inputVoto); //Acquisisco il voto
                //Controllo il Data Entery: il numero non deve essere <= 0 e maggiore di 30
                if(inputVoto <= 0 || inputVoto > 30)
                {
                    printf("Voto inserito non valido...\n");
                    cont--; //Decremento la variabile per non considerare il dato sbagliato inserito
                }
                else
                {
                    //Data Entery corretto, quindi sommo i voti
                    sommaVoti += inputVoto;
                }
                cont++; //Incremento variabile per il ciclo
            }
            media = sommaVoti / numeroStudenti; //Calcolo la media
            printf("Media: %.2f\n\n", media);

        }

        fflush(stdin); //Pulisco il buffer tastiera (non si sa mai)
        printf("Vuoi eseguire nuovamente il programma (y/n)? ");
        scanf("%c", &restart);
        restart = toupper(restart); //Converto la lettera in maiuscolo

    }while(restart == 'Y');

    return 0;
}
