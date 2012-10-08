CC=g++ -std=c++11
SRCDIR=.
BINDIR=bin

all: main

debug: CC += -DDEBUG -g
debug: main

main: main.o ccTest.o sharedPtr.o containerTest.o algorithmTest.o others.o
	$(CC) main.o ccTest.o sharedPtr.o containerTest.o algorithmTest.o others.o -o main

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

others.o: others.cpp
	$(CC) -c others.cpp

memException : memException.cpp
	$(CC) memException.cpp -o memException

clean:
	rm -rf *.o main

run:
	./main
