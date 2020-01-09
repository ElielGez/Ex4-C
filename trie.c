#include "trie.h"

/**
 * buildTrie function , gets pointer to pointer , in order to change head without return it any call
 * @return int , the maximum length of word in the trie , used this param to create str.
**/
int buidlTrie(node **head)
{
    node *next = *head;
    char c;
    int maxLength = 0;
    int wordLength = 0;
    while (scanf("%c", &c) != EOF)
    {
        char tmp = charToLowerCase(c);
        if (tmp == '\t' || tmp == '\n' || tmp == ' ')
        {
            if (wordLength > maxLength)
            {
                maxLength = wordLength;
            }
            wordLength = 0;
            next->isLeaf = true;
            next->count++;
            next = *head;
        }
        else if (isLowerEnglishLetter(tmp))
        {
            addChildren(&next, tmp);
            wordLength++;
        }
    }
    if (wordLength > maxLength)
        maxLength = wordLength;
    next->isLeaf = true;
    next->count++;
    (*head)->isLeaf = false;

    return maxLength;
}

/**
 * printTrie function , print on recursive way the trie by lexographic order . 
**/
void printTrie(const node *root, char str[], int level)
{
    if (root->isLeaf)
    {
        str[level] = '\0';
        printf("%s", str);
        printf("\t%lu\n", root->count);
    }

    int i;
    for (i = 0; i < NUM_LETTERS; i++)
    {
        if (root->children[i])
        {
            str[level] = i + 'a';
            printTrie(root->children[i], str, level + 1);
        }
    }
}
/**
 * printTrieR function , print on recursive way the trie by oposite of lexographic order . 
**/
void printTrieR(const node *root, char str[], int level)
{
    int i;
    for (i = NUM_LETTERS - 1; i >= 0; i--)
    {
        if (root->children[i])
        {
            str[level] = i + 'a';
            printTrieR(root->children[i], str, level + 1);
        }
    }

    if (root->isLeaf)
    {
        str[level] = '\0';
        printf("%s", str);
        printf("\t%lu\n", root->count);
    }
}
/**
 * freeTrie , recursive function to free allocation of nodes in the trie.
**/
void freeTrie(node *root)
{
    if (root)
    {
        freeNode(root);
    }
}

int main(int argc, char *argv[])
{
    node *head = initnode();
    int maxWord = buidlTrie(&head);
    int level = 0;
    char str[maxWord]; // str used on printTrie

    if (argc == 1)
    {
        printTrie(head, str, level);
    }
    else if (argc == 2)
    {
        if (strcmp(argv[1], "r") == 0)
        {
            printTrieR(head, str, level);
        }
    }
    freeTrie(head);
    return 0;
}
