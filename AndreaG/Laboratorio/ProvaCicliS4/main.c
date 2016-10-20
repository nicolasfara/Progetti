#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c=0;
    while(c<=255)
    {
        printf("%c",c);
        c++;
    }

    for(int d=0;d<=255;d++)
    {
        printf("%c",d);
    }

    int e=0;
    do
    {
      printf("%c",e);
      e++;
    }while(e<=255);

    return 0;
}
