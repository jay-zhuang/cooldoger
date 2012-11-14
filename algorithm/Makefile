CC=g++
SRCDIR=.
BINDIR=bin

all: main

debug: CC += -DDEBUG -g
debug: main

main: main.o retangleOverlap.o stlTest.o missingNumber.o isBST.o arrayString.o treeGraph.o stackQueue.o bit.o recursion.o sortSearch.o
	$(CC) main.o retangleOverlap.o stlTest.o missingNumber.o isBST.o arrayString.o treeGraph.o stackQueue.o bit.o recursion.o sortSearch.o -o main

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

isBST.o: isBST.cpp
	$(CC) -c isBST.cpp

arrayString.o: arrayString.cpp
	$(CC) -c arrayString.cpp

treeGraph.o: treeGraph.cpp
	$(CC) -c treeGraph.cpp

stackQueue.o: stackQueue.cpp
	$(CC) -c stackQueue.cpp

bit.o: bit.cpp
	$(CC) -c bit.cpp

recursion.o: recursion.cpp
	$(CC) -c recursion.cpp

sortSearch.o: sortSearch.cpp
	$(CC) -c sortSearch.cpp

clean:
	rm -rf *.o main

run:
	./main
