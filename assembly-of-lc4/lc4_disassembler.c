/************************************************************************/
/* File Name : lc4_disassembler.c 										*/
/* Purpose   : This file implements the reverse assembler 				*/
/*             for LC4 assembly.  It will be called by main()			*/
/*             															*/
/* Author(s) : tjf and you												*/
/************************************************************************/

#include <stdio.h>
#include "lc4_memory.h"
#include <string.h>
#include "lc4_loader.h"
#include <stdlib.h>

void instrcAssign( row_of_memory * memory, short int contents, char* num){
      int d, t, s, secondinstrc;
      int imm5;
    s = contents & 7;
    int tem = contents & ((1<<5) - 1);
    imm5=tem & (1<<(5-1)) ? tem | (((~0) >> 5) << 5) : tem;
    d = (contents & 3584)>>9;
    char holder[100];
    char intruc[100]; 
     t = (contents & 448)>>6;
    
    
    if(strcmp(num, "NOP") == 0){
        sprintf(holder, "%s", "NOP");
    }
    
    
    if(strcmp(num, "0001") == 0){
//         printf("hahaha, it is here!!!!!!\n");

        if(32 & contents){           
            strcpy(intruc, "ADD");
            sprintf (holder, "%s R%d, R%d, #%d", intruc, d, t, imm5);
            //printf("the thing %s\n",holder);
        }
        else{
            
            secondinstrc = contents & 56;
            if(secondinstrc == 0){
                strcpy(intruc, "ADD");
            }
            else if(secondinstrc == 8){
                strcpy(intruc, "MUL");
            }
            else if(secondinstrc == 16){
                strcpy(intruc, "SUB");
            }
            else if(secondinstrc == 24){
                strcpy(intruc, "DIV");
            }
            s = contents & 7;
            if(intruc){
                sprintf(holder, "%s R%d R%d R%d", intruc, d, t, s);
//                 printf("the thing %s\n",holder);
            }
        }    
}
       
    if(strlen(holder)){
        memory->assembly = malloc(sizeof(char)*(strlen(holder)+1));
        strcpy(memory->assembly, holder);
      
        
    }
    
}

void finalResult( row_of_memory* memory, short int opcode, char* num){
    short unsigned int contents;
    while(memory != NULL){
       
        row_of_memory *new_holder = search_opcode(memory, opcode);
        if(new_holder != NULL){
//             printf("the import %X\n", new_holder->contents);
//             printf("the import %s\n", new_holder->assembly);
            if(new_holder->assembly == NULL){                 
                   contents = new_holder->contents;
                    instrcAssign(new_holder, contents, num);                
                memory = new_holder->next;
                              
            }
        }
        else{
            break;
        }
       
    }
    
}
int reverse_assemble (row_of_memory* memory)
{  
    row_of_memory* new_memory = memory;
    finalResult(new_memory, 0, "NOP");
    finalResult(new_memory, 1, "0001");
    //print_list (node);
	return 0 ;
}

