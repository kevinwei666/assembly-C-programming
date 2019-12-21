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


int main ()
{
  char str[] ="h-e-l-l-o, kevin, nice to m*e&e!t u.";
  char * ptr;//set the pointer
  printf ("result \"%s\" :\n",str);
  ptr = my_strtok(str," .-,!&*");//to set the symbol to split
  while (ptr != NULL)
  {
    printf ("%s\n",ptr);
    ptr = my_strtok(NULL, " .-,*&!");//to set the symbol to split
  }
  return 0;
}