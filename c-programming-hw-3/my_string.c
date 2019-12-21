/**************************************************************
 * file name   : my_string.c                                  *
 * author      : tjf & you                                    *
 * description : this C-file defines the functions previously *
 *               declared in the my_string.h header file      *
 *                                                            *
 *                                                            *
 **************************************************************
 *
 */
#include <string.h>
#include "my_string.h"

// strlen functions takes in a pointer to a string and return its length
//
size_t2 my_strlen  (const char *str) {

	size_t2 len = 0 ;
	while (str[len] != '\0') {  // count up to the first NULL
		len++ ; 
	}
	return (len) ;

}

size_t2 my_strlen2 (const char* str) {

	const char* s;
	for (s = str; *s; ++s) ;
	return (s - str);

}


char* my_strcpy  (char *dest, const char *src){
    
    int len1=0;
    len1=strlen(dest);
    int len2=0;
    len2=strlen(src);
    if(len2==0){//check if the length of source is 0 then return null
        
        return NULL;
    }
    else{
    for(int i=0; i<len2;++i){
                  
          dest[i]=src[i];
        }
        return(dest);
    }
    
        
    }


 char* my_strcpy2 (char *dest, const char *src){
    
    char *result = dest;//pointer to dest
    while ((*dest++ = *src++) ) ;//assign the value
    return result;
    
      
 }
    
char* my_strchr  (const char *str, int c) {
    
    int len=0;
    int a=0;
    len=strlen(str);
    char new_string[len];
    for(int i=0; i<len; ++i){
        if(str[i]==c){
            a=i;
            break;//if find the target, break the loop
        }   
    }
    for (int j=0;j<len;++j){
        new_string[j]=str[j+a];//set the new char
    } 
    
   return(new_string);
    
}

char* my_strchr2 (const char *str, int c){
       
    int len=0;
    len=strlen(str);
    const char *ptr;
    char *result;
    for(int i=0; i<len; ++i, str++){
        if(*str=='c'){    
            ptr=str;
            break;
        }     
    }
    
    while ((*result++ = *ptr++) ) ;
    return result;
    
    
}

char* my_strcat  (char *dest, const char *src){
    
    int len1=0;
    int len2=0;
    len1=strlen(dest);
    len2=strlen(src);
    
    for (int i=0; i<len2; ++i){
        
        dest[i+len1]=src[i];
    }
    
    return(dest);
}

char* my_strcat2 (char *dest, const char *src) {    
    int len1=0;
    len1=strlen(dest);   
    char *ptr;
    ptr=dest+len1+1;    
    while ((*ptr++ = *src++));    
    return dest;    
}

int my_strcmp  (const char *str1, const char *str2){
    
    int sumOfstr1=0;
    int sumOfstr2=0;
    int c=0;
    int len1=strlen(str1);
    int len2=strlen(str2);
    
    for (int i=0; i<len1; ++i){

        sumOfstr1+=str1[i];
    
    }
     for (int j=0; j<len2; ++j){

         sumOfstr2+=str2[j];
    
     }
    
     if (sumOfstr2==sumOfstr1){
        
        return c;
            
     }
    
    if (sumOfstr1>sumOfstr2){
         c=1;
        return c;
    }
    
     c=-1;
    return c;
    
}

int my_strcmp2 (const char *str1, const char *str2){
    int sumOfstr1=0;
    int sumOfstr2=0;
    char *ptr1;
    char *ptr2;
    for(ptr1=str1; *ptr1; ptr1++)
        sumOfstr1+=*ptr1;
    
    for(ptr2=str2; *ptr2; ptr2++)
        sumOfstr2+=*ptr2;
   int c=0; 
     if (sumOfstr2==sumOfstr1){
        return c;      
     }   
    if (sumOfstr1>sumOfstr2){
         c=1;
        return c;
    }    
     c=-1;
    return c;   
}
//reveuse the string
void  my_strrev (char *my_string){
    
    int len=strlen(my_string);
    char* startOfstr;
    char* endOfstr;
    char a;
    
    startOfstr=my_string;
    endOfstr=my_string+len-1;
    
   while(endOfstr>startOfstr){
        a=*startOfstr;
        *startOfstr=*endOfstr;
        *endOfstr=a;
        startOfstr++;
        endOfstr--;
    }    
}

void  my_strccase (char *my_string){
    
    int len=strlen(my_string);
    for(int i=0; i<len; ++i){
       //use ASCII, check it is lowercase or uppercase
        if(my_string[i]>=97 && my_string[i]<=122){
            
            my_string[i]=my_string[i]-32;
        }
        else if(my_string[i]>=65 && my_string[i]<=90){
            my_string[i]=my_string[i]+32;
        }
    
    }        
}

char* my_strtok(char *str, const char* delim) {
    static char* ptr;
    if(str != NULL) ptr = str;
    if(ptr[0] == '\0')//if the length of string is 0
    {
        return NULL;}
    char *ret = ptr, *a;
    const char *d;
    for(a = ptr; *a !='\0'; a++) {
        //find the deli
        for(d = delim; *d != '\0'; d++) {
            if(*a == *d) {
                *a = '\0';
                ptr = a+1;
                if(a == ret) { 
                    ret++; 
                    continue; //out of the loop
                }
                return ret;
            }
        }
    }
    return ret;
}

/* CIT 593 students: TODO: implement the remaining string functions
   that were declared in my_string.h */