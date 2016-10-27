/*
Nome: Andrea Giulianini
Nome es: Es1S5
Data Inizio:26/10/2016
Data Fine:26/10/2016
*/
#include <stdio.h>
#include <stdlib.h>
//Lo scopo del programma è quello preso in ingresso un numero intero con base 10 e trasformarlo nel corrispottivo binario
int main()
{
    puts("Inserire un numero intero compreso tra 0 e 255 a base 10 esso verra' convertito in binario\n Se inserito numero con la virgola verra' presa in considerazione solo la parte intera\n I caratteri non vengono presi in considerarione, appena ne viene trovato uno non si considera piu' nulla dopo di esso");
    int l,num;
    l=0;
    num=0;
    int array[8];
    scanf("%d",&num);
    while(num>255||num<0) //Controllo che il numero sia nel range, dato che il controllo lo eseguo su dei tipi int i numeri con la virgola non vengono considerati e dato che leggo con scanf tipi int appena si trova un carattere tutto quello dopo di esso non viene letto
    {
        puts("Valore non accettato, reinserire prego:");
        scanf("%d",&num);
    }
    while(l<8) //Inizio la divisione del numero per 2 per poter prendere il modulo e salvarlo nel vettore
    {
        if((num%2)!=0)
            array[l]=1;
        if((num%2)==0)
            array[l]=0;
        num=(num/2);
        l++;
    }
    for(int j=7;j>=0;j--) //Mostro a video il vettore partendo dall'ultima posizione fino alla prima in modo tale da mostrare correttamente il risultato
    {
        printf("%d",array[j]);
    }
    return 0;
}
