/*
 * list_dynamic.h
 *
 *  Created on: 20 dic 2016
 *      Author: nicolasfarabegoli
 */

#ifndef LIST_DYNAMIC_H_INCLUDED
#define LIST_DYNAMIC_H_INCLUDED

#define INIT_ELEM 5

typedef struct _Dynamic {
	int *vett;
	int num_elem;
    int alloc_elem;
}Dynamic;

int initListD(Dynamic *);
int inHeadD(Dynamic *, int);
int inTailD(Dynamic *, int);
int inElemD(Dynamic *, int, int);
int delHeadD(Dynamic *);
int delTailD(Dynamic *);
int delElemD(Dynamic *, int);
void printListD(Dynamic);
void freeListD(Dynamic *);

#endif /* LIST_H_ */
