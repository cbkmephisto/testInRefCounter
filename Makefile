GPP=g++
FLAGS=-c -pipe -O3 -g -funsafe-math-optimizations # -Wall -W
CC=$(GPP) $(FLAGS)
LK=$(GPP)

all:	testInRefCounter


testInRefCounter:
	$(LK) $(INC) testInRefCounter.cpp -o testInRefCounter

###############

clean:
	rm testInRefCounter
