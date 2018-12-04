#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "datastructure.h"
#include "datetime.h"
#include "cds.h"

static void saveCD(TCD *CD);
static void saveSong(TSong *Song);

void save()
{
   TCD *CD = CDData;
   int i;

   FILE *fp;

   fp = fopen("CDs.xml", "w");

   if(fp == NULL)
      printf("Datei zum speichern konnte nicht geöffnet werden!\n");
   else
   {
      fprintf("<Data>");
      for(i = 0; i <= countCD; i++)
      {
         saveCD(CD);
      }

   }
   fprintf("</Data>");
   fclose(fp);
}

static void saveCD(TCD *CD)
{
   int i;
   fprintf(" <CD>");
   fprintf("  <Title>%s</Title>", CD->Titel);
   fprintf("  <Interpret>%s</Interpret>", CD->Interpret);
   fprintf("  <YearOfAppearance>%i</YearOfAppearance>", CD->ReleaseYear);
   for(i = 0; i<= CD->Number; i++)
   {
      fprintf("  <Song>");
      saveSong(CD->Songs);
   }
   fprintf(" </CD>");
}

static void saveSong(TSong *Song)
{
   fprintf("   <Title>%s</Titel>", Song->Titel);
   fprintf("   <Interpret>%s</Interpret>", Song->Interpret);
   fprintf("   <Duration>%02d:%02d:%02d</Duration>", Song->Length->Hour, Song->Length->Minute, Song->Length->Second);
   fprintf("   </Song>");
}
