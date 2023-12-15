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
    if (linked_list == NULL)
    {
        return false;
    }

    if (linked_list->head == NULL || linked_list->tail == NULL)
    {
        return false;
    }

    LLNode *cursor = linked_list->head;
    LLNode *temp;

    while (cursor != NULL)
    {
        temp = cursor;
        cursor = cursor->next;
        free(temp);
    }

    free(cursor);
    free(linked_list);

    return false;
}

//// ==== Insertion Functions === ////

bool ll_insert(LinkedList *linked_list, void *element, int index)
{
    return false;
}

bool ll_insert_ll(LinkedList *linked_list_alpha, LinkedList *linked_list_bravo, int index)
{
    return false;
}

bool ll_append(LinkedList *linked_list, void *element)
{
    return false;
}

bool ll_prepend(LinkedList *linked_list, void *element)
{
    return false;
}

//// ==== Deletion Functions ==== ////

bool ll_remove(LinkedList *linked_list, int index)
{
    return false;
}

bool ll_pop(LinkedList *linked_list)
{
    return false;
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
    return false;
}

bool ll_is_full(LinkedList *linked_list)
{
    return false;
}

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
