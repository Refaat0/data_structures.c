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
    assert(dll_insert(NULL, &numbers[0], 0) == false);          // testing null dll pointer
    assert(dll_insert(linked_list, NULL, 0) == false);          // testing null element pointer
    assert(dll_insert(linked_list, &numbers[0], 100) == false); // testing index out of bounds

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
    dll_append(animals_list, &animals_array[2]);

    dll_append(planets_list, &planets_array[0]);
    dll_append(planets_list, &planets_array[1]);
    dll_append(planets_list, &planets_array[2]);

    // basically appending flowers_list to the empty general_list
    // general_list = {"Sunflower", "Rose", "Lily"}
    assert(dll_insert_ll(general_list, flowers_list, 0) == true);
    assert(general_list->size == 3);

    // basically appending animals_list at the end of the general_list
    // general_list = {"Sunflower", "Rose", "Lily", "Cat", "Dog", "Axolotl"}
    assert(dll_insert_ll(general_list, animals_list, general_list->size) == true);
    assert(general_list->size == 6);

    // basically appending planets_list in the middle of general_list
    assert(dll_insert_ll(general_list, planets_list, general_list->size / 2) == true);
    assert(general_list->size == 9);

    // testing head/tail/next/prev pointers
    assert(strcmp(*(char **)general_list->head->element, flowers_array[0]) == 0);
    assert(strcmp(*(char **)general_list->head->next->element, flowers_array[1]) == 0);
    assert(strcmp(*(char **)general_list->head->next->next->element, flowers_array[2]) == 0);

    assert(strcmp(*(char **)general_list->tail->element, animals_array[2]) == 0);
    assert(strcmp(*(char **)general_list->tail->prev->element, animals_array[1]) == 0);
    assert(strcmp(*(char **)general_list->tail->prev->prev->element, animals_array[0]) == 0);

    // clean up!
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

    // testing head/tail/next/prev pointers
    assert(strcmp(*(char **)flowers_list->head->element, flowers_array[0]) == 0);
    assert(strcmp(*(char **)flowers_list->head->next->element, flowers_array[1]) == 0);
    assert(strcmp(*(char **)flowers_list->head->next->next->element, flowers_array[2]) == 0);

    assert(strcmp(*(char **)flowers_list->tail->element, flowers_array[2]) == 0);
    assert(strcmp(*(char **)flowers_list->tail->prev->element, flowers_array[1]) == 0);
    assert(strcmp(*(char **)flowers_list->tail->prev->prev->element, flowers_array[0]) == 0);

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

    // testing head/tail/next/prev pointers
    assert(strcmp(*(char **)flowers_list->head->element, flowers_array[2]) == 0);
    assert(strcmp(*(char **)flowers_list->head->next->element, flowers_array[1]) == 0);
    assert(strcmp(*(char **)flowers_list->head->next->next->element, flowers_array[0]) == 0);

    assert(strcmp(*(char **)flowers_list->tail->element, flowers_array[0]) == 0);
    assert(strcmp(*(char **)flowers_list->tail->prev->element, flowers_array[1]) == 0);
    assert(strcmp(*(char **)flowers_list->tail->prev->prev->element, flowers_array[2]) == 0);

    dll_destroy(flowers_list);
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

    // happy paths; basically dequeing; "Rose" should now be the new head after "Sunflower" was removed
    assert(dll_remove(flowers_list, 0));
    assert(strcmp(*(char **)flowers_list->head->element, flowers_array[1]) == 0);
    assert(flowers_list->size == 4);

    // basically popping; "Orchids" should now be the new tail after "Forget Me Not" was popped
    assert(dll_remove(flowers_list, flowers_list->size));
    assert(strcmp(*(char **)flowers_list->tail->element, flowers_array[3]) == 0);
    assert(flowers_list->size == 3);

    // removing at an index
    assert(dll_remove(flowers_list, 1) == true);
    assert(flowers_list->size == 2);

    // testing head/tail/next/prev pointers
    assert(strcmp(*(char **)flowers_list->head->element, "Rose") == 0);
    assert(strcmp(*(char **)flowers_list->head->next->element, "Orchids") == 0);

    assert(strcmp(*(char **)flowers_list->tail->element, "Orchids") == 0);
    assert(strcmp(*(char **)flowers_list->tail->prev->element, "Rose") == 0);

    printf("Testing successful!\n");
}

void test_linked_list_pop()
{
    printf("Testing ll_pop()...\n");

    // initialize a linked list
    DoublyLinkedList *flowers_list = dll_create();
    char *flowers_array[] = {"Sunflower", "Rose", "Lily", "Orchids", "Forget Me Not"};

    // append some elements the list
    assert(dll_append(flowers_list, &flowers_array[0]) == true);
    assert(dll_append(flowers_list, &flowers_array[1]) == true);
    assert(dll_append(flowers_list, &flowers_array[2]) == true);
    assert(dll_append(flowers_list, &flowers_array[3]) == true);
    assert(dll_append(flowers_list, &flowers_array[4]) == true);

    // happy paths; Orchids is the new tail
    assert(dll_pop(flowers_list));
    assert(strcmp(*(char **)flowers_list->tail->element, "Orchids") == 0);
    assert(flowers_list->size == 4);

    // Lily is the new tail
    assert(dll_pop(flowers_list));
    assert(strcmp(*(char **)flowers_list->tail->element, "Lily") == 0);
    assert(flowers_list->size == 3);

    // happy paths; Rose is the new tail
    assert(dll_pop(flowers_list));
    assert(strcmp(*(char **)flowers_list->tail->element, "Rose") == 0);
    assert(flowers_list->size == 2);

    // Sunflower is the new tail
    assert(dll_pop(flowers_list));
    assert(strcmp(*(char **)flowers_list->tail->element, "Sunflower") == 0);
    assert(flowers_list->size == 1);

    // head & tail are now null
    assert(dll_pop(flowers_list) == true);
    assert(flowers_list->size == 0);

    assert(flowers_list->head == NULL);
    assert(flowers_list->tail == NULL);

    // cannot pop an empty list
    assert(dll_pop(flowers_list) == false);

    dll_destroy(flowers_list);
    printf("Testing successful!\n");
}

void test_linked_list_remove_element()
{
    printf("Testing ll_remove_element()...\n");

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

    // problem with deleting an element if it is the tail

    dll_destroy(flowers_list);
    printf("Testing successful!\n");
}

void test_linked_list_clear()
{
    printf("Testing ll_clear()...\n");

    // initialize a linked list
    DoublyLinkedList *flowers_list = dll_create();
    char *flowers_array[] = {"Sunflower", "Rose", "Lily", "Orchids", "Forget Me Not"};

    // append some elements the list
    assert(dll_append(flowers_list, &flowers_array[0]) == true);
    assert(dll_append(flowers_list, &flowers_array[1]) == true);
    assert(dll_append(flowers_list, &flowers_array[2]) == true);
    assert(dll_append(flowers_list, &flowers_array[3]) == true);
    assert(dll_append(flowers_list, &flowers_array[4]) == true);

    // happ paths
    assert(dll_clear(flowers_list) == true);
    assert(flowers_list->head == NULL);
    assert(flowers_list->tail == NULL);
    assert(flowers_list->size == 0);

    dll_destroy(flowers_list);
    printf("Testing successful!\n");
}

//// ==== Testing Miscellaneous Functions === ////

void test_linked_list_is_empty()
{
    printf("Testing ll_is_empty()...\n");

    // initialize a linked list
    DoublyLinkedList *flowers_list = dll_create();
    char *flowers_array[] = {"Sunflower", "Rose", "Lily"};

    // unhappy paths
    assert(dll_is_empty(NULL) == false);

    // happy paths
    assert(dll_is_empty(flowers_list) == true);

    // append some elements the list
    assert(dll_append(flowers_list, &flowers_array[0]) == true);
    assert(dll_append(flowers_list, &flowers_array[1]) == true);
    assert(dll_append(flowers_list, &flowers_array[2]) == true);

    // dll is no longer empty after appending stuff to it (duh!)
    assert(dll_is_empty(flowers_list) == false);

    dll_destroy(flowers_list);
    printf("Testing successful!\n");
}

void test_linked_list_contains()
{
    printf("Testing ll_contains()...\n");

    // initialize a linked list
    DoublyLinkedList *flowers_list = dll_create();
    char *flowers_array[] = {"Sunflower", "Rose", "Lily"};
    char *evil_string = "Red Spider Lily";

    // append some elements the list
    dll_append(flowers_list, &flowers_array[0]);
    dll_append(flowers_list, &flowers_array[1]);
    dll_append(flowers_list, &flowers_array[2]);

    // unhappy paths
    assert(dll_contains(flowers_list, &evil_string) == false); // testing for a non existant string
    assert(dll_contains(NULL, &flowers_array[0]) == false);    // null dll pointer
    assert(dll_contains(flowers_list, NULL) == false);         // null element pointer

    // happy paths
    assert(dll_contains(flowers_list, &flowers_array[0]) == true);
    assert(dll_contains(flowers_list, &flowers_array[1]) == true);
    assert(dll_contains(flowers_list, &flowers_array[2]) == true);

    dll_destroy(flowers_list);
    printf("Testing successful!\n");
}

void test_linked_list_index_of()
{
    printf("Testing ll_index_of()...\n");

    // initialize a linked list
    DoublyLinkedList *flowers_list = dll_create();
    char *flowers_array[] = {"Sunflower", "Rose", "Lily"};
    char *evil_string = "hehe";

    // append some elements the list
    dll_append(flowers_list, &flowers_array[0]);
    dll_append(flowers_list, &flowers_array[1]);
    dll_append(flowers_list, &flowers_array[2]);

    // unhappy paths
    assert(dll_index_of(flowers_list, &evil_string) == -1); // index of a non-existant element
    assert(dll_index_of(NULL, &flowers_array[0]) == -1);    // null dll pointer

    // happy paths
    assert(dll_index_of(flowers_list, &flowers_array[0]) == 0);
    assert(dll_index_of(flowers_list, &flowers_array[1]) == 1);
    assert(dll_index_of(flowers_list, &flowers_array[2]) == 2);

    dll_destroy(flowers_list);
    printf("Testing successful!\n");
}

void test_linked_list_get()
{
    printf("Testing ll_get()...\n");

    // initialize a linked list
    DoublyLinkedList *flowers_list = dll_create();
    char *flowers_array[] = {"Sunflower", "Rose", "Lily"};

    // unhappy paths
    assert(dll_get(NULL, 0) == false);
    assert(dll_get(flowers_list, 100) == false);

    // append some elements the list
    dll_append(flowers_list, &flowers_array[0]);
    dll_append(flowers_list, &flowers_array[1]);
    dll_append(flowers_list, &flowers_array[2]);

    // happy paths
    assert(dll_get(flowers_list, 0) == &flowers_array[0]);
    assert(dll_get(flowers_list, 1) == &flowers_array[1]);
    assert(dll_get(flowers_list, 2) == &flowers_array[2]);

    dll_destroy(flowers_list);
    printf("Testing successful!\n");
}

void test_linked_list_set()
{
    printf("Testing ll_set()...\n");

    // initialize a linked list
    DoublyLinkedList *flowers_list = dll_create();
    char *flowers_array[] = {"Sunflower", "Rose", "Lily"};
    char *silly_string = "Red Spider Lily";

    // append some elements the list
    dll_append(flowers_list, &flowers_array[0]);
    dll_append(flowers_list, &flowers_array[1]);
    dll_append(flowers_list, &flowers_array[2]);

    // unhappy paths
    assert(dll_set(flowers_list, &silly_string, 100) == false); // index out of bounds
    assert(dll_set(NULL, &silly_string, 0) == false);           // null dll pointer
    assert(dll_set(flowers_list, NULL, 0) == false);            // null element pointer

    // happy paths
    assert(dll_set(flowers_list, &silly_string, 0) == true);
    assert(dll_set(flowers_list, &silly_string, 1) == true);
    assert(dll_set(flowers_list, &silly_string, 2) == true);

    assert(strcmp(*(char **)flowers_list->head->element, silly_string) == 0);
    assert(strcmp(*(char **)flowers_list->head->next->element, silly_string) == 0);
    assert(strcmp(*(char **)flowers_list->head->next->next->element, silly_string) == 0);

    assert(strcmp(*(char **)flowers_list->tail->element, silly_string) == 0);
    assert(strcmp(*(char **)flowers_list->tail->prev->element, silly_string) == 0);
    assert(strcmp(*(char **)flowers_list->tail->prev->prev->element, silly_string) == 0);

    assert(flowers_list->size == 3);

    dll_destroy(flowers_list);
    printf("Testing successful!\n");
}

void test_linked_list()
{
    // test_linked_list_create();
    // test_linked_list_destroy();
    // test_linked_list_insert();
    // test_linked_list_insert_list();
    // test_linked_list_append();
    // test_linked_list_prepend();
    // test_linked_list_remove();
    // test_linked_list_pop();
    // test_linked_list_remove_element();
    test_linked_list_clear();
    test_linked_list_is_empty();
    test_linked_list_contains();
    test_linked_list_index_of();
    test_linked_list_get();
    test_linked_list_set();
}
