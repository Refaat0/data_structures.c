#pragma once 
#include "../include/doubly-linked-list-node.h"
#include <assert.h>
#include <stdio.h>

void test_dll_node_create()
{
    printf("Testing ll_node_create...\n");

    DLLNode *node = dll_node_create();

    assert(node != NULL);
    assert(node->element != NULL);
    assert(node->next != NULL);
    assert(node->prev != NULL);

    dll_node_destroy(node);

    printf("Testing successful!\n");
}

void test_dll_node_destroy()
{
    printf("Testing ll_node_destroy...\n");

    DLLNode *node = dll_node_create();
    assert(dll_node_destroy(node) == true);

    printf("Testing successful!\n");
}

void test_dll_node_pointers()
{
    printf("Testing the next/prev pointers for ll_node...\n");

    // initialize nodes
    DLLNode *node = dll_node_create();
    DLLNode *next = dll_node_create();
    DLLNode *prev = dll_node_create();

    // initialize integers
    int integer_next = 12;
    int integer_prev = 24;

    // set the elements for the next & prev pointers
    next->element = &integer_next;
    prev->element = &integer_prev;

    // set the next & prev nodes for the main node
    node->next = next;
    node->prev = prev;

    // testing the next node
    assert(node->next != NULL);
    assert(*(int *)node->next->element == integer_next);

    // testing the prev node
    assert(node->prev != NULL);
    assert(*(int *)node->prev->element == integer_prev);

    printf("Testing successful!\n");
}

void test_ll_node()
{
    test_dll_node_create();
    test_dll_node_destroy();
    test_dll_node_pointers();
}
