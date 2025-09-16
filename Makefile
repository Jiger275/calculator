CXX = clang++
CXXFLAGS = -std=c++17 -Wall

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = calculator

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^
	
$.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean: 
	rm -f $(TARGET) *.o

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
