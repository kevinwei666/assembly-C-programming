/***************************************************************************
 * file name   : assembler.c                                               *
 * author      : tjf & you                                                 *
 * description : This program will assemble a .ASM file into a .OBJ file   *
 *               This program will use the "asm_parser" library to achieve *
 *			     its functionality.										   * 
 *                                                                         *
 ***************************************************************************
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "asm_parser.h"



int main(int argc, char** argv) {

	char* filename = NULL ;					// name of ASM file
	char  program [ROWS][COLS] ; 			// ASM file line-by-line
	char  program_bin_str [ROWS][17] ; 		// instructions converted to a binary string
	unsigned short int program_bin [ROWS] ; // instructions in binary (HEX)
    char s[100] = " R,";
    char *token;
    
    printf ("# of arguments passed: %d\n", argc) ;
    if(argc>=2){
       for (int i=0; i< argc ; i++) {
           printf ( "argv[%d] = %s\n", i, argv[i] ) ;
        }
    }
    else{
       printf("error1: usage: ./assembler <assembly_file.asm>\n"); 
       return 1;
    }
    filename=argv[1];
      FILE *my_file ;
      my_file = fopen (filename, "r");
      if (my_file == NULL) { 
          printf("there is nothing, there is no file here\n");
          return 1 ; 
      }
     else{
        printf("there is sth \n");
         }
    
    char cg;
    int countfile=0;
     for (cg = getc(my_file); cg != EOF; cg = getc(my_file)) 
        if (cg== '\n') // Increment count if this character is newline 
            countfile = countfile + 1;
   
    printf("this is filename %s\n",filename);
    printf("this number line of file %d\n",countfile);
    
    
    printf("transfer the content in file to 2D array gets!!! %d\n", read_asm_file(filename,program));
    
    int rowNum=0;
    int counter=0;
    int lengthbin=0;
    
   
    
    printf("the length  bin in main !!!! is %d\n", lengthbin);
   for(int i=0; i<countfile;++i){
       char *row1;
       char *newRow;
    row1=&program[i][0];
    
    printf("the first string is %s\n", row1);
    char  convertedFinalAdd[100];
    parse_instruction(row1, convertedFinalAdd);
    printf("the final convertedFinalAdd is %s\n",convertedFinalAdd);
       
       for(int j=0; j<17;++j){
           
           program_bin_str[i][j]=convertedFinalAdd[j];
           
       }
       
       newRow=&program_bin_str[i][0];
       printf("the new array is %s\n", newRow);
       
       int ret=str_to_bin (convertedFinalAdd);
       printf("the hex result:%X\n",ret);
       program_bin[i]=ret;
       printf("in the program_bin array %X\n",program_bin[i]);
       
   }
      
 
    write_obj_file 	(filename, program_bin);
    
    
    fclose (my_file) ;


    return (0) ;

}
