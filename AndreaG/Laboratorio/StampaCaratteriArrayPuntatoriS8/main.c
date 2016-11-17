#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int array[3]={0,1,2};
  int array1[4]={0,1,2,3};
  int array2[5]={0,1,2,3,4};

  int cont,cont1,cont2;
  int *ptra;

  ptra=array;
  puts("Valori primo array:");
  for(cont=0;cont<3;cont++)
  {
    printf("\t%d",ptra[cont]);
  }

  ptra=array1;
  puts("\nValori secondo array:");
  for(cont1=0;cont1<4;cont1++)
  {
    printf("\t%d",ptra[cont1]);
  }

  ptra=array2;
  puts("\nValori terzo array:");
  for(cont2=0;cont2<5;cont2++)
  {
    printf("\t%d",ptra[cont2]);
  }

}
