/*
 * list_static.c
 *
 *  Created on: 20 dic 2016
 *      Author: nicolasfarabegoli
 */

#include "list_static.h"
#include <stdio.h>
#include <stdlib.h>

int inHeadS(Static *head, int elem) {
	//Controllo se il vettore è pieno
	if(head->num_elem == MAX)
		return 1;
	//Controllo se il vettore è vuoto
	if(!head->num_elem) {
		head->vett[0] = elem;
        head->num_elem++;
		return 0;
	}
	//Shifto il vettore
	for(int i = head->num_elem; i > 0 ; i--) {
		head->vett[i] = head->vett[i - 1];
	}
	//Aggiungo l'elemento in testa
	head->vett[0] = elem;
	head->num_elem++;
	return 0;
}

int inTailS(Static *head, int elem) {

	if(head->num_elem == MAX)
		return 1;

	if(!head->num_elem) {
		head->vett[0] = elem;
        head->num_elem++;
		return 0;
	}

	head->vett[head->num_elem] = elem;
	head->num_elem++;
    
	return 0;
}

int inElemS(Static *head, int find_elem, int elem) {

	if(!head->num_elem){
        printf("Lista vuota, impossibile trovare elemento\n");
        return 1;
    }

	if(head->num_elem == MAX) {
		printf("Vettore pieno, impossibile inserire elemento");
		return 0;
	}

	for(int i = 0; i < head->num_elem; i++) {
		if(head->vett[i] == find_elem) {
			for(int c = head->num_elem; c > i; c--)
				head->vett[c] = head->vett[c - 1];

			head->vett[i + 1] = elem;
			head->num_elem++;
			return 0;
		}
	}

	return 2;
}

int delHeadS(Static *head) {

	if(!head->num_elem)
		return 1;

	for(int i = 0; i < head->num_elem - 1; i++)
		head->vett[i] = head->vett[i + 1];

	head->num_elem--;
	return 0;
}

int delTailS(Static *head) {
	if(!head->num_elem)
		return 1;

	head->num_elem--;
	return 0;
}

int delElemS(Static *head, int elem) {
	if(!head->num_elem)
		return 1;

    if(head->vett[head->num_elem - 1] == elem) {
        head->num_elem--;
        return 0;
    }

	for(int i = 0; i < head->num_elem; i++) {
		if(head->vett[i] == elem) {
			for(int c = i; c < head->num_elem - 1; c++) {
				head->vett[c] = head->vett[c + 1];
			}
			head->num_elem--;
			return 0;
		}
	}

	return 1;
}

void printListS(Static head) {

    printf("Lista: ");
	if(!head.num_elem) {
		printf("Lista vuota\n\n");
		return;
	}

	for(int i = 0; i < head.num_elem; i++)
		printf("%d ", head.vett[i]);

	printf("\n\n");
}
