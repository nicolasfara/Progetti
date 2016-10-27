/*
Nome: Andrea Giulianini
Nome es: Es2S5
Data Inizio:26/10/2016
Data Fine:28/10/2016
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //Libreria per usare la funzione tolower
//Lo scopo del programma è quello di trovare una data in comune tra le due colleghi, comparerò 2 vettori tra di loro, quando 2 valori combacieranno saranno mandati in output

int main()
{
    puts("Inserire solo date in maniera crescente, e solo numeri compresi tra 1 e 31, nel caso non lo faceste il programma gestisce tutto");
    int collega[2][31]={0};
    int i=0;
    char check;
    do//Ciclo per l'inserimento dei valori per il primo collega
    {
        puts("Valori collega uno:");
        scanf("%d",&collega[0][i]);
        fflush(stdin);
        while((collega[0][i]<=0||collega[0][i]>31)&&i>=0&&i<1)//Controllo particolare sul primo valore del vettore di riga 0
        {
            puts("Valori non corretti, rinserire:");
            scanf("%d",&collega[0][i]);
            fflush(stdin);
        }
        while(i>=1&&i<=31&&collega[0][i]<=collega[0][i-1]||(collega[0][i]<=0||collega[0][i]>31))//Controllo generale per tutto il resto del vettore usclusa la prima posizione
        {
            puts("Valori non corretti, rinserire:");
            scanf("%d",&collega[0][i]);
            fflush(stdin);
        }
        fflush(stdin);
        puts("Vuoi andare al prossimo collega?(n o N per rimanere, qualsiasi altro carattere per uscire)");//Richiesta all'utente se vuole passare al collega dopo
        scanf("%c",&check);
        fflush(stdin);
        tolower(check);
        i++;
    }while(i<31 && check == 'n');//Effetivo controllo per uscire

    i=0;
    do//Ciclo per il secondo collega identi a prima
    {
        puts("Valori collega due:");
        scanf("%d",&collega[1][i]);
        fflush(stdin);
        while((collega[1][i]<=0||collega[1][i]>31)&&i>=0&&i<1)
        {
            puts("Valori non corretti, rinserire:");
            scanf("%d",&collega[1][i]);
            fflush(stdin);
        }
        while(i>=1&&i<=31&&collega[1][i]<=collega[1][i-1]||(collega[1][i]<=0||collega[1][i]>31))
        {
            puts("Valori non corretti, rinserire:");
            scanf("%d",&collega[1][i]);
            fflush(stdin);
        }
        fflush(stdin);
        puts("Vuoi andare a verificare le date in comune?(n o N per rimanere, qualsiasi altro carattere per uscire)");
        scanf("%c",&check);
        fflush(stdin);
        tolower(check);
        i++;
    }while(i<31 && check == 'n');


    puts("Date in comune:");
    for(int l=0;l<31;l++)//I due cicli annidati servono per fare il confronto fra i valori del vettore all'suo interno
    {
        for(int k=0;k<31;k++)
        {
            if(collega[0][l]==collega[1][k]&&collega[0][l]!=0)
                printf("%d\n",collega[0][l]);
        }
    }



    return 0;
}
