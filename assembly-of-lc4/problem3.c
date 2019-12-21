/********************************************************
 * file name   : problem2.c                             *
 * author      : Thomas Farmer
 * description : C program to call LC4-Assembly TRAP_PUTC
 *               the TRAP is called through the wrapper 
 *               lc4putc() (located in lc4_stdio.asm)   *
 ********************************************************
*
*/

int main() {

	char c ;	//the char that is used in this program	
    
    
    //when the input is not 'key enter'
    
   while(c!='\n'){
       
    c=lc4_getc();  //get c from the keyboard
       
    lc4_putc (c) ;  //show c on the screen
   }
   

	return (0) ;

}
