#include "../include/stack.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

void test_stack_create()
{
    printf("Testing test_stack_create()...\n");

    // initialize the stack
    Stack *stack = stack_create();

    // the only path that should happen
    assert(stack != NULL);
    assert(stack->size == 0);
    assert(stack->collection != NULL);

    stack_destroy(stack);
    printf("Testing successful!\n");
}

void test_stack_destroy()
{
    printf("Testing test_stack_destroy()...\n");

    // initialize a stack & some elements
    Stack *stack = stack_create();
    char *sunflower = "Sunflower";
    char *orchid = "Orchid";
    char *rose = "Rose";

    // unhappy paths
    assert(stack_destroy(NULL) == false);

    // pushing some elements to the stack
    stack_push(stack, &sunflower);
    stack_push(stack, &orchid);
    stack_push(stack, &rose);

    // happy paths
    assert(stack_destroy(stack) == true);

    printf("Testing successful!\n");
}

void test_stack_push()
{
    printf("Testing test_stack_push()...\n");

    // initialize a stack & some elements
    Stack *stack = stack_create();
    char *sunflower = "Sunflower";
    char *orchid = "Orchid";
    char *rose = "Rose";

    // unhappy paths
    assert(stack_push(NULL, &rose) == false); // null stack pointer
    assert(stack_push(stack, NULL) == false); // null element pointer

    // happy paths; testing if the push function works
    assert(stack_push(stack, &sunflower) == true);
    assert(stack_push(stack, &orchid) == true);
    assert(stack_push(stack, &rose) == true);

    // testing if the elements were pushed in the correct order (stack->collection is an ArrayList lol)
    assert(strcmp(*(char **)list_get(stack->collection, 0), "Sunflower") == 0);
    assert(strcmp(*(char **)list_get(stack->collection, 1), "Orchid") == 0);
    assert(strcmp(*(char **)list_get(stack->collection, 2), "Rose") == 0);

    stack_destroy(stack);
    printf("Testing successful!\n");
}

void test_stack_peek()
{
    printf("Testing test_stack_peek()...\n");

    // initialize a stack & some elements
    Stack *stack = stack_create();
    char *sunflower = "Sunflower";
    char *orchid = "Orchid";
    char *rose = "Rose";

    // pushing some elements to the stack
    stack_push(stack, &sunflower);
    stack_push(stack, &orchid);
    stack_push(stack, &rose);

    // unhappy paths
    assert(stack_peek(NULL) == NULL);

    // happy paths; testing if the peek function works
    assert(strcmp(*(char **)stack_peek(stack), "Rose") == 0);

    stack_pop(stack);
    assert(strcmp(*(char **)stack_peek(stack), "Orchid") == 0);

    stack_pop(stack);
    assert(strcmp(*(char **)stack_peek(stack), "Sunflower") == 0);
    stack_pop(stack);

    // peeking an empty stack
    assert(stack_peek(stack) == NULL);

    stack_destroy(stack);
    printf("Testing successful!\n");
}

void test_stack_pop()
{
    printf("Testing test_stack_pop()...\n");

    // initialize a stack & some elements
    Stack *stack = stack_create();
    char *sunflower = "Sunflower";
    char *orchid = "Orchid";
    char *rose = "Rose";

    // pushing some elements to the stack
    stack_push(stack, &sunflower);
    stack_push(stack, &orchid);
    stack_push(stack, &rose);

    // unhappy paths
    assert(stack_pop(NULL) == false);

    // happy paths
    assert(stack_pop(stack) == true);
    assert(strcmp(*(char **)stack_peek(stack), "Orchid") == 0);
    assert(stack->size == 2);

    assert(stack_pop(stack) == true);
    assert(strcmp(*(char **)stack_peek(stack), "Sunflower") == 0);
    assert(stack->size == 1);

    assert(stack_pop(stack) == true);
    assert(stack->size == 0);

    // popping from an empty stack
    assert(stack_pop(stack) == false);
    assert(stack->size == 0);

    // stack_destroy(stack);
    printf("Testing successful!\n");
}

void test_stack_is_empty()
{
    printf("Testing test_stack_is_empty()...\n");

    // initialize a stack & some elements
    Stack *stack = stack_create();
    char *sunflower = "Sunflower";
    char *orchid = "Orchid";
    char *rose = "Rose";

    // unhappy paths
    assert(stack_is_empty(NULL) == false);

    // checking if the stack is empty
    assert(stack_is_empty(stack) == true);

    // push some elements to the stack
    stack_push(stack, &sunflower);
    stack_push(stack, &orchid);
    stack_push(stack, &rose);

    // checking if the stack is no longer empty
    assert(stack_is_empty(stack) == false);

    stack_destroy(stack);
    printf("Testing successful!\n");
}

void test_stack_to_list()
{
    printf("Testing test_stack_to_list()...\n");

    // initialize a stack & some elements
    Stack *stack = stack_create();
    char *sunflower = "Sunflower";
    char *orchid = "Orchid";
    char *rose = "Rose";

    // pushing some elements to the stack
    stack_push(stack, &sunflower);
    stack_push(stack, &orchid);
    stack_push(stack, &rose);

    // convert Stack to ArrayList
    ArrayList *array_list = stack_to_list(stack);

    // testing if the conversion worked
    assert(array_list != NULL);
    assert(array_list->size == 3);
    assert(array_list->capacity == INITIAL_CAPACITY);

    stack_destroy(stack);
    list_destroy(array_list);

    printf("Testing successful!\n");
}

void test_stack_contains()
{
    printf("Testing test_stack_contains()...\n");

    // initialize a stack & some elements
    Stack *stack = stack_create();
    char *evil_string = "Red Spider Lily";
    char *sunflower = "Sunflower";
    char *orchid = "Orchid";
    char *rose = "Rose";

    // pushing some elements to the stack
    stack_push(stack, &sunflower);
    stack_push(stack, &orchid);
    stack_push(stack, &rose);

    // unhappy paths
    assert(stack_contains(NULL, &rose) == false); // null stack pointer
    assert(stack_contains(stack, NULL) == false); // null element pointer

    // happy paths
    assert(stack_contains(stack, &sunflower) == true);
    assert(stack_contains(stack, &orchid) == true);
    assert(stack_contains(stack, &rose) == true);

    // testing if the stack contains a non existant element
    assert(stack_contains(stack, &evil_string) == false);

    stack_destroy(stack);
    printf("Testing successful!\n");
}

void test_stack_search()
{
    printf("Testing test_stack_search()...\n");

    // initialize a stack & some elements
    Stack *stack = stack_create();
    char *evil_string = "Red Spider Lily";
    char *sunflower = "Sunflower";
    char *orchid = "Orchid";
    char *rose = "Rose";

    // pushing some elements to the stack
    stack_push(stack, &sunflower);
    stack_push(stack, &orchid);
    stack_push(stack, &rose);

    // unhappy paths
    assert(stack_search(NULL, &rose) == -1); // null stack pointer
    assert(stack_search(stack, NULL) == -1); // null element pointer

    // happy paths
    assert(stack_search(stack, &sunflower) == 1);
    assert(stack_search(stack, &orchid) == 2);
    assert(stack_search(stack, &rose) == 3);

    // testing if the stack can search a non existant element
    assert(stack_search(stack, &evil_string) == -1);

    stack_destroy(stack);
    printf("Testing successful!\n");
}

void test_stack()
{
    test_stack_create();
    test_stack_destroy();
    test_stack_push();
    test_stack_peek();
    test_stack_pop();
    test_stack_is_empty();
    test_stack_to_list();
    test_stack_contains();
    test_stack_search();
}