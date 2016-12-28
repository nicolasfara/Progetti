#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "list.h"
#include "list_dynamic.h"
#include "list_static.h"

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

void menuStruttura();
void menuStatico();
void menuDinamico();

static List *testa = NULL;
static Static vs;
static Dynamic vd;

int main()
{
    int scelta, check;

    //Inizializzo lista statica
    vs.num_elem = 0;
    //Inizializzo la lista dinamica
    if(initListD(&vd))
        exit(EXIT_FAILURE);

    do {

        do {

            clear();
            printf("Gestione delle liste\n\n");
            printf("[0] Strutture linkate\n");
            printf("[1] lista con vettore dinamico\n");
            printf("[2] Lista con vettore statico\n");
            printf("[3] Esci\n\n");
            flush();
            check = scanf("%d", &scelta);

        }while(!check || (scelta < 0 || scelta > 3));

        switch(scelta) {
            case 0:
                clear();
                menuStruttura();
                break;

            case 1:
                clear();
                menuDinamico();
                break;

            case 2:
                clear();
                menuStatico();
                break;

            case 3:
                break;
        }

    }while(scelta != 3);

    //Elimino la lsita con strutture
    delList(&testa);
    //Dealloco il vettore dinamico
    freeListD(&vd);

    return 0;
}

//Funzione per la visualizzazione del menu per le strutture collegate
void menuStruttura() {

    int scelta, check, input, input_find;

    do {

        do {
            clear();
            printf("[0] Inserisci elemento in testa\n");
            printf("[1] Inserisci elemento in coda\n");
            printf("[2] Inserisci dopo elemento\n");
            printf("[3] Elimina elemento in testa\n");
            printf("[4] Elimina elemento in coda\n");
            printf("[5] Elimina elemento\n");
            printf("[6] Esci\n\n");
            flush();
            printf("Inserisci scelta: ");
            check = scanf("%d", &scelta);

        }while(!check || (scelta < 0 || scelta > 6));

        switch(scelta) {
        case 0:
            clear();
            printf("Inserisci elemento: ");
            flush();
            //Ripeto fino che non viene inserito un numero
            do
                check = scanf("%d", &input);
            while(!check);

            if(inHead(&testa, input)){
                printf("Errore allocazioen memoria");
                exit(EXIT_FAILURE);
            }
            printList(testa);
            printf("Premi un tasto per continuare");
            flush();
            getchar();
            break;

        case 1:
            clear();
            printf("Inserisci elemento: ");
            flush();
            //Ripeto fino che non viene inserito un numero
            do
                check = scanf("%d", &input);
            while(!check);

            if(inTail(&testa, input)){
                printf("Errore allocazioen memoria");
                exit(EXIT_FAILURE);
            }
            printList(testa);
            printf("Premi un tasto per continuare");
            flush();
            getchar();
            break;

        case 2:
            clear();
            printf("Inserisci elemento da ricercare: ");
            flush();
            //Ripeto fino che non viene inserito un numero
            do {
                flush();
                check = scanf("%d", &input_find);
            }while(!check);

            printf("Inserisci elemento da aggiungere: ");
            //Ripeto fino che non viene inserito un numero
            do {
                flush();
                check = scanf("%d", &input);
            }while(!check);

            if(inElem(&testa, input_find, input)){
                printf("Errore allocazioen memoria");
                exit(EXIT_FAILURE);
            }
            printList(testa);
            printf("Premi un tasto per continuare");
            flush();
            getchar();
            break;

        case 3:
            clear();
            if(delHead(&testa))
                printf("Impossibile eliminare elemento in testa\n");

            printList(testa);
            printf("\nPremi invio per continuare");
            flush();
            getchar();
            break;

        case 4:
            clear();
            if(delTail(&testa))
                printf("Impossibile eliminare elemento in coda\n");

            printList(testa);
            printf("\nPremi invio per continuare");
            flush();
            getchar();
            break;

        case 5:
            clear();
            do {
                printf("Inserisci elemento da eliminare: ");
                flush();
                check = scanf("%d", &input);
            }while(!check);
            if(delElem(&testa, input))
                printf("Elemento non trovato\n");

            printList(testa);
            flush();
            printf("Premi invio per continuare");
            getchar();
            break;

        case 6:
            //Esco dal menu
            break;
        }

    }while(scelta != 6);
}


void menuStatico() {

    int scelta, check, input, input_find;

    do {
        do {
            clear();
            printf("[0] Inserisci elemento in testa\n");
            printf("[1] Inserisci elemento in coda\n");
            printf("[2] Inserisci dopo elemento\n");
            printf("[3] Elimina elemento in testa\n");
            printf("[4] Elimina elemento in coda\n");
            printf("[5] Elimina elemento\n");
            printf("[6] Esci\n\n");

            printf("Inserisci scelta: ");
            flush();
            check = scanf("%d", &scelta);

        } while(!check || (scelta < 0 || scelta > 6));


        switch (scelta) {
            case 0:
                clear();
                printf("Inserisci elemento: ");
                flush();
                //Ripeto fino che non viene inserito un numero
                do
                    check = scanf("%d", &input);
                while(!check);

                if(inHeadS(&vs, input))
                    printf("Vettore pieno, impossibile inserire l'elemento\n");

                printListS(vs);
                printf("Premi un tasto per continuare");
                flush();
                getchar();
                break;

            case 1:
                clear();
                printf("Inserisci elemento: ");
                flush();
                //Ripeto fino che non viene inserito un numero
                do
                    check = scanf("%d", &input);
                while(!check);

                if(inTailS(&vs, input))
                    printf("Vettore pieno, impossibile inserire l'elemento\n");

                printListS(vs);
                printf("Premi un tasto per continuare");
                flush();
                getchar();
                break;

            case 2:
                clear();
                printf("Inserisci elemento da ricercare: ");
                flush();
                //Ripeto fino che non viene inserito un numero
                do {
                    flush();
                    check = scanf("%d", &input_find);
                }while(!check);

                printf("Inserisci elemento da aggiungere: ");
                //Ripeto fino che non viene inserito un numero
                do {
                    flush();
                    check = scanf("%d", &input);
                }while(!check);

                //Gestisco i due casi di Errore
                if(inElemS(&vs, input_find, input) == 2)
                    printf("Elemento non trovato\n");

                printListS(vs);
                printf("Premi un tasto per continuare");
                flush();
                getchar();
                break;

            case 3:
                clear();
                if(delHeadS(&vs))
                    printf("Impossibile eliminare elemento in testa\n");

                printListS(vs);
                printf("\nPremi invio per continuare");
                flush();
                getchar();
                break;

            case 4:
                clear();
                if(delTailS(&vs))
                    printf("Impossibile eliminare elemento in coda\n");

                printListS(vs);
                printf("\nPremi invio per continuare");
                flush();
                getchar();
                break;

            case 5:
                clear();
                do {
                    printf("Inserisci elemento da eliminare: ");
                    flush();
                    check = scanf("%d", &input);
                }while(!check);

                if(delElemS(&vs, input))
                    printf("Elemento non trovato\n");

                printListS(vs);
                flush();
                printf("Premi invio per continuare");
                getchar();
                break;

            case 6:
                break;
        }

    } while(scelta != 6);
}

void menuDinamico() {

    int scelta, check, input, input_find;

    do {
        do {
            clear();
            printf("[0] Inserisci elemento in testa\n");
            printf("[1] Inserisci elemento in coda\n");
            printf("[2] Inserisci dopo elemento\n");
            printf("[3] Elimina elemento in testa\n");
            printf("[4] Elimina elemento in coda\n");
            printf("[5] Elimina elemento\n");
            printf("[6] Esci\n\n");

            printf("Inserisci scelta: ");
            flush();
            check = scanf("%d", &scelta);

        } while(!check || (scelta < 0 || scelta > 6));


        switch (scelta) {
            case 0:
                clear();
                printf("Inserisci elemento: ");
                flush();
                //Ripeto fino che non viene inserito un numero
                do
                    check = scanf("%d", &input);
                while(!check);

                if(inHeadD(&vd, input)) {
                    printf("Errore allocazione memoria\n");
                    exit(EXIT_FAILURE);
                }

                printListD(vd);
                printf("Premi un tasto per continuare");
                flush();
                getchar();
                break;

            case 1:
                clear();
                printf("Inserisci elemento: ");
                flush();
                //Ripeto fino che non viene inserito un numero
                do
                    check = scanf("%d", &input);
                while(!check);

                if(inTailD(&vd, input)){
                    printf("Errore allocazioen memoria\n");
                    exit(EXIT_FAILURE);
                }

                printListD(vd);
                printf("Premi un tasto per continuare");
                flush();
                getchar();
                break;

            case 2:
                clear();
                printf("Inserisci elemento da ricercare: ");
                flush();
                //Ripeto fino che non viene inserito un numero
                do {
                    flush();
                    check = scanf("%d", &input_find);
                }while(!check);

                printf("Inserisci elemento da aggiungere: ");
                //Ripeto fino che non viene inserito un numero
                do {
                    flush();
                    check = scanf("%d", &input);
                }while(!check);

                //Gestisco i due casi di Errore
                switch(inElemD(&vd, input_find, input)){
                    case 1:
                        printf("Errore allocazione memoria\n");
                        exit(EXIT_FAILURE);
                        break;
                    case 2:
                        printf("Elemento non trovato\n");
                        break;
                }

                printListD(vd);
                printf("Premi un tasto per continuare");
                flush();
                getchar();
                break;

            case 3:
                clear();
                if(delHeadD(&vd))
                    printf("Impossibile eliminare elemento in testa\n");

                printListD(vd);
                printf("\nPremi invio per continuare");
                flush();
                getchar();
                break;

            case 4:
                clear();
                if(delTailD(&vd))
                    printf("Impossibile eliminare elemento in coda\n");

                printListD(vd);
                printf("\nPremi invio per continuare");
                flush();
                getchar();
                break;

            case 5:
                clear();
                do {
                    printf("Inserisci elemento da eliminare: ");
                    flush();
                    check = scanf("%d", &input);
                }while(!check);

                if(delElemD(&vd, input))
                    printf("Elemento non trovato\n");

                printListD(vd);
                flush();
                printf("Premi invio per continuare");
                getchar();
                break;

            case 6:
                break;
        }

    } while(scelta != 6);
}
