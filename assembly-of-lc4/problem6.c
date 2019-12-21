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

   int x_coordinate;
   int y_coordinate;
   int length;
   int width;
   int color;
   char c;
   char* str="game here! press j to move the rectangle to left and k to the right";
   int colorBlack=0;
   
    lc4_puts(str);
   
    x_coordinate = 50;
    y_coordinate = 50 ;
    length = 10;
    width = 10;
    color = 0x7C00;
        
  lc4_draw_rect (x_coordinate,y_coordinate,length,width,color);
    
  while (1) {
               
     c=lc4_getc();  //get the value from keyboard
       
    lc4_putc (c) ; //show it 
        
    //if char is j, move to right
    if (c=='j'){
        //the original rectangle is cover by black
        lc4_draw_rect (x_coordinate,y_coordinate,length,width,colorBlack);
        x_coordinate=x_coordinate+10;
        lc4_draw_rect (x_coordinate,y_coordinate,length,width,color);
    }     
    //if char is j, move to left
    else if (c=='k'){    
        //the original rectangle is cover by black
        lc4_draw_rect (x_coordinate,y_coordinate,length,width,colorBlack);
        x_coordinate=x_coordinate-10;         
        lc4_draw_rect (x_coordinate,y_coordinate,length,width,color);
        
    }          
   }
  
    return (0) ;

}
