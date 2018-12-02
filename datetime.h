#ifndef DATETIME_H_INCLUDED
#define DATETIME_H_INCLUDED

int isTimeValid(TTime Valid);
int getTimeFromString(char *, TTime *Time);
void inputTime(char *, TTime *T);
void printTime(TTime Time, int );

#endif // DATETIME_H_INCLUDED
