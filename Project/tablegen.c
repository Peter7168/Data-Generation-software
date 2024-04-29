#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <string.h>
#include "io.h"
#include "generate.h"


int main(){
int menuChoice1;
char colList[50];
int rowCount;
char fileNm[50];
char proceed;

int arrLe=1000;
int countryArr=195; //length of country arr
int suffLe=100;  //length of email array


printf("  TableGen menu \n --------------- \n" );
printf("1.Generate new table \n 2. Exit \n Selection: ");
scanf("%d", &menuChoice1);

system("clear"); //clearing screen


//menu choice is chosen and based on value the output is given
if(menuChoice1==1){   printf("Column Options\n");
    printf("--------------\n");
    printf("1. User ID       5. Phone Number\n");
    printf("2. First Name    6. Email address\n");
    printf("3. Last Name     7. SIN\n");
    printf("4. Country       8. Password\n");
    printf("\n");
    printf("Enter column list (comma-separated, no spaces):\n");
} 

//if 2 is chosen then exit , and any other number leads to invalid choice
else{if(menuChoice1==2){printf("Goodbye and thanks for using TableGen"); exit(0);}

else{printf("invalid choice");};}



//if choice 1 is chosen in the first menu and the menu is printed , then we continue to receive inputs
if(menuChoice1==1){
 scanf("%s",colList);
printf("You entered: %s \n", colList);




    // enter row count scanner
printf("Enter row count (1<n< 1M): ");
scanf("%d",&rowCount);


//file name is entered
printf("Enter output file name(no suffix) :");
scanf("%s",fileNm);
 strcat(fileNm, ".csv"); //we add a .csv extentsion to the file by concatenating

//summary is printed
printf("Summary of properties: \n");
printf("Row counts: %d",rowCount);
printf("\nFile name: %s \n", fileNm);
printf("Table written successful to %s",fileNm);
printf("\nPress 'c' or 'C' to continue ");


//length of the colList variable, we will use it in colNumb function
size_t length = strlen(colList);

//creating array that contains the column ints
int* colArr=colNumb(colList,(length/2)+1);


//checking the c to proceed input
do{
scanf("%c", &proceed);
} while ( (proceed != 'c') && (proceed != 'C'));


//creating array for all last names, then sorting
char** lastNameList=readFile("last_names.txt",&arrLe);
sortStringsAlphabetically(lastNameList,999);


//creating array for first names, then sorting
char** firstNameList=readFile("first_names.txt",&arrLe);
sortStringsAlphabetically(firstNameList,999);

//creating an array for countries, then sorting
char** countryList=readFile("countries.txt",&countryArr);
sortStringsAlphabetically(countryList,195);

//creating an array for email suffixes
char** emailSuff=readFile("email_suffixes.txt",&suffLe);


//creating an array of random 9 digits to make the sin, and sorting
int* sin=getNineDigitArr(rowCount);
sortIntegers(sin,rowCount);



//creating and sorting array of phone index
int phoneIndex[]= {398, 270, 925, 867, 209, 429, 908, 997,
444, 219};
sortIntegers(phoneIndex,10);




//creating random phone last 4 digit array
 int* fourArray = getFourDigitArray(rowCount);



// all the previously creaated arrays will be taken as parameters for the writeToFile() function, that handles creating adn writing on the file
writeToFile(emailSuff, firstNameList, lastNameList, countryList,colArr, (length/2)+1,rowCount,fileNm,phoneIndex,fourArray,sin);
 



//FREEING THE ALLOCATED MEMORY

 // Free the individual strings
    for (int i = 0; i < 98; i++) {
        free(emailSuff[i]);
    }

    // Free the array of pointers
    free(emailSuff);




//FREEING MEMORY
for (int i = 0; i < 998; i++) {
        free(firstNameList[i]);
        free(lastNameList[i]);
    }

    // Free the array of pointers
    free(firstNameList);
    free(lastNameList);



// Free the individual strings in the countryList array
for (int i = 0; i < 195; i++) {
    free(countryList[i]);
}

// Free the array of pointers for countryList
free(countryList);

//free int arrays
free(fourArray);
free(sin);



}

return 0;}
