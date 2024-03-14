main: main.o sum2.o sub2.o
	g++ -o main.exe main.o sum2.o sub2.o

main.o : main.cpp
	g++ -c main.cpp

sum2.o : sum2.cpp
	g++ -c sum2.cpp

sub2.o : sub2.cpp
	g++ -c sub2.cpp

clean:
	del -r *.o
	del -r *.exe