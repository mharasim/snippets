CC = g++

obj = hash_table.o
CFLAGS = -Wall -g -pedantic -std=c++11

all: test

# Gather objects
test: $(obj)
	$(CC) -o test $(obj)

# Compile objects
hash_table.o: hash_table.cc
	$(CC) $(CFLAGS) -c hash_table.cc

clean:
	rm test $(obj)
