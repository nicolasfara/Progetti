#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct _List {
    int val;
    struct _List *next;
}List;

typedef List *TipoLista;

/* Prototipo aggiungi in testa */
int inHead(TipoLista *, int);

/* Prototipo aggiungi in coda */
int inTail(TipoLista *, int);

/* Prototipo aggiungi dopo un elemento */
int inElem(TipoLista *, int, int);

/* Prototipo elimina dalla testa */
int delHead(TipoLista *);

/* Prototipo elimina dalla coda */
int delTail(TipoLista *);

/* Prototipo elimina un elemento */
int delElem(TipoLista *, int);

/* Stampa la lista */
void printList(TipoLista);

/* Elimina l'intera lista */
void delList(TipoLista *);

#endif // LIST_H_INCLUDED
