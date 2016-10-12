/*
    Nome file: main.c
    Nome: Andrea Giulianini
    Creato: 12/10/2016
    Ultima modifica: 12/10/2016
 */
#include <stdio.h>
#include <stdlib.h>

/*
Scopo:scrivere un programma che chieda all'utente di immettere l'orario di arrivo all'aeroporto (espresso in ore e minuti utilizzando il formato a 24 ore).
Il programma deve visualizzare gli orari di partenza e di arrivo del primo volo che sarà possibile prendere (quello il cui orario di partenza è immediatamente successivo rispetto a quello immesso dall'utente).
*/
int main()
{
    float partenze1[4]={8.00,9.43,11.19,12.47}; //Dichiaro e inizializzo 4 vettori per le partenze e gli ariivi, divisi in modo che la posizione della partenza sia uguale alla posizione dell'arrivo nell'altro vettore
    float partenze2[4]={2.00,3.45,7.00,9.45};
    float arrivi1[4]={10.16,11.52,1.31,3.00};
    float arrivi2[4]={4.08,5.55,9.20,11.58};

    float orario=0; //Variabili per la gestione di alcuni controlli
    int i=0;
    char yn;

    do  //Do-while è un ciclo iterativo che mi permette di poter eseguire un blocco di istruzioni una volta, e rieseguirlo solo se una certa condizione è verificata
    {
        printf("Inserisci orario partenza, dividi le ore dai minuti tramite un .\n");
        fflush(stdin);//Libero il buffer poichè potrei avere problemi se il codice viene rieseguito
        scanf("%[0-9.]",&orario);//Faccio inserire i dati

        if(orario>12)//Con questo if controllo se sono nella zona pm o am
        {
            orario-=12;//Per lavorare in formato 13 ore
            while(i<4)
            {
                if(orario<partenze2[i]) //Controllo per capire quale volo è il successivo
                {
                    printf("Il prossimo volo e' in partenza alle ore:%.2f l'arrivo previsto e' per le ore: %.2f\n",partenze2[i],arrivi2[i]);
                    i=4;
                }
                else //Nel caso il controllo non vada a buon fine, passo all'elemento successivo del vettore per fare di nuovo il controllo
                {
                    i++;
                }
            }
            i=0;
        }
        else
        {
            while(i<4)
            {
                if(orario<partenze1[i])
                {
                    printf("Il prossimo volo e' in partenza alle ore:%.2f l'arrivo previsto e' per le ore: %.2f\n",partenze1[i],arrivi1[i]);
                    i=4;
                }
                else
                {
                    i++;
                }
            }
            i=0;
        }
        printf("Vuoi reiniziare?(y/*): \n");//Richiedo se vuole essere rieseguito il programma
        fflush(stdin);//Libero sempre il buffer per evitare problemi di letture false
        scanf("%c",&yn);

    }while(yn=='y'|| yn=='Y'); //Condizione dell'while

return 0;
}
