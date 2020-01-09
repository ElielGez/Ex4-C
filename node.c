#include "node.h"

/**
 * addChildren function , add node as children with char c if doesn't exist in array.
 * otherwise head equals to the next children with the char c
**/
void addChildren(node **head, char c)
{
    if (head == NULL || *head == NULL)
        return;
    node *tmp = NULL;
    if ((*head)->children[c - 'a'] == NULL)
    {
        tmp = initnode();
        tmp->letter = c;
        (*head)->children[c - 'a'] = tmp;
    }
    else
    {
        tmp = (*head)->children[c - 'a'];
    }
    *head = tmp;
}

/**
 * function to initialize node with null
**/
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

/**
 * recursive function to free allocation of nodes
**/
void freeNode(node *node)
{
    for (int i = NUM_LETTERS - 1; i >= 0; i--)
    {
        if (node->children[i] != NULL)
        {
            freeNode(node->children[i]);
        }
    }
    if (node != NULL)
    {
        free(node);
    }
}