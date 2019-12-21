;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  file name   : factorial_sub.asm                      ;
;  author      : 
;  description : LC4 Assembly subroutine to compute the ;
;                factorial of a number                  ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;
.FALIGN
SUB_FACTORIAL             ; your subroutine goes here
   ;; prologue
    STR R7, R6, #-2  ; save caller’s return address
	STR R5, R6, #-3  ; save caller’s frame pointer
	ADD R6, R6, #-3  ; updates stack pointer
	ADD R5, R6, #0   ; creates/updates frame pointer
    
    ADD R6, R6, #-1  ; allocate space for local vars
	CONST R7, #1     ; only 1 local var: c
	STR R7, R5, #-1  ; c=1 – initialized in the for loop
   ;;Function Body
    JMP THE_PROGRAM
THE_LOOP
    LDR R7, R5, #-1   ;  loads c into R7
	LDR R3, R5, #3    ;  loads a into R3
	MUL R7, R7, R3    ;  R7 = c * a
	STR R7, R5, #-1   ;  update c = R7 }
;   DECREMENT LOOP COUNTER:      A--
	LDR R7, R5, #3    ;  load p into R7
	ADD R7, R7, #-1   ;  decrement p
	STR R7, R5, #3    ;  update p

       
THE_PROGRAM
    LDR R7, R5, #3    ; loads A to R7
    CONST R3, #0	    ; loads 0 into R3
	CMP R7, R3	    ; is A > 0 ?
	BRp THE_LOOP ; if yes, go to the loop


; function body is complete, time to return

    LDR R7, R5, #-1 ; load C into R7
    ADD R6, R5, #0	  ; pop local variables
	ADD R6, R6, #3	  ; decrease stack 
	STR R7, R6, #-1 ; update return value
	LDR R5, R6, #-3 ; restore base ptr 
	LDR R7, R6, #-2 ; restore R7 for RET
	RET		  ; now PC = R7




