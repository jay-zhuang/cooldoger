CC=g++ -std=c++11
SRCDIR=.
BINDIR=bin

all: main

debug: CC += -DDEBUG -g
debug: main

main: main.o command.o adapter.o
	$(CC) main.o command.o adapter.o -o main

main.o: main.cpp
	$(CC) -c main.cpp

command.o: command.cpp
	$(CC) -c command.cpp

adapter.o: adapter.cpp
	$(CC) -c adapter.cpp
run:
	./main
clean:
	rm -rf *.o main
