#include "utils.h"

#define NUM_LETTERS 26

typedef struct node
{
    char letter;
    long unsigned int count;
    struct node *children[NUM_LETTERS];
    bool isLeaf;
} node;

void addChildren(node **head, char c);
node *initnode();