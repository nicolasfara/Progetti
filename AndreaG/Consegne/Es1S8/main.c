#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=1;
    int *pa;
    pa=&a;
    printf("%d",*pa);

    char b='b';
    char *pb;
    pb=&b;
    printf("\n%c",*pb);

    float c=(1.23);
    float *pc;
    pc=&c;
    printf("\n%f",*pc);

    double d=(1.23456789);
    double *pd;
    pd=&d;
    printf("\n%lf",*pd);

    return 0;
}
