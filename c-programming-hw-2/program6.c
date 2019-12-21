/********************************************************
 * file name   : program1.c                             *
 * author      : Thomas Farmer                          *
 * description : Hello World Program                    *
 *                                                      *
 ********************************************************
*
*/

#include <stdio.h>
#include "program5_swap.h"

void swap (int a, int b) ;

int main () {
    
   int a = 5 ;
   int b = 10 ;
   printf ("a= %d\n", a) ;
   printf ("b= %d\n", b) ;
   swap (a, b) ;//swap them
   printf ("a= %d\n", a) ;
   printf ("b= %d\n", b) ;
    
    return (0) ;
	
}
