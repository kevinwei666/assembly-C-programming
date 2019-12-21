/***************************************************************************
 * file name   : asm_parser.c                                              *
 * author      : tjf & you                                                 *
 * description : the functions are declared in asm_parser.h                *
 *               The intention of this library is to parse a .ASM file     *
 *			        										               * 
 *                                                                         *
 ***************************************************************************
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "asm_parser.h"

int read_asm_file2 (char* filename, char program [ROWS][COLS] ){
    
            FILE *my_file ;
            int byte_read ;
            int j=0;//row number in array
            my_file = fopen (filename, "r");
            if (my_file == NULL) { 
                printf("error2: read_asm_file() failed\n"); 
                printf("you are in the function!\n");
                return 2 ; 
            }
            do {
               for(int i=0; i<COLS;++i){

                   byte_read = fgetc (my_file) ;
                  if(byte_read=='\n'){
                       j++;
                       i=-1;
                   } 
                  if(byte_read!='\n'){
                   program[j][i]=byte_read;
                   }

                                   
               } 

            if (byte_read == EOF) break ;

          }  while (1) ;
          
    printf("the value of j in final %d\n",j);

          fclose (my_file) ;

          return 0;  
}


int read_asm_file (char* filename, char program [ROWS][COLS] ){
    
    FILE *my_file ;
    char buffer1[COLS];
    char buffer2[COLS];
    my_file = fopen (filename, "r");
    int j=0;//counter
    if (my_file == NULL) { 
        
        printf("error2: read_asm_file() failed\n"); 
        printf("you are in the function!\n");
        return 2 ; 
    }
    
    while(1){
        //fgets (buffer1, COLS, my_file);
        if(fgets (buffer1, COLS, my_file)==NULL) break;
        for(int a=0; a<COLS;++a){
        if(buffer1[a]!='\n'){
            buffer2[a]=buffer1[a];
            }
        else{
            buffer2[a]=buffer1[a+1];
        }
          if(buffer1[a]==NULL) break;    
         }
        
        
        for(int i=0; i<COLS; ++i){
        
        program[j][i]=buffer2[i];
        
        
    }
        
       
     j++;   
    }
    printf("the j in the second function is %d\n",j);
        
    fclose (my_file) ;
    
    return 0;
    
}


int parse_instruction 	(char* instr, char* instr_bin_str){
    char* otherInstr;
    char *token;
    char s[100] = " R,";
    char holder[COLS]=" ";
    //printf("the instruction1 %s\n", instr);
    strcpy(otherInstr, instr);
   // printf("the other instruction1 %s\n", otherInstr);
    token=strtok(instr, s);
    if(strcmp(token,"ADD")==0){
       // printf("hello!here\n");
       // printf("the instruction2 %s\n", instr);
        parse_add(otherInstr, holder);
    }
     else if(strcmp(token,"SUB")==0){
        
        parse_sub(otherInstr, holder);
    }
     else if(strcmp(token,"MUL")==0){
        
        parse_mul(otherInstr, holder);
    }
     else if(strcmp(token,"DIV")==0){
        
        parse_div(otherInstr, holder);
    }
     else if(strcmp(token,"O")==0){
        
        parse_or(otherInstr, holder);
    }
     else if(strcmp(token,"XO")==0){
        
        parse_xor(otherInstr, holder);
    }
    else if(strcmp(token,"AND")==0){
        
        parse_and(otherInstr, holder);
    }
    else{
        printf("parse_instruction() failed.\n");
        return 3;
    }
    
   // printf("the holder!!!! is %s\n",holder);
    strcpy(instr_bin_str,holder);
    return 0;
}

int parse_and 	(char* instr, char* instr_bin_str ){
    
     char *token;
    char s[100] = " R,";
    char holder[COLS]=" ";
    char regConverted[100];
    int j=0;//counter
    
    token=strtok(instr, s);
    
    if((strcmp(token,"AND")!=0)){
        printf("this is not add! error4: parse_and() failed\n");
        return 4;
        
    }
    else{
    while(token!=NULL){
        if(strcmp(token,"AND")==0){
            holder[0]='0';
            holder[1]='1';
            holder[2]='0';
            holder[3]='1';
            holder[10]='0';
            holder[11]='0';
            holder[12]='0';
        }
        if(strcmp(token,"0")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
        if(strcmp(token,"1")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"2")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"3")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"4")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"5")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"6")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"7")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        token = strtok(NULL, s);
        
          j++;   
    }
    }    

            
    printf("the holder is %s\n",holder);
    strcpy(instr_bin_str,holder);
    
    
    return 0;
    
    
    
    
}
int parse_add 	(char* instr, char* instr_bin_str ){
    
    char *token;
    char s[100] = " R,";
    char holder[COLS]=" ";
    char regConverted[100];
    int j=0;//counter
    
    token=strtok(instr, s);
    
    if((strcmp(token,"ADD")!=0)){
        printf("this is not add! error4: parse_add() failed\n");
        return 4;
        
    }
    else{
    while(token!=NULL){
        if(strcmp(token,"ADD")==0){
            holder[0]='0';
            holder[1]='0';
            holder[2]='0';
            holder[3]='1';
            holder[10]='0';
            holder[11]='0';
            holder[12]='0';
        }
        if(strcmp(token,"0")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
        if(strcmp(token,"1")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"2")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"3")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"4")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"5")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"6")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"7")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        token = strtok(NULL, s);
          j++;   
    }
    }    

            
    printf("the holder is %s\n",holder);
    strcpy(instr_bin_str,holder);
    
    
    return 0;
    
}

int parse_reg (char reg_num, char* instr_bin_str){
    
    
    if(reg_num=='0'){
        printf("here\n");
        char *newone="000";
        strcpy(instr_bin_str,newone);
        
    }
    else if(reg_num=='1'){
        
        char *newone="001";
        strcpy(instr_bin_str,newone);
        
    }
    else if(reg_num=='2'){
        
        char *newone="010";
        strcpy(instr_bin_str,newone);
        
    }
    else if(reg_num=='3'){
        
        char *newone="011";
        strcpy(instr_bin_str,newone);
        
    }
    else if(reg_num=='4'){
        
        char *newone="100";
        strcpy(instr_bin_str,newone);
        
    }
    else if(reg_num=='5'){
        
        char *newone="101";
        strcpy(instr_bin_str,newone);
        
    }
    else if(reg_num=='6'){
        
        char *newone="110";
        strcpy(instr_bin_str,newone);
        
    }
    else if(reg_num=='7'){
        
        char *newone="111";
        strcpy(instr_bin_str,newone);
        
    }
    else{
        printf("error 5: the parse_reg failed\n");
        return 5;
        
    }
   
    return 0;
    
}

int parse_sub  (char* instr, char* instr_bin_str ){
    
    char *token;
    char s[100] = " R,";
    char holder[COLS]=" ";
    char regConverted[100];
    int j=0;//counter
    
    token=strtok(instr, s);
    
    if((strcmp(token,"SUB")!=0)){
        printf("! error4: parse_sub() failed\n");
        return 4;
        
    }
    else{
    while(token!=NULL){
        if(strcmp(token,"SUB")==0){
            holder[0]='0';
            holder[1]='0';
            holder[2]='0';
            holder[3]='1';
            holder[10]='0';
            holder[11]='1';
            holder[12]='0';
        }
        if(strcmp(token,"0")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
        if(strcmp(token,"1")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"2")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"3")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"4")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"5")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"6")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"7")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        token = strtok(NULL, s);
          j++;   
    }
    }    
           
    printf("the holder is %s\n",holder);
    strcpy(instr_bin_str,holder);   
    return 0;  
}


int parse_mul (char* instr, char* instr_bin_str ){
    
     char *token;
    char s[100] = " R,";
    char holder[COLS]=" ";
    char regConverted[100];
    int j=0;//counter
    
    token=strtok(instr, s);
    
    if((strcmp(token,"MUL")!=0)){
        printf("! error4: parse_mul() failed\n");
        return 4;
        
    }
    else{
    while(token!=NULL){
        if(strcmp(token,"MUL")==0){
            holder[0]='0';
            holder[1]='0';
            holder[2]='0';
            holder[3]='1';
            holder[10]='0';
            holder[11]='0';
            holder[12]='1';
        }
        if(strcmp(token,"0")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
        if(strcmp(token,"1")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"2")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"3")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"4")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"5")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"6")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"7")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        token = strtok(NULL, s);
          j++;   
    }
    }    
           
    printf("the holder is of multiple %s\n",holder);
    strcpy(instr_bin_str,holder);   
    return 0;  
    
    
}

int parse_div (char* instr, char* instr_bin_str ){
    
     char *token;
    char s[100] = " R,";
    char holder[COLS]=" ";
    char regConverted[100];
    int j=0;//counter
    
    token=strtok(instr, s);
    
    if((strcmp(token,"DIV")!=0)){
        printf("! error4: parse_div() failed\n");
        return 4;
        
    }
    else{
    while(token!=NULL){
        if(strcmp(token,"DIV")==0){
            holder[0]='0';
            holder[1]='0';
            holder[2]='0';
            holder[3]='1';
            holder[10]='0';
            holder[11]='1';
            holder[12]='1';
        }
        if(strcmp(token,"0")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
        if(strcmp(token,"1")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"2")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"3")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"4")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"5")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"6")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"7")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        token = strtok(NULL, s);
          j++;   
    }
    }    
           
    printf("the holder is of div %s\n",holder);
    strcpy(instr_bin_str,holder);   
    return 0;  
    
    
}

int parse_or (char* instr, char* instr_bin_str ){
    
      char *token;
    char s[100] = " R,";
    char holder[COLS]=" ";
    char regConverted[100];
    int j=0;//counter
    
    token=strtok(instr, s);
    
    if((strcmp(token,"O")!=0)){
        printf("! error4: parse_or() failed\n");
        return 4;
        
    }
    else{
    while(token!=NULL){
        if(strcmp(token,"O")==0){
            holder[0]='0';
            holder[1]='1';
            holder[2]='0';
            holder[3]='1';
            holder[10]='0';
            holder[11]='1';
            holder[12]='0';
        }
        if(strcmp(token,"0")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
        if(strcmp(token,"1")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"2")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"3")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"4")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"5")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"6")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"7")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        token = strtok(NULL, s);
          j++;   
    }
    }    
           
    printf("the holder is %s\n",holder);
    strcpy(instr_bin_str,holder);   
    return 0;  
       
}

int parse_xor (char* instr, char* instr_bin_str ){
    
     char *token;
    char s[100] = " R,";
    char holder[COLS]=" ";
    char regConverted[100];
    int j=0;//counter
    
    token=strtok(instr, s);
    
    if((strcmp(token,"XO")!=0)){
        printf("! error4: parse_xor() failed\n");
        return 4;
        
    }
    else{
    while(token!=NULL){
        if(strcmp(token,"XO")==0){
            holder[0]='0';
            holder[1]='1';
            holder[2]='0';
            holder[3]='1';
            holder[10]='0';
            holder[11]='1';
            holder[12]='1';
        }
        if(strcmp(token,"0")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
        if(strcmp(token,"1")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"2")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"3")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"4")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"5")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        
         if(strcmp(token,"6")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];                
            }            
        }
        
         if(strcmp(token,"7")==0){
            char a=*token;
            parse_reg(a, regConverted);
            if(j==1){
            holder[4]=regConverted[0];
            holder[5]=regConverted[1];
            holder[6]=regConverted[2];
            }
            if(j==2){
            holder[7]=regConverted[0];
            holder[8]=regConverted[1];
            holder[9]=regConverted[2];
                
            }
            if(j==3){
            holder[13]=regConverted[0];
            holder[14]=regConverted[1];
            holder[15]=regConverted[2];
                
            }
            
        }
        token = strtok(NULL, s);
          j++;   
    }
    }               
    printf("the holder is %s\n",holder);
    strcpy(instr_bin_str,holder);   
    return 0;     
}
unsigned short int str_to_bin (char* instr_bin_str) {
    unsigned short int program_bin [ROWS] ;
    unsigned short int *result[ROWS];
    char number[100];
    strcpy(number, instr_bin_str);
    
    char holder[100];
    long int convertedHex[100];
    int partlength=4;
    int length=strlen(instr_bin_str);
    
    char* endPtr;
    long bigNumber;
    int base;

      
      bigNumber = strtol(number, &endPtr, 2); 
    
    if(bigNumber==0){
        printf("str_to_bin failed\n");
        return 6;
    }
    

        return bigNumber;

    
    
}
int write_obj_file 	(char* filename, unsigned short int program_bin[ROWS] ){
    int counter=0;
    for(int ii=0; ii<ROWS; ii++){
      
        if(program_bin[ii]==NULL) break;
        counter++;
        
    }
    printf("the length in function %d\n", counter);
    char filenamecopy[100];
    strcpy(filenamecopy,filename);
    
     printf("the new name is %s\n",filenamecopy);
    int w=0;
    for(int q=0; q<100;++q){
        if(filenamecopy[q]=='.'){
            w=q;            
        break;
            }       
    }
    filenamecopy[w+1]='o';
    filenamecopy[w+2]='b';
    filenamecopy[w+3]='j';
    filenamecopy[w+4]='\0';
    
    printf("the new name is %s\n",filenamecopy);
    FILE *my_filenew ;
    my_filenew = fopen (filenamecopy, "wb");
     if (my_filenew == NULL) { 
          printf("there is nothing, there is no file here\n");
          return 7 ; 
      }
    
    int line1=0xDECA;
    fwrite(&line1, sizeof(int), 1, my_filenew);
    fwrite(&counter, sizeof(unsigned short int), 1, my_filenew);
    int thereverseleft;
    int thereverseright;
    
     for(int d=0; d<counter;d++){
         //shiffing the number to reverse
        thereverseright=program_bin[d]>>8;
        thereverseleft=program_bin[d]<<8;
        program_bin[d]=thereverseright+thereverseleft;
        fwrite(&program_bin[d], sizeof(unsigned short int), 1, my_filenew);
        
    }
    
   

    fclose (my_filenew);
    
    return 0;
    
    
    
}






