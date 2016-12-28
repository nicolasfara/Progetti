#ifndef PILE_CODE_STATIC_H_INCLUDED
#define PILE_CODE_STATIC_H_INCLUDED

#include "list_static.h"

typedef Static TipoPilaStatic;
typedef Static TipoCodaStatic;

int pushPilaStatic(TipoPilaStatic *p, int elem);
int popPilaStatic(TipoPilaStatic *p);
int emptyPilaStatic(TipoPilaStatic p);
void printPilaStatic(TipoPilaStatic p);
void initPilaStatic(TipoPilaStatic *p);

int pushCodaStatic(TipoCodaStatic *c, int elem);
int popCodaStatic(TipoCodaStatic *c);
int emptyCodaStatic(TipoCodaStatic c);
void printCodaStatic(TipoCodaStatic c);
void initCodaStatic(TipoCodaStatic *c);

#endif
