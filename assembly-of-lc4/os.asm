;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  file name   : os.asm                                 ;
;  author      : 
;  description : LC4 Assembly program to serve as an OS ;
;                TRAPS will be implemented in this file ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;   OS - TRAP VECTOR TABLE   ;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.OS
.CODE
.ADDR x8000
  ; TRAP vector table
  JMP TRAP_GETC           ; x00
  JMP TRAP_PUTC           ; x01
  JMP TRAP_GETS           ; x02
  JMP TRAP_PUTS           ; x03
  JMP TRAP_TIMER          ; x04
  JMP TRAP_GETC_TIMER     ; x05
  JMP TRAP_DRAW_PIXEL     ; x06
  JMP TRAP_RESET_VMEM	  ; x07
  JMP TRAP_BLT_VMEM	      ; x08
  JMP TRAP_DRAW_RECT      ; x09

  ;
  ; CIT 593 - TO DO - add a vector for TRAP_DRAW_RECT
  ; place this vector at x8009
  ;
  
  
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;   OS - MEMORY ADDRESSES & CONSTANTS   ;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

  ;; these handy alias' will be used in the TRAPs that follow
  USER_CODE_ADDR .UCONST x0000	; start of USER code
  OS_CODE_ADDR 	 .UCONST x8000	; start of OS code

  OS_GLOBALS_ADDR .UCONST xA000	; start of OS global mem
  OS_STACK_ADDR   .UCONST xBFFF	; start of OS stack mem

  OS_KBSR_ADDR .UCONST xFE00  	; alias for keyboard status reg
  OS_KBDR_ADDR .UCONST xFE02  	; alias for keyboard data reg

  OS_ADSR_ADDR .UCONST xFE04  	; alias for display status register
  OS_ADDR_ADDR .UCONST xFE06  	; alias for display data register

  OS_TSR_ADDR .UCONST xFE08 	; alias for timer status register
  OS_TIR_ADDR .UCONST xFE0A 	; alias for timer interval register

  OS_VDCR_ADDR	.UCONST xFE0C	; video display control register
  OS_MCR_ADDR	.UCONST xFFEE	; machine control register
  OS_VIDEO_NUM_COLS .UCONST #128
  OS_VIDEO_NUM_ROWS .UCONST #124


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;; OS DATA MEMORY RESERVATIONS ;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.DATA
.ADDR xA000
OS_GLOBALS_MEM	.BLKW x1000
;;;  LFSR value used by lfsr code
LFSR .FILL 0x0001

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;; OS VIDEO MEMORY RESERVATION ;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.DATA
.ADDR xC000
OS_VIDEO_MEM .BLKW x3E00

X_GLO .UCONST xA000
Y_GLO .UCONST xA001
LEN_GLO_MEM .UCONST xA002
WID_GLO_MEM .UCONST xA003
COLR_GLO_MEM .UCONST xA004
OS_VIDEO_GLO_MEM .UCONST xA005
OS_ROWS_GLO_MEM .UCONST xA006
OS_COLS_GLO_MEM .UCONST xA007
R7_GLO_MEM .UCONST xA008

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;   OS & TRAP IMPLEMENTATIONS BEGIN HERE   ;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.CODE
.ADDR x8200
.FALIGN
  ;; first job of OS is to return PennSim to x0000 & downgrade privledge
  CONST R7, #0   ; R7 = 0
  RTI            ; PC = R7 ; PSR[15]=0


;;;;;;;;;;;;;;;;;;;;;;;;;;;   TRAP_GETC   ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Function: Get a single character from keyboard
;;; Inputs           - none
;;; Outputs          - R0 = ASCII character from ASCII keyboard

.CODE
TRAP_GETC
    LC R0, OS_KBSR_ADDR  ; R0 = address of keyboard status reg
    LDR R0, R0, #0       ; R0 = value of keyboard status reg
    BRzp TRAP_GETC       ; if R0[15]=1, data is waiting!
                         ; else, loop and check again...

    ; reaching here, means data is waiting in keyboard data reg

    LC R0, OS_KBDR_ADDR  ; R0 = address of keyboard data reg
    LDR R0, R0, #0       ; R0 = value of keyboard data reg
    RTI                  ; PC = R7 ; PSR[15]=0


;;;;;;;;;;;;;;;;;;;;;;;;;;;   TRAP_PUTC   ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Function: Put a single character out to ASCII display
;;; Inputs           - R0 = ASCII character to write to ASCII display
;;; Outputs          - none

.CODE
TRAP_PUTC
  LC R1, OS_ADSR_ADDR 	; R1 = address of display status reg
  LDR R1, R1, #0    	; R1 = value of display status reg
  BRzp TRAP_PUTC    	; if R1[15]=1, display is ready to write!
		    	        ; else, loop and check again...

  ; reaching here, means console is ready to display next char

  LC R1, OS_ADDR_ADDR 	; R1 = address of display data reg
  STR R0, R1, #0    	; R1 = value of keyboard data reg (R0)
  RTI			        ; PC = R7 ; PSR[15]=0


;;;;;;;;;;;;;;;;;;;;;;;;;;;   TRAP_GETS   ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Function: Get a string of characters from the ASCII keyboard
;;; Inputs           - R0 = Address to place characters from keyboard
;;; Outputs          - R1 = Lenght of the string without the NULL

.CODE
TRAP_GETS

 LC R5, OS_KBSR_ADDR  ; R5 = address of keyboard status reg
 LDR R5, R5, #0       ; R5 = value of keyboard status reg
 BRzp TRAP_GETS       ; if R5[15]=1, data is waiting!
                           
 LC R5, OS_KBDR_ADDR  ; R5 = address of keyboard data reg
 LDR R5, R5, #0       ; R5 = value of keyboard data reg  
 
  CONST R3, x00       ; To set as the boundary of memory
  HICONST R3, x20
  CMP R0, R3          ;compare R0 with boundary
  BRnz END_GETS       ;if it is too small, end             
  CONST R3, xFF       ; To set as the boundary of memory
  HICONST R3, x7F
  CMP R0, R3          ;compare R0 with boundary
  BRp END_GETS        ;if it is too big, end                           
  CMPI R5, x0A         ; compare R5 with enter key
  BRz ADD_NULL_TO_END  ; if the input is enter, the string is ended, a nall should be added                
  STR R5, R0, #0       ; store value of R5 to R0 
  ADD R0, R0, #1       ; address R0 +1
  ADD R1, R1, #1       ; R1 is the length, +1
  JMP TRAP_GETS        ; back to the top of loop
  ADD_NULL_TO_END
  CONST R4, x00         ;null
  STR R4, R0, #0        ;give null to the end
  
  END_GETS
  RTI

;;;;;;;;;;;;;;;;;;;;;;;;;;;   TRAP_PUTS   ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Function: Put a string of characters out to ASCII display
;;; Inputs           - R0 = Address for first character
;;; Outputs          - none

.CODE
TRAP_PUTS
  CONST R3, x00     ;To set as the boundary of memory
  HICONST R3, x20    
  CMP R0, R3        ;compare R0 with boundary  
  BRn END_PUTS      ;if it is too small, end  
  CONST R3, xFF     ;To set as the boundary of memory
  HICONST R3, x7F
  CMP R0, R3        ;compare R0 with boundary
  BRp END_PUTS      ;if it is too big, end
  LDR R4, R0, #0    ; load the value from R0 to R4
  PUTS_LOOP 
    CMPI R4, x00            ; determine if the value of R4 is null
    BRz END_PUTS            ;if it is null, end 
    LC R1, OS_ADSR_ADDR 	  ; R1 = address of display status reg
    LDR R1, R1, #0    	  ; R1 = value of display status reg
    BRzp TRAP_PUTS    	  ; if R1[15]=1, display is ready to write! else, loop and check again... 
    LC R1, OS_ADDR_ADDR 	; R1 = address of display data reg
    STR R4, R1, #0    	; R1 = value of ASCII character (R4)  
    ADD R0, R0, #1        ; the address of R0 +1   
    LDR R4, R0, #0        ; load the value from R0 to R4 
    JMP PUTS_LOOP
  END_PUTS
  RTI

;;;;;;;;;;;;;;;;;;;;;;;;;   TRAP_TIMER   ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Function:
;;; Inputs           - R0 = time to wait in milliseconds
;;; Outputs          - none

.CODE
TRAP_TIMER
  LC R1, OS_TIR_ADDR 	; R1 = address of timer interval reg
  STR R0, R1, #0    	; Store R0 in timer interval register

COUNT
  LC R1, OS_TSR_ADDR  	; Save timer status register in R1
  LDR R1, R1, #0    	; Load the contents of TSR in R1
  BRzp COUNT    	; If R1[15]=1, timer has gone off!

  ; reaching this line means we've finished counting R0

  RTI       		; PC = R7 ; PSR[15]=0



;;;;;;;;;;;;;;;;;;;;;;;   TRAP_GETC_TIMER   ;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Function: Get a single character from keyboard
;;; Inputs           - R0 = time to wait
;;; Outputs          - R0 = ASCII character from keyboard (or NULL)

.CODE
TRAP_GETC_TIMER
  LC R1, OS_TIR_ADDR 	               ; R1 = address of timer interval reg
  STR R0, R1, #0    	               ; Store R0 in timer interval register
 TIMER_LOOP
  LC R1, OS_TSR_ADDR  	            ; Save timer status register in R1
  LDR R1, R1, #0    	            ; Load the contents of TSR in R1     
  BRzp GET_VALUE    	            ; If R1[15]=1, timer has gone off!   
  CONST R0, #0                          ; set the value of R0 is 0 at first
  BRz END_TIMER                         ; go to the end of timer
  GET_VALUE                             ; the loop to get the value from keyboard
    LC R0, OS_KBSR_ADDR               ; R0 = address of keyboard status reg
    LDR R0, R0, #0                    ; R0 = value of keyboard status reg
    BRzp TIMER_LOOP                   ; if R0[15]=1, data is waiting!                                  
    LC R0, OS_KBDR_ADDR               ; R0 = address of keyboard data reg
    LDR R0, R0, #0                    ; R0 = value of keyboard data reg
  END_TIMER
  RTI                                   ; PC = R7 ; PSR[15]=0



;;;;;;;;;;;;;;;;;;;;;;;;;   TRAP_DRAW_PIXEL   ;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Function: Draw point on video display
;;; Inputs           - R0 = row to draw on (y)
;;;                  - R1 = column to draw on (x)
;;;                  - R2 = color to draw with
;;; Outputs          - none

.CODE
TRAP_DRAW_PIXEL
  LEA R3, OS_VIDEO_MEM       ; R3=start address of video memory
  LC  R4, OS_VIDEO_NUM_COLS  ; R4=number of columns

  CMPIU R1, #0    	         ; Checks if x coord from input is > 0
  BRn END_PIXEL
  CMPIU R1, #127    	     ; Checks if x coord from input is < 127
  BRp END_PIXEL
  CMPIU R0, #0    	         ; Checks if y coord from input is > 0
  BRn END_PIXEL
  CMPIU R0, #123    	     ; Checks if y coord from input is < 123
  BRp END_PIXEL

  MUL R4, R0, R4      	     ; R4= (row * NUM_COLS)
  ADD R4, R4, R1      	     ; R4= (row * NUM_COLS) + col
  ADD R4, R4, R3      	     ; Add the offset to the start of video memory
  STR R2, R4, #0      	     ; Fill in the pixel with color from user (R2)

END_PIXEL
  RTI       		         ; PC = R7 ; PSR[15]=0
  


;;;;;;;;;;;;;;;;;;;;;;;;;;;;; TRAP_RESET_VMEM ;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; In double-buffered video mode, resets the video display
;;; CIT 593 students do not need to modify this trap, it's for future HWs
;;; Inputs - none
;;; Outputs - none
.CODE	
TRAP_RESET_VMEM
	LC R4, OS_VDCR_ADDR
	CONST R5, #1
	STR R5, R4, #0
	RTI

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; TRAP_BLT_VMEM ;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; TRAP_BLT_VMEM - In double-buffered video mode, copies the contents
;;; of video memory to the video display.
;;; CIT 593 students do not need to modify this trap, it's for future HWs
;;; Inputs - none
;;; Outputs - none
.CODE
TRAP_BLT_VMEM
	LC R4, OS_VDCR_ADDR
	CONST R5, #2
	STR R5, R4, #0
	RTI




;; CIT 593 TO DO: Add TRAP: TRAP_DRAW_RECT
;;R0 – “x coordinate” of upper-left corner of the rectangle.
;;R1 – “y coordinate” of upper-left corner of the rectangle.
;;R2 – length of the rectangle (in number of pixels).
;;R3 – width of the side of the rectangle (in number of pixels).
;;R4 – the color of the rectangle

.CODE	
TRAP_DRAW_RECT
   ADD R6, R2, R0           ; set R6 as length
  ADD R6, R6, #-1          ; length-1 as it starts from 0
  CMPIU R6, #0    	       ; check if it is too small
  BRnz END_DRAW_RECT
  CMPIU R6, #127    	   ; Checks if if it is too big
  BRp END_DRAW_RECT
  
  ADD R6, R3, R1           ; set R6 as width
  ADD R6, R6, #-1          ; width-1 as it starts from 0
  CMPIU R6, #0    	       ; check if it is too small
  BRnz END_DRAW_RECT
  CMPIU R6, #123    	   ; Checks if if it is too big
  BRp END_DRAW_RECT
  LEA R6, OS_GLOBALS_MEM   ; set R6 as the start of global memory
  STR R0, R6, #0           ; store R0 to R6   
  ADD R6, R6, #1           ; R6 address+1
  STR R1, R6, #0           ; store R1 to R6 
  ADD R6, R6, #1           ; R6 address+1
  STR R2, R6, #0           ; store R2 to R6  
  ADD R6, R6, #1           ; R6 address+1
  STR R3, R6, #0           ; store R3 to R6 
  ADD R6, R6, #1           ; R6 address+1
  STR R4, R6, #0           ; store R4 to R6 
  ADD R6, R6, #1           ; R6 address+1
  LEA R0, OS_VIDEO_MEM     ; R0 =start address of video memory
  STR R0, R6, #0           ; store R0 to R6
  ADD R6, R6, #1           ; R6 address+1 
  LC R0, OS_VIDEO_NUM_ROWS     ; there are 124 as from 0 to 123
  STR R0, R6, #0           ; store R0 to R6
  ADD R6, R6, #1           ; R6 address+1
  LC R0, OS_VIDEO_NUM_COLS     ; there are 128 as from 0 to 127
  STR R0, R6, #0           ; store R0 to R6 
  ADD R6, R6, #1           ; R6 address+1
  STR R7, R6, #0           ; store R0 to R7
;;assign the register to global memorys     
  LC R0, Y_GLO              ; set R0 to y-globalmem
  LDR R0, R0, #0             
  LC R1, OS_COLS_GLO_MEM     ; set R1 to column-globalmem
  LDR R1, R1, #0            
  LC R2, X_GLO              ; set R2 to x-globalmem
  LDR R2, R2, #0             
  LC R3, OS_VIDEO_GLO_MEM      ; set R3 as video memory
  LDR R3, R3, #0            ; the start of video memory
  LC R6, COLR_GLO_MEM      ; set R6 as color
  LDR R6, R6, #0            
;;set length
  LC R5, LEN_GLO_MEM        ; Set the R5 in LEN_GLO_MEM
  LDR R5, R5, #0            ; 
  ADD R5, R5, R2            ; to get the real length, location+value
  ADD R5, R5, #-1           ; -1, as it starts from 0
;; set width
  LC R7, WID_GLO_MEM       ; Set the R7 in WID_GLO_MEM
  LDR R7, R7, #0            ; 
  ADD R7, R7, R0            ; to get the real wide, location+value
  ADD R7, R7, #-1           ; -1, as it starts from 0     
;;color the panel  
  DRAW_LENGTH_LOOP    
     MUL R4, R0, R1      	    ; row x the number of row
     ADD R4, R4, R2      	    ; row x the number of row +column
     ADD R4, R4, R3      	    ; to the start of video memory
     STR R6, R4, #0      	    ; use color
                               ;;go to next row
     ADD R2, R2, #1            ; to next row
     CMPU R5, R2               ; check the if finish                               
     BRzp DRAW_LENGTH_LOOP    
  ;;color next row  
  TO_UPDATE_W    
      ;; Increase the y-coord by 1. 
      ;; If y-coord > full width, then we have reached the full width so can return rectangle       
      ; Reset the x-coord to its original value
      LC R2, X_GLO           ; set R2 in X_GLO
      LDR R2, R2, #0            
      ADD R0, R0, #1            ; change the row
      CMPU R7, R0               ;  check the if finish                                   
      BRzp DRAW_LENGTH_LOOP  
  END_DRAW_RECT
  LC R7, R7_GLO_MEM             ; PC value in os global mem
  LDR R7, R7, #0                ;  PC value
  RTI

