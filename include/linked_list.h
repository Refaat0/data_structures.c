#pragma once 
#include "../include/ll_node.h"
#include <stdbool.h>

typedef struct LinkedList
{
    int size;

    LLNode *head;
    LLNode *tail;

} LinkedList;

//// ==== Linked List "Life-Cycle" Functions ==== ////

/**
 * this function returns an initialized linked-list
 * @return an initialized linked-list
 */
LinkedList *ll_create();

/**
 * this function destroys a specified linked-list
 * @param linked_list a pointer to a linked-list structure
 * @return a boolean of true if the operation is successful
 */
bool ll_destroy(LinkedList *linked_list);

//// ==== Insertion Functions === ////

/**
 * this function inserts an element to an index in a linked-list specified in the function parameters
 * @param linied_list a pointer to a linked_list structure
 * @param element a void pointer to an element
 * @param index an index in the linked-list
 * @return a boolean of true if the operation is successful
 */
bool ll_insert(LinkedList *linked_list, void *element, int index);

/**
 * this functions inserts a linked-list to an index in another linked-list specified in the function parameters
 * @param linked_list_alpha a pointer to a linked-list structure
 * @param linked_list_bravo a pointer to another linked-list structure
 * @param index an index in linked_list_alpha
 * @return a boolean of true if the operation is successful
 */
bool ll_insert_ll(LinkedList *linked_list_alpha, LinkedList *linked_list_bravo, int index);

/**
 * this function inserts an element to the start of a linked_list specified in the function parameters
 * @param linked_list a pointer to a linked_list structure
 * @param element a void pointer to an element
 * @return a boolean of true if the operation is successful
 */
bool ll_append(LinkedList *linked_list, void *element);

/**
 * this function inserts an element to the end of a linked-list specified in the function parameters
 * @param linked_list a pointer to a linked-list structure
 * @param element a void pointer to an element
 * @return a boolean of true if the operation is successful
 */
bool ll_prepend(LinkedList *linked_list, void *element);

//// ==== Deletion Functions ==== ////

/**
 * this function removes removes an element at an index of a linked-list specified in the function parameters
 * @param linked_list a pointer to a linked-list structure
 * @param index an index in this linked-list
 * @return a boolean of true if the operation is successful
 */
bool ll_remove(LinkedList *linked_list, int index);

/**
 * this function removes an element at the end of a linked-list specified in the function parameters
 * @param linked_list a pointer to a linked-list structure
 * @return a boolean of true if the operation is successful
 */
bool ll_pop(LinkedList *linked_list);

/**
 * this function removes an element from a linked-list specified in the function parameters
 * @param linked_list a pointer to a linked-list structure
 * @param element a void pointer to an element
 * @return a boolean of true if the operation is successful
 */
bool ll_remove_element(LinkedList *linked_list, void *element);

/**
 * this function removes all elements from a linked-list specified in the function parameters
 * @param linked_list a pointer to a linked-list structure
 * @return a boolean of true if the operation is successful
 */
bool ll_clear(LinkedList *linked_list);

//// ==== Miscellaneous Functions === ////

/**
 * this function checks if a linked-list specified in the function parameters is empty
 * @param linked_list a pointer to a linked-list structure
 * @return a boolean of true if linked-list is empty
 */
bool ll_is_empty(LinkedList *linked_list);

/**
 * this function checks if a linked-list specified in the function parameters is full
 * @param linked_list a pointer to a linked-list structure
 * @return a boolean of true if linked-list is full
 */
bool ll_is_full(LinkedList *linked_list);

/**
 * this function checks if an element is in a linked-list specified in the function parameters
 * @param linked_list a pointer to a linked-list structure
 * @param element a void pointer to an element
 * @return a boolean of true if the element is found in the linked-list
 */
bool ll_contains(LinkedList *linked_list, void *element);

/**
 * this function finds the zero-based index of the element in a linked-list specified in the function parameters,
 * where the index is -1 if the element is not found in the linked-list
 * @param linked_list a pointer to linked-list structure
 * @param element a void pointer to an element
 * @return an integer representing the index of the element in the linked-list
 */
int ll_index_of(LinkedList *linked_list, void *element);

/**
 * this function returns the element in a linked-list at the index specified in the function parameters
 * @param linked_list a pointer to linked-list structure
 * @param index an index in this linked-list
 * @return a void pointer of the element
 */
void *ll_get(LinkedList *linked_list, int index);

/**
 * this function sets the index in a linked-list to the element specified in the function parameters
 * @param linked_list a pointer to linked-list structure
 * @param element a void pointer to an element
 * @param index an index in this linked-list\
 * @return a boolean of true if the operation is successful
 */
bool ll_set(LinkedList *linked_list, void *element, int index);
