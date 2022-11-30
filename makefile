COMP_FLAG = --std=c++11 -Wall -pedantic-errors -Werror -DNDEBUG

Mtmchkin: Mtmchkin.o utilities.o Player.o Card.o
	g++ $(COMP_FLAG) -cpp $*.cpp -o $@

Mtmchkin.o: Mtmchkin.h Mtmchkin.cpp utilities.h Player.h Card.h
	g++ $(COMP_FLAG) -cpp $*.cpp -o $@

Card.o: Card.h Card.cpp Player.h utilities.h
	g++ $(COMP_FLAG) -cpp $*.cpp -o $@

Player.o: Player.h Player.cpp utilities.h
	g++ $(COMP_FLAG) -cpp $*.cpp -o $@

utilities.o: utilities.h utilities.cpp
	g++ $(COMP_FLAG) -cpp $*.cpp -o $@

clean:
	rm -f Mtmchkin.o utilities.o Player.o Card.o Mtmchkin