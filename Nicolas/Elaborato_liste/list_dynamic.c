#include "list_dynamic.h"
#include <stdio.h>
#include <stdlib.h>

int initListD(Dynamic *head) {
    head->vett = (int *)malloc(sizeof(int) * INIT_ELEM);
    //Controllo errori
    if(head->vett == NULL)
        return 1;

    //Inizializzo i campi
    head->num_elem = 0;
    head->alloc_elem = INIT_ELEM;
    //Allocato correttamente
    return 0;
}

int inHeadD(Dynamic *head, int elem) {
    //Controllo se è il primo elemento
    if(!head->num_elem) {
        head->vett[0] = elem;
        head->num_elem++;
        return 0;
    }
    //Controllo se devo riallocare
    if(head->num_elem == head->alloc_elem) {
        //Aggiorno l'allocazione aggiungendo 5 posizioni nel vettore
        head->alloc_elem += 5;
        //Rialloco la memoria
        head->vett = (int *)realloc(head->vett, sizeof(int) * head->alloc_elem);
        if(head->vett == NULL)
            return 1;
    }
    //Shifto il vettore
    for(int i = head->num_elem; i > 0; i--)
        head->vett[i] = head->vett[i - 1];

    head->vett[0] = elem;
    head->num_elem++;
    return 0;
}

int inTailD(Dynamic *head, int elem) {
    //Controllo se il vettore è vuoto, se si aggiungo in testa
    if(!head->num_elem) {
        head->vett[0] = elem;
        head->num_elem++;
        return 0;
    }

    //Controllo se devo riallocare
    if(head->num_elem == head->alloc_elem) {
        //Aumento l'allocazione
        head->alloc_elem += 5;
        //Rialloco il vettore
        head->vett = (int *)realloc(head->vett, sizeof(int) * head->alloc_elem);
        //Contrllo se è stato riallocato correttamente
        if(head->vett == NULL)
            return 1;
    }

    //Aggiungo l'elemento in coda
    head->vett[head->num_elem] = elem;
    head->num_elem++;
    return 0;

}

int inElemD(Dynamic *head, int find_elem, int elem) {
    //Controllo se il vettore è vuoto
    if(!head->num_elem) {
        printf("Impossibile trovare l'elemento\n");
        return 0;
    }

    //Controllo se devo riallocare il vettore
    if(head->num_elem == head->alloc_elem) {
        head->alloc_elem += 5;
        head->vett = (int *)realloc(head->vett, sizeof(int) * head->alloc_elem);
        if(head->vett)
            return 1;
    }

    //Cerco l'elemento
    for(int i = 0; i < head->num_elem; i++) {
        if(head->vett[i] == find_elem) {
            //Shifto il vettore
            for(int c = head->num_elem; c > i; c--)
                head->vett[c] = head->vett[c - 1];
            //Aggiungo dopo l'elemento
            head->vett[i + 1] = elem;
            head->num_elem++;
            return 0;
        }
    }
    //non ho trovato nessun elemento
    return 2;
}

int delHeadD(Dynamic *head) {
    //Controllo se la lista è vuota
    if(!head->num_elem)
        return 1;

    //Shifto il vettore
    for(int i = 0; i < head->num_elem - 1; i++)
        head->vett[i] = head->vett[i + 1];

    //Decremento il numero degli elementi
    head->num_elem--;
    return 0;
}

int delTailD(Dynamic *head) {
    //Controllo se la lista è vuota
    if(!head->num_elem)
        return 1;
    //Decremento il numero degli elementi (quindi elimino l'ultimo elemento)
    head->num_elem--;
    return 0;
}

int delElemD(Dynamic *head, int elem) {
    //Controllo se la lista è vuota
    if(!head->num_elem) {
        printf("Impossibile eliminare l'elemento\n");
        return 0;
    }

    //Controllo se è l'ultimo elemento del vettore
    if(head->vett[head->num_elem - 1] == elem) {
        head->num_elem--;
        return 0;
    }

    for(int i = 0; i < head->num_elem; i++) {
        if(head->vett[i] == elem) {
            for(int c = i; c < head->num_elem - 1; c++)
                head->vett[c] = head->vett[c + 1];

            //Decremento il numero degli elementi
            head->num_elem--;
            return 0;
        }
    }
    //Non ho trovato l'elemento
    return 1;
}

void printListD(Dynamic head) {
    printf("Lista: ");
    //Controllo se la lista è vuota
    if(!head.num_elem) {
        printf("Lista vuota\n\n");
        return;
    }
    //Stampo gli elementi del vettore
    for(int i = 0; i < head.num_elem; i++)
        printf("%d ", head.vett[i]);

    printf("\n\n");
}

void freeListD(Dynamic *head) {
    free(head);
}
