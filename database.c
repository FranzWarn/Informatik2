#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "datastructure.h"
#include "datetime.h"
#include "cds.h"

static void saveCD(TCD *CD,FILE *fp);
static void saveSong(TSong *Song, TCD *CD,FILE *fp);

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
      fprintf(fp,"<Data>\n");
      for(i = 0; i < countCD; i++)
      {
         saveCD(CD+i, fp);
      }

   }
   fprintf(fp,"</Data>\n");
   fclose(fp);
}

static void saveCD(TCD *CD,FILE *fp)
{
   int i;
   fprintf(fp," <CD>\n");
   fprintf(fp,"  <Title>%s</Title>\n", CD->Titel);
   if(CD->Interpret)
      fprintf(fp,"  <Interpret>%s</Interpret>\n", CD->Interpret);
   fprintf(fp,"  <YearOfAppearance>%i</YearOfAppearance>\n", CD->ReleaseYear);
   for(i = 0; i< CD->Number; i++)
   {
      fprintf(fp,"  <Song>\n");
      saveSong(CD->Songs+i, CD, fp);
   }
   fprintf(fp," </CD>\n");
}

static void saveSong(TSong *Song,TCD *CD,FILE *fp)
{
   fprintf(fp,"   <Title>%s</Titel>\n", Song->Titel);
   if(CD->Interpret == NULL)
      fprintf(fp,"   <Interpret>%s</Interpret>\n", Song->Interpret);
   fprintf(fp,"   <Duration>%02d:%02d:%02d</Duration>\n", Song->Length.Hour, Song->Length.Minute, Song->Length.Second);
   fprintf(fp,"   </Song>\n");
}

void load()
{
//   TCD *CD;

   FILE *fp;
   fp = fopen("cds.xml", "r");
   int len = 200;
   char *Input = malloc(len*sizeof(char));
   int i = 0;

   if(fp == NULL)
   {
      printf("Datei konnte nicht geladen werden!");
      return;
   }
   else
   {
      while((fgets(Input, len, fp)) != EOF)
      {
         printf("%s", Input);

      }
   }
   fclose(fp);
  // printf("%s", *Input);
   waitForEnter();
}

