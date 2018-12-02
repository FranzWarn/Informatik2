#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include "datastructure.h"
#include "datetime.h"
#include "cds.h"

int countCD = 0;
TCD CDData[MAXCDS];

static void createSong(TSong *Song, TCD *CD);
static void listOneCD(TCD *CD);
static void listOneSong(TSong *Song, int i, TCD *CD);

void createCD()
{
   TCD * CD = CDData + countCD;
   CD->Number = 0;
   if(countCD > MAXCDS)
   {
      printf("Maximale Anzahl an CDs gespeichert!\n");
      return;
   }
   getText("Bitte geben Sie den CD Namen ein: ", 50, &(CD->Titel), 0);
   getText("\nBitte geben Sie einen Interpreten an: ", 50, &(CD->Interpret), 1);
   getNumber("\nBitte geben Sie das Erscheinungsjahr an: ", &(CD->ReleaseYear), 1920, 2019);
   do
   {
      createSong(CD->Songs+CD->Number, CD);
      (CD->Number)++;
   }while (askYesOrNo("Möchten Sie noch ein Lied eingeben? (J/N) : ") && CD->Number<MAXSONGS);
   if(CD->Number == MAXSONGS)
      printf("Die Maximale Anzhal an Songs wurde eingegeben!\n");
   countCD++;
}

static void createSong(TSong *Song, TCD *CD)
{
   if((CD->Interpret))
   {
      getText("\nBitte geben Sie den Titelsong an: ", 50, &(Song->Titel), 0);
      inputTime("\nGeben Sie bitte die Dauer des Liedes ein\n(Format hh:mm:ss oder mm:ss): ", &(Song->Length));
   }
   else
   {
      getText("\nBitte geben Sie den Interpreten des Liedes an: ", 50, &(Song->Interpret), 0);
      getText("\nBitte geben Sie den Titelsong an: ", 50, &(Song->Titel), 0);
      inputTime("\nGeben Sie bitte die Dauer des Liedes ein\n(Format hh:mm:ss oder mm:ss): ", &(Song->Length));
   }
}

void editCD()
{
   printf("editCD\n\n");
   waitForEnter();
}

void deleteCD()
{
   printf("deleteCD\n\n");
   waitForEnter();
}

void searchSong()
{
   printf("searchSong\n\n");
   waitForEnter();
}

void sortCDs()
{
   printf("sortCDs\n\n");
   waitForEnter();
}

void listCDs()
{
   TCD *CD = CDData;
   int i;
   int j = 0;
   char *heading="Liste aller CDs";

   if(countCD == 0)
   {
      printf("\nBis Jetzt keine CD eingegeben!\n\n");
      waitForEnter();
      return;
   }
   printf("%s\n",heading);
   j = CountChar(heading);
   printLine('-', j);

   for(i = 0; i< countCD; i++)
      listOneCD(CD+i);

   printf("\n\n");
   waitForEnter();

}

static void listOneCD(TCD *CD)
{
   int i;
   printf("\n\nTitel           : %s", CD->Titel);
   printf("\nInterpret       : %s", CD->Interpret);
   printf("\nErscheinungsjahr: %i", CD->ReleaseYear);
   printf("\nAnzahl Lieder   : %i", CD->Number);
   for(i = 0; i< CD->Number; i++)
         listOneSong(CD->Songs+i, i, CD);
}

static void listOneSong(TSong *Song, int i, TCD *CD)
{

   if(!(Song->Interpret))
      printf("\n   %i. %s (%s; ", i+1, CD->Interpret, Song->Titel);
   else
      printf("\n   %i. %s (%s; ", i+1, Song->Interpret, Song->Titel);
   if(!(Song->Length.Hour))
      printTime(Song->Length, 1);
   else
      printTime(Song->Length, 0);
}
