CC=g++ -std=c++11
SRCDIR=.
BINDIR=bin

all: main

debug: CC += -DDEBUG -g
debug: main

main: main.o command.o
	$(CC) main.o command.o -o main

main.o: main.cpp
	$(CC) -c main.cpp

piano: command.cpp
	$(CC) -c command.cpp

run:
	./main
clean:
	rm -rf *.o main
