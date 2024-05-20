#//314085986
#//mishaaskarov@gmail.com
CXX = clang++
CXXFLAGS = -std=c++11 -Werror -Wsign-conversion -MMD -MP
VALGRIND_FLAGS = -v --leak-check=full --show-leak-kinds=all --error-exitcode=99

SOURCES = Graph.cpp Algorithms.cpp TestCounter.cpp Demo.cpp
OBJECTS = $(SOURCES:.cpp=.o)

.PHONY: all run test tidy valgrind clean

all: demo test

run: demo test
	./test
	./demo

demo: $(filter-out TestCounter.o, $(OBJECTS))
	$(CXX) $(CXXFLAGS) $^ -o $@

test: TestCounter.o Test.o $(filter-out Demo.o, $(OBJECTS))
	$(CXX) $(CXXFLAGS) $^ -o $@

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

valgrind: demo test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o *.d demo test
