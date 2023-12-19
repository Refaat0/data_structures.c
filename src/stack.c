#include "../include/array-list.h"
#include "../include/stack.h"
#include <stdbool.h>

//// ==== Stack "Life-Cycle" Functions ==== ////

Stack *stack_create()
{
    Stack *stack;
    return stack;
}

bool stack_destroy(Stack *stack)
{
    return false;
}

//// ==== Stack "Life-Cycle" Functions ==== ////

bool stack_push(Stack *stack, void *element)
{
    return false;
}

void *stack_peek(Stack *stack)
{
    void *nullptr;
    return nullptr;
}

bool stack_pop(Stack *stack)
{
    return false;
}

bool stack_is_full(Stack *stack)
{
    return false;
}

bool stack_is_empty(Stack *stack)
{
    return false;
}

ArrayList *stack_to_list(Stack *stack)
{
    ArrayList *list;
    return list;
}

bool stack_contains(Stack *stack)
{
    return false;
}

bool stack_search(Stack *stack, void *element)
{
    return false;
}
