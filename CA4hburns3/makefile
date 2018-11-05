CC = g++
CC_FLAGS = -std=c++14 -Wall -pedantic -g -Wextra
 
# File names
EXEC = war.exe
SOURCES = $(wildcard *.cpp)
SOURCESHPP = $(wildcard *.hpp)
OBJECTS = $(SOURCES:.cpp=.o)
 
# Main target
$(EXEC): $(SOURCES) $(SOURCESHPP) PlayingCard.o
	$(CC) $(CC_FLAGS) $(SOURCES) -o $(EXEC)
 
# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)
checkmem:
	valgrind ./$(EXEC)
