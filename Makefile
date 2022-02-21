CXX = g++

CXXFLAGS = -Wall -Wno-uninitialized

COMMON_OBJECT_FILES = utility.o cards.o

tests: tests.o ${COMMON_OBJECT_FILES}
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@
	./tests

# game: main.o cards.o utility.o
# 	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@
# 	./game



clean:
	/bin/rm -f tests *.o