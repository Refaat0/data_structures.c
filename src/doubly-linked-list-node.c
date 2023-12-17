#include "../include/doubly-linked-list-node.h"
#include <stdbool.h>
#include <stdlib.h>

DLLNode *dll_node_create()
{
    DLLNode *node = malloc(sizeof(DLLNode));
    if (node == NULL)
    {
        free(node);
        return NULL;
    }

    node->element = NULL;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

bool ll_node_destroy(DLLNode *node)
{
    if (node == NULL)
    {
        return false;
    }

    free(node);
    return true;
}
