PROJECT := $(shell pwd)
SRCDIR  := $(PROJECT)/../../
TEST := $(wildcard $(PROJECT)/*.cpp)
SRC := $(wildcard $(SRCDIR)/src/*.cpp)
override SRC := $(SRC) $(TEST) 

TARGET := LRParser
CXX := g++
INCLUDE := -I $(SRCDIR)/src/
CFLAGS := -std=c++17 -g


$(TARGET): $(SRC)
	$(CXX) $(CFLAGS) $(INCLUDE) -o $@ $^

clean :
	find . -name '*.o' | xargs rm -f
	find . -name $(TARGET) | xargs rm -f