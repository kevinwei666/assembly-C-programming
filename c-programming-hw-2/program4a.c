/********************************************************
 * file name   : program1.c                             *
 * author      : Thomas Farmer                          *
 * description : Hello World Program                    *
 *                                                      *
 ********************************************************
*
*/

#include <stdio.h>
void swap (int a, int b) {
    
    int c = 0 ;
    c = a ; /* swap values of a and b */
    a = b ;
    b = c ;
    printf ("a= %d\n", a) ;
    printf ("b= %d\n", b) ;
    return ;
    
}
int main () {
    
   int a = 5 ;
   int b = 10 ;
   printf ("a= %d\n", a) ;
   printf ("b= %d\n", b) ;
   swap (a, b) ;//call function
   printf ("a= %d\n", a) ;
   printf ("b= %d\n", b) ;
    
    return (0) ;
	
}
