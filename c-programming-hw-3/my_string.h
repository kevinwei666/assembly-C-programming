/**************************************************************
 * file name   : my_string.h                                  *
 * author      : tjf                                          *
 * description : this header file declares the functions for  *
 *               the "my_string" library that will mimc those *
 *               in the standard "string.h" C-library         *
 *                                                            *
 **************************************************************
 *
 */

/* a typedef to save us from writing "unsigned long" */

typedef unsigned long size_t2 ;


/* functions to determine the length of a string */

size_t2 my_strlen  (const char *str) ; 
size_t2 my_strlen2 (const char *str) ;

/* functions to copy a string */

char* my_strcpy  (char *dest, const char *src) ;
char* my_strcpy2 (char *dest, const char *src) ;

/* functions to search a string */

char* my_strchr  (const char *str, int c) ;
char* my_strchr2 (const char *str, int c) ;

/* functions to concatenate string */

char* my_strcat  (char *dest, const char *src) ;
char* my_strcat2 (char *dest, const char *src) ;

/* functions to compare two strings */

int my_strcmp  (const char *str1, const char *str2) ;
int my_strcmp2 (const char *str1, const char *str2) ;

// function to reverse a string

void  my_strrev (char *my_string);


// function to change the uppercase and lowercase

void  my_strccase (char *my_string);


char* my_strtok(char *str, const char* delim);
