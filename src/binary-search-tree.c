#include "../include/binay-search-tree-node.h"
#include "../include/binary-search-tree.h"
#include "../include/array-list.h"
#include "../include/stack.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

BinarySearchTree *bst_create()
{
    BinarySearchTree *bst = malloc(sizeof(BinarySearchTree));
    if (bst == NULL)
    {
        free(bst);
        return NULL;
    }

    bst->root = NULL;
    bst->height = 0;
    return bst;
}

bool bst_destroy(BinarySearchTree *bst)
{
    return false;
}

bool bst_insert(BinarySearchTree *bst, void *element, int (*comparator)(void *, void *))
{
    if (bst == NULL || element == NULL || comparator == NULL)
    {
        return false;
    }

    BinarySearchTreeNode *new_node = bst_node_create(element);

    if (bst->root == NULL)
    {
        bst->root = new_node;
        return true;
    }

    BinarySearchTreeNode *cursor = bst->root;
    while (cursor != NULL)
    {
        if (comparator(element, cursor->element) >= 0)
        {
            if (cursor->right == NULL)
            {
                cursor->right = new_node;
                return true;
            }
            cursor = cursor->right;
        }
        else if (comparator(element, cursor->element) < 0)
        {
            if (cursor->left == NULL)
            {
                cursor->left = new_node;
                return true;
            }
            cursor = cursor->left;
        }
    }

    free(new_node);
    return false;
}

bool bst_remove(BinarySearchTree *bst, void *element, int (*comparator)(void *, void *))
{
    if (bst == NULL || element == NULL || comparator == NULL)
    {
        return false;
    }

    BinarySearchTreeNode *cursor = bst->root;
    BinarySearchTreeNode *cursor_parent = cursor;
    while (cursor != NULL && cursor->element != element)
    {
        cursor_parent = cursor;
        if (comparator(element, cursor->element) >= 0)
        {
            cursor = cursor->right;
        }
        else
        {
            cursor = cursor->left;
        }
    }

    if (cursor == NULL)
    {
        return false;
    }

    // case #1: leaft node
    if (cursor->right == NULL && cursor->left == NULL)
    {
        if (comparator(cursor->element, cursor_parent->element) >= 0)
        {
            // remove right
            cursor_parent->right = NULL;
        }
        else
        {
            // remove left
            cursor_parent->left = NULL;
        }

        free(cursor);
        return true;
    }

    // case #2: right subtree
    if (cursor->right != NULL && cursor->left == NULL)
    {
        cursor->element = cursor->right->element;

        free(cursor->right);
        cursor->right = NULL;

        return true;
    }

    // case #3: left subtree
    if (cursor->right == NULL && cursor->left != NULL)
    {
        cursor->element = cursor->left->element;

        free(cursor->left);
        cursor->left = NULL;

        return true;
    }

    // case #4: right & left subtree -- smallest element in the right subtree --
    if (cursor->right != NULL && cursor->left != NULL)
    {
        void *element = bst_sub_min(cursor)->element;
        void *element_copy;

        memcpy(element_copy, element, sizeof(void *));

        bst_remove(bst, element, comparator);
        cursor->element = element_copy;

        return true;
    }

    return false;
}

BinarySearchTreeNode *bst_min(BinarySearchTree *bst)
{
    BinarySearchTreeNode *cursor = bst->root;
    while (cursor->left != NULL)
    {
        cursor = cursor->left;
    }

    return cursor;
}

BinarySearchTreeNode *bst_max(BinarySearchTree *bst)
{
    BinarySearchTreeNode *cursor = bst->root;
    while (cursor->right != NULL)
    {
        cursor = cursor->right;
    }

    return cursor;
}

BinarySearchTreeNode *bst_sub_min(BinarySearchTreeNode *bst_sub_root)
{
    bst_sub_root = bst_sub_root->right;
    while (bst_sub_root->left != NULL)
    {
        bst_sub_root = bst_sub_root->left;
    }

    return bst_sub_root;
}

BinarySearchTreeNode *bst_sub_max(BinarySearchTreeNode *bst_sub_root)
{
    bst_sub_root = bst_sub_root->left;
    while (bst_sub_root->right != NULL)
    {
        bst_sub_root = bst_sub_root->right;
    }

    return bst_sub_root;
}

ArrayList *bst_post_order(BinarySearchTree *bst)
{
    return NULL;
}

ArrayList *bst_pre_order(BinarySearchTree *bst)
{
    BinarySearchTreeNode *cursor = bst->root;
    ArrayList *result = list_create();
    Stack *nodes = stack_create();

    while (cursor != NULL || !stack_is_empty(nodes))
    {
        if (cursor != NULL)
        {
            list_append(result, cursor->element);
            stack_push(nodes, cursor->right);
            cursor = cursor->left;
        }
        else
        {
            cursor = stack_peek(nodes);
            stack_pop(nodes);
        }
    }

    free(nodes);
    return result;
}

ArrayList *bst_in_order(BinarySearchTree *bst)
{
    ArrayList *result = list_create();
    Stack *nodes = stack_create();

    BinarySearchTreeNode *cursor = bst->root;

    while (cursor != NULL || !stack_is_empty(nodes))
    {
        while (cursor != NULL)
        {
            stack_push(nodes, cursor);
            cursor = cursor->left;
        }

        cursor = stack_peek(nodes);
        stack_pop(nodes);
        list_append(result, cursor->element);
        cursor = cursor->right;
    }

    stack_destroy(nodes);
    return result;
}
