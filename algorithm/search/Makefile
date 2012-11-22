CC=g++

CPP_FILES := $(wildcard *.cpp)
OBJ_FILES := $(notdir $(CPP_FILES:.cpp=.o))

all: lookup
debug: CC += -DDEBUG -g
debug: lookup


lookup: $(OBJ_FILES)
	$(CC) -o $@ $^

%.o: %.cpp
	$(CC) -c -o $@ $<

clean:
	rm -rf $(OBJ_FILES) lookup

run:
	cat queries.txt | lookup
