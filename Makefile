PROJECT := $(shell readlink $(dir $(lastword $(MAKEFILE_LIST))) -f)

CXX:=g++
CXXFLAGS:= -std=c++11 \
	-g

SRC := $(shell find $(PROJECT) -type f -name "*.cpp")
OBJ := $(SRC:.cpp=.o)
TARGET := signal_handle

all: $(TARGET)

$(OBJ) : %.o : %.cpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET) : $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@


clean:
	rm *.o $(TARGET)


.PHONY: all clean
