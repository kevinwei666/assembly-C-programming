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

int main() {

	// a string we will test with
	char my_string [100] = "Tom" ;
    
	// test of strlen() functions 
	printf ("Sample string: \"%s\" \n", my_string) ;
    
	printf (" string's length: strlen()     = %lu \n",   strlen  (my_string)) ;
	printf (" string's length: my_strlen()  = %lu \n", my_strlen (my_string)) ;
	printf (" string's length: my_strlen2() = %lu \n", my_strlen2(my_string)) ;

    /* CIT 593 students: TODO: add code to test your my_string.h functions */
    //test of my_strcpy functions
    char source[100]="hello, kevin";
    char destination[100];
    printf("Final copied string : %s\n", my_strcpy(destination,source));
    printf("Final2 copied string : %s\n", my_strcpy2(destination,source));
    
    //test of my_strchr functions
    char my_string2[100]="hello, kevin";
    char test_char='e';
    printf("my_strchr,the result  string : %s\n", my_strchr(my_string2, test_char));
    printf("my_strchr,the result2  string : %s\n", my_strchr(my_string2, test_char));
    //test of my_strcat functions
    
    char my_string3[100]="hello, kevin";
    char my_string4[100]="hhhh";
    printf("my_strcat,the result  string : %s\n", my_strcat(my_string3, my_string4));
    printf("my_strcat,the result2  string : %s\n", my_strcat2(my_string3, my_string4));
    //test of strcmp functions
    
    char my_string5[100]="a";
    char my_string6[100]="hello, kevin";
    int ret=my_strcmp(my_string5,my_string6);
    
     if (ret==0){
         printf(" strcmp,test1 equal\n");
     }
    else if (ret==1){
         printf("strcmp,test1 str1 is larger than str2\n");
     }
    else if (ret==-1){
         printf(" strcmp,test1 str1 is less than str2\n");
     }
    else{
        printf(" strcmp,test1 nothing: %d\n", ret);
    }
    int ret2=my_strcmp2(my_string5,my_string6);
    if (ret2==0){
         printf("strcmp, test2 equal\n");
     }
    else if (ret2==1){
         printf("strcmp,test2 str1 is larger than str2\n");
     }
    else if (ret2==-1){
         printf(" strcmp,test2 str1 is less than str2\n");
     }
    else{
        printf(" strcmp,test2 nothing: %d\n", ret);
    }
    
    
    
    
	return (0) ;

}
