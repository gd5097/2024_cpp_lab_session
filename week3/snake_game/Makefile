CXX = g++
CXXFLAGS = -std=c++11

main: main.o console.o
	$(CXX) -lncurses -o main main.o console.o

console.o: console.cpp
	$(CXX) $(CXXFLAGS) -c console.cpp

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -rf *.o
