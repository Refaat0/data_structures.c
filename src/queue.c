#include "../include/array-list.h"
#include "../include/queue.h"
#include <stdbool.h>
#include <stdlib.h>

//// ==== Queue "Life-Cycle" Functions ==== ////

Queue *queue_create()
{
    Queue *queue = malloc(sizeof(Queue));
    if (queue == NULL)
    {
        free(queue);
        return NULL;
    }

    queue->collection = list_create();
    if (queue->collection == NULL)
    {
        list_destroy(queue->collection);
        free(queue);

        return NULL;
    }

    queue->size = 0;
    return queue;
}

bool queue_destroy(Queue *queue)
{
    if (queue == NULL)
    {
        return false;
    }

    list_destroy(queue->collection);
    free(queue);

    return true;
}

//// ==== Queue Operational Functions ==== ////

bool queue_enqueue(Queue *queue, void *element)
{
    if (queue == NULL || element == NULL)
    {
        return false;
    }

    list_prepend(queue->collection, element);
    queue->size++;

    return true;
}

bool queue_dequeue(Queue *queue)
{
    if (queue == NULL)
    {
        return false;
    }

    if (list_pop(queue->collection) == true)
    {
        queue->size--;
        return true;
    }

    return false;
}

bool queue_is_empty(Queue *queue)
{
    if (queue == NULL)
    {
        return false;
    }

    return list_is_empty(queue->collection);
}

bool queue_clear(Queue *queue)
{
    if (queue == NULL)
    {
        return false;
    }

    list_clear(queue->collection);
    queue->size = 0;

    return true;
}

ArrayList *queue_to_list(Queue *queue)
{
    if (queue->collection == NULL)
    {
        return NULL;
    }

    return queue->collection;
}

bool queue_contains(Queue *queue, void *element)
{
    if (queue == NULL || element == NULL)
    {
        return false;
    }
    
    return list_contains(queue->collection, element);
}
