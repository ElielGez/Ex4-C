#include "trie.h"

void buidlTrie(node **head)
{
    node *next = *head;
    char c;
    while (scanf("%c", &c) != EOF)
    {
        char tmp = charToLowerCase(c);
        if (tmp == '\t' || tmp == '\n' || tmp == ' ')
        {
            next->isLeaf = true;
            next = *head;
        }
        else if (isLowerEnglishLetter(tmp))
        {
            next->isLeaf = false;
            addChildren(&next, tmp);
        }
    }
    next->isLeaf = true;
    (*head)->isLeaf = false;
}

int main()
{
    node *head = initnode();
    buidlTrie(&head);
    printf("%d", head->children['a' - 'a']->children['b' - 'a']->count);
    return 0;
}