#ifndef DATASTRUCTURE_H_INCLUDED
   #define DATASTRUCTURE_H_INCLUDED

   #define MAXSONGS 30
   #define MAXCDS 100

   typedef struct       // Struktur, um eine Uhrzeit abzuspeichern
   {
      int Hour;
      int Minute;
      int Second;
   } TTime;

   typedef struct
   {
      char *Titel;
      char *Interpret;
      TTime Length;
   } TSong;

   typedef struct
   {
      char *Titel;
      char *Interpret;
      int ReleaseYear;
      int Number;
      TSong Songs[MAXSONGS];
   } TCD;

   extern int countCD;
   extern TCD CDData[];

#endif
