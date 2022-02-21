CXX = g++

CXXFLAGS= -Wall -Wno-uninitialized

clean:
	/bin/rm -f tests *.o

cards.o:
	g++ $(CXX_FLAG) -c cards.cpp

utility.o:
	g++ $(CXX_FLAG) -c utility.cpp

game: main.o cards.o utility.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@
	./game

tests: tests.o cards.o utility.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@
	./tests