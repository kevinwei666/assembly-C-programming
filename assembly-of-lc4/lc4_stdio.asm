;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  file name   : lc4_stdio.asm                          ;
;  author      : 
;  description : LC4 Assembly subroutines that call     ;
;                call the TRAPs in os.asm (the wrappers);
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;; WRAPPER SUBROUTINES FOLLOW ;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

GLOBAL_ARRAY_ADDRESS .UCONST x7FFF
GLOBAL_ARRAY_SIZE .UCONST x1000
;;THE_ARRAY_ADDRESS .UCONST x4000
;;the address holder that I may use
;.DATA 
;.ADDR x7FEF
;THE_HOLDER;
        

.DATA
.ADDR x4000
 


    
.CODE
.ADDR x0010    ;; this code should be loaded after line 10
               ;; this is done to preserve "USER_START"
               ;; subroutine that calls "main()"


;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;; TRAP_PUTC Wrapper ;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.FALIGN
lc4_putc

	;; PROLOGUE ;;
        ; CIT 593 TODO: write prologue code here
        STR R7, R6, #-2  ; save caller’s return address
	    STR R5, R6, #-3  ; save caller’s frame pointer
	    ADD R6, R6, #-3  ; updates stack pointer
	    ADD R5, R6, #0   ; creates/updates frame pointer
		;; there is no local variable in this function
	;; FUNCTION BODY ;;
		; CIT 593 TODO: write code to get arguments to the trap from the stack
		;  and copy them to the register file for the TRAP call
        
        LDR R0, R5, #3  ;load the value of c to R0
	    TRAP x01        ; R0 must be set before TRAP_PUTC is called
    
    
    
	
	;; EPILOGUE ;; 
		; TRAP_PUTC has no return value, so nothing to copy back to stack
        
        ADD R6, R5, #0;  pop local variables
        ADD R6, R6, #3;  decrease stack
        LDR R5, R6, #-3; restore base ptr
        LDR R7, R6, #-2; restore R7 for RET
        
	RET

;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;; TRAP_GETC Wrapper ;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.FALIGN
lc4_getc
	;; PROLOGUE
        ; CIT 593 TODO: write prologue code here
         STR R7, R6, #-2  ; save caller’s return address
	     STR R5, R6, #-3  ; save caller’s frame pointer
	     ADD R6, R6, #-3  ; updates stack pointer
	     ADD R5, R6, #0   ; creates/updates frame pointer
         ;;there is no local variable in this function
		
	;; FUNCTION BODY ;;
		; CIT 593 TODO: TRAP_GETC doesn't require arguments!
        
   
	TRAP x00        ; Call's TRAP_GETC 
                    ; R0 will contain ascii character from keyboard
                    ; you must copy this back to the stack
    STR R0, R5, #2;
	
	;; EPILOGUE ;; 
		; TRAP_GETC has a return value, so make certain to copy it back to stack
        
     
     
     ADD R6, R5, #0;  pop local variables
        ADD R6, R6, #3;  decrease stack
        LDR R5, R6, #-3; restore base ptr
        LDR R7, R6, #-2; restore R7 for RET
          
	RET
    
    
    
;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;; TRAP_PUTS Wrapper ;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.FALIGN
lc4_puts
 ;;PROLOGUE ;;
        ; CIT 593 TODO: write prologue code here
       STR R7, R6, #-2  ; save caller’s return address
	    STR R5, R6, #-3  ; save caller’s frame pointer
	    ADD R6, R6, #-3  ; updates stack pointer
	    ADD R5, R6, #0   ; creates/updates frame pointer
		;; there is no local variable in this function
        
;; FUNCTION BODY ;;
		; CIT 593 TODO: write code to get arguments to the trap from the stack
		;  and copy them to the register file for the TRAP call
        
        LDR R0, R5, #3  ;load the value of c to R0
	    TRAP x03        ; R0 must be set before TRAP_PUTC is called


;; EPILOGUE ;; 
		; TRAP_PUTC has no return value, so nothing to copy back to stack
        
        
        
        ADD R6, R5, #0;  pop local variables
        ADD R6, R6, #3;  decrease stack
        LDR R5, R6, #-3; restore base ptr
        LDR R7, R6, #-2; restore R7 for RET
        
	RET


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;; TRAP_DRAW_RECT Wrapper ;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.FALIGN
lc4_draw_rect
;; PROLOGUE ;;
      
        STR R7, R6, #-2  ; save caller’s return address
	    STR R5, R6, #-3  ; save caller’s frame pointer
	    ADD R6, R6, #-3  ; updates stack pointer
	    ADD R5, R6, #0   ; creates/updates frame pointer
		
;; FUNCTION BODY ;;
		; CIT 593 TODO: write code to get arguments to the trap from the stack
		
        LDR R0, R5, #3  ; load the value of x to R0
        LDR R1, R5, #4  ; load the value of y to R0
        LDR R2, R5, #5  ;load the value of l to R0
        LDR R3, R5, #6  ;load the value of w to R0
        LDR R4, R5, #7  ;load the value of color to R0
        
        
        
	    TRAP x09        ; 
        
        ; ;; LEA R5 THE_HOLDER;
        ;;the above is another way to hold the original address
        ;;make it back to the right place as R5 is modified in the trap
        CONST R5 xEF;
        HICONST R5 x7F
        

;; EPILOGUE ;; 
		
       
        
        ADD R6, R5, #0;  pop local variables
        ADD R6, R6, #3;  decrease stack
        LDR R5, R6, #-3; restore base ptr
        LDR R7, R6, #-2; restore R7 for RET
	    
     RET





















