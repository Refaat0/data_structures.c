#include "../include/array-list.h"
#include <stdbool.h>

typedef struct Queue
{
    ArrayList *collection;
    int size;
} Queue;

//// ==== Queue "Life-Cycle" Functions ==== ////

/**
 * this function returns an initialize Queue
 * @return an initialized Queue
 */
Queue *queue_create();

/**
 * this function destroys a Queue specified in the function parameters
 * @param queue a pointer to a Queue structure
 * @return a boolean of true if the operation is successful
 */
bool queue_destroy(Queue *queue);

//// ==== Queue Operational Functions ==== ////

/**
 * this function inserts an element to the start of a Queue specified in the function parameters
 * @param queue a pointer to a Queue structure
 * @param element a void pointer to an element
 * @return a boolean of true if the operation is successful
 */
bool queue_enqueue(Queue *queue, void *element);

/**
 * this function removes an element to the end of a Queue specified in the function parameters
 * @param queue a pointer to a Queue structure
 * @return a boolean of true if the operation is successful
 */
bool queue_dequeue(Queue *queue);

/**
 * this function checks if the Queue specified in the function parameters is empty
 * @param queue a pointer to a Queue structure
 * @return a boolean of true if the Queue is empty
 */
bool queue_is_empty(Queue *queue);

/**
 * this functions clears the Queue specified in the function parameters
 * @param queue a pointer to a Queue structure
 * @return a boolean of true if the operation is successful
 */
bool queue_clear(Queue *queue);

/**
 * this function converts a Queue specified in the function parameters to an ArrayList
 * @param queue a pointer to a Queue structure
 * @return an Arraylist containing all the elements from the Queue in order of appearance
 */
ArrayList *queue_to_list(Queue *queue);

/**
 * this function checks if an element is in a Queue specified in the function parameters
 * @param queue a pointer to a Queue structure
 * @return a boolean of true if the element is found in the Queue
 */
bool queue_contains(Queue *queue, void *element);
