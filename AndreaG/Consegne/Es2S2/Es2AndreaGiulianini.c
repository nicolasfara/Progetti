/*
    Nome file: Es2AndreaGiulianini.c
    Nome: Andrea Giulianini
    Data creazione: 09/10/2016
    Data ultima modifica: 09/10/2016
 */

#include <stdio.h> //Libreria standart input/output

int main()
{
    //Dichiarazione variabili

    int pNumero = 6;
    int sNumero = 2;
    int ris = 0;
    float risf = 8.8;

    int var = 0;  //Variabile usata per aiutarci nella dimostrazione dei calcoli

    printf("Utilizziamo Operatori Aritmetici");

    //Variabili prima delle operazioni
    printf("Somma: Primo numero = %d, Secondo numero = %d, Risultato = %d\n", pNumero, sNumero, ris);
    ris = pNumero + sNumero; //Operatore somma
    //Visualizzo valore variabili dopo operatore di assegnamento
    printf("Somma tra primo operando e secondo operando, risultato = %d\n\n", ris);

    //Ripeto il tutto usando tutti gli operatori rimanenti (-,*,/,%)

    printf("Sottrazione: Primo numero = %d, Secondo numero = %d, Risultato = %d\n", pNumero, sNumero, ris);
    ris = pNumero - sNumero;
    printf("Differenza tra il primo operando e secondo operando, risultato = %d\n\n", ris);


    printf("Moltiplicazione: Primo numero = %d, Secondo numero = %d, Risultato = %d\n", pNumero, sNumero, ris);
    ris = pNumero * sNumero;
    printf("Differenza tra il primo operando e secondo operando, risultato = %d\n\n", ris);

    printf("Divisione: Primo numero = %d, Secondo numero = %d, Risultato = %d\n", pNumero, sNumero, ris);
    ris = pNumero / sNumero;
    printf("Divisone tra il primo operando e secondo operando, risultato = %d\n\n", ris);

    printf("Resto della divisione: Primo numero = %d, Secondo numero = %d, Risultato = %d\n", pNumero, sNumero, ris);
    ris = pNumero % sNumero;
    printf("Resto della divisione tra il primo operando e secondo operando, risultato = %d\n\n", ris);

    printf("Assegnamento Composto");

    ris = 15;

    //Vediamo le variabili prima delle operazioni
    printf("Operatore somma: Valore variabile ris = %d, valore variabile pNumero = %d\n", ris, pNumero);
    ris += pNumero; //Somma in assegnamento composto
    //Vediamo le variabili dopo l'assegnamento composto
    printf("Somma tra ris e pNumero, ris = %d\n\n", ris);

    //Ripeto tutto per le altre forme

    pNumero = 5;
    printf("Operatore differenza: Valore variabile ris = %d, valore variabile pNumero = %d\n", ris, pNumero);
    ris -= pNumero;
    printf("Diff tra ris e pNumero, ris = %d\n\n", ris);


    pNumero = 3;
    printf("Operatore moltiplicativo: Valore variabile ris = %d, valore variabile pNumero = %d\n", ris, pNumero);
    ris *= pNumero;
    printf("Moltiplicazione tra ris e pNumero, ris = %d\n\n", ris);


    pNumero = 3;
    printf("Operatore Divisione: Valore variabile ris = %d, valore variabile pNumero = %d\n", ris, pNumero);
    ris /= pNumero;
    printf("Divisione tra ris e pNumero, ris = %d\n\n", ris);

    pNumero = 7;
    printf("Operatore divisione (float): Valore variabile ris = %d, valore variabile pNumero = %d\n", ris, pNumero);
    //Utilizzo il casting per ottenere le cifre decimali nel risultato casting = (TipoVariabile)NomeVariabile
    //In questo modo ho convertito la variabile pNumero da int a float (solo per questa esecuzione)
    risf /= (float)pNumero; //Eseguo il calcolo con operatore divisione (float) nella forma di assegnamento composto
    printf("Divisione tra risf e pNumero, risf = %.3f\n\n", risf);

    pNumero = 3;
    printf("Operatore resto divisione: Valore variabile ris = %d, valore variabile pNumero = %d\n", ris, pNumero);
    ris %= pNumero; //Eseguo il calcolo con operatore modulo nella forma di assegnamento composto
    printf("Resto divisione tra ris e pNumero, ris = %d\n\n", ris);


    printf("Incremento e decremento");

    //Vediamo valore variabile
    printf("Valore variabile var PRIMA di incrementarla: %d\n", var);
    //Incremento con notazione prefissa
    ++var;
    //Mostro variabile dopo incremento
    printf("Valore variabile var DOPO l'incremento: %d\t\t(incremento con notazione prefissa)\n\n", var);
    //Passaggi dopo uguali ma con altri tipi di incremento-decremeto

    printf("Valore variabile var PRIMA di incrementarla: %d\n", var);
    //Incremento con notazione postfissa
    var++;
    printf("Valore variabile var DOPO l'incremento: %d\t\t(incremento con notazione postfissa)\n\n", var);

    printf("Valore variabile var PRIMA di decrementarla: %d\n", var);
    --var;
    printf("Valore variabile var DOPO il decremento: %d\t\t(decremento con notazione prefissa)\n\n", var);

    printf("Valore variabile var PRIMA di decrementarla: %d\n", var);
    var--;
    printf("Valore variabile varID DOPO il decremento: %d\t\t(decremento con notazione postfissa)\n\n", var);


    printf("Espressioni di decremento ed di incremento");

    var = 8;

    //Visualizzo il valore delle variabili prima di eseguire il calcolo
    printf("Valore variabile ris = %d, valore var = %d\n", ris, var);
    ris += var++; //Sommo ris con var e il risultato lo memorizzo in ris, l'incremento di var avviene dopo la fase di assegnamento
    //VIsualizzo il valore delle variabili dopo l'esecuzione del calcolo
    printf("Somma tra ris e (var++ = %d), ris = %d\t(var è incrementata dopo il calcolo)\n\n", var, ris);
    //Poi uguale con gli altri operatori

    printf("Valore variabile ris = %d, valore var = %d\t\t(var vale 9 perchè deriva dall'incremento precedente)\n", ris, var);
    ris += ++var;//Incremento var prima dell'operazione di somma
    printf("Somma tra ris e (++var = %d), ris = %d\t(var è incrementata prima del caclolo)\n\n", var, ris);

    var = 5;

    printf("Valore variabile ris = %d, valore var = %d\n", ris, var);
    ris += var--; //sommo ris con var e il risultato lo memorizzo in ris (il decremento avviene dopo l'operazione)
    printf("Somma tra ris e (var-- = %d), ris = %d\t(var è decrementata dopo il calcolo)\n\n", var, ris);

    printf("Valore variabile ris = %d, valore var = %d\t\t(var vale 7 perchè deriva dal decremento precedente)\n", ris, var);
    ris += --var; //sommo ris con var e il risultato lo memorizzo in ris (il decremento avviene prima dell'operazione)
    printf("Somma tra ris e (--var = %d), ris = %d\t(var è decrementata prima del calcolo)\n\n", var, ris);
    //In poche parole, ++var l'incremento della variabile avviene prima di tutto quello presente nell'espressione, a differenza di var++ dove l'incremento è l'ultima cosa

    printf("Operazioni Relazionali\n\n");

    printf("Confrontiamo 2 numeri in ingresso\n");
    scanf("%f %f", &pNumero, &sNumero);

    //Utilizzo operatori maggiore, minore e uguale
    if (pNumero > sNumero)
    {
        printf("%.2f è maggiore di %.2f\n", pNumero, sNumero);
    }
    else if(pNumero < sNumero)
    {
        printf("%.2f è minore di %.2f\n", pNumero, sNumero);
    }
    else if (pNumero == sNumero)
    {
        printf("%.2f è uguale a %.2f\n", pNumero, sNumero);
    }
    else if (pNumero != sNumero)
    {
        printf("%.2f è diverso da %.2f\n", pNumero, sNumero);
    }

    //operatori con maggiore uguale e minore uguale
    if (pNumero >= sNumero)
    {
        printf("La differenza tra %.2f e %.2f e\' maggiore o uguale a 0, differenza = %.2f\n", pNumero, sNumero, pNumero - sNumero);
    }
    else if (pNumero <= sNumero)
    {
        printf("La differenza tra %.2f e %.2f e\' minore o uguale a 0, differenza = %.2f\n\n", pNumero, sNumero, pNumero - sNumero);
    }


    printf("Operatori Logici\n\n");

    //Equivale a chiedersi se inputPrimo è diverso da 0
    if (!pNumero)
    {
        printf("%.2f è diverso da 0\n", pNumero);
    }

    //Con && (AND logico) si devono verificare entrambe le condizioni per eseguire il body dell'if
    if (!pNumero && !sNumero)
    {
        printf("Sia %.2f che %.2f sono diversi da 0\n", pNumero, sNumero);
    }

    printf("Inserisci due numeri: (prova anche con uno negativo)\n");
    scanf("%f %f", &pNumero, &sNumero);

    //Con || (OR logico) si deve verificare almeno una condizione per eseguire il body dell'if
    if (pNumero < 0 || sNumero < 0)
    {
        printf("Hai inserito almeno un numero negativo\n\n");
    }
    else if (pNumero > 0 || sNumero >0)
    {
        printf("Hai inserito almeno un numero positivo\n\n");
    }

    printf("Operatori Bitwise \n\n");

    ris = pNumero & sNumero;
    printf("AND tra il pNumero e sNumero, = %d\n", ris);

    ris = pNumero | sNumero;
    printf("OR tra il pNumero e sNumero, = %d\n", ris);

    ris = ~ pNumero;
    printf("Complemento a 1 di pNumero, = %d\n", ris);

    ris = pNumero ^ sNumero;
    printf("XOR tra pNumero e sNumero, = %d\n", ris);

    ris = pNumero >> 1;
    printf("Shift a destra di pNumero di 1 posizione, = %d\n", ris);

    ris = pNumero << 1;
    printf("Shift a sinistra di pNumero di 1 posizione, = %d\n\n", ris);

    printf("Operatore Ternario\n\n");

    pNumero > 5 ? printf("pNumero > 5\n\n") : printf("pNumero < 5\n\n");

    //segnalo al S.O. che il programma è terminato correttamente
    return 0;
}
