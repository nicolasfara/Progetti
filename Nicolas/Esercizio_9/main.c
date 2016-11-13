/*
 * Autore: Nicolas Farabegoli
 * Data Creazione: 7/11/2016
 * Ultima modifica: 10/11/2016
 * Versione: 1.0.2
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Scrivere un programma C che generi un “cammino casuale”
all’interno di una matrice 10x10.
La matrice conterrà dei caratteri (inizialmente saranno tutti ‘.’).
Il programma deve passare casualmente da un elemento all'altro, muovendosi in alto,
in basso, a sinistra o a destra di una posizione soltanto.
Gli elementi visitati dal programma dovranno essere etichettati
con lettere che vanno dalla A alla Z nell'ordine con cui vengono visitati.
*/

//Define per semplificare le funzioni random
#define RANDOMIZE() srand(time(NULL))
#define RANDOM_NEXT_STEP() rand() % 4
#define RANDOM_FIRST_POSITION() rand() % 9 + 1
//Define in cui sono specificate le direzioni
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

//Prototipo funzione
void positionArray(int srandom);

//Array globale
int arrayPos[4];

int main()
{
  int colonne = 0;
  int righe = 0;
  char lett = 'A';
  int nextPos = 0;
  int error = 0;
  //Dichiarazione vettore
  char vett[10][10] =
  {
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
  };

  printf("Cammino casuale\n\n");
  //Genero il seme per il random
  RANDOMIZE();

  //Genero la posizione casuale per la prima lettera
  righe = RANDOM_FIRST_POSITION();
  colonne = RANDOM_FIRST_POSITION();

  //Imposta la lettera A nella posizione appena calcolata
  vett[righe][colonne] = lett;

  for (int i = 0; i < 25; i++)
  {
    //Genero la prossima mossa casualmente
    nextPos = RANDOM_NEXT_STEP();
    //Calcolo le altre alternative mosse nel caso la prima sia occupata
    positionArray(nextPos);

    for (int c = 0; c < 4; c++)
    {
      //Eseguo le mosse
      switch (arrayPos[c])
      {
        case UP:
          //Verifico che sia presente il '.' e non esca dalla matrice
          if (vett[righe - 1][colonne] == '.' && righe - 1 >= 0)
          {
            //Ripreistino l'errore
            error = 0;
            c = 4;
            //Decremento le righe per la prossima mossa
            righe -= 1;
            //Scrivo la lettera in qesta posizione
            vett[righe][colonne] = ++lett;
          }
          else
            error++;
          break;

        case DOWN:
          if (vett[righe + 1][colonne] == '.' && righe + 1 <= 9)
          {
            //Ripreistino l'errore
            error = 0;
            c = 4;
            //Incremento le righe per la prossima mossa
            righe += 1;
            //Scrivo la lettera in qesta posizione
            vett[righe][colonne] = ++lett;
          }
          else
            error++;
          break;

        case LEFT:
          if (vett[righe][colonne - 1] == '.' && colonne - 1 >= 0)
          {
            //Ripreistino l'errore
            error = 0;
            c = 4;
            //Decremento le colonne per la prossima mossa
            colonne -= 1;
            //Scrivo la lettera in qesta posizione
            vett[righe][colonne] = ++lett;
          }
          else
            error++;
          break;

        case RIGHT:
          if (vett[righe][colonne + 1] == '.' && colonne + 1 <= 9)
          {
            //Ripreistino l'errore
            error = 0;
            c = 4;
            //Incremento le colonne per la prossima mossa
            colonne += 1;
            //Scrivo la lettera in qesta posizione
            vett[righe][colonne] = ++lett;
          }
          else
            error++;
          break;
      }

      //Se tutte le posizioni sono occupate
      if (error == 4)
      {
        i = 26; //Esco dal for esterno
        c = 4; //Esco dal for interno
        printf("Cammino non completato\n");
      }
    }
    //Se sono arrivato alla lettera Z ho terminato il programma senza errori
    if (i == 24)
      printf("Cammino completato\n");

  }
  //Stampo il vettore
  for (int row = 0; row < 10; row++)
  {
    for (int col = 0; col < 10; col++)
    {
      printf("%c ", vett[row][col]);
    }
    printf("\n");
  }

  return 0;
}

//Funzione che calcola le altre possibili direzioni oltre a quella generata casualmente
void positionArray(int srandom)
{
  int cont = 1;
  //Inserisco il primo numero random nella funzione
  arrayPos[0] = srandom;
  //INserisco i suoi precedenti fino a 0 nelle posizioni successive del vettore
  for (int i = srandom - 1; i >= 0; i--)
  {
    arrayPos[cont] = i;
    cont++;
  }
  //Inserico i suoi successivi nelle posizioni successive del vettore
  for (int t = srandom + 1; t <= 3; t++)
  {
    arrayPos[cont] = t;
    cont++;
  }
  cont = 1;
}
