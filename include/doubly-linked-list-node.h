#pragma once 
#include <stdbool.h>

typedef struct DLLNode
{
    void *element;
    struct DLLNode *next;
    struct DLLNode *prev;

} DLLNode;

/**
 * this function initializes a Node for a DoublyLnkedList
 * @return an initalized DoublyLnkedList Node
 */
DLLNode *dll_node_create();

/**
 * this function destroys a Node for a DoublyLnkedList
 * @return a boolean of true if the operation is successful
 */
bool dll_node_destroy(DLLNode *node);
