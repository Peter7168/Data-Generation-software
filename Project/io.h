#ifndef IO_H
#define IO_H


char** readFile( char* filename, int* numStrings);



    void writeToFile(char** email, char** firstnames, char** lastnames, char** country,int* colList, int colLength,int numbOfRows, char* filename, int* phoneIndex,
    int* lastFourDigits, int* sin);

#endif
