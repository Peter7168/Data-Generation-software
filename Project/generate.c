#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function that creates a random 9 digit sin
int getNineDigitNumber() {
    return rand() % 900000000 + 100000000; // Generates a random 9-digit number
}

// Function to create an array of random 9-digit integers
int* getNineDigitArr(int arrLength) {
    int* arr = (int*)malloc(arrLength * sizeof(int));
    if (arr == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }

    for (int i = 0; i < arrLength; i++) {
        arr[i] = getNineDigitNumber();
    }

    return arr;
}



// Generates a random 4-digit number
int getFourDigitNumber() {
    return rand() % 9000 + 1000; }


// Function to create an array of random 4-digit numbers
int* getFourDigitArray(int n) {
    srand((unsigned)time(NULL)); // Seed the random number generator with the current time


    int* array = (int*)malloc(n * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        array[i] = getFourDigitNumber();
    }

    return array;
}



//function thst creates a password by choosing random valid chars in a char array
    char* passwordCreate() {
    int minLength = 6;
    int maxLength = 16;
    int passwordLength = (rand() % (maxLength - minLength + 1)) + minLength;

    char* password = (char*)malloc((passwordLength + 1) * sizeof(char)); // +1 for the null terminator
    if (password == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }

    const char printableCharacters[] = "0123456789"
                                       "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                       "abcdefghijklmnopqrstuvwxyz"
                                       "!#$%&'()*+-.:;<=>?@[\\]^_`{|}~";

    int numPrintableCharacters = sizeof(printableCharacters) - 1; // Exclude the null terminator

    
int i=0;
    for ( i = 0; i < passwordLength; i++) {
        int randomIndex = rand() % numPrintableCharacters;
        password[i] = printableCharacters[randomIndex];
    }

    password[passwordLength] = '\0'; //null-terminating password string
    return password;
}
