#include <stdio.h>
#include <stdlib.h>
#include "pile_code.h"
#include "pile_code_static.h"
#include "pile_code_dynamic.h"

#ifdef _WIN32   //Ambiente Windows
    #define flush() fflush(stdin)
    #define clear() system("cls")
    #ifdef _WIN64
        #define flush() fflush(stdin)
        #define clear() system("cls")
    #endif

#elif __APPLE__ //Ambiente macOS
    #define flush() fpurge(stdin)
    #define clear() system("clear")

#elif __linux__ //Ambiente Linux
    #include <stdio_ext.h>
    #define flush() __fpurge(stdin)
    #define clear() system("clear")
#endif

void menuPile(void);
void menuPileStrutture(void);
void menuPileStatic(void);
void menuPileDynamic(void);

void menuCode(void);
void menuCodeStrutture(void);
void menuCodeStatic(void);
void menuCodeDynamic(void);

static TipoPila pila;
static TipoCoda coda;
static TipoPilaDynamic pilaDynamic;
static TipoCodaDynamic codaDynamic;
static TipoPilaStatic pilaStatic;
static TipoCodaStatic codaStatic;

int main() {

    int scelta, check;

    //Inizliazzazione delle strutture dati
    initCoda(&coda);
    initPila(&pila);
    initPilaStatic(&pilaStatic);
    initCodaStatic(&codaStatic);
    initPilaDynamic(&pilaDynamic);
    initCodaDynamic(&codaDynamic);

    do {

        do {
            clear();
            printf("Tipi di dato strattto PILA e CODA\n\n");
            printf("[0] PILE\n");
            printf("[1] CODE\n");
            printf("[2] Exit\n");
            printf("\nInserisci scelta: ");
            flush();
            check = scanf("%d", &scelta);
        } while(!check || (scelta < 0 || scelta > 2));

        switch (scelta) {
            case 0:
                menuPile();
                break;

            case 1:
                menuCode();
                break;

            case 2:
                break;
        }

    } while(scelta != 2);

    return 0;
}

void menuPile(void) {
    int check, scelta_menu;
    //Menu per la gestione delle pile
    do {
        clear();
        printf("[0] Pile con strutture collegate\n");
        printf("[1] Pile con array statico\n");
        printf("[2] Pile con array dinamico\n");
        printf("[3] Exit\n");
        flush();
        check = scanf("%d", &scelta_menu);
    } while(!check || (scelta_menu < 0 || scelta_menu > 3));
    //Menù per la scelta delle operazioni da fare
    switch (scelta_menu) {
        case 0:
            menuPileStrutture();
            break;

        case 1:
            menuPileStatic();
            break;

        case 2:
            menuPileDynamic();
            break;

        case 3:
            break;
    }
}

void menuPileStrutture(void) {
    int scelta, check, input;
    TipoPila tmp;

    do {
        //Menu per la scelta delle operazioni
        do {
            clear();
            printf("Pila con strutture collegate\n\n");
            printf("[0] push\n");
            printf("[1] pop\n");
            printf("[2] Exit\n");
            printf("\nInserisci scelta: ");
            flush();
            check = scanf("%d", &scelta);
        } while(!check || (scelta < 0 || scelta > 2));
        //Menu per la gestione delle operazioni
        switch (scelta) {
            case 0:
                clear();
                printf("Inserisci elemento da inserire nella pila: ");
                flush();
                scanf("%d", &input);
                if(push(&pila, input))
                    exit(1);

                printPila(pila);
                printf("Premi un tasto per continuare...");
                flush();
                getchar();
                break;

            case 1:
                clear();
                tmp = pop(&pila);
                //Controllo se la pila è vuota
                if(tmp == NULL)
                    printf("Pila vuota\n");

                printPila(pila);
                printf("premi un tasto per continuare\n");
                flush();
                getchar();
                break;

            case 2:
                break;
        }
    } while(scelta != 2);
}

void menuPileStatic(void) {
    int scelta, check, input;

    do {
        //menu per la scelta dell operazioni
        do {
            clear();
            printf("Pila con vettore statico\n\n");
            printf("[0] push\n");
            printf("[1] pop\n");
            printf("[2] Exit\n");
            printf("\nInserisci scelta: ");
            flush();
            check = scanf("%d", &scelta);
        } while(!check || (scelta < 0 || scelta > 2));
        //Menu per la gesione delle scelte
        switch (scelta) {
            case 0:
                clear();
                printf("Inserisci elemento da inserire nella pila: ");
                flush();
                scanf("%d", &input);
                //Inserisco l'elemento e controllo se il vettore è gia pieno
                if(pushPilaStatic(&pilaStatic, input))
                    printf("Pila piena impossibile aggiungere l'elemento\n");

                printPilaStatic(pilaStatic);
                printf("Premi un tasto per continuare...");
                flush();
                getchar();
                break;

            case 1:
                clear();
                //Controllo se la pila è vuota
                //Elimino l'elemento in testa
                if(popPilaStatic(&pilaStatic))
                    printf("Pila vuota\n");

                printPilaStatic(pilaStatic);
                printf("premi un tasto per continuare\n");
                flush();
                getchar();
                break;

            case 2:
                break;
        }
    } while(scelta != 2);
}

void menuPileDynamic(void) {
    int scelta, check, input;

    do {
        //menu per la scelta delle operazioni
        do {
            clear();
            printf("Pila con vettore statico\n\n");
            printf("[0] push\n");
            printf("[1] pop\n");
            printf("[2] Exit\n");
            printf("\nInserisci scelta: ");
            flush();
            check = scanf("%d", &scelta);
        } while(!check || (scelta < 0 || scelta > 2));
        //Menu per la gestione delle operazioni
        switch (scelta) {
            case 0:
                clear();
                printf("Inserisci elemento da inserire nella pila: ");
                flush();
                scanf("%d", &input);
                //Inserisco l'elemento e controllo se il vettore è pieno
                if(pushPilaDynamic(&pilaDynamic, input))
                    exit(1); //Errore allocazioen memoria, esco da programma

                printPilaDynamic(pilaDynamic);
                printf("Premi un tasto per continuare...");
                flush();
                getchar();
                break;

            case 1:
                clear();
                if(popPilaDynamic(&pilaDynamic))
                    printf("Pila vuota\n");

                printPilaDynamic(pilaDynamic);
                printf("premi un tasto per continuare\n");
                flush();
                getchar();
                break;

            case 2:
                break;
        }
    } while(scelta != 2);
}

void menuCode(void) {
    int check, scelta_menu;
    //Menu per la gestione delle pile
    do {
        clear();
        printf("[0] Code con strutture collegate\n");
        printf("[1] Code con array statico\n");
        printf("[2] Code con array dinamico\n");
        printf("[3] Exit\n");
        flush();
        check = scanf("%d", &scelta_menu);
    } while(!check || (scelta_menu < 0 || scelta_menu > 3));
    //Menù per la scelta delle operazioni da fare
    switch (scelta_menu) {
        case 0:
            menuCodeStrutture();
            break;

        case 1:
            menuCodeStatic();
            break;

        case 2:
            menuCodeDynamic();
            break;

        case 3:
            break;
    }
}

void menuCodeStrutture(void) {
    int scelta, check, input;
    TipoLista tmp;

    do {

        do {
            clear();
            printf("Pila con strutture collegate\n\n");
            printf("[0] push\n");
            printf("[1] pop\n");
            printf("[2] Exit\n");
            printf("\nInserisci scelta: ");
            flush();
            check = scanf("%d", &scelta);
        } while(!check || (scelta < 0 || scelta > 2));

        switch (scelta) {
            case 0:
                clear();
                printf("Inserisci elemento da inserire nella Coda: ");
                flush();
                scanf("%d", &input);
                if(pushCoda(&coda, input))
                    exit(1);

                printCoda(&coda);
                printf("Premi un tasto per continuare...");
                flush();
                getchar();
                break;

            case 1:
                clear();
                tmp = popCoda(&coda);
                if(tmp == NULL)
                    printf("Coda vuota\n");
                else
                    printf("Elemento eliminato in testa alla coda: %d\n", tmp->val);

                printCoda(&coda);
                printf("premi un tasto per continuare\n");
                flush();
                getchar();
                break;

            case 2:
                break;
        }
    } while(scelta != 2);
}

void menuCodeStatic(void) {
    int scelta, check, input;

    do {

        do {
            clear();
            printf("Pila con vettore statico\n\n");
            printf("[0] push\n");
            printf("[1] pop\n");
            printf("[2] Exit\n");
            printf("\nInserisci scelta: ");
            flush();
            check = scanf("%d", &scelta);
        } while(!check || (scelta < 0 || scelta > 2));

        switch (scelta) {
            case 0:
                clear();
                printf("Inserisci elemento da inserire nella coda: ");
                flush();
                scanf("%d", &input);
                if(pushCodaStatic(&codaStatic, input))
                    printf("Coda piena impossibile aggiungere l'elemento\n");

                printCodaStatic(codaStatic);
                printf("Premi un tasto per continuare...");
                flush();
                getchar();
                break;

            case 1:
                clear();
                if(popCodaStatic(&codaStatic))
                    printf("Coda vuota\n");

                printCodaStatic(codaStatic);
                printf("premi un tasto per continuare\n");
                flush();
                getchar();
                break;

            case 2:
                break;
        }
    } while(scelta != 2);
}

void menuCodeDynamic(void) {
    int scelta, check, input;

    do {

        do {
            clear();
            printf("Pila con vettore statico\n\n");
            printf("[0] push\n");
            printf("[1] pop\n");
            printf("[2] Exit\n");
            printf("\nInserisci scelta: ");
            flush();
            check = scanf("%d", &scelta);
        } while(!check || (scelta < 0 || scelta > 2));

        switch (scelta) {
            case 0:
                clear();
                printf("Inserisci elemento da inserire nella coda: ");
                flush();
                scanf("%d", &input);
                if(pushCodaDynamic(&codaDynamic, input))
                    printf("Coda piena impossibile aggiungere l'elemento\n");

                printCodaDynamic(codaDynamic);
                printf("Premi un tasto per continuare...");
                flush();
                getchar();
                break;

            case 1:
                clear();
                if(popCodaDynamic(&codaDynamic))
                    printf("Coda vuota\n");

                printCodaDynamic(codaDynamic);
                printf("premi un tasto per continuare\n");
                flush();
                getchar();
                break;

            case 2:
                break;
        }
    } while(scelta != 2);
}
