/************************************************************************/
/* File Name : lc4_loader.c		 										*/
/* Purpose   : This file implements the loader (ld) from PennSim		*/
/*             It will be called by main()								*/
/*             															*/
/* Author(s) : tjf and you												*/
/************************************************************************/

#include <stdio.h>
#include <string.h>
#include "lc4_memory.h"
#include "lc4_disassembler.h"
#include <stdlib.h>

/* declarations of functions that must defined in lc4_loader.c */

FILE* open_file(char* file_name)
{
    FILE *my_file ;
      my_file = fopen (file_name, "r");
      if (my_file == NULL) { 
          printf("there is nothing, there is no file here\n");
          return NULL  ; 
      }
    
	return my_file;
}

int together(unsigned char a, unsigned char b){
    
    int firstone=a<<8;
    int finalresult=firstone+b;
    return finalresult;
    
}

int parse_file (FILE* my_obj_file, row_of_memory** memory)
{
	 unsigned  char  instrHolder[2];
     unsigned char adds[2];
     unsigned char numOfinstr[2];
     unsigned char instrvalue[2];
     unsigned char readchar;
     short unsigned int result;
     row_of_memory* headerPointer = *memory;
     //int counter=0;    
    
        while(1) {
            fread (instrHolder, sizeof(unsigned char), 2, my_obj_file); 
            
            if (instrHolder[0] == 0xCA && instrHolder[1] == 0xDE){ 
               
                
                fread (adds, sizeof(unsigned char), 2, my_obj_file);
                int alladdress=together(adds[0],adds[1]);
               
                fread (numOfinstr, sizeof(unsigned char), 2, my_obj_file);                
                int numb=together(numOfinstr[0],numOfinstr[1]);
                
                for(int i=0; i<numb;++i){
                    fread (instrvalue, sizeof(unsigned char), 2, my_obj_file);
                 
                    int theinstr=together(instrvalue[0], instrvalue[1]);
                   
                    add_to_list(&headerPointer, alladdress, theinstr);
                   
                    alladdress++;
 
              
                }
                                
            }
            if (instrHolder[0] == 0xC3 && instrHolder[1] == 0xB7){
                fread (adds, sizeof(unsigned char), 2, my_obj_file);
                int alladdress=together(adds[0],adds[1]);
                fread (numOfinstr, sizeof(unsigned char), 2, my_obj_file);
                int numb=together(numOfinstr[0],numOfinstr[1]);
                char* temp = malloc(numb + 1);
                fread(temp, 1, numb, my_obj_file);
                //temp[numb] = '\0';
                row_of_memory* target = search_address(headerPointer, alladdress);
                if (target == NULL){
                 add_to_list(&headerPointer, alladdress, 0);
                target = search_address(headerPointer, alladdress);
                }          
               if(strlen(temp)!=0) {               
                target->label = temp;
               }
                else{
                    free(temp);
                }
            }
          
            if (instrHolder[0] == 0xDA && instrHolder[1] == 0xDA){
                  fread (adds, sizeof(unsigned char), 2, my_obj_file);
//                   printf("the value here is %X AND %X\n", adds[0], adds[1]);
                  int alladdress=together(adds[0],adds[1]);
//                   printf("the address is %X\n",alladdress);
                  fread (numOfinstr, sizeof(unsigned char), 2, my_obj_file);                
                  int numb=together(numOfinstr[0],numOfinstr[1]);
//                   printf("the number is %X\n",numb);
                  for(int i=0; i<numb;++i){
                    fread (instrvalue, sizeof(unsigned char), 2, my_obj_file);
//                    printf("!!!in for loop the value here is %X AND %X\n", instrvalue[0], instrvalue[1]);
                    int theinstr=together(instrvalue[0], instrvalue[1]);
//                    printf("the instr is %X\n",theinstr);
                   
                    add_to_list(&headerPointer, alladdress, theinstr);
                   

                    alladdress++;
 
              
                }
    
              }
            
            
              

            if(feof(my_obj_file)) break;
           
        }       
       
         *memory = headerPointer;
    fclose(my_obj_file);

    return 0;
}

