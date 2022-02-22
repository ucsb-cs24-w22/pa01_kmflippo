CXX = g++

CXXFLAGS = -Wall -Wno-uninitialized

COMMON_OBJECT_FILES = utility.o cards.o

test: tests.o ${COMMON_OBJECT_FILES}
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@
	./test

game: main.o ${COMMON_OBJECT_FILES}
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

clean:
	/bin/rm -f test *.o