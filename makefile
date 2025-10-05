CC := g++
CFLAGS := -std=c++17 -O2 -Wall -Wextra -pipe
TARGET := hacker-rm
SRC := hacker-rm.cpp
OBJ := $(SRC:.cpp=.o)


.PHONY: all clean


all: $(TARGET)


# Multi-stage: compile .o then link
$(OBJ): $(SRC)
$(CC) $(CFLAGS) -c -o $@ $<


$(TARGET): $(OBJ)
$(CC) $(CFLAGS) -o $@ $^


clean:
rm -f $(OBJ) $(TARGET)
