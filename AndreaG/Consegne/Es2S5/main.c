/*
Nome: Andrea Giulianini
Nome es: Es2S5
Data Inizio:26/10/2016
Data Fine:27/10/2016
*/
#include <stdio.h>
#include <stdlib.h>
//Lo scopo del programma è quello di trovare una data in comune tra le due colleghi, comparerò 2 vettori tra di loro, quando 2 valori combacieranno saranno mandati in output

int main()
{
/*
    puts("Si considera solo un mese composto da 31 giorni\n Basta inserire il numero del giorno libero per fare l'incontro\n Usare i caratteri se si vuole interrompere l'inserimento di date per un collega oppure 0\n (Es:c,c4,0 vanno bene per uscire, 3c non va bene poichè lo considero missclick, prendendo buono il primo numero\n I giorni vanno messi in ordine crescente)");
    int col[31]={0};
    int col1[31]={0};
    int cont=0;
    int cont1=0;
    int check;
    do //Richiesta valori per il primo collega
    {
        puts("Inserire data primo collega");
        check=scanf("%d",&col[cont]); //Creazione variabile di controllo per verificare che i valori siano corretti
        fflush(stdin);
        while(col[cont]>31||col[cont]<0)//Verifica inserimetno se sbagliata cosa fa
        {
            puts("Valore non valido, rinserire:");
            check=scanf("%d",&col[cont]);
            fflush(stdin);
            for(int i=0;i<=30;i++)
            {
                if(col[cont]==col[i])
                {
                    puts("Valore non valido, rinserire:");
                    check=scanf("%d",&col[cont]);
                    fflush(stdin);
                }
            }
        }
        cont++;
    }while(check!=0 && cont<=31 && col[cont-1]!=0);//Altro controllo per verificare che i valori siano conformi
    col[cont-1]=0;

    cont=0;
    do//Richiesta secondo collega analoga a quella di prima
    {
        puts("Inserire data secondo collega");
        check=scanf("%d",&col1[cont]);
        fflush(stdin);
        if(col1[cont]>31||col1[cont]<0)
        {
            puts("Valore non valido, rinserire:");
            check=scanf("%d",&col1[cont]);
            fflush(stdin);
        }
        for(int i=0;i<=30;i++)
            {
                if(col1[cont]==col1[i])
                {
                    puts("Valore non valido, rinserire:");
                    check=scanf("%d",&col[cont]);
                    fflush(stdin);
                }
            }
        cont++;
    }while((check!=0) && cont<=31&& col1[cont-1]!=0);
    col1[cont-1]=0;

    puts("Date disponibili:\n"); //Lo scopo dei cicli è quello di confrontare i due vettori per intero
    for (cont=0; cont<=30; cont++)//Con questo for mi sposto per le date del primo collega
        {
            for (cont1=0; cont1<=30; cont1++)//Con questo per le date del secondo
            {
                if(col[cont]==col1[cont1]&&col[cont]!=0)
                {
                    printf("%d\t",col[cont]);
                }
            }
        }
*/
    int collega[31];
    int collega1[31];

    return 0;
}
