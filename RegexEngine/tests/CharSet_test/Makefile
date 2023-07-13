PROJECT := $(shell pwd)
SRCDIR  := $(PROJECT)/../../
TEST := $(PROJECT)/CharSet_test.cpp
SRC := $(SRCDIR)/src/CharSet.cpp
override SRC := $(SRC) $(TEST) 

TARGET := CharSet
CXX := g++
INCLUDE := -I $(SRCDIR)/src/
CFLAGS := -std=c++17 -g


$(TARGET): $(SRC)
	$(CXX) $(CFLAGS) $(INCLUDE) -o $@ $^

clean :
	find . -name '*.o' | xargs rm -f
	find . -name $(TARGET) | xargs rm -f