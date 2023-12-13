#include "../include/list.h"
#include <assert.h>
#include <stdio.h>

//// ==== Testing Helper Functions ==== ////

void test_ensure_capacity()
{
    List *list = list_create();
    int a = 7;

    // check if the initial capacity was initialized properly
    assert(list->capacity == INITIAL_CAPACITY);

    // fill up the list
    for (int i = 1; i <= INITIAL_CAPACITY; i++)
    {
        list_append(list, &a);
    }

    // add one more element to envoke the _ensure_capacity function
    list_append(list, &a);

    // check if the list's capacity has grown
    assert(list->capacity == INITIAL_CAPACITY * GROWING_RATE);
}

void test_trim_to_size()
{
    List *list = list_create();
    int a = 7;

    list_append(list, &a);
    list_append(list, &a);
    list_append(list, &a);
    _trim_to_size(list);

    assert(list->capacity == 3);
}

//// ==== Testing List "Life-Cycle" Functions ==== ////

void test_list_create()
{
    List *list = list_create();

    assert(list != NULL);
    assert(list->capacity == INITIAL_CAPACITY);
    assert(list->size == 0);

    list_destroy(list);
}

void test_list_destroy()
{
    // how do i test this :(
    List *list = list_create();
    assert(list_destroy(list) == true);
}

//// ==== Testing Insertion Functions === ////

void test_list_insert()
{
    List *list = list_create();

    int numbers[] = {1, 2, 3,
                     4, 5, 6,
                     10, 20, 30};

    int n = sizeof(numbers) / sizeof(numbers[0]);

    // basically prepending elements to the list -> list = [3, 2, 1]
    assert(list_insert(list, &numbers[0], 0) == true);
    assert(list_insert(list, &numbers[1], 0) == true);
    assert(list_insert(list, &numbers[2], 0) == true);

    assert(*(int *)list_get(list, 0) == 3);
    assert(*(int *)list_get(list, 1) == 2);
    assert(*(int *)list_get(list, 2) == 1);

    // basically appending elements to the list -> list = [3, 2, 1, 4, 5, 6 ]
    assert(list_insert(list, &numbers[3], list->size) == true);
    assert(list_insert(list, &numbers[4], list->size) == true);
    assert(list_insert(list, &numbers[5], list->size) == true);

    assert(*(int *)list_get(list, 3) == 4);
    assert(*(int *)list_get(list, 4) == 5);
    assert(*(int *)list_get(list, 5) == 6);

    // basically appending elements to the middle of the list -> list = [3, 2, 1]
    assert(list_insert(list, &numbers[6], list->size) == true);
    assert(list_insert(list, &numbers[7], list->size) == true);
    assert(list_insert(list, &numbers[8], list->size) == true);

    assert(*(int *)list_get(list, 6) == 10);
    assert(*(int *)list_get(list, 7) == 20);
    assert(*(int *)list_get(list, 8) == 30);

    list_destroy(list);
}

void test_list_insert_list()
{
}

void test_list_append()
{
    List *list = list_create();

    int numbers[] = {1, 2, 3};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    assert(list_append(list, &numbers[0]) == true);
    assert(list_append(list, &numbers[1]) == true);
    assert(list_append(list, &numbers[2]) == true);

    assert(*(int *)list_get(list, 0) == 1);
    assert(*(int *)list_get(list, 1) == 2);
    assert(*(int *)list_get(list, 2) == 3);

    list_destroy(list);
}

void test_list_prepend()
{
    List *list = list_create();

    int numbers[] = {1, 2, 3};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    assert(list_prepend(list, &numbers[0]) == true);
    assert(list_prepend(list, &numbers[1]) == true);
    assert(list_prepend(list, &numbers[2]) == true);

    assert(*(int *)list_get(list, 0) == 3);
    assert(*(int *)list_get(list, 1) == 2);
    assert(*(int *)list_get(list, 2) == 1);

    list_destroy(list);
}

//// ==== Testing Deletion Functions === ////

void test_list_remove()
{
    List *list = list_create();

    int numbers[] = {1, 2, 3};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    list_append(list, &numbers[0]);
    list_append(list, &numbers[1]);
    list_append(list, &numbers[2]);
    assert(list->size == 3);

    list_remove(list, 1);
    assert(list->size == 2);
    assert(*(int *)list_get(list, 1) != 1);
    assert(*(int *)list_get(list, 0) == 1);
    assert(*(int *)list_get(list, 1) == 3);

    list_destroy(list);
}

void test_list_pop()
{
    List *list = list_create();

    int numbers[] = {1, 2, 3};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    list_append(list, &numbers[0]);
    list_append(list, &numbers[1]);
    list_append(list, &numbers[2]);

    assert(list_pop(list) == true);
    assert(*(int *)list_get(list, 0) == 1);
    assert(*(int *)list_get(list, 0) == 2);
    assert(list->size == 2);

    assert(list_pop(list) == true);
    assert(*(int *)list_get(list, 0) == 1);
    assert(list->size == 1);

    assert(list_pop(list) == true);
    assert(list->size == 0);
}

void test_list_remove_element()
{
    List *list = list_create();

    int numbers[] = {1, 2, 3};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    list_append(list, &numbers[0]);
    list_append(list, &numbers[1]);
    list_append(list, &numbers[2]);

    assert(list_remove_element(list, &numbers[0]));
    assert(list->size == 2);

    list_destroy(list);
}

void test_list_clear()
{
    List *list = list_create();

    int numbers[] = {1, 2, 3};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    list_append(list, &numbers[0]);
    list_append(list, &numbers[0]);
    list_append(list, &numbers[0]);

    assert(list_clear(list) == true);
    assert(list->size == 0);
}

//// ==== Testing Miscellaneous Functions === ////

void test_list_is_empty()
{
    List *list = list_create();

    assert(list_is_empty(list) == true);

    int a = 12;
    list_append(list, &a);

    assert(list_is_empty(list) == false);
}

void test_list_is_full()
{
    List *list = list_create();
    int a = 7;

    // the list should not be full since we did not yet add anything to it
    assert(list_is_full(list) == false);

    // fill up the list with elements
    for (int i = 1; i <= INITIAL_CAPACITY; i++)
    {
        list_append(list, &a);
    }

    // it should be full now
    assert(list_is_full(list) == true);

    // the list should now automatically grow
    list_append(list, &a);

    // it should not be full since the capacity just grew by INITIAL_CAPACITY * GROWING_RATE
    assert(list_is_full(list) == false);
}

void test_list_contains()
{
    List *list = list_create();

    int a = 2;
    int b = 4;
    int c = 6;

    int evil_int = 100;

    list_append(list, &a);
    list_append(list, &b);
    list_append(list, &c);

    assert(list_contains(list, &a) == true);
    assert(list_contains(list, &b) == true);
    assert(list_contains(list, &c) == true);

    assert(list_contains(list, &evil_int) == false);

    list_destroy(list);
}

void test_list_index_of()
{
    List *list = list_create();
    int a = 7;
    int b = 14;
    int c = 21;

    assert(list_index_of(list, &a) == -1);

    list_append(list, &a);
    list_append(list, &b);
    list_append(list, &c);

    assert(list_index_of(list, &a) == 0);
    assert(list_index_of(list, &b) == 1);
    assert(list_index_of(list, &c) == 2);

    list_destroy(list);
}

void test_list_get()
{
    List *list = list_create();
    int a = 7;
    int b = 14;
    int c = 21;

    assert(list_get(list, 0) == NULL);

    list_append(list, &a);
    list_append(list, &b);
    list_append(list, &c);

    assert(list_get(list, 0) == &a);
    assert(list_get(list, 1) == &b);
    assert(list_get(list, 2) == &c);

    list_destroy(list);
}

void test_list_set()
{
    List *list = list_create();
    int a = 7;
    int b = 14;

    assert(list_set(list, &a, 0) == false);

    list_append(list, &a);
    assert(list_set(list, &b, 0) == true);
    assert(*(int *)list_get(list, 0) == 14);

    list_destroy(list);
}

void test_list()
{
    test_ensure_capacity();
    test_trim_to_size();
    test_list_create();
    test_list_destroy();
    test_list_insert();
    test_list_append();
    test_list_remove();
    test_list_remove_element();
    test_list_clear();
    test_list_is_full();
    test_list_is_empty();
    test_list_contains();
    test_list_index_of();
    test_list_get();
    test_list_set();
}
