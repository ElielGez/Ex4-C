#include "utils.h"
#include "node.h"

int buidlTrie(node **head);
void printTrie(const node *root, char str[], int level);
void printTrieR(const node *root, char str[], int level);
void freeTrie(node *root);