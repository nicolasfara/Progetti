#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;
    int tmp;
    printf("Inserire tre numeri che verranno ordinati in modo crescente\nn");
    scanf("%d %d %d", &a,&b,&c);

    if(a>b)
    {
        tmp=a;
        a = b;
        b =tmp;
    }
    if(a>c)
    {
        tmp=a;
        a = c;
        c =tmp;
    }
    if(b>c)
    {
        tmp=b;
        b= c;
        c =tmp;
    }
    printf("%d %d %d",a,b,c);
    return 0;
}
