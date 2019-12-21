;;;;;;;;;;;;;;;;;;;;;;;;;;;;main;;;;;;;;;;;;;;;;;;;;;;;;;;;;
		.CODE
		.FALIGN
main
	;; prologue
	STR R7, R6, #-2	;; save return address
	STR R5, R6, #-3	;; save base pointer
	ADD R6, R6, #-3
	ADD R5, R6, #0
	ADD R6, R6, #-8	;; allocate stack space for local variables
	;; function body
	LEA R7, L2_problem6
	STR R7, R5, #-8
	CONST R7, #0
	STR R7, R5, #-7
	LDR R7, R5, #-8
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR lc4_puts
	LDR R7, R6, #-1	;; grab return value
	ADD R6, R6, #1	;; free space for arguments
	CONST R7, #50
	STR R7, R5, #-2
	STR R7, R5, #-3
	CONST R7, #10
	STR R7, R5, #-4
	STR R7, R5, #-5
	CONST R7, #0
	HICONST R7, #124
	STR R7, R5, #-6
	LDR R7, R5, #-6
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #-5
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #-4
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #-3
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #-2
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR lc4_draw_rect
	LDR R7, R6, #-1	;; grab return value
	ADD R6, R6, #5	;; free space for arguments
	JMP L4_problem6
L3_problem6
	JSR lc4_getc
	LDR R7, R6, #-1	;; grab return value
	ADD R6, R6, #0	;; free space for arguments
	STR R7, R5, #-1
	LDR R7, R5, #-1
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR lc4_putc
	LDR R7, R6, #-1	;; grab return value
	ADD R6, R6, #1	;; free space for arguments
	LDR R7, R5, #-1
	CONST R3, #106
	CMP R7, R3
	BRnp L6_problem6
	LDR R7, R5, #-7
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #-5
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #-4
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #-3
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #-2
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR lc4_draw_rect
	LDR R7, R6, #-1	;; grab return value
	ADD R6, R6, #5	;; free space for arguments
	LDR R7, R5, #-2
	ADD R7, R7, #10
	STR R7, R5, #-2
	LDR R7, R5, #-6
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #-5
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #-4
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #-3
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #-2
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR lc4_draw_rect
	LDR R7, R6, #-1	;; grab return value
	ADD R6, R6, #5	;; free space for arguments
	JMP L7_problem6
L6_problem6
	LDR R7, R5, #-1
	CONST R3, #107
	CMP R7, R3
	BRnp L8_problem6
	LDR R7, R5, #-7
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #-5
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #-4
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #-3
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #-2
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR lc4_draw_rect
	LDR R7, R6, #-1	;; grab return value
	ADD R6, R6, #5	;; free space for arguments
	LDR R7, R5, #-2
	ADD R7, R7, #-10
	STR R7, R5, #-2
	LDR R7, R5, #-6
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #-5
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #-4
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #-3
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #-2
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR lc4_draw_rect
	LDR R7, R6, #-1	;; grab return value
	ADD R6, R6, #5	;; free space for arguments
L8_problem6
L7_problem6
L4_problem6
	JMP L3_problem6
	CONST R7, #0
L1_problem6
	;; epilogue
	ADD R6, R5, #0	;; pop locals off stack
	ADD R6, R6, #3	;; free space for return address, base pointer, and return value
	STR R7, R6, #-1	;; store return value
	LDR R5, R6, #-3	;; restore base pointer
	LDR R7, R6, #-2	;; restore return address
	RET

		.DATA
L2_problem6 		.STRINGZ "game here! press j to move the rectangle to left and k to the right"
