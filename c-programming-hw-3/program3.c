/**************************************************************
 * file name   : program1.c                                   *
 * author      : tjf & you                                    *
 * description : this C-file tests the functions of the       *
 *               "my_string" library                          *
 *                                                            *
 *                                                            *
 **************************************************************
 *
 */

#include <stdio.h>
#include <string.h>
#include "my_string.h"

int main (int argc, char** argv) {  
 int integerArray[argc];
 char newstringArray[argc][250];
 int* ptr=integerArray;
 int a=0;
 int b=0;
printf ("# of arguments passed: %d\n", argc) ;
for (int i=0; i< argc ; i++) {   
    int numbers;
    //check if there is a number
    if (sscanf(argv[i], "%d", &numbers) == 1) { 
       *ptr=numbers; 
        ptr++;//address++
        a++;//get the # of integers
     }
    else{       
      sprintf(newstringArray[b],argv[i]);
        b++;      //get # of string     
    }
}    
    printf("Answer of problem 3 \n");   
    for(int j=0; j< a ; j++){        
        printf ( "integerArray[%d] = %d\n", j, integerArray[j] ) ;
    }
    int d=0;//len of first string
    while(newstringArray[0][d]!='\0'){
        newstringArray[0][d]=newstringArray[0][d+2];
        ++d;       //get the length
    }     
    for( int n=0; n< b ; n++){     
        printf ( " %s", newstringArray[n] ) ;//print the string
    }  
    printf("\n");   
      return (0) ;
}