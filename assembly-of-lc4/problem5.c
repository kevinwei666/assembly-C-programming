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
//there are 3 rectangles here, first 2 rectangles are legal however the last one is out of the boundary, then 
//it won't be shown not he screen
   int x_cordination;
   int y_cordination;
   int length;
   int width;
   int color;
 
    x_cordination = 50;
    y_cordination = 5 ;
    length = 10;
    width = 5;
    color = 0x7C00;
        
   lc4_draw_rect (x_cordination,y_cordination,length,width,color);
    
   
    
    x_cordination = 10;
    y_cordination = 10 ;
    length = 50;
    width = 40;
    color = 0x03E0;
    
    lc4_draw_rect (x_cordination,y_cordination,length,width,color);
    
   
    
    x_cordination = 120;
    y_cordination = 100;
    length = 27;
    width = 10;
    color = 0x7FE0;
    lc4_draw_rect (x_cordination,y_cordination,length,width,color);

	return (0) ;

}
