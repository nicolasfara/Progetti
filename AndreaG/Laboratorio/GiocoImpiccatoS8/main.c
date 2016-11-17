#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
  char stringa[7]={"ANDREA"};
  char codificata[7];
  strcpy(codificata,stringa);
  char ch;
  int crediti=strlen(stringa)*2;
  int i,token;

  for(i=0;i<6;i++)
  {
    if(codificata[i]=='a' ||codificata[i]=='A' ||codificata[i]=='e' ||codificata[i]=='E' ||codificata[i]=='i' ||codificata[i]=='I' ||codificata[i]=='o' ||codificata[i]=='O' ||codificata[i]=='u' ||codificata[i]=='U')
      codificata[i]='+';
    else
      codificata[i]='-';
  }
  printf("%s\n\n",codificata);

  while(crediti>=0)
  {
    puts("");
    scanf("%c",&ch);
    while ( getchar() != '\n' );
    for(i=0;i<7+1;i++)
    {
      if(stringa[i]==ch)
        codificata[i]=ch;
    }
    printf("\n%s\nCrediti rimasti:%d\t",codificata,crediti);
    token=0;
    for(i=0;i<6;i++)
    {
      if(codificata[i]!='+'&& codificata[i]!='-')
        token++;
    }
    if(token==6&&crediti>0)
    {
      puts("Hai vinto");
      return 0;
    }
    crediti=crediti-1;
  }
  if(crediti<0)
    puts("Hai perso");

  return 0;
}
