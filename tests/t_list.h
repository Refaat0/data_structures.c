#include "../include/list.h"
#include <assert.h>
#include <stdio.h>

//// ==== Testing Helper Functions ==== ////

void test_ensure_capacity()
{
    printf("Testing _ensure_capacity...\n");

    // initialize a list & an element
    List *list = list_create();
    int angel_int = 7;

    // unhappy path
    assert(_ensure_capacity(NULL) == false);

    // check if the initial capacity was initialized properly
    assert(list->capacity == INITIAL_CAPACITY);

    // fill up the list with
    for (int i = 1; i <= INITIAL_CAPACITY; i++)
    {
        list_append(list, &angel_int);
    }

    // add one more element to envoke the _ensure_capacity function
    list_append(list, &angel_int);

    // check if the list's capacity has grown
    assert(list->capacity == INITIAL_CAPACITY * GROWING_RATE);

    list_destroy(list);
    printf("Testing successful!\n");
}

void test_trim_to_size()
{
    printf("Testing _trim_to_size...\n");

    // initialize a list; its starting capacity is the INITIAL_CAPACITY
    List *list = list_create();
    int a = 7;

    // unhappy path
    assert(_trim_to_size(NULL) == false);

    // append three elements to the list
    list_append(list, &a);
    list_append(list, &a);
    list_append(list, &a);

    // test the the function reduced the lists capacity to three
    assert(_trim_to_size(list) == true);
    assert(list->capacity == 3);

    list_destroy(list);
    printf("Testing successful!\n");
}

//// ==== Testing List "Life-Cycle" Functions ==== ////

void test_list_create()
{
    printf("Testing list_create()...\n");

    // initialize a list
    List *list = list_create();

    // checking if it has been initialized properly
    assert(list != NULL);
    assert(list->capacity == INITIAL_CAPACITY);
    assert(list->size == 0);

    list_destroy(list);
    printf("Testing successful!\n");
}

void test_list_destroy()
{
    printf("Testing list_destroy()...\n");

    // how do i test this :(
    List *list = list_create();
    assert(list_destroy(list) == true);

    printf("Testing successful!\n");
}

//// ==== Testing Insertion Functions === ////

void test_list_insert()
{
    printf("Testing list_insert()...\n");

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
    printf("Testing successful!\n");
}

void test_list_insert_list()
{
    printf("Testing list_insert_list()...\n");

    // initialize two different lists
    List *list_alpha = list_create();
    List *list_bravo = list_create();

    // initialize an array of odd integers to append to list_alpha
    int numbers_odd[] = {1, 3, 5};
    int n_of_odd = sizeof(numbers_odd) / sizeof(numbers_odd[0]);

    // initialize an array of even integers to append to list_bravo
    int numbers_evn[] = {2, 4, 6};
    int n_of_evn = sizeof(numbers_evn) / sizeof(numbers_evn[0]);

    // append the arrays to their respective lists
    for (int i = 0; i < n_of_odd; i++)
    {
        list_append(list_alpha, &numbers_odd[i]);
    }
    for (int i = 0; i < n_of_odd; i++)
    {
        list_append(list_bravo, &numbers_evn[i]);
    }

    // check if the function returned true & inserted the elements
    assert(list_insert_list(list_alpha, list_bravo, 0) == true);
    assert(list_alpha->size == 6);

    // check if the inserted elements where indeed inserted at index 0
    assert(*(int *)list_get(list_alpha, 0) == 2);
    assert(*(int *)list_get(list_alpha, 1) == 4);
    assert(*(int *)list_get(list_alpha, 2) == 6);
    assert(*(int *)list_get(list_alpha, 3) == 1);
    assert(*(int *)list_get(list_alpha, 4) == 3);
    assert(*(int *)list_get(list_alpha, 5) == 5);

    list_destroy(list_alpha);
    list_destroy(list_bravo);

    printf("Testing successful!\n");
}

void test_list_append()
{
    printf("Testing list_append()...\n");

    // initalize a list
    List *list = list_create();

    // initialize an array of numbers
    int numbers[] = {1, 2, 3};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    // append the list with the elements in the numbers array from left to right
    assert(list_append(list, &numbers[0]) == true);
    assert(list_append(list, &numbers[1]) == true);
    assert(list_append(list, &numbers[2]) == true);

    // verify that the elements have been appended properly -> list={ 1, 2, 3 }
    assert(*(int *)list_get(list, 0) == 1);
    assert(*(int *)list_get(list, 1) == 2);
    assert(*(int *)list_get(list, 2) == 3);

    list_destroy(list);
    printf("Testing successful!\n");
}

void test_list_prepend()
{
    printf("Testing list_prepend()...\n");

    // initialize a list
    List *list = list_create();

    // initialize an array of numbers
    int numbers[] = {1, 2, 3};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    // prepend the list with the elements in the numbers array from left to right
    assert(list_prepend(list, &numbers[0]) == true);
    assert(list_prepend(list, &numbers[1]) == true);
    assert(list_prepend(list, &numbers[2]) == true);

    // verify that the elements have been prepended properly -> list={ 1, 2, 3 }
    assert(*(int *)list_get(list, 0) == 3);
    assert(*(int *)list_get(list, 1) == 2);
    assert(*(int *)list_get(list, 2) == 1);

    list_destroy(list);
    printf("Testing successful!\n");
}

//// ==== Testing Deletion Functions === ////

void test_list_remove()
{
    printf("Testing list_remove()...\n");

    // initialize the list
    List *list = list_create();

    // initialize an array of numbers
    int numbers[] = {1, 2, 3};

    // append the list with elements from the numbers array
    list_append(list, &numbers[0]);
    list_append(list, &numbers[1]);
    list_append(list, &numbers[2]);

    // unhappy paths
    assert(list_remove(list, 100) == false); // index out of bounds
    assert(list_remove(NULL, 0) == false);   // null pointer

    // check that the list's size is 3 as we just appended 3 elements to the list
    assert(list->size == 3);

    // remove the element at index 0 in the list & verify that the size decrease to 2
    assert(list_remove(list, 0) == true);
    assert(list->size == 2);

    // verify that the element at index 0 is no longer 1 but now 2
    assert(*(int *)list_get(list, 0) == 2);

    // verify that the element at index 1 is no longer 2 but now 3
    assert(*(int *)list_get(list, 1) == 3);

    // remove the element at index 1 in the list & verify that the size decrease to 1
    assert(list_remove(list, 1) == true);
    assert(list->size == 1);

    // verify that the element at index 0 is still 2
    assert(*(int *)list_get(list, 0) == 2);

    // remove the final element in the list & verify that the size decreased to 0
    assert(list_remove(list, 0) == true);
    assert(list->size == 0);

    // verify that trying to remove an element from an empty list returns false
    assert(list_remove(list, 0) == false);

    list_destroy(list);
    printf("Testing successful!\n");
}

void test_list_pop()
{
    printf("Testing list_pop()...\n");

    // initialize a list & a numbers array
    List *list = list_create();
    int numbers[] = {1, 2, 3};

    // append the list with elements from the numbers array
    list_append(list, &numbers[0]);
    list_append(list, &numbers[1]);
    list_append(list, &numbers[2]);

    // unhappy path
    assert(list_pop(NULL) == false);

    // pop three off this list, verify that the size decreased and,
    // list[0] & list[1] are still equals to one & two respectively
    assert(list_pop(list) == true);
    assert(*(int *)list_get(list, 0) == 1);
    assert(*(int *)list_get(list, 1) == 2);
    assert(list->size == 2);

    // pop two off this list, verify that the size decreased and,
    // list[0] is still equals to one
    assert(list_pop(list) == true);
    assert(*(int *)list_get(list, 0) == 1);
    assert(list->size == 1);

    // pop one off this list and verify that the size is zero
    assert(list_pop(list) == true);
    assert(list->size == 0);

    // verify that trying to pop elements from an empty list returns false
    assert(list_pop(list) == false);

    list_destroy(list);
    printf("Testing successful!\n");
}

void test_list_remove_element()
{
    printf("Testing list_remove_element()...\n");

    // initialize a list & a numbers array
    List *list = list_create();
    int numbers[] = {1, 2, 3};

    // append the list with elements from the numbers array
    list_append(list, &numbers[0]);
    list_append(list, &numbers[1]);
    list_append(list, &numbers[2]);

    // unhappy paths
    assert(list_remove_element(NULL, &numbers[0]) == false);
    assert(list_remove_element(list, NULL) == false);

    // remove the element "one" from the list & verify that the list's size decreased
    assert(list_remove_element(list, &numbers[0]) == true);
    assert(list->size == 2);

    // verify that the element "one" has indeed been removed
    assert(*(int *)list_get(list, 0) == 2);
    assert(*(int *)list_get(list, 1) == 3);

    // remove the element "three" from the list & verify that the list's size decreased
    assert(list_remove_element(list, &numbers[2]) == true);
    assert(list->size == 1);

    // remove the element last element from the list & verify that the list's size is zero
    assert(list_remove_element(list, &numbers[1]) == true);
    assert(list->size == 0);

    // verify that trying to remove an element from an empty array returns false
    assert(list_remove_element(list, &numbers[0]) == false);
    assert(list_remove_element(list, &numbers[1]) == false);
    assert(list_remove_element(list, &numbers[2]) == false);

    list_destroy(list);
    printf("Testing successful!\n");
}

void test_list_clear()
{
    printf("Testing list_clear()...\n");

    // initialize a list & a numbers array
    List *list = list_create();
    int numbers[] = {1, 2, 3};

    // unhappy path
    assert(list_clear(NULL) == false); // can not clear when list is NULL
    assert(list_clear(list) == false); // can not clear an empty list

    // append the list with elements from the numbers array
    list_append(list, &numbers[0]);
    list_append(list, &numbers[0]);
    list_append(list, &numbers[0]);

    // verify that the list has been cleared
    assert(list_clear(list) == true);
    assert(list->size == 0);

    list_destroy(list);
    printf("Testing successful!\n");
}

//// ==== Testing Miscellaneous Functions === ////

void test_list_is_empty()
{
    printf("Testing list_is_empty()...\n");

    // initialize a list & an integer
    List *list = list_create();
    int silly_integer = 7;

    // unhappy paths
    assert(list_is_empty(NULL) == false);

    // verify that the list is indeed empty
    assert(list_is_empty(list) == true);

    // append an element to the list & verify that it is no longer empty
    list_append(list, &silly_integer);
    assert(list_is_empty(list) == false);

    list_destroy(list);
    printf("Testing successful!\n");
}

void test_list_is_full()
{
    printf("Testing list_is_full()...\n");

    // initialize a list & an integer
    List *list = list_create();
    int silly_integer = 7;

    // unhappy paths
    assert(list_is_full(NULL) == false);

    // the list should not be full since we did not yet add anything to it
    assert(list_is_full(list) == false);

    // fill up the list with elements
    for (int i = 1; i <= INITIAL_CAPACITY; i++)
    {
        list_append(list, &silly_integer);
    }

    // it should be full now
    assert(list_is_full(list) == true);

    // the list should now automatically grow
    list_append(list, &silly_integer);

    // it should not be full since the capacity just grew by INITIAL_CAPACITY * GROWING_RATE
    assert(list_is_full(list) == false);

    list_destroy(list);
    printf("Testing successful!\n");
}

void test_list_contains()
{
    printf("Testing list_contains()...\n");

    // initialize a list & an array of numbers
    List *list = list_create();
    int numbers[] = {1, 2, 3};
    int evil_int = 100;

    // unhappy path
    assert(list_contains(list, NULL) == false);
    assert(list_contains(NULL, &evil_int) == false);

    // append the list with some elements
    list_append(list, &numbers[0]);
    list_append(list, &numbers[1]);
    list_append(list, &numbers[2]);

    // verify that the list indeed contains the appended elements
    assert(list_contains(list, &numbers[0]) == true);
    assert(list_contains(list, &numbers[1]) == true);
    assert(list_contains(list, &numbers[2]) == true);

    // verify that the list does not contain the evil_int as it was never appended to the list
    assert(list_contains(list, &evil_int) == false);

    list_destroy(list);
    printf("Testing successful!\n");
}

void test_list_index_of()
{
    printf("Testing list_index_of()...\n");

    // initialize a list & an array of numbers
    List *list = list_create();
    int numbers[] = {7, 14, 21};
    int evil_int = 0;

    // unhappy path
    assert(list_index_of(NULL, &numbers[0]) == false);
    assert(list_index_of(list, NULL) == false);

    // verify that the return value of index_of is -1 for an element that doesnt exist in the list
    assert(list_index_of(list, &evil_int) == -1);

    // append the list with some elements
    list_append(list, &numbers[0]);
    list_append(list, &numbers[1]);
    list_append(list, &numbers[2]);

    // verify that index_of returns the correct index
    assert(list_index_of(list, &numbers[0]) == 0);
    assert(list_index_of(list, &numbers[1]) == 1);
    assert(list_index_of(list, &numbers[2]) == 2);

    list_destroy(list);
    printf("Testing successful!\n");
}

void test_list_get()
{
    printf("Testing list_get()...\n");

    // initialize a list & a numbers array
    List *list = list_create();
    int numbers[] = { 7, 14, 21 };

    // unhappy paths
    assert(list_get(NULL, 0) == false);
    assert(list_get(list, 100) == false);

    // append elements to the list
    list_append(list, &numbers[0]);
    list_append(list, &numbers[1]);
    list_append(list, &numbers[2]);

    // verify that list_get returns the correct elements
    assert(list_get(list, 0) == &numbers[0]);
    assert(list_get(list, 1) == &numbers[1]);
    assert(list_get(list, 2) == &numbers[2]);

    list_destroy(list);
    printf("Testing successful!\n");
}

void test_list_set()
{
    printf("Testing list_set()...\n");

    // initialize a list & some integers
    List *list = list_create();
    int silly_integer_minding_owns_business = 10;
    int evil_integer_stealing_silly_integers_index = 7;

    // unhappy paths
    assert(list_set(NULL, &silly_integer_minding_owns_business, 0) == false);
    assert(list_set(list, &silly_integer_minding_owns_business, 100) == false);
    assert(list_set(list, NULL, 0) == false);

    // append an element to the list
    list_append(list, &silly_integer_minding_owns_business);

    // verify that the function indeed overwrites the index with the user specified element
    assert(*(int*)list_get(list, 0) == 10);
    assert(list_set(list, &evil_integer_stealing_silly_integers_index, 0) == true);
    assert(*(int*)list_get(list, 0) == 7);

    list_destroy(list);
    printf("Testing successful!\n");
}

void test_list()
{
    test_list_remove_element();
    test_ensure_capacity();
    test_trim_to_size();
    test_list_create();
    test_list_destroy();
    test_list_insert();
    test_list_append();
    test_list_prepend();
    test_list_remove();
    test_list_pop();
    test_list_clear();
    test_list_is_empty();
    test_list_is_full();
    test_list_contains();
    test_list_index_of();
    test_list_get();
    test_list_set();
}
