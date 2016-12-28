#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/* Inserise il nuovo elemento in testa
    ritorna 1 se l'allocazione � fallita;
    0 se la funzione � terminata con successo */
int inHead(List **head, int elem) {
    List *tmp;
    tmp = (List *)malloc(sizeof(List));
    if(tmp == NULL)
        return 1;

    tmp->next = NULL;
    tmp->val = elem;

    if(*head == NULL) {
        *head = tmp;
        return 0;
    }

    tmp->next = *head;
    *head = tmp;
    return 0;
}

/* Inserisce l'elemento in coda,
    restituisce 1 se l'allocazione fallisce;
    0 se la funzione � terminata con successo */
int inTail(List **head, int elem) {
    List *tmp, *prec = NULL;
    tmp = (List *)malloc(sizeof(List));
    if(tmp == NULL)
        return 1;

    tmp->next = NULL;
    tmp->val = elem;

    if(*head == NULL) {
        *head = tmp;
        return 0;
    }

    prec = *head;
    while(prec->next != NULL)
        prec = prec->next;

    prec->next = tmp;
    return 0;
}

/* Inserisce un nuovo elemento successivamente a quello da ricercare,
    restituisce 1 se l'allocazione fallisce;
    0 se la funzione termina con successo.
    In caso di fallita ricerca, la funzione inserisce il nuovo elemento in coda. */
int inElem(List **head, int find, int elem) {
    List *tmp, *prec = NULL;
    tmp = (List *)malloc(sizeof(List));
    if(tmp == NULL)
        return 1;

    tmp->next = NULL;
    tmp->val = elem;
    prec = *head;

    if(*head == NULL) {
        printf("Impossibile trovare elemento.\n");
        return 0;
    }

    if(prec->val == find) {
        tmp->next = prec->next;
        prec->next = tmp;
        return 0;
    }

    while(prec->next != NULL) {
        if(prec->val == find) {
            tmp->next = prec->next;
            prec->next = tmp;
            return 0;
        }
        prec = prec->next;
    }
    //Controllo se � nell'ultim posizione
    if(prec->val == find) {
        prec->next = tmp;
        return 0;
    }

    //Se arrivo qui non ho trovato l'elemento, quindi aggiungo in coda
    prec->next = tmp;
    printf("Elemento non trovato, aggiungo in coda\n");
    return 0;
}

/* Elimina l'elemento presente in testa alla lista,
    restituisce 1 se la lista � vuota;
    0 se la funzione termina con successo */
int delHead(List **head) {
    //Controllo se la lista � vuota
    if(*head == NULL)
        return 1;

    List *tmp = *head;
    *head = tmp->next;
    free(tmp);
    return 0;
}

/* Elimina dalla coda della l'ista l'ultimo elemento,
    restituisce 1 se la lista � vuota,
    0 se la funzione termina con successo */
int delTail(List **head) {
    //Controllo se la lista � vuota
    if(*head == NULL)
        return 1;

    List *tmp, *prec;
    tmp = *head;
    prec = NULL;

    while(tmp->next != NULL) {
        prec = tmp;
        tmp = tmp->next;
    }

    prec->next = NULL;
    free(tmp);
    return 0;
}

/* Elimina dalla lista l'elemento da cercare,
    restituisce 1 se la lista � vuota oppure se l'elemento non � trovato,
    0 se la funzione temrina correttamente */
int delElem(List **head, int elem) {
    //Controllo se la lista � vuota
    if(*head == NULL)
        return 1;

    List *tmp = *head, *prec = NULL;
    //Controllo se l'elemento � in testa
    if(tmp->val == elem) {
        *head = tmp->next;
        free(tmp);
        return 0;
    }

    while(tmp->next != NULL) {
        if(tmp->val == elem) {
            prec->next = tmp->next;
            free(tmp);
            return 0;
        }
        prec->next = tmp;
        tmp = tmp->next;
    }

    if(tmp->val == elem) {
        prec->next = NULL;
        free(tmp);
        return 0;
    }

    //Se l'elemento non � stato trovato restituisco 1
    return 1;
}

/* Stampa l'intera lista, se vuota stampa messaggio lista vuota */
void printList(List *head) {
    List *tmp;

    tmp = head;

    printf("Lista: ");

    if(head == NULL) {
        printf("Lista vuota\n");
        return;
    }

    while(tmp->next != NULL) {
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }

    printf("%d\n\n", tmp->val);
}

/* Elimina dalla memoria tutte le celle della lista allocate */
void delList(List **head) {

    if(*head == NULL)
        return;

    List *tmp = *head, *prec = NULL;

    if(tmp->next == NULL) {
        free(tmp);
        free(*head);
        return;
    }

    while(tmp->next != NULL) {
        prec = tmp;
        tmp = tmp->next;
        free(prec);
    }

    free(tmp);
    free(*head);

}
