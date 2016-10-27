/*
 * Autore: Nicolas Farabegoli
 * Data creazione: 19/10/2016
 * Data ultima modifica: 19/10/2016
 * Versione: 1.0.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Descrizione progetto
/*
 Scrivere un programma C che, preso in input un valore numero_studenti, permetta l’inserimento da tastiera del voto di ciascuno degli studenti e ne calcoli la media utilizzando sia il costrutto for che il costrutto while. Visualizzare poi un commento in base al voto medio della classe come mostrato in tabella:
 
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
    int numero_studenti = 0;
    float sommaVotiFor = 0;
    float sommaVotiWhile = 0;
    int contFor = 0;
    int contWhile = 0;
    float votoInput = 0;
    float media = 0;
    char restart = 'Y';
    
    do
    {
        printf("Calcolo media voti\nInserisci il numero degli studenti: ");
        scanf("%d", &numero_studenti); //Acquisisco il numero degli studenti
        
        //Se numero_studenti è < 0 termia il programma
        if (numero_studenti <= 0)
        {
            printf("Hai inserito un numero non valido\n");
            continue; //salta alla condizione del do... while che alla prima esecuzione risulta vera
            //in quanto restart è inizializzato a 'Y' e quindi viene rieseguito il ciclo.
        }
        
        //CALCOLO MEDIA CON COSTRUTTO FOR
        printf("\nCalcolo media con costrutto for\n");
        for (contFor = 0; contFor < numero_studenti; contFor++)
        {
            printf("Inserisci voto: ");
            scanf("%f", &votoInput); //Acquisico il voto
            if (votoInput > 10 || votoInput <= 0) //controllo che il voto non sia maggiore di 10 o minore di 0
            {
                printf("Voto non valido, inseriscilo nuovamente\n");
                contFor--; //decremento la variabile per poter reinserire il voto
                continue; //salto alla condizione del for non eseguendo le istruzioni successive
            }
            sommaVotiFor += votoInput; //calcolo la somma dei voti
        }
        media = sommaVotiFor / numero_studenti; //calcolo la media
        printf("La media dei voti è %.2f\n\n", media);
        
        //Mostro commento sulla media
        if (media < 6)
            printf("MEDIA INSUFFICIENTE\n\n");
        else if (media >= 6 && media < 7)
            printf("MEDIA SUFFICIENTE\n\n");
        else if (media >= 7 && media < 8)
            printf("MEDIA DISCRETA\n\n");
        else if (media >= 8 && media < 9)
            printf("MEDIA BUONA\n\n");
        else if (media >= 9 && media <= 10)
            printf("MEDIA OTTIMA\n\n");
        
        fpurge(stdin); //pulisco buffer della tastiera
        
        
        //CALCOLO MEDIA CON CONTRUTTO WHILE
        printf("Calcolo media voti con ciclo while\n");
        media = 0; //Riporto a 0 il valore di media per non avere calcolo errato
        while (contWhile < numero_studenti) //eseguo un ciclo pari al numero di voti da inserire
        {
            printf("Inserisci voto: ");
            scanf("%f", &votoInput); //acquisisco il voto
            if (votoInput > 10 || votoInput <= 0) //controllo che il voto non sia maggiore di 10 o minore di 0
            {
                printf("Voto non valido, inseriscilo nuovamente\n");
                continue; //non eseguo le restati istruzioni e salto alla condizione del while per poter inserire nuvamente il voto
            }
            sommaVotiWhile += votoInput; //calcolo la somma totale dei voti
            ++contWhile; //incremento il contatore
        }
        media = sommaVotiWhile / numero_studenti; //calcolo la media
        printf("La media dei voti è: %.2f\n\n", media);
        
        //Scrivo il commento sulla media
        if (media < 6)
            printf("MEDIA INSUFFICIENTE\n\n");
        else if (media >= 6 && media < 7)
            printf("MEDIA SUFFICIENTE\n\n");
        else if (media >= 7 && media < 8)
            printf("MEDIA DISCRETA\n\n");
        else if (media >= 8 && media < 9)
            printf("MEDIA BUONA\n\n");
        else if (media >= 9 && media <= 10) //comprendo anche il 10 come media
            printf("MEDIA OTTIMA\n\n");
        
        fpurge(stdin); //pulisco il buffer della tastiera
        printf("Vuoi calcolare una nuova media (Y/n)? ");
        scanf("%[^\n]", &restart); //Acquisico Y o N
        
        restart = toupper(restart); //converto il carattere in maiuscolo
        
    } while (restart == 'Y'); //Rieseguo il ciclo se l'utente ha inserito Y
    
    
    return 0;
}
