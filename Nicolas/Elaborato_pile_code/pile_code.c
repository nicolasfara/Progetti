#include "pile_code.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>


void initPila(TipoPila *p) {
    //Inizializzo la pila
    *p = NULL;
}

int isEmptyPila(TipoPila p) {
    //ritorno true se è vuota, false se ci sono elementi
    return (p == NULL);
}

int push(TipoPila *p, int elem) {
    //Aggiungo in testa e controllo errore allocazione
    if(inHead(p, elem))
        return 1;
    //Tutto ok
    return 0;
}

TipoPila pop(TipoPila *p) {
    //Controllo se la lista è vuota
    if(isEmptyPila(*p))
        return NULL;
    //Salvo l'elemento in testa in una variabile tmp
    TipoPila tmp = *p;
    //Elimino l'elemento dalla testa
    delHead(p);

    return tmp;
}

void printPila(TipoPila p) {
    printf("Pila: ");
    //Stampo la lista
    printList(p);
}

//Funzioni per le CODE

void initCoda(TipoCoda *c) {
    c->first = NULL;
    c->last = NULL;
}

int isEmptyCoda(TipoCoda c) {
    //Controllo se la coda è vuota
    if(c.first == NULL)
        return 1;
    //Coda piena
    return 0;
}

int pushCoda(TipoCoda *c, int elem) {

    if(isEmptyCoda(*c)){
        c->first = (List *)malloc(sizeof(List));
        if(c->first == NULL)
            return 1;
        c->last = c->first;
    }
    else {
        c->last->next = (List *)malloc(sizeof(List));
        if(c->last->next == NULL)
            return 1;

        c->last = c->last->next;
    }

    c->last->val = elem;
    c->last->next = NULL;
    return 0;
}

TipoLista popCoda(TipoCoda *c) {

    if(isEmptyCoda(*c))
        return NULL;

    TipoLista tmp = c->first;
    delHead(&c->first);
    return tmp;
}

void printCoda(TipoCoda *c) {

     TipoLista tmp;
     TipoCoda appoggio;
     appoggio.first = NULL;
     appoggio.last = NULL;

     printf("Coda: ");

     if(c->first == NULL) {
         printf("Coda vuota\n\n");
         return;
     }

     tmp = popCoda(c);

     while (tmp != NULL) {
         pushCoda(&appoggio, tmp->val);
         printf("%d ", tmp->val);
         tmp = popCoda(c);
     }

     c->first = appoggio.first;
     c->last = appoggio.last;

     printf("\n\n");
}
