CXX = g++
CXXFLAGS = -Wall -std=c++17

all: program

program : main.o Complex.o Sort.o
	$(CXX) $(CXXFLAGS) -o program  Complex.o Sort.o main.o

main.o : main.cpp Sort.h Complex.h
	$(CXX) $(CXXFLAGS) -c  main.cpp

Complex.o : Complex.cpp Complex.h
	$(CXX) $(CXXFLAGS) -c Complex.cpp

Sort.o : Sort.cpp Sort.h Complex.h
	$(CXX) $(CXXFLAGS) -c Sort.cpp
clean:
	rm -f program Complex.o Sort.o main.o
