#include "../include/linked_list.h"
#include "../include/ll_node.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

//// ==== Linked List "Life-Cycle" Functions ==== ////

LinkedList *ll_create()
{
    LinkedList *linked_list = malloc(sizeof(LinkedList));
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

bool ll_destroy(LinkedList *linked_list)
{
    // nothing to free
    if (linked_list == NULL)
    {
        return false;
    }

    // no nodes to free; only free the linked list structure
    if (linked_list->head == NULL || linked_list->tail == NULL)
    {
        free(linked_list);
        return true;
    }

    // free all the nodes & then the list
    LLNode *temp  = linked_list->head;

    while (temp != NULL)
    {
        temp = temp->next;
        free(linked_list->head);
        linked_list->head = temp;
    }

    linked_list = NULL;
    free(linked_list);

    return false;
}

//// ==== Insertion Functions === ////

bool ll_insert(LinkedList *linked_list, void *element, int index)
{
    if (linked_list == NULL || element == NULL)
    {
        return false;
    }

    if (index < 0 || index > linked_list->size)
    {
        return false;
    }

    LLNode *new_node = ll_node_create(element);
    new_node->element = element;

    //
    if (index == 0)
    {
        ll_append(linked_list, element);
        return true;
    }
    if (index >= linked_list->size)
    {
        ll_prepend(linked_list, element);
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

    LLNode *cursor = linked_list->head;

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

bool ll_insert_ll(LinkedList *linked_list_alpha, LinkedList *linked_list_bravo, int index)
{
    return false;
}

bool ll_append(LinkedList *linked_list, void *element)
{
    if (linked_list == NULL || element == NULL)
    {
        return false;
    }

    LLNode *new_node = ll_node_create(element);
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

bool ll_prepend(LinkedList *linked_list, void *element)
{
    if (linked_list == NULL || element == NULL)
    {
        return false;
    }

    LLNode *new_node = ll_node_create();
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

bool ll_remove(LinkedList *linked_list, int index)
{
    return false;
}

bool ll_pop(LinkedList *linked_list)
{
    return true;
}

bool ll_remove_element(LinkedList *linked_list, void *element)
{
    return false;
}

bool ll_clear(LinkedList *linked_list)
{
    return false;
}

//// ==== Miscellaneous Functions === ////

bool ll_is_empty(LinkedList *linked_list)
{
    return linked_list->size == 0;
}

// bool ll_is_full(LinkedList *linked_list)
// {
//     return linked_list->size == 0;
// }

bool ll_contains(LinkedList *linked_list, void *element)
{
    return false;
}

int ll_index_of(LinkedList *linked_list, void *element)
{
    return 0;
}

void *ll_get(LinkedList *linked_list, int index)
{
}

bool ll_set(LinkedList *linked_list, void *element, int index)
{
    return false;
}
