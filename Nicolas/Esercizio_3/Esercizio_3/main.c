/*
 * Nome file: main.c
 * Autore: Nicolas Farabegoli
 * Data creazione: 10/10/2016
 * Versione: 1.2.0
 * Ultima modifica: 16/10/2016
 */

#include <stdio.h>


/*
 * SPECIFICHE PROGRAMMA:
 * Il programma deve chiedere all'utente di inserire l'ora di arrivo all'aeroporto
 * e fornire all'utente il prossimo volo.
 */

int main()
{
    //dichiarazioni variabil
    
    int cont = 0; //variabile di appoggio per il ciclo while
    float oraInput = 0;
    int parteDecimale = 0;
    
    float orePartenzaAM[4] = {8.00, 9.43, 11.19, 12.47};
    float orePartenzaPM[4] = {2.00, 3.45, 7.00, 9.45};
    float oreArrivo_partenzaAM[4] = {10.16, 11.52, 1.31, 3.00};
    float oreArrivo_partenzaPM[4] = {4.08, 5.55, 9.20, 11.58};
    
    printf("TIME DEPARTURE\nEnter a 24-hour time (format hh.mm)\n");
    int check = scanf("%f", &oraInput); //acquisisco l'ora dell'utente
    
    //Separo la parte decimale dell'orario , quindi ricavo i minuti.
    parteDecimale = (int)oraInput;
    parteDecimale = (int)((oraInput - parteDecimale) * 100);
    
    //CONROLLO DATA ENTRY
    //Controllo che il dato inserito sia corretto e che i minuti non superino 59
    if (!check || parteDecimale > 59)
    {
        printf("Formato orario inserito non corretto\n");
        return 0; //esco dal programma
    }
    
    //controllo se il formato ora è AM o PM
    //Se oraInput < 13 all'ora è AM
    if (oraInput < 13.0f)
    {
        //Eseguo un ciclo che controlla le ore di partenza e quando L' ora di partenza è maggiore di quella inserita dall'utente
        //Fermo il contatore (esce dall while) e poi eseguo i successivi controlli
        while(oraInput > orePartenzaAM[cont])
            cont++;
        
        //Se l'ora di partenza è minore di quella di arrivo, quella di arrivo è pomeriggio (PM) poichè il formato è 12-hour e non 24
        //eseguo questo controllo per specificare PM o AM in "arriving time at: "
        if (oreArrivo_partenzaAM[cont] < orePartenzaAM[cont])
        {
            //In questo caso l'ora di arrivo è PM
            printf("\nClosest departure time is: %.2fAM, arriving at: %.2fPM\n\n", orePartenzaAM[cont], oreArrivo_partenzaAM[cont]);
            
        }
        else
        {
            //in questo caso l'ora di arrivo è maggiore di quella di partenza, quindi l'ora di arrivo è AM
            printf("\nClosest departure time is: %.2fAM, arriving at: %.2fAM\n\n", orePartenzaAM[cont], oreArrivo_partenzaAM[cont]);
        }
    }
    else
    {
        //Ora inserita è PM
        
        oraInput -= 12; //converto l'orario nel formato da 24h a 12h
        
        //Eseguo un ciclo che controlla le ore di partenza e quando L' ora di partenza è maggiore di quella inserita dall'utente
        //(quindi seleziono l'ora del prossimo volo) fermo il contatore (esce dal while) e poi eseguo i successivi controlli
        while(oraInput > orePartenzaPM[cont])
            cont++;
        
        //Se l'ora inserita è maggiore dell'ultimo volo disponibile, fornisco il primo volo della mattina successiva
        if (oraInput > orePartenzaPM[3])
        {
            printf("\nClosest departure time is: %.2fAM, arriving at: %.2fAM\n\n", orePartenzaAM[0], oreArrivo_partenzaAM[0]);
        }
        else
        {
            //L'ora inserita è minore dell'ultimo volo, quindi procedo normalmente
            printf("\nClosest departure time is: %.2fPM, arriving at: %.2fPM\n\n", orePartenzaPM[cont], oreArrivo_partenzaPM[cont]);
        }
        
    }
    //Ritorno al SO che il programma è terminata correttamente
    return 0;
}
