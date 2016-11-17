#include <stdio.h>
#include <stdlib.h>

int somma(int a, int b);

int main(int argc, char *argv[])
{
  printf("%d\n",somma(atoi(argv[1]),atoi(argv[2])));
  return 0;
}

int somma(int a, int b)
{
  int c=0;
  c = a+b;
  return c;
}
