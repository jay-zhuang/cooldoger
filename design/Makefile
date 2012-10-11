CC=g++ -std=c++11
SRCDIR=.
BINDIR=bin

all: main

debug: CC += -DDEBUG -g
debug: main

main: main.o command.o adapter.o bridge.o composite.o
	$(CC) main.o command.o adapter.o bridge.o composite.o -o main

main.o: main.cpp
	$(CC) -c main.cpp

command.o: command.cpp
	$(CC) -c command.cpp

adapter.o: adapter.cpp
	$(CC) -c adapter.cpp

bridge.o: bridge.cpp
	$(CC) -c bridge.cpp

composite.o: composite.cpp
	$(CC) -c composite.cpp

run:
	./main
clean:
	rm -rf *.o main
