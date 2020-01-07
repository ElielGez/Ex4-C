CC=gcc
OBJECTS_MAIN=utils.o trie.o
FLAGS= -Wall -g -fPIC
PROGRAMS=trie

all: $(PROGRAMS)
trie: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o trie $(OBJECTS_MAIN) -lm
utils.o: utils.c utils.h
	$(CC) $(FLAGS) -c utils.c
trie.o: trie.c utils.h 
	$(CC) $(FLAGS) -c trie.c

.PHONY: clean all

clean:
	rm -f *.o *.so $(PROGRAMS)