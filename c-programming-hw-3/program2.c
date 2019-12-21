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
	char my_string [100] = "HelloKevinGoodLuck" ;
    
	// test of strlen() functions 
	printf ("Sample string: \"%s\" \n", my_string) ;
    printf ("test of reverse string\n") ;
    
    my_strrev (my_string);
    
    printf ("Sample string: %s \n", my_string) ;
    
    printf ("test of convert string\n") ;
    
    my_strccase(my_string);
    
    printf ("new string: %s \n", my_string) ;
    
   
    
	return (0) ;

}
