#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int r;
    puts("Inserire grandezza stringa");
    scanf("%d",&r);
    fflush(stdin);
    char str[r];
    char str1[r];

    for(int j=0;j<r;j++)
    {
        str[j]=0;
        str1[j]=0;
    }

    puts("Inserire valori stringa uno:");
    str[0] = tolower(scanf("%[^\n]",&str));
    fflush(stdin);

    puts("Inserire valori stringa due:");
    str1[0] = tolower(scanf("%[^\n]",&str1));
    fflush(stdin);

    int l=0;
    for(int i=0;i<r;i++)
    {
        if(str[i]==str1[i])
        {
            l++;
        }
    }
    if(l==r)
    puts("Sono uguali");
    else
    puts("Sono diverse");

    return 0;
}
