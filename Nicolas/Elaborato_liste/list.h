#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct _List {
    int val;
    struct _List *next;
}List;

/* Prototipo aggiungi in testa */
int inHead(List **, int);

/* Prototipo aggiungi in coda */
int inTail(List **, int);

/* Prototipo aggiungi dopo un elemento */
int inElem(List **, int, int);

/* Prototipo elimina dalla testa */
int delHead(List **);

/* Prototipo elimina dalla coda */
int delTail(List **);

/* Prototipo elimina un elemento */
int delElem(List **, int);

/* Stampa la lista */
void printList(List *);

/* Elimina l'intera lista */
void delList(List **);

#endif // LIST_H_INCLUDED
