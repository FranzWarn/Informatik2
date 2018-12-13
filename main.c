#include <stdio.h>
#include "datastructure.h"
#include "datetime.h"
#include "tools.h"
#include "menu.h"
#include "cds.h"
#include "database.h"

void inputTime();


char *menu[] = {"Neue CD anlegen",
               "CD bearbeiten",
               "CD loeschen",
               "Suchen",
               "Sortieren",
               "Auflisten",
               "Programm beenden"};

char *titel = "CD-Verwaltung Deluxe";
int Input = 0;

int main()
{
   load();
   do
   {
      Input = getmenu(titel,menu,7);

      switch (Input)
      {
         case 1: createCD();     break;
         case 2: editCD();       break;
         case 3: deleteCD();     break;
         case 4: searchSong();   break;
         case 5: sortCDs();      break;
         case 6: listCDs();      break;
         case 7: save();         break;
      }

    } while (Input != 7);


  /* do
   {
      clearScreen();
      printf("Hinweis: Druecken Sie nur die Eingabetaste,\n");
      printf("         um die jeweilige Eingabe abzubrechen.\n\n");

      inputTime();
   } while (askYesOrNo("Moechten Sie noch einmal (j/n) ? "));
   */
   return 0;
}

/********************************************************************
 * Funktion void inputTime(void)
 *   - Benutzer soll eine Uhrzeit eingeben.
 *   - Eingabe wird mit Hilfe der Funktion getTimeFromString geparst
 *     und geprueft. Bei gueltiger Uhrzeit steht dieses in der
 *     Uhrzeitvariable Time.
 *   - Ergebnis der Eingabe wird entsprechend angezeigt.
 *   - wird nur die Eingabetaste gedrueckt, wird die Funktion ohne
 *     weitere Bildschirmausgabe beendet.
 * Paramater: keine
 * Funktionsergebnis: nichts
 *******************************************************************/
/*void inputTime()
{
   TTime Time;
   char Input[20];
   int ok = 0;

   do
   {
      printf("Geben Sie bitte eine gueltige Uhrzeit ein: ");
      *Input = '\0';
      scanf("%19[^\n]", Input);
      clearBuffer();
      if (*Input)
         if (getTimeFromString(Input, &Time))
         {
            printf("Die Uhrzeit %02i:%02i:%02i ist gueltig!\n", Time.Hour, Time.Minute, Time.Second);
            ok = 1;
         }
         else
            printf("Die eingegebene Uhrzeit %s ist ungueltig!\n", Input);
      else
         ok = 1;
   } while (!ok);

   printf("\n");
}
*/
