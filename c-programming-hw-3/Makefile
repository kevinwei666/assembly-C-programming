#########################################################
#  file name   : Makefile                               #
#  author      : Thomas Farmer                          #
#  description : Makefile to automate compiling         #
#                and linking                            #
#########################################################
#
#

all: program1 program2 program3 program4

my_string.o: my_string.c
		clang -c my_string.c 
	
program1.o: program1.c
		clang -c program1.c

program2.o: program2.c
		clang -c program2.c
		
program4.o: program4.c
		clang -c program4.c

program1: program1.o my_string.o
		clang my_string.o program1.o -o program1

program2: program2.o my_string.o
		clang my_string.o program2.o -o program2

program3: program3.c 
		clang program3.c -o program3

program4: program4.o my_string.o
		clang my_string.o program4.o -o program4


clean:
		rm -rf *.o

clobber: clean
		rm -rf program1 program2 program3 program4


