#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tools.h"
#include "datastructure.h"
#include "datetime.h"

int getmenu(char *Titel, char **menu, int count)
{
   int i;
   int j = 0;
   int z = 0;
   z = CountChar(Titel);

   do
   {
      clearScreen();
      printf("%s\n", Titel);
      printLine('=', z);
      printf("\n\n");

      for ( i = 0; i < count; i++)
      {
         printf("%i. %s \n", (i + 1), *(menu+i));
      }

      printf("\n\nIhre Wahl: ");
      scanf("%i", &j);
      clearBuffer();

   } while ((j < 1) || (j > count));
   return j;
}
