#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>






//function that seperates the 2,3,4 numbers and will use those to create the csv file, here token temp variable is the number 2 or 3 or4
int* colNumb(char inputString[],int size) {

    char* token;
      int* colArr = (int*)malloc(size * sizeof(int));
    // Use strtok to tokenize the string based on the comma delimiter
    token = strtok(inputString, ",");
    

    // Loop through the tokens and print them
    int i=0;
    while (token != NULL) {
        
        
colArr[i]=atoi(token);
i++;


        token = (char *)strtok(NULL, ","); // NULL as the first argument to continue tokenizing
    };
    
    return colArr;}




//string comparison function
int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// Function to sort an array of strings
void sortStringsAlphabetically(char *array[], size_t size) {
    qsort(array, size, sizeof(char *), compareStrings);
}

// Comparison function for qsort
int compareIntegers(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to sort an array of integers using qsort
void sortIntegers(int array[], size_t size) {
    qsort(array, size, sizeof(int), compareIntegers);
}




