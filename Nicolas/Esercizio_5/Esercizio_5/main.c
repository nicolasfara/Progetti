/*
 * Autore: Nicolas Farabegoli
 * Data creazione: 19/10/2016
 * Data ultima modifica: 19/10/2016
 * Versione: 1.0.0
 */

//Descrizone progetto

/*
    Scrivere un programma C che, preso in input un valore riga e un valore colonna, stampi a video la tavola pitagorica della moltiplicazione e quella dell’addizione, utilizzando una volta il costrutto for e una volta il costrutto while (quindi sia for che while per la somma, sia for che while per la moltiplicazione). Inserire nel codice il controllo sull’input dell’utente.
 */

#include <stdio.h>

int main()
{
    
    int inputRow = 0;
    int inputColumn = 0;
    int checkRow = 0;
    int checkColumn = 0;
    int cont = 0, cont2 = 0;
    
    printf("Tavola pitagorica somma e moltiplicazione con costrutto while e for per ognuna\n");
    
    printf("Inserisci il numero di righe: ");
    checkRow = scanf("%d", &inputRow);
    printf("Inserisci il numero di righe: ");
    checkColumn = scanf("%d", &inputColumn);
    
    if (!checkRow || !checkColumn)
    {
        printf("Carattere inserito non valido\n");
        return 0;
    }
    
    printf("==============================================================================\n\n");
    printf("Tavola pitagorica moltiplicazione (for)\n");
    for (cont = 1; cont <= inputRow; cont++)
    {
        for (cont2 = 1; cont2 <= inputColumn; cont2++)
        {
            printf("%d\t", cont2*cont);
        }
        
        printf("\n");
    }
    
    printf("\n\n");
    
    printf("Tavola pitagorica moltiplicazione (while)\n");
    cont = 1;
    cont2 = 1;
    while (cont <= inputRow)
    {
        while (cont2 <= inputColumn)
        {
            printf("%d\t", cont2*cont);
            cont2++;
        }
        cont2 = 1;
        cont++;
        printf("\n");
    }
    printf("\n\n");
    
    printf("Tavola pitagorica somma (for)\n");
    for (cont = 0; cont <= inputRow; cont++)
    {
        for (cont2 = 0; cont2 <= inputColumn; cont2++)
        {
            printf("%d\t", cont2+cont);
        }
        
        printf("\n");
    }
    
    printf("\n\n");
    
    printf("Tavola pitagorica somma (while)\n");
    cont = 0;
    cont2 = 0;
    while (cont <= inputRow)
    {
        while (cont2 <= inputColumn)
        {
            printf("%d\t", cont2+cont);
            cont2++;
        }
        cont2 = 0;
        cont++;
        printf("\n");
    }
    printf("\n\n");

    return 0;
}
