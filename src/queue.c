#include "../include/array-list.h"
#include "../include/queue.h"
#include <stdbool.h>
#include <stdlib.h>

//// ==== Queue "Life-Cycle" Functions ==== ////

Queue *queue_create()
{
    Queue *queue = malloc(sizeof(Queue));
    return queue;
}

bool queue_destroy(Queue *queue)
{
    return false;
}

//// ==== Queue Operational Functions ==== ////

bool queue_enqueue(Queue *queue, void *element)
{
    return false;
}

bool queue_dequeue(Queue *queue)
{
    return false;
}

bool queue_is_empty(Queue *queue)
{
    return false;
}

bool queue_clear(Queue *queue)
{
    return false;
}

ArrayList *queue_to_list(Queue *queue)
{
    return queue->collection;
}

bool queue_contains(Queue *queue, void *element)
{
    return false;
}
