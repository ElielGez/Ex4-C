#include "node.h"

void addChildren(node **head, char c)
{
    if (head == NULL || *head == NULL)
        return;
    node *tmp = NULL;
    if ((*head)->children[c - 'a'] == NULL)
    {
        tmp = initnode();
        tmp->letter = c;
        tmp->count++;
        (*head)->children[c - 'a'] = tmp;
    }
    else
    {
        (*head)->children[c - 'a']->count++;
        tmp = (*head)->children[c - 'a'];
    }
    *head = tmp;
}

node *initnode()
{
    node *tmp = (node *)malloc(sizeof(node));
    tmp->count = 0;
    tmp->isLeaf = false;
    tmp->letter = 0;
    for (size_t i = 0; i < NUM_LETTERS; i++)
    {
        tmp->children[i] = NULL;
    }
    return tmp;
}