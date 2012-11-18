JFALAGS = -g
JC = javac
CC = gcc

all: javaCode cCode

cCode: Palindromer.c
	$(CC) Palindromer.c -o Palindromer

javaCode: Palindromer.java
	$(JC) $(JFALAGS) Palindromer.java

clean:
	rm -rf Palindromer Palinderomer.class

run: javaRun cRun

javaRun:
	java -ea Palindromer

cRun:
	./Palindromer
