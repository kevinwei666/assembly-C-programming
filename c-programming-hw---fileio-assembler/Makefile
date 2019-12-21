#########################################################
#  file name   : Makefile                               #
#  author      : Thomas Farmer                          #
#  description : Makefile to automate compiling         #
#                and linking                            #
#########################################################
#
#

all: assembler

asm_parser.o:asm_parser.c
			clang -c asm_parser.c
			
assembler.o:assembler.c
			clang -c assembler.c
			
assembler: assembler.o asm_parser.o
			clang assembler.o asm_parser.o -o assembler
			
clean:
		rm -rf *.o

clobber: clean
		rm -rf  assembler