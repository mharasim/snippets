CC = g++

obj = binary_heap.o
CFLAGS = -Wall -g -pedantic -std=c++11

all: test

# Gather objects
test: $(obj)
	$(CC) -o test $(obj)

# Compile objects
binary_heap.o: binary_heap.cc
	$(CC) $(CFLAGS) -c binary_heap.cc

clean:
	rm test $(obj)
