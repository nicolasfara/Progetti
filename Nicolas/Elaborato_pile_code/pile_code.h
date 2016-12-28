#ifndef _PILE_CODE_H_INCLUDED
#define _PILE_CODE_H_INCLUDED

#include "list.h"

typedef struct _Pila {
    int val;
    struct _Pila *next;
}Lista;

typedef TipoLista TipoPila; //Serve per poter utilizzare la libreria sulle liste

//=-=-=-= CODE -=-=-=-=-= //

// typedef struct _StructList {
//     int val;
//     struct _StructList *next;
// }StructList;


typedef struct _Coda {
    TipoLista first;
    TipoLista last;
}TipoCoda;


//Funzioni per le pile
void initPila(TipoPila *p);
int isEmptyPila(TipoPila);
int push(TipoPila *p, int elem);
TipoPila pop(TipoPila *p);
void printPila(TipoPila);

//Funzioni per le code
void initCoda(TipoCoda *c);
int isEmptyCoda(TipoCoda c);
int pushCoda(TipoCoda *c, int elem);
TipoLista popCoda(TipoCoda *c);
void printCoda(TipoCoda *c);

#endif
