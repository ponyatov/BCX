FORTH.log: bcx$(EXE) FORTH.bc
	$(CURDIR)/$^

VMC = bcx.c $(OS).c
VMH = bcx.h $(OS).h

CC = gcc

bcx$(EXE): $(VMC) $(VMH)
	$(CC) $(CFLAGS) -o $@ $(VMC)

%.bc: compiler$(EXE) %.4th
	$(CURDIR)/$^ && od -x $@

BCC = $(VMC) compiler.cpp parser.cpp lexer.cpp
BCH = $(CMH) compiler.hpp parser.hpp

CXXFLAGS += -DBCXCOMPILER

compiler$(EXE): $(BCC) $(BCH)
	$(CXX) $(CXXFLAGS) -o $@ $(BCC)

parser.cpp: compiler.yacc
	bison -o $@ $<

lexer.cpp: compiler.lex
	flex -o $@ $<

