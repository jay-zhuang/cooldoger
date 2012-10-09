CC=g++
SRCDIR=.
BINDIR=bin

all: main

debug: CC += -DDEBUG -g
debug: main

main: main.o retangleOverlap.o stlTest.o missingNumber.o
	$(CC) main.o retangleOverlap.o stlTest.o missingNumber.o -o main

main.o: main.cpp
	$(CC) -c main.cpp

retangleOverlap.o: retangleOverlap.cpp
	$(CC) -c retangleOverlap.cpp

coins.o: coins.cpp
	$(CC) -c coins.cpp

stlTest.o: stlTest.cpp
	$(CC) -c stlTest.cpp

missingNumber.o: missingNumber.cpp
	$(CC) -c missingNumber.cpp

clean:
	rm -rf *.o main

run:
	./main
