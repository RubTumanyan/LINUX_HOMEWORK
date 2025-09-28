CXX = g++
CXXFLAGS = -Wall -Wextra -O2
TARGET = read-file

all: $(TARGET)

$(TARGET) : read-file.cpp
	$(CXX) $(CXXFLAGS)  read-file.cpp -o $(TARGET)

clean:
	rm -f $(TAREGTi)
