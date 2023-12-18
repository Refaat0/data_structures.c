#include "../include/doubly-linked-list.h"
#include "../include/doubly-linked-list-node.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

//// ==== Linked List "Life-Cycle" Functions ==== ////

DoublyLinkedList *dll_create()
{
    DoublyLinkedList *linked_list = malloc(sizeof(DoublyLinkedList));
    if (linked_list == NULL)
    {
        free(linked_list);
        return NULL;
    }

    linked_list->head = NULL;
    linked_list->tail = NULL;
    linked_list->size = 0;

    return linked_list;
}

bool dll_destroy(DoublyLinkedList *linked_list)
{
    // there is no double-linked-list, & as an extension, nodes to free
    if (linked_list == NULL)
    {
        return false;
    }

    // there is a doubly-linked-list to free, but no nodes attached to it
    if (linked_list->head == NULL || linked_list->tail == NULL)
    {
        free(linked_list);
        return true;
    }

    // there is a doubly-linked-list to free, and a single node (head & tail)
    if (linked_list->head &&
        linked_list->tail &&
        linked_list->head->next == NULL &&
        linked_list->tail->prev == NULL)
    {
        // head & tail are the same nodes for DLL's with a size of 1!
        free(linked_list->head);
        free(linked_list->tail);
        return true;
    }

    /**
     * there is a doubly-linked-list & nodes to free,
     * we need to free all the nodes attached to the dll before we free the dll,
     * so we dont get any memory leaks!
     */
    // traverses the linked-list & free's ever single node
    DLLNode *cursor = linked_list->head;
    while (cursor != NULL)
    {
        cursor = cursor->next;
        free(linked_list->head);
        linked_list->head = cursor;
    }

    // good practice i think?
    linked_list = NULL;

    // cleanup!
    free(linked_list);
    free(cursor);

    return true;
}

//// ==== Insertion Functions === ////

bool dll_insert(DoublyLinkedList *linked_list, void *element, int index)
{
    if (linked_list == NULL || element == NULL)
    {
        return false;
    }

    if (index < 0 || index > linked_list->size)
    {
        return false;
    }

    DLLNode *new_node = dll_node_create();
    new_node->element = element;

    //
    if (index == 0)
    {
        dll_append(linked_list, element);
        return true;
    }
    if (index >= linked_list->size)
    {
        dll_prepend(linked_list, element);
        return true;
    }

    // make the node the head & tail if it is the first element to be added to this list
    if (linked_list->head == NULL || linked_list->tail == NULL)
    {
        linked_list->head = new_node;
        linked_list->tail = new_node;
        linked_list->size++;
        return true;
    }

    DLLNode *cursor = linked_list->head;

    for (int i = 0; i < index - 1 && cursor != NULL; i++)
    {
        cursor = cursor->next;
    }

    if (cursor == NULL)
    {
        return false;
    }

    new_node->prev = cursor;
    new_node->next = cursor->next;
    cursor->next->prev = new_node;
    cursor->next = new_node;

    linked_list->size++;

    return false;
}

bool dll_insert_ll(DoublyLinkedList *linked_list_alpha, DoublyLinkedList *linked_list_bravo, int index)
{
    return false;
}

bool dll_prepend(DoublyLinkedList *linked_list, void *element)
{
    if (linked_list == NULL || element == NULL)
    {
        return false;
    }

    DLLNode *new_node = dll_node_create();
    new_node->element = element;

    // make the node the head & tail if it is the first element to be added to this list
    if (linked_list->head == NULL || linked_list->tail == NULL)
    {
        linked_list->head = new_node;
        linked_list->tail = new_node;
        linked_list->size++;
        return true;
    }

    // append node
    new_node->next = linked_list->head;
    linked_list->head->prev = new_node;
    linked_list->head = new_node;

    linked_list->size++;

    return true;
}

bool dll_append(DoublyLinkedList *linked_list, void *element)
{
    if (linked_list == NULL || element == NULL)
    {
        return false;
    }

    DLLNode *new_node = dll_node_create();
    new_node->element = element;

    // make the node the head & tail if it is the first element to be added to this list
    if (linked_list->head == NULL || linked_list->tail == NULL)
    {
        linked_list->head = new_node;
        linked_list->tail = new_node;
        linked_list->size++;
        return true;
    }

    // prepend node
    new_node->prev = linked_list->tail;
    linked_list->tail->next = new_node;
    linked_list->tail = new_node;

    linked_list->size++;

    return true;
}

//// ==== Deletion Functions ==== ////

bool dll_remove(DoublyLinkedList *linked_list, int index)
{
    return false;
}

bool dll_pop(DoublyLinkedList *linked_list)
{
    return true;
}

bool dll_remove_element(DoublyLinkedList *linked_list, void *element)
{
    return false;
}

bool dll_clear(DoublyLinkedList *linked_list)
{
    return false;
}

//// ==== Miscellaneous Functions === ////

bool dll_is_empty(DoublyLinkedList *linked_list)
{
    return linked_list->size == 0;
}


bool dll_contains(DoublyLinkedList *linked_list, void *element)
{
    return false;
}

int dll_index_of(DoublyLinkedList *linked_list, void *element)
{
    return 0;
}

void *dll_get(DoublyLinkedList *linked_list, int index)
{
    return NULL;
}

bool dll_set(DoublyLinkedList *linked_list, void *element, int index)
{
    return false;
}
