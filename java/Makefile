JFALAGS = -g
JC = javac

all: main

main: main.java
	$(JC) $(JFALAGS) main.java

clean:
	rm -rf main main.class *.html *.css resources package-list

run: mainRun

mainRun:
	java -ea main
