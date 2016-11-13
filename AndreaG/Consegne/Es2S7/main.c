/*
Nome: Andrea Giulianini
Es: Es2S7
Data Inizio: 13/11/2016
Data Fine: 13/11/2016
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Es nel quale bisogna ricercare se la seconda stringa compare nella prima e sostituire in output con un * per occorenza
int main()
{
    char str[31]={'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
    char str1[31]={'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};

    int ci,ck,cl,cj,cu;
    int lengthS1,lengthS2;
    int token=0;

    //Gestione input prima stringa
    puts("Inserire due stringhe formate solo da caratteri minuscoli\nLa seconda piu' conrta della prima\nLa lettura da parte programma delle stringhe si ferma ad uno spazio o alla fine dei 30 caratteri\nInserire prima stringa:");
    scanf("%30s",str);
    fflush(stdin);
    for(ci=0;ci<31;ci++)
    {
        if((str[ci]<97 || str[ci]>122)&&str[ci]!='\0'){
            puts("Inseriti caratteri non accetati");
            return 0;
        }
    }

    //Gestione input seconda stringa
    puts("\nInserire seconda stringa:");
    scanf("%30s",str1);
    fflush(stdin);
    for(ci=0;ci<31;ci++)
    {
        if((str1[ci]<97 || str1[ci]>122)&&str1[ci]!='\0'){
            puts("Inseriti caratteri non accetati");
            return 0;
        }
    }

    //Calcolo la lunghezza della prima stringa
    lengthS1=0;
    for(ck=0;ck<31;ck++)
    {
        if(str[ck]!='\0')
            lengthS1++;
    }
    //printf("\nPrima length %d\n",lengthS1);

    //Calcolo lunghezza seconda stringa
    lengthS2=0;
    for(ck=0;ck<31;ck++)
    {
        if(str1[ck]!='\0')
            lengthS2++;
    }
    //printf("Seconda legth %d\n",lengthS2);

    //Gestione input riguardante la lunghezza della seconda stringa rispetto alla prima
    if(lengthS2>lengthS1)
    {
        puts("Seconda stringa piu' grande della prima, non accetato");
        return 0;
    }

    /********* VERSIONE SENZA STRING.H *********/

    //Ciclo per la sostituzione delle occorenze con gli *
    for(cl=0;cl<lengthS1;cl++)
    {
    token=0;//Variabile contatore
       if(str[cl]==str1[0])
       {
           for(cj=0;cj<lengthS2;cj++)//Controllo se dopo la prima lettera uguale anche le altre lo sono
           {
               if(str[cl+cj]==str1[cj])
                token++;
           }
           if(token==lengthS2)//Se tutte le lettere sono uguali dopo la prima
           {
               for(cj=0;cj<lengthS2;cj++)
               {
                    str[cl+cj]='*';//Sostituzione vera e propria
               }
           }
       }
    }

    //Output
    puts("\nVersione senza string.h");
    printf("\n%c",str[0]);
    for(cu=1;cu<lengthS1;cu++)
    {
        if(str[cu-1]!='*')
            printf("%c",str[cu]);
    }

    /********* FINE VERSIONE SENZA STRING.H *********/

    /********* VERSIONE CON STRING.H *********/
    puts("\n\nVersione con string.h");
    char str2[31];
    char str3[31];

    for(cu=0;cu<31;cu++) //Ricopio le stringhe
    {
        str2[cu]=str[cu];
        str3[cu]=str1[cu];
    }

    int *occ;
    while(strstr(str2,str3)!=NULL)
    {
        occ=strstr(str2,str3);
        *occ='*';
        for(;*occ!='\0';)
        {
            occ++;
            *occ=*(occ+strlen(str3)-1);
        }
    }

    printf("\n%c",str2[0]);
    for(cu=1;cu<strlen(str2);cu++)
    {
        if(str[cu-1]!='*')
            printf("%c",str2[cu]);
    }

    /********* FINE VERSIONE CON STRING.H *********/


    return 0;
}
