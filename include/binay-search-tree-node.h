#pragma once
#include "stdbool.h"

typedef struct BinarySearchTreeNode
{
    struct BinarySearchTreeNode *right;
    struct BinarySearchTreeNode *left;
    void *element;
} BinarySearchTreeNode;

/**
 * this function inititializes a Node for a BinarySearchTree
 * @param element a void point to an element that this Node will hold
 * @return an initialized Node for a BinarySearchTree
 */
BinarySearchTreeNode *bst_node_create(void *element);

/**
 * this function destroys a Node for a BinarySearchTree
 * @param node a void point to a Node for a BinarySearchTree
 * @return a boolean of true if the operation is successful
 */
bool bst_node_destroy(BinarySearchTreeNode *node);
