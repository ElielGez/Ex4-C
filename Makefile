CC=gcc
OBJECTS_MAIN=node.o utils.o trie.o
FLAGS= -Wall -g -fPIC
PROGRAMS=frequency

all: $(PROGRAMS)
frequency: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o frequency $(OBJECTS_MAIN) -lm
utils.o: utils.c utils.h
	$(CC) $(FLAGS) -c utils.c
node.o: node.c node.h utils.h
	$(CC) $(FLAGS) -c node.c
trie.o: trie.c trie.h node.h utils.h 
	$(CC) $(FLAGS) -c trie.c

.PHONY: clean all

clean:
	rm -f *.o $(PROGRAMS)