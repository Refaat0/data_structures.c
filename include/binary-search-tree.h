#pragma once
#include "../include/binay-search-tree-node.h"
#include "../include/array-list.h"

typedef struct BinarySearchTree
{
    BinarySearchTreeNode *root;
    int height;
} BinarySearchTree;

/**
 * this function initializes a BinarySearchTree
 * @return an initialized BinarySearchTree
 */
BinarySearchTree *bst_create();

/**
 * this function destroys a BinarySearchTree
 * @param bst a pointer to a BinarySearchTree
 * @return    a boolean of true if the operation is successful
 */
bool bst_destroy(BinarySearchTree *bst);

/**
 * this function inserts an element to a BinarySearchTree
 * @param bst         a pointer to a BinarySearchTree
 * @param element     a void pointer to an element
 * @param comparator  a pointer to a comparator function
 * @return            a boolean of true if the operation is successful
 */
bool bst_insert(BinarySearchTree *bst, void *element, int (*comparator)(void *, void *));

/**
 * this function removes an element from a BinarySearchTree
 * @param bst         a pointer to a BinarySearchTree
 * @param element     a void pointer to an element
 * @param comparator  a pointer to a comparator function
 * @return            a boolean of true if the operation is successful
 */
bool bst_remove(BinarySearchTree *bst, void *element, int (*comparator)(void *, void *));

/**
 * this function stores all elements in a BinarySearchTree in an ArrayList, in order of a post-order traversal
 * @param bst a pointer to a BinarySearchTree
 * @return    an ArrayList containing the elements of a BinarySearchTree in post-order
 */
ArrayList *bst_post_order(BinarySearchTree *bst);

/**
 * this function stores all elements in a BinarySearchTree in an ArrayList, in order of a pre-order traversal
 * @param bst a pointer to a BinarySearchTree
 * @return    an ArrayList containing the elements of a BinarySearchTree in pre-order
 */
ArrayList *bst_pre_order(BinarySearchTree *bst);

/**
 * this function stores all elements in a BinarySearchTree in an ArrayList, in order of an in-order traversal
 * @param bst a pointer to a BinarySearchTree
 * @return    an ArrayList containing the elements of a BinarySearchTree in, in-order
 */
ArrayList *bst_in_order(BinarySearchTree *bst);

/**
 * this function returns the left-most BinarySearchTreeNode in a BinarySearchTree
 * @param bst a pointer to a BinarySearchTree
 * @return the smallest Node in a BinarySearchTree
 */
BinarySearchTreeNode *bst_min(BinarySearchTree *bst);

/**
 * this function returns the right-most BinarySearchTreeNode in a BinarySearchTree
 * @param bst a pointer to a BinarySearchTree
 * @return the largest Node in a BinarySearchTree
 */
BinarySearchTreeNode *bst_max(BinarySearchTree *bst);

/**
 * this function returns the right-most BinarySearchTreeNode in the left of a BinarySearchTree, 
 * where a Node is used to determine the root of the BinarySearchTree
 * @param bst_sub_root a pointer to a BinarySearchTreeNode
 * @return the largest Node in a subtree
 */
BinarySearchTreeNode *bst_sub_max(BinarySearchTreeNode *bst_sub_root);

/**
 * this function returns the left-most BinarySearchTreeNode in the right of a BinarySearchTree, 
 * where a Node is used to determine the root of the BinarySearchTree
 * @param bst_sub_root a pointer to a BinarySearchTreeNode
 * @return the smallest Node in a subtree
 */
BinarySearchTreeNode *bst_sub_min(BinarySearchTreeNode *bst_sub_root);
