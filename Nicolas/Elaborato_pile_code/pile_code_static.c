#include "pile_code_static.h"
#include <stdio.h>


void initPilaStatic(TipoPilaStatic *p) {
    //Inizializzo il numero degli elementi
    p->num_elem = 0;
}

int pushPilaStatic(TipoPilaStatic *p, int elem) {
    //Aggiungo in testa
    if(inHeadS(p, elem))
        return 1; //Restituico errore se pila piena
    //tutto ok
    return 0;
}

int popPilaStatic(TipoPilaStatic *p) {
    //Controllo se la pila è vuota
    if(!p->num_elem)
        return 1;

    //Eilino dalla testa
    printf("Elemento in testa eliminato: %d\n", p->vett[0]);
    delHeadS(p);
    return 0;
}

int emptyPilaStatic(TipoPilaStatic p) {
    //Controllo se la pila è vuota
    if(!p.num_elem)
        return 1;

    //Lista non vuota
    return 0;
}

void printPilaStatic(TipoPilaStatic p) {
    printf("Pila: ");
    //Stampo la lista
    printListS(p);
}

//-------FUNZIONI PER LE CODE ---------//

void initCodaStatic(TipoCodaStatic *c) {
    //Inizializzo la coda
    c->num_elem = 0;
}

int pushCodaStatic(TipoCodaStatic *c, int elem) {
    //Inserisco in coda
    if(inTailS(c, elem))
        return 1; //Coda piena
    //Tutto ok
    return 0;
}

int popCodaStatic(TipoCodaStatic *c) {
    //Controllo coda vuota
    if(!c->num_elem)
        return 1;
    //Stampo l'elemento in testa
    printf("Elemento in testa eliminato: %d\n", c->vett[0]);
    delHeadS(c); //Elimino elemento in testa
    return 0;
}

int emptyCodaStatic(TipoCodaStatic c) {
    if(!c.num_elem)
        return 1;
    //Coda vuota
    return 0;
}

void printCodaStatic(TipoCodaStatic c) {
    printf("Coda: ");
    //Stampo la lista
    printListS(c);
}
