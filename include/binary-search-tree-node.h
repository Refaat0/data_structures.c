#pragma once
#include <stdbool.h>

typedef struct BSTNode
{
    void *element;
    struct BSTNode *right;
    struct BSTNode *left;
} BSTNode;

/**
 * this function initializes a Node for a BinarySearchTree
 * @return an initialized Node for a BinarySearchTree
 */
BSTNode *create_bst_node();

/**
 * this function destroys a Node for a BinarySearchTree
 * @param node a pointer to a BSTNode structure
 * @return a boolean of true if the operation is successful
 */
bool destroy_bst_node(BSTNode *node);
