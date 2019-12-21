/************************************************************************/
/* File Name : lc4.c 													*/
/* Purpose   : This file contains the main() for this project			*/
/*             main() will call the loader and disassembler functions	*/
/*             															*/
/* Author(s) : tjf and you												*/
/************************************************************************/

#include <stdio.h>
#include "lc4_memory.h"
#include "lc4_loader.h"
#include "lc4_disassembler.h"

/* program to mimic pennsim loader and disassemble object files */
// int main (int argc, char** argv)
int main () {

	/**
	 * main() holds the linked list &
	 * only calls functions in other files
	 */
    char* filename=NULL;
    
    
//      printf ("# of arguments passed: %d\n", argc) ;
//        if(argc>=2){
//        for (int i=0; i< argc ; i++) {
//            printf ( "argv[%d] = %s\n", i, argv[i] ) ;
//         }
//         }
//        else{
//        printf("error1: usage: ./lc4 <object_file.obj>\n"); 
//        return 1;
//     }
        row_of_memory* memory = NULL ;
        filename="testfile.obj";
        //filename=argv[1];
        FILE *a=open_file(filename);

        parse_file(a, &memory);
        
      
        reverse_assemble (memory);
        print_list(memory);
        int d=delete_list(&memory);
        printf("\n\n after deletion!!!!!!!\n");
         print_list(memory);
	     printf("the d is %d\n",d);
    
    

    //printf("the file here is %s\n",open_file(filename));

	/* step 1: create head pointer to linked list: memory 	*/
	//row_of_memory* memory = NULL ;


	/* step 2: determine filename, then open it		*/
	/*   TODO: extract filename from argv, pass it to open_file() */


	/* step 3: call function: parse_file() in lc4_loader.c 	*/
	/*   TODO: call function & check for errors		*/


	/* step 4: call function: reverse_assemble() in lc4_disassembler.c */
	/*   TODO: call function & check for errors		*/


	/* step 5: call function: print_list() in lc4_memory.c 	*/
	/*   TODO: call function 				*/


	/* step 6: call function: delete_list() in lc4_memory.c */
	/*   TODO: call function & check for errors		*/


	/* only return 0 if everything works properly */
	return 0 ;
}

