/*
    Nome file: main.c
    Autore: Nicolas Farabegoli
    Data creazione: 06/10/2016
    Data ultima modifica: 09/10/2016
 */

#include <stdio.h>

//programma che utilizza tutti gli operatori visti a lezione

int main()
{
    //dichiarazione variabili

    int primoOperando = 3;
    int secondoOperando = 2;
    int risultatoIntero = 0;
    float risultatoFloat = 13;
    
    int varID = 0;  //variabile utilizzata per l'incremento e decremento
    
    printf("**** UTILIZZO OPERATORI ARITMETICI ****\n\n");
    
    //Visualizzo valore variabili prima di utilizzare l'operatore
    printf("Somma: valore primoOperando = %d, valore secondoOperando = %d, valore risultatoIntero = %d\n", primoOperando, secondoOperando, risultatoIntero);
    risultatoIntero = primoOperando + secondoOperando; //eseguo calcolo con operatore somma
    //Visualizzo valore variabili dopo operatore di assegnamento
    printf("Somma tra primoOperando e secondoOperando, risultatoIntero = %d\n\n", risultatoIntero);
    
    //Visualizzo valore variabili prima di utilizzare l'operatore
    printf("Differenza: valore primoOperando = %d, valore secondoOperando = %d, valore risultatoIntero = %d\n", primoOperando, secondoOperando, risultatoIntero);
    risultatoIntero = primoOperando - secondoOperando; //eseguo calcolo con operatore differenza
    //Visualizzo valore variabili dopo operatore di assegnamento
    printf("Differenza tra primoOperando e secondoOperando, risultatoIntero = %d\n\n", risultatoIntero);
    
    //Visualizzo valore variabili prima di utilizzare l'operatore
    printf("Moltiplicazione: valore primoOperando = %d, valore secondoOperando = %d, valore risultatoIntero = %d\n", primoOperando, secondoOperando, risultatoIntero);
    risultatoIntero = primoOperando * secondoOperando; //eseguo calcolo con operatore moltiplicazione
    //Visualizzo valore variabili dopo operatore di assegnamento
    printf("Moltiplicazione tra primoOperando e secondoOperando, risultatoIntero = %d\n\n", risultatoIntero);
    
    //Visualizzo valore variabili prima di utilizzare l'operatore
    printf("DIvisione: valore primoOperando = %d, valore secondoOperando = %d, valore risultatoIntero = %d\n", primoOperando, secondoOperando, risultatoIntero);
    risultatoIntero = primoOperando / secondoOperando; //eseguo calcolo con operatore divisione
    //Visualizzo valore variabili dopo operatore di assegnamento
    printf("Divisione tra primoOperando e secondoOperando, risultatoIntero = %d\n\n", risultatoIntero);
    
    //Visualizzo valore variabili prima di utilizzare l'operatore
    printf("Resto divisione: valore primoOperando = %d, valore secondoOperando = %d, valore risultatoIntero = %d\n", primoOperando, secondoOperando, risultatoIntero);
    risultatoIntero = primoOperando % secondoOperando; //eseguo calcolo con operatore modulo
    //Visualizzo valore variabili dopo operatore di assegnamento
    printf("Resto divisione tra primoOperando e secondoOperando, risultatoIntero = %d\n\n", risultatoIntero);
    
    printf("**** UTILIZZO OPERATORI ARITMETICI, NELLA FORMA DI ASSEGNAMENTO COMPOSTO ****\n\n");
    
    risultatoIntero = 20;
    
    //Visualizzo valore variabili prima di utilizzare l'operatore
    printf("Operatore somma: Valore variabile risultatoIntero = %d, valore variabile primoOperando = %d\n", risultatoIntero, primoOperando);
    risultatoIntero += primoOperando; //eseguo il calcolo con operatore somma nella forma di assegnamento composto
    //Visualizzo valore delle variabili dopo l'operatore di assegnamento
    printf("Somma tra risultatoIntero e primoOperando, risultatoIntero = %d\n\n", risultatoIntero);
    
    primoOperando = 5;
    //Visualizzo valore variabili prima di utilizzare l'operatore
    printf("Operatore differenza: Valore variabile risultatoIntero = %d, valore variabile primoOperando = %d\n", risultatoIntero, primoOperando);
    risultatoIntero -= primoOperando; //eseguo il calcolo con operatore differenza nella forma di assegnamento composto
    //Visualizzo valore delle variabili dopo l'operatore di assegnamento
    printf("DIfferenza tra risultatoIntero e primoOperando, risultatoIntero = %d\n\n", risultatoIntero);
    
    primoOperando = 2;
    //Visualizzo valore variabili prima di utilizzare l'operatore
    printf("Operatore moltiplicazione: Valore variabile risultatoIntero = %d, valore variabile primoOperando = %d\n", risultatoIntero, primoOperando);
    risultatoIntero *= primoOperando; //eseguo il calcolo con operatore moltiplicazione nella forma di assegnamento composto
    //Visualizzo valore delle variabili dopo l'operatore di assegnamento
    printf("Moltiplicazione tra risultatoIntero e primoOperando, risultatoIntero = %d\n\n", risultatoIntero);
    
    primoOperando = 5;
    //Visualizzo valore variabili prima di utilizzare l'operatore
    printf("Operatore divisione: Valore variabile risultatoIntero = %d, valore variabile primoOperando = %d\n", risultatoIntero, primoOperando);
    risultatoIntero /= primoOperando; //eseguo il calcolo con operatore divisione (intera) nella forma di assegnamento composto
    //Visualizzo valore delle variabili dopo l'operatore di assegnamento
    printf("Divisione tra risultatoIntero e primoOperando, risultatoIntero = %d\n\n", risultatoIntero);
    
    primoOperando = 7;
    //Visualizzo valore variabili prima di utilizzare l'operatore
    printf("Operatore divisione (float): Valore variabile risultatoIntero = %d, valore variabile primoOperando = %d\n", risultatoIntero, primoOperando);
    //Per ottenre cifre decimali dalla divisione, converto in modo esplicito la variabile primoOperando utilizzando il cast (tipo variabili) nome variabile
    //In questo modo ho convertito la variabile primoOperando da int a float (solo per questa esecuione)
    risultatoFloat /= (float)primoOperando; //eseguo il calcolo con operatore divisione (float) nella forma di assegnamento composto
    //Visualizzo valore delle variabili dopo l'operatore di assegnamento
    printf("Divisione tra risultatoFloat e primoOperando, risultatoFloat = %.3f\n\n", risultatoFloat);
    
    primoOperando = 3;
    //Visualizzo valore variabili prima di utilizzare l'operatore
    printf("Operatore resto divisione: Valore variabile risultatoIntero = %d, valore variabile primoOperando = %d\n", risultatoIntero, primoOperando);
    risultatoIntero %= primoOperando; //eseguo il calcolo con operatore modulo nella forma di assegnamento composto
    //Visualizzo valore delle variabili dopo l'operatore di assegnamento
    printf("Resto divisione tra risultatoIntero e primoOperando, risultatoIntero = %d\n\n", risultatoIntero);
    
    
    printf("**** OPERATORI DI INCREMENTO E DECREMENTO *****\n\n");
    
    //Mostro il valore delle variabili prima dell'operatore
    printf("Valore variabile varID PRIMA di incrementarla: %d\n", varID);
    //Eseguo l'incremento della variabile con notazione prefissa
    ++varID;
    //Mostro il valore delle variabili dopo l'operatore
    printf("Valore variabile varID DOPO l'incremento: %d\t\t(incremento con notazione prefissa)\n\n", varID);
    
    
    //Mostro il valore delle variabili prima dell'operatore
    printf("Valore variabile varID PRIMA di incrementarla: %d\n", varID);
    //Eseguo l'incremento della variabile con notazione postfissa
    varID++;
    //Mostro il valore delle variabili dopo l'operatore
    printf("Valore variabile varID DOPO l'incremento: %d\t\t(incremento con notazione postfissa)\n\n", varID);
    
    
    //Decremento variabili
    
    //Mostro il valore delle variabili prima dell'operatore
    printf("Valore variabile varID PRIMA di decrementarla: %d\n", varID);
    //Eseguo l'incremento della variabile con notazione prefissa
    --varID;
    //Mostro il valore delle variabili dopo l'operatore
    printf("Valore variabile varID DOPO il decremento: %d\t\t(decremento con notazione prefissa)\n\n", varID);
    
    
    //Mostro il valore delle variabili prima dell'operatore
    printf("Valore variabile varID PRIMA di decrementarla: %d\n", varID);
    //Eseguo l'incremento della variabile con notazione postfissa
    varID--;
    //Mostro il valore delle variabili dopo l'operatore
    printf("Valore variabile varID DOPO il decremento: %d\t\t(decremento con notazione postfissa)\n\n", varID);
    
    
    //Incremento e decremento in espressioni
    
    printf("**** OPERATORI DI INCREMENTO E DECREMENTO IN ESPRESSIONI ****\n\n");
    
    varID = 5;  //assegno alle variabile varID il valore 5
    
    //Visualizzo il valore delle variabili prima di eseguire il calcolo
    printf("Valore variabile risultatoIntero = %d, valore varID = %d\n", risultatoIntero, varID);
    risultatoIntero += varID++; //sommo risultatoIntero con varID e il risultato lo memorizzo in risultatoIntero (l'incremento avviene dopo l'operazione)
    //VIsualizzo il valore delle variabili dopo l'esecuzione del calcolo
    printf("Somma tra risultatoIntero e (varID++ = %d), risultatoIntero = %d\t(varID è incrmentata dopo il calcolo)\n\n", varID, risultatoIntero);
    
    //Visualizzo il valore delle variabili prima di eseguire il calcolo
    printf("Valore variabile risultatoIntero = %d, valore varID = %d\t\t(varID vale 6 perchè deriva dall'incremento precedente)\n", risultatoIntero, varID);
    risultatoIntero += ++varID; //sommo risultatoIntero con varID e il risultato lo memorizzo in risultatoIntero (l'incremento avviene prima dell'operazione)
    //VIsualizzo il valore delle variabili dopo l'esecuzione del calcolo
    printf("Somma tra risultatoIntero e (++varID = %d), risultatoIntero = %d\t(varID è incrementata prima del caclolo)\n\n", varID, risultatoIntero);
    
    varID = 5;  //assegno alle variabile varID il valore 5
    
    //Visualizzo il valore delle variabili prima di eseguire il calcolo
    printf("Valore variabile risultatoIntero = %d, valore varID = %d\n", risultatoIntero, varID);
    risultatoIntero += varID--; //sommo risultatoIntero con varID e il risultato lo memorizzo in risultatoIntero (il decremento avviene dopo l'operazione)
    //VIsualizzo il valore delle variabili dopo l'esecuzione del calcolo
    printf("Somma tra risultatoIntero e (varID-- = %d), risultatoIntero = %d\t(varID è decrmentata dopo il calcolo)\n\n", varID, risultatoIntero);
    
    //Visualizzo il valore delle variabili prima di eseguire il calcolo
    printf("Valore variabile risultatoIntero = %d, valore varID = %d\t\t(varID vale 4 perchè deriva dal decremento precedente)\n", risultatoIntero, varID);
    risultatoIntero += --varID; //sommo risultatoIntero con varID e il risultato lo memorizzo in risultatoIntero (il decremento avviene prima dell'operazione)
    //VIsualizzo il valore delle variabili dopo l'esecuzione del calcolo
    printf("Somma tra risultatoIntero e (--varID = %d), risultatoIntero = %d\t(varID è decrementata prima del caclolo)\n\n", varID, risultatoIntero);
    
    
    /*N.B: la visualizzazione della variabile varID alla funzione printf risulta essere sempre incrementata o decrementata,
     la differenza avviene nel calcolo dell'espressione: se utilizzo ++varID questa prima viene incrementata e poi si eseguono gli altri calcoli;
     nel caso opposto varID++ prima esegue il calcolo e poi incrementa la variabile. Richimamndo la funzione printf dopo l'espressione, la variabile
     varID risulterà sempre o incrementata o decrementata.*/
    
    //segnalo al S.O. che il programma è terminato correttamente
    return 0;
}
