clean:
	/bin/rm -f tests *.o

game: main.o cards.o utility.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@
	./game

tests: tests.o cards.o utility.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@
	./tests