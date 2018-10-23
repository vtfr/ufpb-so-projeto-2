# Victor Franco Vieira Lima

CC=g++
CPPFLAGS=-Isrc -std=c++11 -Wall -Wextra -O3

SOURCES=$(wildcard src/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
BINARY=projeto

all: build

clear:
	rm -f $(OBJECTS) $(BINARY)

build: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
