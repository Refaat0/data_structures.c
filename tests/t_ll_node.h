#pragma once 
#include "../include/ll_node.h"
#include <assert.h>
#include <stdio.h>

void test_ll_node_create()
{
    printf("Testing ll_node_create...\n");

    LLNode *node = ll_node_create();

    assert(node != NULL);
    assert(node->element != NULL);
    assert(node->next != NULL);
    assert(node->prev != NULL);

    ll_node_destroy(node);

    printf("Testing successful!\n");
}

void test_ll_node_destroy()
{
    printf("Testing ll_node_destroy...\n");

    LLNode *node = ll_node_create();
    assert(ll_node_destroy(node) == true);

    printf("Testing successful!\n");
}

void test_ll_node_pointers()
{
    printf("Testing the next/prev pointers for ll_node...\n");

    // initialize nodes
    LLNode *node = ll_node_create();
    LLNode *next = ll_node_create();
    LLNode *prev = ll_node_create();

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
    test_ll_node_create();
    test_ll_node_destroy();
    test_ll_node_pointers();
}
