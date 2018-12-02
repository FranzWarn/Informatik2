#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include "datastructure.h"
#include "datetime.h"
#include "cds.h"

/********************************************************************
 * Funktion int isTimeValid(int)
 *   - Funktion prüft ob eine korrekte Uhrzeit vom Benutzer
 *     eingegeben worden ist
 *   - Werte werden von Funktion getTimeFromString übergeben
 * Paramater: Datenstruktur von TTime
 * Funktionsergebnis: 1 für korrekt / 0 für inkorrekt
 *******************************************************************/
int isTimeValid(TTime Valid)
{
   if ((Valid.Hour < 0) || (Valid.Hour > 23))
      return 0;
   if (Valid.Minute < 0 || Valid.Minute > 59)
      return 0;
   if (Valid.Second < 0 || Valid.Second>59)
      return 0;
   else
      return 1;
}

int getTimeFromString(char *Input, TTime *Time)
{
   char *pStd = Input;
   char *pMin = NULL;
   char *pSek = NULL;
   char *check = Input;
   TTime Valid;

   while(*check)
   {
      if (*check == ':')
      {
         if (!pMin)
            pMin = check+1;
         else
        {
            pSek = check+1;
            break;
        }
      }
      check++;
   }

   if (!pSek && pStd && pMin)
   {
      pSek = pMin;
      pMin = pStd;
      pStd = NULL;
   }

   if(pStd != NULL)
   {
      if(*pStd < '0' || *pStd > '9')
         return 0;
   }
   if(*pMin < '0' || *pMin > '9')
      return 0;
   if(*pSek < '0' || *pSek > '9')
      return 0;
   if(pStd != NULL)
      Valid.Hour = atoi(pStd);
   Valid.Minute = atoi(pMin);
   Valid.Second = atoi(pSek);

   if(isTimeValid(Valid))
   {
      if(pStd == NULL)
         Time->Hour = '0';
      Time->Hour = Valid.Hour;
      Time->Minute = Valid.Minute;
      Time->Second = Valid.Second;
      return 1;
   }
   else
      return 0;
}


void inputTime(char *inviation, TTime *T)
{
   char Input[20];
   TTime Time;
   int ok = 0;
   do
   {
      printf(inviation);
      *Input = '\0';
      scanf("%19[^\n]", Input);
      clearBuffer();
      ok =(getTimeFromString(Input, &Time));
   }while(!ok);
   T->Hour = Time.Hour;
   T->Minute = Time.Minute;
   T->Second = Time.Second;
}

void printTime(TTime Time, int AllowEmpty)
{
   if(AllowEmpty)
      printf("%02d:%02d)", Time.Minute, Time.Second);
   else
      printf("%02d:%02d:%02d)", Time.Hour, Time.Minute, Time.Second);
}
