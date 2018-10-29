CXXFLAGS = -Isrc -std=c++11 -Wall -Wextra -O3

SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
BINARY = projeto

all: $(BINARY)

clear:
	rm -f $(OBJECTS) $(BINARY)

debug: CXXFLAGS += -DDEBUG
debug: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
