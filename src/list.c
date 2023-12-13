#include "../include/list.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//// ==== Helper Functions === ////

bool _ensure_capacity(List *list)
{
    if (list == NULL)
    {
        return false;
    }

    if (list_is_full(list))
    {
        list->collection = realloc(list->collection, (list->capacity * GROWING_RATE) * sizeof(void *));
        list->capacity = list->capacity * GROWING_RATE;

        return true;
    }

    return false;
}

bool _trim_to_size(List *list)
{
    if (list == NULL)
    {
        return false;
    }

    list->collection = realloc(list->collection, list->size * sizeof(void *));
    list->capacity = list->size;

    return true;
}

//// ==== List "Life-Cycle" Functions ==== ////

List *list_create()
{
    List *list = malloc(sizeof(List));
    if (list == NULL)
    {
        free(list);
        return NULL;
    }

    list->collection = malloc(sizeof(void *) * INITIAL_CAPACITY);
    if (list->collection == NULL)
    {
        free(list->collection);
        free(list);
        return NULL;
    }

    list->capacity = INITIAL_CAPACITY;
    list->size = 0;

    return list;
}

bool list_destroy(List *list)
{
    if (list == NULL)
    {
        return false;
    }
    free(list->collection);
    free(list);

    return true;
}

//// ==== Insertion Functions === ////

bool list_insert(List *list, void *element, int index)
{
    if (list == NULL)
    {
        return false;
    }

    if (element == NULL)
    {
        return false;
    }

    if (index < 0 || index > list->size)
    {
        return false;
    }

    _ensure_capacity(list);

    // i still dont understand why this works :(
    for (int i = list->size; i > index; i--)
    {
        list->collection[i] = list->collection[i - 1];
    }
    list->collection[index] = element;
    list->size++;

    return true;
}

bool list_insert_list(List *list_alpha, List *list_bravo, int index)
{
    if (list_alpha == NULL || list_bravo == NULL)
    {
        return false;
    }

    if (index < 0 || index > list_alpha->size)
    {
        return false;
    }

    for (int i = 0; i < list_bravo->size; i++)
    {
        list_insert(list_alpha, list_bravo->collection[i], index + i);
    }

    return true;
}

bool list_append(List *list, void *element)
{
    if (list_insert(list, element, list->size))
    {
        return true;
    }

    return false;
}

bool list_prepend(List *list, void *element)
{
    if (list_insert(list, element, 0))
    {
        return true;
    }

    return false;
}

//// ==== Deletion Functions ==== ////

bool list_remove(List *list, int index)
{
    if (list == NULL)
    {
        return false;
    }

    if (index < 0 || index > list->size)
    {
        return false;
    }

    if (list_is_empty(list))
    {
        return false;
    }

    for (int i = index; i < list->size; i++)
    {
        list->collection[i] = list->collection[i + 1];
    }

    list->size--;

    return true;
}

bool list_pop(List *list)
{
    if (list == NULL)
    {
        return false;
    }

    if (list_is_empty(list))
    {
        return false;
    }

    list->size--;

    return true;
}

bool list_remove_element(List *list, void *element)
{
    if (list == NULL)
    {
        return false;
    }

    if (element == NULL)
    {
        return false;
    }

    for (int i = 0; i < list->size; i++)
    {
        if (list->collection[i] == element)
        {
            list_remove(list, i);
            return true;
        }
    }

    return false;
}

//// ==== Miscellaneous Functions === ////

bool list_clear(List *list)
{
    if (list == NULL)
    {
        return false;
    }

    if (list_is_empty(list))
    {
        return false;
    }

    while (!list_is_empty(list))
    {
        list_pop(list);
    }

    return true;
}

bool list_is_empty(List *list)
{
    if (list == NULL)
    {
        return false;
    }

    return list->size == 0;
}

bool list_is_full(List *list)
{
    if (list == NULL)
    {
        return false;
    }

    return list->size == list->capacity;
}


bool list_contains(List *list, void *element)
{
    if (list == NULL)
    {
        return false;
    }

    if (list == element)
    {
        fprintf(stderr, ">>ERROR: Element cannot be NULL\n");
        return false;
    }

    for (int i = 0; i < list->size; i++)
    {
        if (list->collection[i] == element)
        {
            return true;
        }
    }

    return false;
}

int list_index_of(List *list, void *element)
{
    if (list == NULL)
    {
        return false;
    }

    if (element == NULL)
    {
        return false;
    }

    if (list_is_empty(list))
    {
        return -1;
    }

    for (int i = 0; i < list->size; i++)
    {
        if (list->collection[i] == element)
        {
            return i;
        }
    }

    return -1;
}

void *list_get(List *list, int index)
{
    if (list == NULL)
    {
        return NULL;
    }

    if (index < 0 || index >= list->size)
    {
        return NULL;
    }

    return list->collection[index];
}

bool list_set(List *list, void *element, int index)
{
    if (list == NULL)
    {
        return false;
    }

    if (list == element)
    {
        fprintf(stderr, ">>ERROR: Element cannot be NULL\n");
        return false;
    }

    if (index < 0 || index >= list->size)
    {
        return false;
    }

    list->collection[index] = element;

    return true;
}
