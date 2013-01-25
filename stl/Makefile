CC=g++ -std=c++11

CPP_FILES := $(wildcard *.cpp)
OBJ_FILES := $(notdir $(CPP_FILES:.cpp=.o))

all: main

debug: CC += -DDEBUG -g
debug: main

main: $(OBJ_FILES)
	$(CC) -o $@ $^

%.o: %.cpp
	$(CC) -c -o $@ $<

clean:
	rm -rf $(OBJ_FILES) main

run:
	./main
