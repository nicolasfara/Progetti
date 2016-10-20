#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Buttar fuori tutta la tabella ASCII
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



    //Inserire numero per trovare suoi divisori
    int ingresso;
    puts("\nInserire numero:");
    scanf("%d",&ingresso);
    int tmp=ingresso;
    int ris;
    puts("Divisori trovati con while");
    while(tmp!=0)
    {
        ris = ingresso % tmp;
        if(ris==0)
            printf("Un divisore e': %d\n",tmp);
        tmp--;
    }

    puts("Divisori trovati con for");
    for(tmp=ingresso;tmp!=0;tmp--)
    {
        ris = ingresso % tmp;
        if(ris==0)
            printf("Un divisore e': %d\n",tmp);
    }

    puts("Divisori trovati con do-while");
    tmp=ingresso;
    do
    {
        ris = ingresso % tmp;
        if(ris==0)
            printf("Un divisore e': %d\n",tmp);
        tmp--;
    }while(tmp!=0);

    //Capire se un numero è primo
    tmp=ingresso;
    int k=0;
    while(tmp>2)
    {
        if(ingresso%(tmp-1)==0)
        {
            k=1;
        }
        tmp--;
    }
    if(k==1)
        puts("il numeo non e' primo");
    else
        puts("il numero e' primo");


    //Stampare tutti i numeri primi
    puts("Tutti i numeri primi, prima di quello inserito");
    int cont,cont2,h;
    for(cont=2;cont<ingresso;cont++)
    {
        for(cont2=2;cont2<cont;cont2++)
        {
            if((cont%cont2)==0)
                h++;
        }
        if(h==0)
        {
            printf("%d   ",cont);
        }
        h=0;
    }
return 0;
}
