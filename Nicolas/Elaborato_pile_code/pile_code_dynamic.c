#include "pile_code_dynamic.h"
#include <stdio.h>
#include <stdlib.h>

int initPilaDynamic(TipoPilaDynamic *p) {

    if(initListD(p))
        return 1; //Errore allocazione
    //Tutto ok
    return 0;
}

int pushPilaDynamic(TipoPilaDynamic *p, int elem) {
    if(inHeadD(p, elem))
        return 1;

    //tutto ok
    return 0;
}

int popPilaDynamic(TipoPilaDynamic *p) {
    //Controllo se la lista è vuota
    if(!p->num_elem){
        printf("Pila vuota, nessun elemento da eliminare\n");
        return 1;
    }
    //Stampo il valore eliminato dalla testa
    printf("Elemento in testa eliminato: %d\n", p->vett[0]);
    //Elimino il valore
    delHeadD(p);
    return 0;
}

int emptyPilaDynamic(TipoPilaDynamic p) {
    //Controllo se la pila è vuota
    if(!p.num_elem)
        return 1;

    //Pila non vuota
    return 0;
}

void printPilaDynamic(TipoPilaDynamic p) {
    printf("Pila: ");
    //Stampo la pila
    printListD(p);
}


//------ FUNZIONI PER LE CODE --------//

int initCodaDynamic(TipoCodaDynamic *c) {
    //inizializzo la coda
    if(initListD(c))
        return 1;
    //tutto ok
    return 0;
}

int pushCodaDynamic(TipoCodaDynamic *c, int elem) {
    //Aggiungo in coda
    if(inTailD(c, elem))
        return 1;

    //tutto ok
    return 0;
}

int popCodaDynamic(TipoCodaDynamic *c) {
    //Controllo se la coda è vuota
    if(!c->num_elem) {
        printf("Coda vuota, nessun elemento da eliminare\n");
        return 1;
    }
    //Stampo l'elemento in testa
    printf("Elemento in testa da eliminato: %d\n", c->vett[0]);
    //Elimino l'elemento in testa
    delHeadD(c);
    return 0;
}

int emptyCodaDynamic(TipoCodaDynamic c) {
    //Controllo se la coda è vuota
    if(!c.num_elem)
        return 1;
    //Coda non vuota
    return 0;
}

void printCodaDynamic(TipoCodaDynamic c) {
    printf("Coda: ");
    //Stampo la coda
    printListD(c);
}
