TARGET := SimpleLexer
CFLAGS := -g -lm -std=c++11
INCLUDE := -I ./
CXX := g++

$(TARGET): SimpleLexer.cpp SimpleLexer_test.cpp
	$(CXX) $(CFLAGS) $(INCLUDE) -o $@ $^

clean :
	find . -name '*.o' | xargs rm -f
	find . -name $(TARGET) | xargs rm -f