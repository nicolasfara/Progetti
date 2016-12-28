/*
 * list_static.h
 *
 *  Created on: 20 dic 2016
 *      Author: nicolasfarabegoli
 */

#ifndef LIST_STATIC_H_INCLUDED
#define LIST_STATIC_H_INCLUDED

#define MAX 5

typedef struct _Static {
	int vett[MAX];
	int num_elem;
}Static;

int inHeadS(Static *, int);
int inTailS(Static *, int);
int inElemS(Static *, int, int);
int delHeadS(Static *);
int delTailS(Static *);
int delElemS(Static *, int);
void printListS(Static);

#endif /* LIST_H_ */
