#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "generate.h"



//function that read the names text file and creates a name array that contains the names
char** readFile ( char* filename, int* numStrings) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file %s\n", filename);
        exit(1);
    }


    // Count the number of strings in the file
    int count = 1000;
    

    // Allocating memory for the array of strings
    char** stringArray = (char**)malloc(count * sizeof(char*));
    if (stringArray == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Reading the strings into the array
    for (int i = 0; i < count; i++) {
        char buffer[100]; 
        if (fgets(buffer, sizeof(buffer), file) != NULL) {
            // Remove the newline character if present
            size_t length = strlen(buffer);
            if (length > 0 && buffer[length - 1] == '\n') {
                buffer[length - 1] = '\0';
            }
            stringArray[i] = strdup(buffer);
            if (stringArray[i] == NULL) {
                printf("Memory allocation failed for string %d\n", i);
                exit(1);
            }
        }
    }

    *numStrings = count;
    fclose(file);
    return stringArray;
}


   
/*Function to create and write on the csv file, the function will iterate through the colList array  
and print the first column sorted , and the rest of the columns will be random.
The function will check the column number using a switch statement , and if it is the first column , then print the soted array
, otherwise choose randomly using rand() function*/
    void writeToFile(char** email, char** firstnames, char** lastnames, char** country,int* colList, int colLength,int numbOfRows, char* filename, int* phoneIndex,
    int* lastFourDigits, int* sin)

    {
srand(time(NULL)); // seed random number function with time
        //creating a file csv to write on it in w mode
         FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing\n");
        return;}

        //the collist array has the id of columns that we need
        int phoneCounter=0;
        int countryCounter=0;
        int firstNameCtr=1;
        int lastNameCtr=1;
        int sinCounter=0;
       
     
        int tempRand=rand()%999;
        
        int i=0;
       
        int j=0;
int rowCounter=1;

        for(j=0;j<numbOfRows;j++){
            tempRand=rand()%999;
         
        for(i=0;i<=colLength;i++){


            //switch statment for the columns
            switch(colList[i]){
case 1:


if(i>0){fprintf(file,",");};
 if(j==0){fprintf(file,"Id number");};
 if(j>0){fprintf(file,"%d", rowCounter++);}
break;


case 2:
if(firstNameCtr==999){firstNameCtr=0;}

if(i>0){fprintf(file,",");}
if(j>0){if(i==0){fprintf(file,"%s",firstnames[firstNameCtr]);}; 
if(colList[0]==6){fprintf(file,"%s",firstnames[firstNameCtr]);}
else{if(i>0){fprintf(file,"%s",firstnames[tempRand]);};}}


 if(j==0){fprintf(file,"First name ");continue;};

break;

case 3:
if(lastNameCtr==999){lastNameCtr=0;}

if(i>0){fprintf(file,",");}

if(j>0){if(i==0){fprintf(file,"%s",lastnames[lastNameCtr]);}
if(colList[0]==6){fprintf(file,"%s",lastnames[lastNameCtr]); }
else{if(i>0){ fprintf(file,"%s",lastnames[tempRand]);};}}

if(j==0){fprintf(file,"Last Name");continue;}

break;

case 4:

if(countryCounter==195){countryCounter=0;}
if(i>0){fprintf(file,",");};
if(j>0){if(i==0){fprintf(file,"%s",country[countryCounter]);countryCounter++;}
if(i>0){ fprintf(file,"%s",country[rand()%195]);};}
 if(j==0){fprintf(file,"Country");continue;};

break;


case 5:


if (phoneCounter==9){phoneCounter=0;}
if(i>0){fprintf(file,","); };
if(j==0){fprintf(file,"Phone number");continue;};

if(j>0){if(i==0){fprintf(file,"%d - %d",phoneIndex[phoneCounter],lastFourDigits[phoneCounter]); phoneCounter++;}


if(i>0){fprintf(file,"%d-%d",phoneIndex[rand()%10],lastFourDigits[rand()%10]);}}


break;

case 6:
if(i>0){fprintf(file,","); };
if(j==0){fprintf(file,"Email");continue;};

if(j>0){if(i==0){fprintf(file,"%c%s@%s",firstnames[firstNameCtr][0],lastnames[lastNameCtr],email[rand()%99]) ;     }else{
if(colList[0]==2){fprintf(file,"%c%s@%s",firstnames[firstNameCtr][0],lastnames[tempRand],email[rand()%99]); }else{
if(colList[0]==3){fprintf(file,"%c%s@%s",firstnames[tempRand][0],lastnames[lastNameCtr],email[rand()%99]) ;} else{
fprintf(file,"%c%s@%s",firstnames[tempRand][0],lastnames[tempRand],email[rand()%99]);}}}}




break;


case 7:

if(sinCounter==numbOfRows){sinCounter=0;}
if(i>0){fprintf(file,",");};
if(j>0){if(i==0){fprintf(file,"%d",sin[sinCounter]);sinCounter++;}
if(i>0){ fprintf(file,"%d",sin[rand()%numbOfRows]);};}
 if(j==0){fprintf(file,"SIN");continue;};

break;

case 8:
if(i>0){fprintf(file,",");};
 if(j==0){fprintf(file,"Password");continue;};
 if(i>0){ fprintf(file,"%s",passwordCreate());};
 break;
            }//end of switch statement


        }; //end of inner for loop

firstNameCtr++;
lastNameCtr++;
fprintf(file,"\n");

        } //end of outer for loop

    }
    
    

    

  


