#ifndef TOOLS_H
   #define TOOLS_H TOOLS.H

   void clearBuffer();                          // Leert den Tastaturpuffer
   void clearScreen();                          // Leert den Terminal
   short askYesOrNo(char *);                    // Ja/Nein Abfrage
   void waitForEnter();                         // Eingabeaufforderung der Entertaste
   int CountChar(char *);
   void printLine(char, int);
   int getText(char *, int, char **, int);
   void getNumber(char *, int *, int, int);

#endif
