PROJECT := $(shell pwd)
SRCDIR  := $(PROJECT)/../../
TEST := $(wildcard $(PROJECT)/*.cpp)
SRC := $(wildcard $(SRCDIR)/src/*.cpp)
override SRC := $(SRC) $(TEST) 

TARGET := SimpleCalculator
CXX := g++
INCLUDE := -I $(SRCDIR)/src/
CFLAGS := -std=c++11 -g


$(TARGET): $(SRC)
	$(CXX) $(CFLAGS) $(INCLUDE) -o $@ $^

clean :
	find . -name '*.o' | xargs rm -f
	find . -name $(TARGET) | xargs rm -f