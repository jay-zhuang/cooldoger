CC=g++ -std=c++11
SRCDIR=.
BINDIR=bin

all: main

debug: CC += -DDEBUG -g
debug: main

main: main.o ccTest.o sharedPtr.o containerTest.o
	$(CC) main.o ccTest.o sharedPtr.o containerTest.o -o main

main.o: main.cpp
	$(CC) -c main.cpp

ccTest.o: ccTest.cpp
	$(CC) -c ccTest.cpp

sharedPtr.o: sharedPtr.cpp
	$(CC) -c sharedPtr.cpp

containerTest.o: containerTest.cpp
	$(CC) -c containerTest.cpp
	
clean:
	rm -rf *.o main
