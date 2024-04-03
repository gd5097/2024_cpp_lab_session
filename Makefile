FLAGS = -Werror -std=c++11 -g
CC = g++

all: main

main: main.o game.o tetromino.o console.o
	$(CC) $(FLAGS) -lncurses -o main main.o game.o tetromino.o console.o

main.o: main.cpp game.h tetromino.h console/console.h
	$(CC) $(FLAGS) -c main.cpp

game.o: game.cpp game.h tetromino.h console/console.h
	$(CC) $(FLAGS) -c game.cpp

tetromino.o: tetromino.cpp tetromino.h
	$(CC) $(FLAGS) -c tetromino.cpp

console.o: console/console.cpp console/console.h
	$(CC) $(FLAGS) -c console/console.cpp

clean:
	rm -f *.o main.exe main