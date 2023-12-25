#pragma once
#include "../include/binary-search-tree-node.h"
#include "../include/array-list.h"

typedef struct BinarySearchTree
{
    BSTNode *root;
    int height;
    int size;
} BinarySearchTree;

/**
 * this function initializes a BinarySearchTree
 * @return an initialized BinarySearchTree
 */
BinarySearchTree *create_bst();

/**
 * this function destrorys a BinarySearchTree
 * @return a boolean of true if the operation is successful
 */
bool destroy_bst(BinarySearchTree *bst);

/**
 * this function inserts an element to a BinarySearchTree
 * @param bst     a pointer to a BinarySearchTree structure
 * @param element a void pointer to an element
 * @return a boolean of true if the operation is successful
 */
bool bst_insert(BinarySearchTree *bst, void *element);

/**
 * this function removes the first occurance of an element in a BinarySearchTree
 * @param bst     a pointer to a BinarySearchTree structure
 * @param element a void pointer to an element
 * @return a boolean of true if the operation is successful
 */
bool bst_remove(BinarySearchTree *bst, void *element);

/**
 * this function searches for an element in a BinarySearchTree
 * @param bst     a pointer to a BinarySearchTree structure
 * @param element a void pointer to an element
 * @return a boolean of true if the element is found in the BinarySearchTree
 */
bool bst_search(BinarySearchTree *bst, void *element);

/**
 * this function returns the height of a BinarySearchTree
 * @param bst a pointer to a BinarySearchTree structure
 * @return    an integer value representing a BinarySearchTree's height
 */
int bst_get_height(BinarySearchTree *bst);

/**
 * this function traverses a BinarySearchTree in a post-order fashion and,
 * returns the result in an ArrayList
 * @param bst a pointer to a BinarySearchTree structure
 * @return    an ArrayList containing the element of a BinarySearchTree in post-order
 */
ArrayList bst_post_order_traversal(BinarySearchTree *bst);

/**
 * this function traverses a BinarySearchTree in a pre-order fashion and,
 * returns the result in an ArrayList
 * @param bst a pointer to a BinarySearchTree structure
 * @return    an ArrayList containing the element of a BinarySearchTree in pre-order
 */
ArrayList bst_pre_order_traversal(BinarySearchTree *bst);

/**
 * this function traverses a BinarySearchTree in an in-order fashion and,
 * returns the result in an ArrayList
 * @param bst a pointer to a BinarySearchTree structure
 * @return    an ArrayList containing the element of a BinarySearchTree in, in-order
 */
ArrayList bst_in_order_traversal(BinarySearchTree *bst);
