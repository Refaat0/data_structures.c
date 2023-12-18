#pragma once
#include "../include/doubly-linked-list.h"
#include <assert.h>
#include <stdio.h>

//// ==== Testing Linked-List "Life-Cycle" Functions ==== ////

void test_linked_list_create()
{
    printf("Testing ll_create()...\n");

    // initialize a linked list
    DoublyLinkedList *linked_list = dll_create();

    // check if it has been initialized properly
    assert(linked_list != NULL);
    assert(linked_list->size == 0);
    assert(linked_list->head == NULL);
    assert(linked_list->tail == NULL);

    dll_destroy(linked_list);
    printf("Testing successful!\n");
}

void test_linked_list_destroy()
{
    printf("Testing ll_destroy()...\n");

    // initialize a linked list & an array of elements
    DoublyLinkedList *linked_list = dll_create();
    int numbers[] = { 1, 2, 3 };

    // append some elements to the linked list
    dll_append(linked_list, &numbers[0]);
    dll_append(linked_list, &numbers[1]);
    dll_append(linked_list, &numbers[2]);

    // check if the linked list was properly destroyed
    assert(dll_destroy(linked_list) == true);
    
    printf("Testing successful!\n");
}

//// ==== Testing Insertion Functions === ////

void test_linked_list_insert()
{
    printf("Testing ll_insert()...\n");



    printf("Testing successful!\n");
}

void test_linked_list_insert_list()
{
    printf("Testing ll_insert_list()...\n");
    printf("Testing successful!\n");
}

void test_linked_list_append()
{
    printf("Testing ll_append()...\n");
    printf("Testing successful!\n");
}

void test_linked_list_prepend()
{
    printf("Testing ll_prepend()...\n");
    printf("Testing successful!\n");
}

//// ==== Testing Deletion Functions === ////

void test_linked_list_remove()
{
    printf("Testing ll_remove()...\n");
    printf("Testing successful!\n");
}

void test_linked_list_pop()
{
    printf("Testing ll_pop()...\n");
    printf("Testing successful!\n");
}

void test_linked_list_remove_element()
{
    printf("Testing ll_remove_element()...\n");
    printf("Testing successful!\n");
}

void test_linked_list_clear()
{
    printf("Testing ll_clear()...\n");
    printf("Testing successful!\n");
}

//// ==== Testing Miscellaneous Functions === ////

void test_linked_list_is_empty()
{
    printf("Testing ll_is_empty()...\n");
    printf("Testing successful!\n");
}

void test_linked_list_is_full()
{
    printf("Testing ll_is_full()...\n");
    printf("Testing successful!\n");
}

void test_linked_list_contains()
{
    printf("Testing ll_contains()...\n");
    printf("Testing successful!\n");
}

void test_linked_list_index_of()
{
    printf("Testing ll_index_of()...\n");
    printf("Testing successful!\n");
}

void test_linked_list_get()
{
    printf("Testing ll_get()...\n");
    printf("Testing successful!\n");
}

void test_linked_list_set()
{
    printf("Testing ll_set()...\n");
    printf("Testing successful!\n");
}

void test_linked_list()
{
    test_linked_list_create();
    test_linked_list_destroy();
    test_linked_list_insert();
    test_linked_list_insert_list();
    test_linked_list_append();
    test_linked_list_prepend();
    test_linked_list_remove();
    test_linked_list_pop();
    test_linked_list_remove_element();
    test_linked_list_clear();
    test_linked_list_is_empty();
    test_linked_list_is_full();
    test_linked_list_contains();
    test_linked_list_index_of();
    test_linked_list_get();
    test_linked_list_set();
}
