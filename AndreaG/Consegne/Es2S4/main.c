/*
Nome: Andrea Giulianini
Nome programma: Es2Settimana4
Versione 1.0
Data Inizio: 23/10/2016
Data Fine: 23/10/2016
*/
#include <stdio.h>
#include <stdlib.h>
//Lo scopo del programma è quello di calcolare la media di una classe, preso in input il numero di studenti e chiedendo a ciascuno un voto
int main()
{
    int num_std;//Memorizza il numero di studenti
    int media=0;//Variabile per contenere il valore della media
    int voti[500];//Variabile per memorizzare i varii voli

    printf("Inserire numero studenti: ");
    scanf("%d",&num_std);

    for(int i=0;i<num_std;i++)//Ciclo per chiedere l'inserimento dei voti
    {
        printf("Inserire il voto dello studente %d: ",(i+1));
        scanf("%d",&voti[i]);
        while(voti[i]>10 || voti[i]<0)//Controllo dell'ingresso, solo per voti realistici.
        {
            printf("Voto non accettato, reinserire prego: ");
            scanf("%d",&voti[i]);
        }
        media+=voti[i];//Primo calcolo della media, somma.

    }

    media = (media/num_std);//Parte finale del calcolo della media
    printf("La media è: %d  ",media);
    if(media<6) //Gestione della scritta in base alla media
        printf("Media Insufficente");
    else if(media>=6 && media<7)
        printf("Media Sufficente");
    else if(media>=7 && media<8)
        printf("Media Discreta");
    else if(media>=8 && media<9)
        printf("Media Buona");
    else if(media>=9 && media<=10)
        printf("Media Ottima");

    return 0;
}
