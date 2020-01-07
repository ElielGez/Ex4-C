#define NUM_LETTERS ((int)26)

typedef struct Node
{
    char letter;
    long unsigned int count;
    struct Node *children[NUM_LETTERS];
} Node;