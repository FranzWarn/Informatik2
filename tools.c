/****************************************************************************************************
*****************************************************************************************************
*** MODUL:           tools.c
*** BESCHREIBUNG:    Stellt einige nützliche Funktionen zur Verfügung
*** GLOBALE FKT:     clearBuffer
***                  clearScreen
***                  printLine
***                  WaitForEnter
***                  AskYesOrNo
***                  getNumber
*** LOKALE FKT:      -/-
*****************************************************************************************************
****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "datastructure.h"


/**********************************************************
* Funktion:     clearBuffer
* Beschreibung: Tastaturpuffer leeren
* Parameter:    -/-
* Ergebnis:     -/-
**********************************************************/
void clearBuffer()
{
   char Dummy;
   do
   {
      scanf("%c", &Dummy);
   } while (Dummy != '\n');
}

/**********************************************************
* Funktion:     clearScreen
* Beschreibung: Leert die Konsole
* Parameter:    -/-
* Ergebnis:     -/-
**********************************************************/
void clearScreen()
{
   #ifdef __unix__
      #define clrscreen() system("clear")    // Leert die Konsole (Unix)
   #else
      #define clrscreen() system("CLS")      // Leert die Konsole (Windows)
   #endif // __unix__

   clrscreen();
}

/**********************************************************
 * Funktion:      askYesOrNo
 * Beschreibung:  Nachfrage, ob etwas wiederholt werden soll
 * Parameter:     Promttext in Stringform
 * Ergebnis:      1 wenn j oder J eingegeben wurde,
 *                0 wenn n oder N
**********************************************************/
short askYesOrNo(char *prompt)
{
   unsigned char input;

   do
   {
      printf("%s", prompt);                                    // Abfrage zum Wiederholen anzeigen

      if ( (input = getchar()) != '\n')                        // Einlesen eines Chars
         clearBuffer();

      switch (input)                                           // Überprüfung des Chars
      {
         case 'j':
         case 'J': return 1;
         case 'n':
         case 'N': return 0;
         default: input = '\0';
      }
   } while (!input);                                           // Solange nicht ja oder nein eingegeben wurde

   return 0;   // Dummy, sonst gibts Compilerfehler
}

/**********************************************************
 * Funktion:      waitForEnter
 * Beschreibung:  Eingabeaufforderung zur Betätigung
 *                der Eingabetaste (Piratentaste, arrrrr)
 * Parameter:     -/-
 * Ergebnis:      -/-
**********************************************************/
void waitForEnter()
{
   puts("Bitte Eingabetaste druecken ...");
   clearBuffer();
}

/**********************************************************
 * Funktion:      CountChar
 * Beschreibung:  Zählen aller chars eines Strings
 * Parameter:     String
 * Ergebnis:      Anzahl der Chars als int
**********************************************************/
int CountChar(char *word)
{
   char *tmp = word;
   int i = 0;

   while(*tmp)
   {
      i++;
      tmp++;
   }
   return i;
}

/**********************************************************
 * Funktion:      printLine
 * Beschreibung:  Zeichen mit angegebener Anzahl ausgeben
 * Parameter:     Das Zeichen, welches ausgegeben werden
 *                soll + die Anzahl
 * Ergebnis:      -/-
**********************************************************/
void printLine(char p, int z)
{
   int i;

   for(i = 0; i<z; i++)
   {
      printf("%c", p);
   }
}

int getText(char *Prompt, int Maxlen, char **P, int AllowEmpty)
{
    char *Input;
    char Format[20];
    *P = NULL;
    Input = calloc(Maxlen+1, sizeof(char));

    if (Input)
    {
        printf(Prompt);
        sprintf(Format, "%%%i[^\n]", Maxlen);
        do
        {
            scanf(Format, Input);
            clearBuffer();
            if (*Input)
            {
                *P = malloc(strlen(Input+1));
                if (*P)
                    strcpy(*P, Input);
                else
                {
                    free(Input);
                    return 0;
                }
            }
            else
            {
                if (AllowEmpty)
                {
                    free(Input);
                    return 1;
                }
            }
        }while (*Input == '\0');
        free(Input);
        return 1;
    }
    return 0;
}

void getNumber(char *Prompt, int *N, int uz, int oz)
{
   printf(Prompt);
   do
   {
      scanf("%i", N);
      clearBuffer();
   }while(*N < uz || *N > oz);
}
