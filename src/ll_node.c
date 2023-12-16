#include "../include/ll_node.h"
#include <stdbool.h>
#include <stdlib.h>

LLNode *ll_node_create()
{
    LLNode *node = malloc(sizeof(LLNode));
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

bool ll_node_destroy(LLNode *node)
{
    if (node == NULL)
    {
        return false;
    }

    free(node);
    return true;
}
