#include "../include/binay-search-tree-node.h"
#include "stdbool.h"
#include "stdlib.h"

BinarySearchTreeNode *bst_node_create(void *element)
{
    BinarySearchTreeNode *node = malloc(sizeof(BinarySearchTreeNode));
    if (node == NULL)
    {
        free(node);
        return NULL;
    }

    node->element = element;
    node->right = NULL;
    node->left = NULL;

    return node;
}

bool bst_node_destroy(BinarySearchTreeNode *node)
{
    if (node == NULL)
    {
        return false;
    }

    free(node);
    return true;
}
