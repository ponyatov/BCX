default: FORTH.c

FORTH.c: bc2c$(EXE) FORTH.bc
	$(CURDIR)/$^ $@

bc2c$(EXE): bc2c.c bcx.c
	$(CC) -o $@ $^

FORTH.log: bcx$(EXE) FORTH.bc
	$(CURDIR)/$^

VMC = bcx.c $(OS).c
VMH = bcx.h $(OS).h

CC = gcc

CFLAGS += -I.

bcx$(EXE): $(VMC) $(VMH)
	$(CC) $(CFLAGS) -o $@ $(VMC)

%.bc: compiler$(EXE) %.4th
	$(CURDIR)/$^ && hexdump -C $@

BCC = $(VMC) compiler.cpp parser.cpp lexer.cpp
BCH = $(CMH) compiler.hpp parser.hpp

CXXFLAGS += -I. -DBCXCOMPILER

compiler$(EXE): $(BCC) $(BCH)
	$(CXX) $(CXXFLAGS) -o $@ $(BCC)

parser.cpp: compiler.yacc
	bison -o $@ $<

lexer.cpp: compiler.lex
	flex -o $@ $<

doxy:
	rm -rf docs ; doxygen doxy.gen 1>/dev/null

