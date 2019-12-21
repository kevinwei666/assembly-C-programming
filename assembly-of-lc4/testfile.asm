.CODE
Labela
    ADD R1, R0, R1
    MUL R2, R1, R1
    SUB R3, R2, R1
    DIV R1, R3, R2
    ADD R1, R2, #8
ASCD
    ADD R1, R0, R1
    MUL R2, R1, R1
NOP
.DATA
.ADDR x3000
  global_array
   .FILL #12
   .FILL #12

