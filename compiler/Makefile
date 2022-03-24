CC=gcc -g -std=c11 -I./
TARGET=compiler

all:
	${CC} util.c ast.c code.c bcgen.c lexer.c vm.c parser.c main.c -o ${TARGET}

.PHONY: clean

clean:
	rm -f *.o ${TARGET}