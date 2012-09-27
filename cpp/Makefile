CC=g++ -std=c++11
SRCDIR=.
BINDIR=bin

all: main

debug: CC += -DDEBUG -g
debug: main

main: main.o ccTest.o sharedPtr.o containerTest.o algorithmTest.o
	$(CC) main.o ccTest.o sharedPtr.o containerTest.o algorithmTest.o -o main

main.o: main.cpp
	$(CC) -c main.cpp

ccTest.o: ccTest.cpp
	$(CC) -c ccTest.cpp

sharedPtr.o: sharedPtr.cpp
	$(CC) -c sharedPtr.cpp

containerTest.o: containerTest.cpp
	$(CC) -c containerTest.cpp
	
algorithmTest.o: algorithmTest.cpp
	$(CC) -c algorithmTest.cpp

clean:
	rm -rf *.o main
