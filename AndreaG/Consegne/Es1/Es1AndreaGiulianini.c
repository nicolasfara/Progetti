/*
    Nome file: main.c
    Nome: Andrea Giulianini
    Creato: 03/10/2016
    Ultima modifica: 08/10/2016
 */
#include <stdio.h>//Usata per includere le funzioni di Input/Output.
#include <limits.h>//Usata per includere i parametri di grandezza di ogni tipo di variabile.
#include <float.h>//Usata per includere i parametri per le variabili float e double.

//Lo scopo del programma è quello di visualizzare ogni caratteristica delle variabili viste a lezione, imparando anche ad usare i qualificatori delle variabili stesse.
int main()
{
//Qui dichiaro tutte le variabili di tipo intero.
   int intero=1; //Dichiaro e inizializzo le variabili.
   short int sIntero=2;
   long int lIntero=3;
   unsigned int uIntero=4;
   unsigned short int usIntero=5;
   unsigned long int ulIntero=6;

   int contoCaratteri = 0;//Uso questa variabile per assegnare il valore di ritorno della funzione printf, che è in particolare un numero che identifica quanti caratteri effetivamente ci sono nell'uotput della funzione

//Mando l'uotput tramite la funzione printf usando tutti i modificatori, mostrando specificatamente per ogni tipo di variabile quanto vale in questo momento, la sua occpupazione di memoria e che range di valori può assumere.
//%d perchè sono interi, il modificatore (-) mi mette l'indentazione a sinistra, modificatore (+) mostra il segno, campo minimo (3) numero caratteri minimo, modificatore (0) mette 0 nei caratteri vuoti, modificatore (h) indica che è uno short.
//sizeof(tipovariabile) mi dice la grandezza in byte del tipo della variabile.
//NB: i vari \t e \n servono per un output più ordinato possibile.
   contoCaratteri = printf("int\t\t\tValore:%-3d\t\t Occupazione memoria: %dbyte\t Valore min: %d\t Valore max: %d\n",intero,sizeof(int),INT_MIN,INT_MAX); //Prendo il valore di ritorno della valore printf facendo un'assegnamento a contoCaratteri
   printf("Numero caratteri printf: %d\n",contoCaratteri);
   contoCaratteri = printf("short int\t\tValore:%+3hd\t\t Occupazione memoria: %dbyte\t Valore min: %d\t\t\t Valore max: %d\n",sIntero,sizeof(short int),SHRT_MIN,SHRT_MAX);
   printf("Numero caratteri printf: %d\n",contoCaratteri);
   contoCaratteri = printf("long int\t\tValore:%03ld\t\t Occupazione memoria: %dbyte\t Valore min: %d\t Valore max: %d\n",lIntero,sizeof(long int),LONG_MIN,LONG_MAX);
   printf("Numero caratteri printf: %d\n",contoCaratteri);
   contoCaratteri = printf("unsigned int\t\tValore:%3d\t\t Occupazione memoria: %dbyte\t Valore: %u\n",uIntero,sizeof(unsigned int),UINT_MAX);
   printf("Numero caratteri printf: %d\n",contoCaratteri);
   contoCaratteri = printf("unsigned short int\tValore:%3hd\t\t Occupazione memoria: %dbyte\t Valore: %u\n",usIntero,sizeof(unsigned short int),USHRT_MAX);
   printf("Numero caratteri printf: %d\n",contoCaratteri);
   contoCaratteri = printf("unsigned long int\tValore:%3ld\t\t Occupazione memoria: %dbyte\t Valore: %u\n",ulIntero,sizeof(unsigned long int),ULONG_MAX);
   printf("Numero caratteri printf: %d\n",contoCaratteri);


//Qui tratto le variabili di tipo char.
   char Carattere='c';
   unsigned char uCarattere='u';
//Mando l'output tramite la funzione printf.
//%c perchè sono char
   contoCaratteri = printf("char\t\t\tValore:%c\t\t Occupazione memoria: %dbyte\t Valore min: %d\t\t\t Valore max: %d\n",Carattere,sizeof(char),CHAR_MIN,CHAR_MAX);
   printf("Numero caratteri printf: %d\n",contoCaratteri);
   contoCaratteri = printf("unsigned char\t\tValore:%c\t\t Occupazione memoria: %ubyte\t Valore: %d\n",uCarattere,sizeof(unsigned char),UCHAR_MAX);
   printf("Numero caratteri printf: %d\n",contoCaratteri);


//Qui tratto le variabili di tipo double (long era l'unico specificato nel testo dell'esercizio, per questo mancano float e double)
   long double lDouble = 1.23;
//Qui mando in output tramite la funzione printf
//Uso %Lg perchè, L sta ad indicare un long(double) e la g perchè mi permette di visualizzare in modo più intelligente il mio double a seconda del numero che gli viene assegnato.
//In particolare sul mio compilatore devo per forza usare %Lg perchè se no in altra maniera non riesco a visualizzare il numero, in più devo fare un richiamo diretto al compilatore tramite __mingw_printf se no non funziona proprio sulla mia macchina.
   contoCaratteri = __mingw_printf("long double\t\tValore:%Lg\t\t Occupazione memoria: %dbyte\t Valore min: %g\t\t\t Valore max: %g\n",lDouble,sizeof(long double),LDBL_MIN,LDBL_MAX);
   printf("Numero caratteri printf: %d\n",contoCaratteri);

   return 0;
}

