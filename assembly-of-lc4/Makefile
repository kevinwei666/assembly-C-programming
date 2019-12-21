#########################################################
#  file name   : Makefile                               #
#  author      : Thomas Farmer                          #
#  description : Makefile to automate compiling         #
#                and linking                            #
#########################################################
#
#

all: lc4


lc4_memory.o: lc4_memory.c lc4_memory.h
	clang -g -c lc4_memory.c


lc4_loader.o: lc4_loader.c lc4_loader.h
	clang -g -c lc4_loader.c

lc4_disassembler.o: lc4_disassembler.c lc4_disassembler.h
	clang -c lc4_disassembler.c


lc4: lc4.c lc4_memory.o lc4_loader.o lc4_disassembler.o
	clang -g lc4.c lc4_memory.o lc4_loader.o lc4_disassembler.o -o lc4


clean:
	rm -rf *.o

clobber: clean
	rm -rf lc4