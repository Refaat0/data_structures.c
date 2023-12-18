#pragma once
#include "../include/doubly-linked-list.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

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
    int numbers[] = {1, 2, 3};

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

    // initialize a linked list & an array of elements
    DoublyLinkedList *linked_list = dll_create();
    int numbers[] = {1, 2, 3,
                     10, 20, 30,
                     100, 200, 300};

    // unhappy paths
    assert(dll_insert(NULL, &numbers[0], 0) == false);
    assert(dll_insert(linked_list, NULL, 0) == false);
    assert(dll_insert(linked_list, &numbers[0], 100) == false);

    // happy paths; basically prepending
    assert(dll_insert(linked_list, &numbers[0], 0) == true);
    assert(dll_insert(linked_list, &numbers[1], 0) == true);
    assert(dll_insert(linked_list, &numbers[2], 0) == true);
    assert(linked_list->size == 3);

    // checking if the last three elements where prepended correctly; DLL={3,2,1}
    assert(dll_index_of(linked_list, &numbers[0]) == 2); // element "1" is at index 2
    assert(dll_index_of(linked_list, &numbers[1]) == 1); // element "2" is at index 1
    assert(dll_index_of(linked_list, &numbers[2]) == 0); // element "0" is at index 0

    // basically appending
    assert(dll_insert(linked_list, &numbers[3], linked_list->size) == true);
    assert(dll_insert(linked_list, &numbers[4], linked_list->size) == true);
    assert(dll_insert(linked_list, &numbers[5], linked_list->size) == true);
    assert(linked_list->size == 6);

    // checking if the last three elements where appended correctly; DLL={3,2,1, 10,20,30}
    assert(dll_index_of(linked_list, &numbers[3]) == 3); // element "10" is at index 3
    assert(dll_index_of(linked_list, &numbers[4]) == 4); // element "20" is at index 4
    assert(dll_index_of(linked_list, &numbers[5]) == 5); // element "30" is at index 5

    // actually using the insert function as intended
    assert(dll_insert(linked_list, &numbers[6], 3) == true);
    assert(dll_insert(linked_list, &numbers[7], 5) == true);
    assert(dll_insert(linked_list, &numbers[8], 7) == true);
    assert(linked_list->size == 9);

    // checking if the last three elements where appended correctly; DLL={3,2,1, 100, 10,200, 20,300,30}
    assert(dll_index_of(linked_list, &numbers[6]) == 3); // element "10" is at index 3
    assert(dll_index_of(linked_list, &numbers[7]) == 5); // element "20" is at index 4
    assert(dll_index_of(linked_list, &numbers[8]) == 7); // element "30" is at index 5

    dll_destroy(linked_list);
    printf("Testing successful!\n");
}

void test_linked_list_insert_list()
{
    printf("Testing ll_insert_list()...\n");

    // initialize link lists
    DoublyLinkedList *general_list = dll_create();
    DoublyLinkedList *flowers_list = dll_create();
    DoublyLinkedList *animals_list = dll_create();
    DoublyLinkedList *planets_list = dll_create();

    // initialize arrays
    char *flowers_array[] = {"Sunflower", "Rose", "Lily"};
    char *animals_array[] = {"Cat", "Dog", "Axolotl"};
    char *planets_array[] = {"Sun", "Moon", "Earth"};

    // fill up the lists with some elements
    dll_append(flowers_list, &flowers_array[0]);
    dll_append(flowers_list, &flowers_array[1]);
    dll_append(flowers_list, &flowers_array[2]);

    dll_append(animals_list, &animals_array[0]);
    dll_append(animals_list, &animals_array[1]);
    dll_append(animals_list, &animals_list[2]);

    dll_append(planets_list, &planets_list[0]);
    dll_append(planets_list, &planets_list[1]);
    dll_append(planets_list, &planets_list[2]);

    // inserts the animals list before the flowers list
    assert(dll_insert_ll(general_list, flowers_list, 0) == true);

    // come back to this after index_of and get functions are tested

    dll_destroy(general_list);
    dll_destroy(flowers_list);
    dll_destroy(animals_list);
    dll_destroy(planets_list);

    printf("Testing successful!\n");
}

void test_linked_list_append()
{
    printf("Testing ll_append()...\n");

    // initialize a linked list
    DoublyLinkedList *flowers_list = dll_create();
    char *flowers_array[] = {"Sunflower", "Rose", "Lily"};

    // unhappy paths
    assert(dll_append(NULL, &flowers_array[0]) == false);
    assert(dll_append(flowers_list, NULL) == false);
    
    // append some elements the list
    assert(dll_append(flowers_list, &flowers_array[0]) == true);
    assert(dll_append(flowers_list, &flowers_array[1]) == true);
    assert(dll_append(flowers_list, &flowers_array[2]) == true);

    // check if the elements were appended properly
    assert(dll_index_of(flowers_list, &flowers_array[0]) == 0);
    assert(dll_index_of(flowers_list, &flowers_array[1]) == 1);
    assert(dll_index_of(flowers_list, &flowers_array[2]) == 2);


    dll_destroy(flowers_list);

    printf("Testing successful!\n");
}

void test_linked_list_prepend()
{
    printf("Testing ll_prepend()...\n");

    // initialize a linked list
    DoublyLinkedList *flowers_list = dll_create();
    char *flowers_array[] = {"Sunflower", "Rose", "Lily"};

    // unhappy paths
    assert(dll_prepend(NULL, &flowers_array[0]) == false);
    assert(dll_prepend(flowers_list, NULL) == false);
    
    // append some elements the list
    assert(dll_prepend(flowers_list, &flowers_array[0]) == true);
    assert(dll_prepend(flowers_list, &flowers_array[1]) == true);
    assert(dll_prepend(flowers_list, &flowers_array[2]) == true);

    // check if the elements were appended properly
    assert(dll_index_of(flowers_list, &flowers_array[0]) == 2);
    assert(dll_index_of(flowers_list, &flowers_array[1]) == 1);
    assert(dll_index_of(flowers_list, &flowers_array[2]) == 0);

    printf("Testing successful!\n");
}

//// ==== Testing Deletion Functions === ////

void test_linked_list_remove()
{
    printf("Testing ll_remove()...\n");

    // initialize a linked list
    DoublyLinkedList *flowers_list = dll_create();
    char *flowers_array[] = {"Sunflower", "Rose", "Lily", "Orchids", "Forget Me Not"};

    // append some elements the list
    assert(dll_append(flowers_list, &flowers_array[0]) == true);
    assert(dll_append(flowers_list, &flowers_array[1]) == true);
    assert(dll_append(flowers_list, &flowers_array[2]) == true);
    assert(dll_append(flowers_list, &flowers_array[3]) == true);
    assert(dll_append(flowers_list, &flowers_array[4]) == true);

    // unhappy paths
    assert(dll_remove(NULL, 0) == false);
    assert(dll_remove(flowers_list, 100) == false);

    // happy paths
    // basically dequeing
    assert(dll_remove(flowers_list, 0));
    assert(flowers_list->size == 4);

    // basically popping
    assert(dll_remove(flowers_list, flowers_list->size));
    assert(flowers_list->size == 3);

    // removing at an index
    assert(dll_remove(flowers_list, 1) == true);
    assert(flowers_list->size == 2);

    // checking if the correct elements were removed
    assert(strcmp(*(char**)dll_get(flowers_list, 0), flowers_array[1]) == 0); // "rose"   should be at index 0
    assert(strcmp(*(char**)dll_get(flowers_list, 1), flowers_array[3]) == 0); // "orchid" should be at index 1

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

    // test_linked_list_is_empty();
    // test_linked_list_is_full();
    // test_linked_list_contains();
    // test_linked_list_index_of();
    // test_linked_list_get();
    // test_linked_list_set();
}
