FORTH.log: ./bcx$(EXE) FORTH.bc
	$^

VMC = bcx.c $(OS).c
VMH = bcx.h $(OS).h

CC = gcc

./bcx$(EXE): $(VMC) $(VMH)
	$(CC) $(CFLAGS) -o $@ $(VMC)

%.bc: ./compiler$(EXE) %.4th
	$^

BCC = compiler.cpp parser.cpp lexer.cpp
BCH = compiler.hpp parser.hpp
./compiler$(EXE): $(BCC) $(BCH)
	$(CXX) -o $@ $(BCC)

parser.cpp: compiler.yacc
	bison -o $@ $<

lexer.cpp: compiler.lex
	flex -o $@ $<

