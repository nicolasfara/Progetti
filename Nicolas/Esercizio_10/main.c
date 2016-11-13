/*
 * Autore: Nicolas Farabegoli
 * Data Creazione: 8/11/2016
 * Ultima modifica: 13/11/2016
 * Versione: 1.4.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
Scrivere un programma C che riceva in ingresso due parole inserite da tastiera.
Si consideri che ciascuna parola può contenere al massimo 30 caratteri.
Il programma deve sostituire ogni occorrenza della seconda parola nella prima parola con il carattere ’*’
 */

//PROTOTIPI FUNZIONI
unsigned int lenghtString(char *string);
void readString(char *inputString, unsigned int elements);

int main()
{
    //Dichiarazioni variabili
    char str1[31] = {0};
    char str2[31] = {0};
    char *ptrStr;
    unsigned int cont = 0;

    /******* UTILIZZO FUNZIONI STRING.H ******/

    //Acquisisco le strighe in modo sicuro con funzioni custom
    readString(str1, sizeof(str1));
    fflush(stdin);
    readString(str2, sizeof(str2));

    if (strlen(str1) < strlen(str2))
        printf("La seconda parola e' maggiore della prima, impossibile trovare corrispondenze\n");
    else
    {
        //Cerco corrispondenza della seconda stringa nella prima
        ptrStr = strstr(str1, str2);
        ///Finchè viene trovata corrispondenza cerco dentro la prima stringa
        while (ptrStr != NULL)
        {
            //Sostituisco il primo carattere trovato corrispondente con *
            ptrStr[0] = '*';
            //Shifto il vettore
            for (unsigned int i = 0; i < strlen(str1); i++)
                ptrStr[i + 1] = ptrStr[strlen(str2) + i];
            //Controllo nuovamente se viene trovata corrispondenza
            ptrStr = strstr(str1, str2);
        }
        //Stampo il vettore modificato
        printf("Sostituzione: %s\n", str1);
    }
    /******* FINE UTILIZZO FUNZIONI STRING.H ********/

    printf("Programma senza uso di funzioni <string.h>\n");

    //In questa parte di programma vengono utilizzate solo funzioni create da me che replicano il funzionamento di quelle di <string.h>

    /******* PROGRAMMA SENZA FUNZIONI STRING.H ******/

    readString(str1, sizeof(str1));
    fflush(stdin);
    readString(str2, sizeof(str2));

    if (lenghtString(str1) < lenghtString(str2))
        printf("La seconda parola è maggiore della prima, impossibile trovare corrispondenze\n\n");
    else
    {
        do
        {
            //azzero variabile per ciclo successivo
            cont = 0;
            //Ciclo che scorre tutti i caratteri della prima stringa
            for (unsigned int i = 0; i < lenghtString(str1); i++)
            {
                //Verifico che il primo carattere i-esimo sia uguale al primo di str2
                if(str1[i] == str2[0])
                {
                    //Verifico che anche i successivi sia uguali
                    for (unsigned int c = 1; c < lenghtString(str2) - 1; c++)
                    {
                        if (str1[i + c] == str2[c])
                            cont++; //Incremento variabile se sono uguali
                        else
                            c = lenghtString(str2) + 1; //Altrimenti esco dal for
                    }
                    //Registro nel puntatore l'indirizzo di memoria di str1 nella posizione i-esima
                    ptrStr = &str1[i];
                    //Esco dal for solo se è stata trovata corrispondenza di str2 in str1
                    if (cont == lenghtString(str2) - 2)
                        i = lenghtString(str1) + 1;
                }
            }
            //Se la variabile ci conteggio è uguale al numero di elementi di str2 - 2 poichè il primo elemento era già stato conforntato e non consideriamo il \0
            if (cont == lenghtString(str2) - 2)
            {
                //Inserisco il carattere * al puntatore nella posizione 0 (che a sua volta lo sostituisce in str1)
                ptrStr[0] = '*';
                //Shifto il vettore str1 agendo sul puntatore ptrStr
                for (unsigned int i = 0; i < lenghtString(str1); i++)
                    ptrStr[i + 1] = ptrStr[lenghtString(str2) - 1 + i];
            }

        } while(cont != 0); //Se no viene trovata corrispondenza tra str1 e str2 viene ripetuto il ciclo

        //Stampo il vettore con la sostituzione dell' *
        printf("Sostituzione: %s\n", str1);
    }
    /******* FINE PROGRAMMA SENZA FUNZIONI STRING.H *******/

    return 0;
} //END MAIN


/// @Input: pointer to string
/// @Output: number of elements in to the string (including '\0')
/// @Description: the function return the number of the elements in to the string
unsigned int lenghtString(char *string)
{
    unsigned int lenght = 0;
    //incremento il conteggio fino a che non incontro il terminatore
    while (string[lenght] != '\0')
        lenght++;
    //Ritorno il valore della lunghezza + 1 per conteggiare anche il terminatore
    return lenght + 1;
}//END LENGHTSTRING

/// @Input: puntatore alla stringa, numero di elementi
/// @Output: void
/// @Description: Acquisisce la stringa da stdin in maniera sicura, acquisendo solo lettere per un massimo di caratteri specificati dall'utente
void readString(char *inputString, unsigned int elements)
{
    int pass = 0;
    do
    {
        //Azzero variabile per ciclo successivo
        pass = 0;
        printf("Inserisci una parola senza spazi di massimo 30 caratteri: ");

        //Eseguo un acquisizione sicura con la funzione fgets() limitando il numero massimo di caratteri
        if(fgets(inputString, elements, stdin) == NULL)
            printf("Errore, hai inserito un caratterne non valido\n");

        //Ciclo per individuale il carattere \n acquisito da fgets() e lo sotituisco con \0 (terminatore)
        for (unsigned int i = 0; i < lenghtString(inputString); i++)
            if (inputString[i] == '\n')
                inputString[i] = '\0';

        //Verifico che siano inserite solo lettere
        for (unsigned int set = 0; set < lenghtString(inputString) - 1; set++)
        {
            //Controllo che non vengano inseriti caratteri diversi da lettere
            if (!isalpha(inputString[set]))
            {
                pass++;
                printf("Hai inserito un carattere non valido\n");
                set = lenghtString(inputString) + 1; //esco dal for per non eseguire cicli inutili
            }
        }

    }while(pass > 0);
}//END READSTRING
