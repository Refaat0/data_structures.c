#include "../include/array-list.h"
#include "../include/queue.h"
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

void test_queue_create()
{
    printf("Testing test_queue_create()...\n");
    // initialize a Queue
    Queue *queue = queue_create();

    // testing if the Queue was initialized correctly
    assert(queue != NULL);
    assert(queue->size == 0);
    assert(queue->collection != NULL);

    printf("Testing successful!\n");
}

void test_queue_destroy()
{
    printf("Testing test_queue_destroy()...\n");

    // initialize a Queue
    Queue *queue = queue_create();

    // unhappy paths
    assert(queue_destroy(NULL) == false);

    // happy paths
    assert(queue_destroy(queue) == true);

    printf("Testing successful!\n");
}

void test_queue_enqueue()
{
    printf("Testing test_queue_enqueue()...\n");

    // initialize a Queue & some elements
    Queue *queue = queue_create();
    char *sunflower = "Sunflower";
    char *orchid = "Orchid";
    char *rose = "Rose";

    // unhappy paths
    assert(queue_enqueue(NULL, &rose) == false); // null queue pointer
    assert(queue_enqueue(queue, NULL) == false); // null element pointer

    // happy paths
    assert(queue->size == 0);
    assert(queue_enqueue(queue, &sunflower) == true);
    assert(queue->size == 1);
    assert(queue_enqueue(queue, &orchid) == true);
    assert(queue->size == 2);
    assert(queue_enqueue(queue, &rose) == true);
    assert(queue->size == 3);

    assert(strcmp(*(char **)list_get(queue->collection, 0), "Rose") == 0);
    assert(strcmp(*(char **)list_get(queue->collection, 1), "Orchid") == 0);
    assert(strcmp(*(char **)list_get(queue->collection, 2), "Sunflower") == 0);

    queue_destroy(queue);
    printf("Testing successful!\n");
}

void test_queue_dequeue()
{
    printf("Testing test_queue_dequeue()...\n");

    // initialize a Queue & some elements
    Queue *queue = queue_create();
    char *sunflower = "Sunflower";
    char *orchid = "Orchid";
    char *rose = "Rose";

    // unhappy paths
    assert(queue_dequeue(NULL) == false); // null queue pointer

    // enqueue some elements
    queue_enqueue(queue, &sunflower);
    queue_enqueue(queue, &orchid);
    queue_enqueue(queue, &rose);

    // happy paths
    assert(queue->size == 3);
    assert(queue_dequeue(queue) == true);
    assert(queue->size == 2);
    assert(queue_dequeue(queue) == true);
    assert(queue->size == 1);
    assert(queue_dequeue(queue) == true);
    assert(queue->size == 0);

    // dequeue an empty queue
    assert(queue_dequeue(queue) == false);

    queue_destroy(queue);
    printf("Testing successful!\n");
}

void test_queue_is_empty()
{
    printf("Testing test_queue_is_empty()...\n");

    // initialize a Queue
    Queue *queue = queue_create();
    char *evil_string = "Red Spider Lily";

    // unhappy paths
    assert(queue_to_list(NULL) == false); // null queue pointer

    // happy paths
    assert(queue_is_empty(queue) == true);
    queue_enqueue(queue, &evil_string);
    assert(queue_is_empty(queue) == false);

    queue_destroy(queue);
    printf("Testing successful!\n");
}

void test_queue_clear()
{
    printf("Testing test_queue_clear()...\n");

    // initialize a Queue & some elements
    Queue *queue = queue_create();
    char *sunflower = "Sunflower";
    char *orchid = "Orchid";
    char *rose = "Rose";

    // enqueue some elements
    queue_enqueue(queue, &sunflower);
    queue_enqueue(queue, &orchid);
    queue_enqueue(queue, &rose);

    // unhappy paths
    assert(queue_clear(NULL) == false); // null queue pointer

    // happy paths
    assert(queue_clear(queue) == true);
    assert(queue->size = 0);

    queue_destroy(queue);
    printf("Testing successful!\n");
}

void test_queue_to_list()
{
    printf("Testing test_queue_to_list()...\n");

    // initialize a Queue
    Queue *queue = queue_create();

    queue_destroy(queue);
    printf("Testing successful!\n");
}

void test_queue_contains()
{
    printf("Testing test_queue_contains()...\n");

    // initialize a Queue & some elements
    Queue *queue = queue_create();

    char *evil_string = "Red Spider Lily";
    char *sunflower = "Sunflower";
    char *orchid = "Orchid";
    char *rose = "Rose";

    // enqueue some elements
    queue_enqueue(queue, &sunflower);
    queue_enqueue(queue, &orchid);
    queue_enqueue(queue, &rose);

    // unhappy paths
    assert(queue_contains(NULL, &rose) == false); // null queue pointer
    assert(queue_contains(queue, NULL) == false); // null element pointer

    // happy paths
    assert(queue_contains(queue, &sunflower) == true);
    assert(queue_contains(queue, &orchid) == true);
    assert(queue_contains(queue, &rose) == true);

    // checking if the queue contains a non existant element
    assert(queue_contains(queue, &evil_string) == false);

    queue_destroy(queue);
    printf("Testing successful!\n");
}

void test_queue()
{
    test_queue_create();
    test_queue_destroy();
    test_queue_enqueue();
    test_queue_dequeue();
    test_queue_is_empty();
    test_queue_clear();
    test_queue_to_list();
    test_queue_contains();
}