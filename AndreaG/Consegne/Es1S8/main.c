/*
Nome Prop: Andrea Giulianini
Nome Es: Es1S8
Data Inizio:17/11/2016
Data Fine:17/11/2016
*/
#include <stdio.h>
#include <stdlib.h>



int main()
{
    int a=1; //Dichiaro,Inizializzo Variabile
    int *pa; //Dichiaro Vettore
    pa=&a; //Inizializzo Puntatore
    printf("%d",*pa); //Output

    //Ripeto come prima
    char b='b';
    char *pb;
    pb=&b;
    printf("\n%c",*pb);

    float c=(1.23);
    float *pc;
    pc=&c;
    printf("\n%f",*pc);

    double d=(1.23456789);
    double *pd;
    pd=&d;
    printf("\n%lf",*pd);

    return 0;
}
