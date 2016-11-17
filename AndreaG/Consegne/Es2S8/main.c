/*
Nome Prop: Andrea Giulianini
Nome Es: Es2S8
Data Inizio:16/11/2016
Data Fine:17/11/2016
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    //Dichiaro Variabili
    int cont, cont1;
    char *p = (char *)malloc(100*sizeof(char)); //Alloco spazio per il puntatore

    puts("Inserisci frase: ");
    fgets(p,100*sizeof(char),stdin); //Inizializzo puntatore

    puts("\n La tua frase �:\t");

    for(cont=0;*p!='\0';cont++,p++) //Ciclo per spostarmi nel Puntatore
    {
        while(ispunct(*p)||isspace(*p))//Controllo del carattere
        {
            for(cont1=0;*p!='\0';cont1++,p++)//Controllo del dato succesivo
            {
                *p=*(p+1);
            }
            p-=cont1;
        }
    }
    p-=cont;
    printf("%s",p);
    free(p);//De alloco la memoria presa dalla malloc

    return 0;
}
