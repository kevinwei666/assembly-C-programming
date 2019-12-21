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

	//to show the sentence 
    char* str="I LOVE CIT593";
    
    lc4_puts(str);
    
    int a[3] = {1, 2, 3} ;
    int * var = &a[0]

    int* var = a ;
     print ("the value here is %d\n",var [0]) ;
//      print (a [0]) ;
//      print (*var ) ;
//      var++;
//      print (var [0]);
//      print (a [0]);

	return (0) ;

}
