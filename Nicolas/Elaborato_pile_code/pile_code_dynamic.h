#ifndef PILE_CODE_DYNAMIC_H_INCLUDED
#define PILE_CODE_DYNAMIC_H_INCLUDED

#include "list_dynamic.h"

typedef Dynamic TipoPilaDynamic;
typedef Dynamic TipoCodaDynamic;

int initPilaDynamic(TipoPilaDynamic *p);
int pushPilaDynamic(TipoPilaDynamic *p, int elem);
int popPilaDynamic(TipoPilaDynamic *p);
int emptyPilaDynamic(TipoPilaDynamic p);
void printPilaDynamic(TipoPilaDynamic p);

int initCodaDynamic(TipoCodaDynamic *c);
int pushCodaDynamic(TipoCodaDynamic *c, int elem);
int popCodaDynamic(TipoCodaDynamic *c);
int emptyCodaDynamic(TipoCodaDynamic c);
void printCodaDynamic(TipoCodaDynamic c);

#endif
