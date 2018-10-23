# Victor Franco Vieira Lima

CC=g++
CFLAGS=-std=c++11

SOURCES=$(wildcard src/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
BINARY=projeto

all: build

clear:
	rm src/*.o projeto

build: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(BINARY)

%.o: %.cpp
	$(CC) -Isrc $(CFLAGS) -c $< -o $@
