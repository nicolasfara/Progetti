//
//  main.c
//  Esercizio1
//
//  Created by Nicolas Farabegoli on 03/10/16.
//  Copyright © 2016 Nicolas Farabegoli. All rights reserved.
//

#include <stdio.h>
#include <limits.h> //file di include per val. Max e Min delle variabili
#include <float.h>  //file include per utilizzare variabili float e sue definizioni

int main()
{
    //Dichiarazioni variabili locali
    unsigned char varUChar = 92;
    char varChar = 'N';
    
    unsigned short varUShort = 29384;   //la scrittura 'unsigned short int' sarebbe ridondante in quanto equivale a 'unsigned short'
    short int varSInt = -7463;          //la scrittura 'signed short int' sarebbe ridondante in quanto equivale a 'short int'
    int varInt = -2394;                 //la scrittura 'signed int' sarebbe ridondante in quanto equivale a 'int'
    unsigned int varUInt = 4830;
    unsigned long varULong = 7483920;   //la scrittura 'unsigned long int' sarebbe ridondante in quanto equivale a 'unsigned long'
    long int varLInt = -575839;         //la scrittura 'signed long int' sarebbe ridondante in quanto equivale a 'long int'
    float varFloat = 73.29382;
    long double varLDuble = 92022.232;
    
    //Variabile per conteggio caratteri funzione printf
    int conteggioCaratteri = 0;
    
    //NB: Tutte le tabulazioni (\t) all'interno dei printf servono ad avere un output ordinato ed incolonnato
    
    
    /*  In questa printf i comandi di conversione utilizzati sono:
     MODIFICATORE: (-) per allineamento a sinistra
     CAMPO MINIMO: campoMinimo 2 in quanto voglio mostrare solo due cifre
     SPECIFICA CONVERSIONE: (d) in quanto è un intero.
     sizeof(..) restituisce un unsigned lond, utilizzo quindi come specificaConversione %lu (Considerazione valida per tutti i printf in cui viene richiamato sizeof(...)    */
    conteggioCaratteri = printf("TIPO VARIABILE: unsigned char \t VALORE VARIABILE: %-2d \t\t\t VAL. MIN: 0 \t\t\t\t\t\t VAL. MAX: %d \t\t\t\t\t\t BYTE OCCUPATI: %lu \t", varUChar, UCHAR_MAX, sizeof(unsigned char));
    
    //Scrivo da quanti caratteri è composto il printf
    printf("Riga da %d caratteri\n", conteggioCaratteri);
    
    
    /*  In questa printf i comandi di conversione utilizzati sono:
     SPECIFICA CONVERSIONE: (c) perché devo solo visualizzare un carattere, gli altri comandi in questo caso non avevano utilità */
    conteggioCaratteri = printf("TIPO VARIABILE: char \t\t\t VALORE VARAIBILE: %c \t\t\t VAL. MIN: %d \t\t\t\t\t VAL. MAX: %d \t\t\t\t\t\t BYTE OCCUPATI: %lu \t", varChar, CHAR_MIN, CHAR_MAX, sizeof(char));
    
    //Scrivo da quanti caratteri è composto il printf
    printf("Riga da %d caratteri\n", conteggioCaratteri);
    
    
    /*  In questo printf i comandi di conversione utilizzati sono:
     MODIFICATORE: (-) allineamento a sinistra.
     CAMPO MINIMO: campoMinimo con valore 5 in quanto voglio mostrare 5 cifre.
     MODIFICATORE LUNGHEZZA: (h) poichè applicata ad uno "short".
     SPECIFICA CONVERSIONE: (d) in quanto il dato è intero   */
    conteggioCaratteri = printf("TIPO VARIABILE: unsigned short \t VALORE VARIABILE: %-5hd \t\t VAL. MIN: 0 \t\t\t\t\t\t VAL. MAX: %d \t\t\t\t\t BYTE OCCUPATI: %lu \t", varUShort, USHRT_MAX, sizeof(unsigned short));
    
    //Scrivo da quanti caratteri è composto il printf
    printf("Riga da %d caratteri\n", conteggioCaratteri);
    
    
    /*  In questo printf i comandi di cnversione utilizzati sono:
     MODIFICATORE: (-) allinemanto a destra.
     CAMPO MINIMO: campoMinimo con valore 4 in qunado voglio mostrare 4 cifre.
     MODIFICATORE LUNGHEZZA: (h) in quanto utilizziamo il qualificatore "short".
     SPECIFICA CONVERSIONE: (d) in quanto voglio mostrare un intero  */
    conteggioCaratteri = printf("TIPO VARIABILE: short int \t\t VALORE VARIABILE: %-4hd \t\t VAL. MIN: %d \t\t\t\t\t VAL. MAX: %d \t\t\t\t\t BYTE OCCUPATI: %lu \t", varSInt, SHRT_MIN, SHRT_MAX, sizeof(short int));
    
    //Scrivo da quanti caratteri è composto il printf
    printf("Riga da %d caratteri\n", conteggioCaratteri);
    
    
    /*  In questo printf i comandi di cnversione utilizzati sono:
     MODIFICATORE: (-) allinemanto a destra.
     CAMPO MINIMO: campoMinimo con valore 4 in qunado voglio mostrare 4 cifre.
     SPECIFICA CONVERSIONE: (d) in quanto voglio mostrare un intero  */
    conteggioCaratteri = printf("TIPO VARIABILE: int \t\t\t VALORE VARIABILE: %-4d \t\t VAL. MIN: %d \t\t\t\t VAL. MAX: %d \t\t\t\t BYTE OCCUPATI: %lu \t", varInt, INT_MIN, INT_MAX, sizeof(int));
    //Scrivo da quanti caratteri è composto il printf
    
    printf("Riga da %d caratteri\n", conteggioCaratteri);
    
    
    /*  In questo printf i comandi di cnversione utilizzati sono:
     MODIFICATORE: (-) allinemanto a destra; (+) rappresentazione del segno anche se valore positivo.
     CAMPO MINIMO: campoMinimo con valore 4 in qunado voglio mostrare 4 cifre.
     SPECIFICA CONVERSIONE: (d) in quanto voglio mostrare un intero; In VAL. MAX utilizzo (u) per indicare un dato unsigned  */
    conteggioCaratteri = printf("TIPO VARIABILE: unsigned int \t VALORE VARIABILE: %-+4d \t\t VAL. MIN: 0 \t\t\t\t\t\t VAL. MAX: %u \t\t\t\t BYTE OCCUPATI: %lu \t", varUInt, UINT_MAX, sizeof(unsigned int));
    
    //Scrivo da quanti caratteri è composto il printf
    printf("Riga da %d caratteri\n", conteggioCaratteri);
    
    
    /*  In questo printf i comandi di cnversione utilizzati sono:
     MODIFICATORE: (-) allinemanto a destra.
     CAMPO MINIMO: campoMinimo con valore 7 in qunado voglio mostrare 7 cifre.
     MODIFICATORE LUNGHEZZA: (l) in quanto utilizziamo il qualificatore "long".
     SPECIFICA CONVERSIONE: (d) in quanto voglio mostrare un intero  */
    conteggioCaratteri = printf("TIPO VARIABILE: unsigned long \t VALORE VARIABILE: %-7ld \t\t VAL. MIN: 0 \t\t\t\t\t\t VAL. MAX: %lu \t BYTE OCCUPATI: %lu \t", varULong, ULONG_MAX, sizeof(unsigned long));
    
    //Scrivo da quanti caratteri è composto il printf
    printf("Riga da %d caratteri\n", conteggioCaratteri);
    
    
    /*  In questo printf i comandi di cnversione utilizzati sono:
     MODIFICATORE: (-) allinemanto a destra.
     CAMPO MINIMO: campoMinimo con valore 6 in qunado voglio mostrare 6 cifre.
     MODIFICATORE LUNGHEZZA: (l) in quanto utilizziamo il qualificatore "long".
     SPECIFICA CONVERSIONE: (d) in quanto voglio mostrare un intero
     Per VAL. MIN si utilizza %ld in quanto il dato è long double; per VAL. MAX si usa %lu per indicare un dato unsigned long*/
    conteggioCaratteri = printf("TIPO VARIABILE: long int \t\t VALORE VARIABILE: %-6ld \t\t VAL. MIN: %ld \t VAL. MAX: %lu \t\t BYTE OCCUPATI: %lu \t", varLInt, LONG_MIN, LONG_MAX, sizeof(long int));
    
    //Scrivo da quanti caratteri è composto il printf
    printf("Riga da %d caratteri\n", conteggioCaratteri);
    
    
    /*  In questo printf i comandi di cnversione utilizzati sono:
     MODIFICATORE: (-) allinemanto a destra.
     CAMPO MINIMO: campoMinimo con valore 6 in qunado voglio mostrare 6 cifre.
     PRECISIONE: precisione con valore 3 quindi 3 cifre all'esponente (in questo caso sono 2) e viene agiunto uno spazio.
     SPECIFICA CONVERSIONE: (f) in quanto voglio mostrare un numero in virgola mobile a singola precisione
     In VAL. MIN e VAL. MAX ho utilizzato la specificaConversione (g) per utilizzare la notazione esponenziale*/
    conteggioCaratteri = printf("TIPO VARIABILE: float \t\t\t VALORE VARIABILE: %-6.3f \t\t VAL. MIN: %g \t\t\t\t VAL. MAX: %g \t\t\t\t BYTE OCCUPATI: %lu \t", varFloat, FLT_MIN, FLT_MAX, sizeof(float));
    
    //Scrivo da quanti caratteri è composto il printf
    printf("Riga da %d caratteri\n", conteggioCaratteri);
    
    
    /*  In questo printf i comandi di cnversione utilizzati sono:
     MODIFICATORE: (-) allinemanto a destra.
     CAMPO MINIMO: campoMinimo con valore 4 in qunado voglio mostrare 4 cifre.
     MODIFICATORE LUNGHEZZA: (L) in quanto utilizziamo il qualificatore "long".
     SPECIFICA CONVERSIONE: (f) in quanto è sotto inteso che è un float
     In VAL. MAX e VAL.MIN ho utilizzato la specificaConversione (Lg) per utilizzare la notazione esponenziale   */
    conteggioCaratteri = printf("TIPO VARIABILE: long double \t VALORE VARIABILE: %-6.3Lf \t VAL. MIN: %Lg \t\t\t VAL. MAX: %Lg \t\t\t BYTE OCCUPATI: %lu \t", varLDuble, LDBL_MIN, LDBL_MAX, sizeof(long double));
    
    //Scrivo da quanti caratteri è composto il printf
    printf("Riga da %d caratteri\n\n", conteggioCaratteri);
    
    //Indico a S.O. che la funzione main è stata eseguita senza errori
    return 0;
}

