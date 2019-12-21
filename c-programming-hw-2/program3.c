/********************************************************
 * file name   : program1.c                             *
 * author      : Thomas Farmer                          *
 * description : Hello World Program                    *
 *                                                      *
 ********************************************************
*
*/

#include <stdio.h>

int main () {
   
    char name [50] ;
    float hw1,hw2,hw3,hw4, averagehw, midterm, final, finalaverage;
    
    printf ("Welcome to CIT 593\n ") ;
    
    printf ("Could you enter your name, please\n ") ;
    
    scanf ("%s", name) ;//enter name
    
    printf ("enter the score of hw1, please\n ") ;
    
    scanf ("%f", &hw1) ;//enter the hw1 score
    
    while(hw1<0.0){
        printf ("wrong input, please input your hw1 score again.\n ") ;
        scanf ("%f", &hw1) ;
    }
    
    printf ("enter the score of hw2, please\n ") ;
    
    scanf ("%f", &hw2) ;//enter the hw2 score
    
    while(hw2<0.0){
        printf ("wrong input, please input your hw2 score again.\n ") ;
        scanf ("%f", &hw2) ;
    }
    
    printf ("enter the score of hw3, please\n ") ;
    
    scanf ("%f", &hw3) ;//enter the hw2 score
    
    while(hw3<0.0){
        printf ("wrong input, please input your hw3 score again.\n ") ;
        scanf ("%f", &hw3) ;
    }
    
    printf ("enter the score of hw4, please\n ") ;
    
    scanf ("%f", &hw4) ;//enter the hw4 score
    
    while(hw4<0.0){
        printf ("wrong input, please input your hw4 score again.\n ") ;
        scanf ("%f", &hw4) ;
    }
   
    
    averagehw=((hw1+hw2+hw3+hw4)/400)*100;//ccalculate the averagehw
    
    printf ("enter the score of midterm, please\n ") ;
    
    scanf ("%f", &midterm) ;//get the midterm score
    
    while(midterm<0.0){
        printf ("wrong input, please input your midterm score again.\n ") ;
        scanf ("%f", &midterm) ;
    }
    
    
    
    printf ("enter the score of final, please\n ") ;
    scanf ("%f", &final) ;
     while(final<0.0){
        printf ("wrong input, please input your final score again.\n ") ;
        scanf ("%f", &final) ;
    }
    //calculation the final average
    finalaverage= averagehw*0.6+midterm*0.2+final*0.2;
    
     printf ("%s\n ", name) ;
     printf(" \t%-*s%9.2f %%\n",18,"HW average:",averagehw);
     printf(" \t%-*s%9.2f %%\n",18,"Midterm Grade:",midterm);
     printf(" \t%-*s%9.2f %%\n",18,"Final Exam Grade:",final);
     printf(" \t%-*s%9.2f %%\n",18,"Final Average:",finalaverage);
    
    
    return (0) ;
	
}
