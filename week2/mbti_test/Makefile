main.o: main.cpp
	g++ -c main.cpp

print.o: print.cpp
	g++ -c print.cpp

test.o: test.cpp
	g++ -c test.cpp

main: main.o print.o test.o
	g++ main.o print.o test.o -o main.exe


clean:
	del -rf *.o
	del -rf main.exe