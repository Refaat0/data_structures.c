#pragma once 
#include "../include/doubly-linked-list-node.h"
#include <stdbool.h>

typedef struct DoublyLinkedList
{
    DLLNode *head;
    DLLNode *tail;
    int size;
} DoublyLinkedList;

//// ==== Linked List "Life-Cycle" Functions ==== ////

/**
 * this function returns an initialized DoublyLinkedList
 * @return an initialized DoublyLinkedList
 */
DoublyLinkedList *dll_create();

/**
 * this function destroys a specified DoublyLinkedList
 * @param linked_list a pointer to a DoublyLinkedList structure
 * @return a boolean of true if the operation is successful
 */
bool dll_destroy(DoublyLinkedList *linked_list);

//// ==== Insertion Functions === ////

/**
 * this function inserts an element to an index in a DoublyLinkedList specified in the function parameters
 * @param linked_list a pointer to a DoublyLinkedList structure
 * @param element a void pointer to an element
 * @param index an index in the DoublyLinkedList
 * @return a boolean of true if the operation is successful
 */
bool dll_insert(DoublyLinkedList *linked_list, void *element, int index);

/**
 * this functions inserts a DoublyLinkedList to an index in another DoublyLinkedList specified in the function parameters
 * @param linked_list_alpha a pointer to a DoublyLinkedList structure
 * @param linked_list_bravo a pointer to another DoublyLinkedList structure
 * @param index an index in linked_list_alpha
 * @return a boolean of true if the operation is successful
 */
bool dll_insert_ll(DoublyLinkedList *linked_list_alpha, DoublyLinkedList *linked_list_bravo, int index);

/**
 * this function inserts an element to the start of a DoublyLinkedList specified in the function parameters
 * @param linked_list a pointer to a DoublyLinkedList structure
 * @param element a void pointer to an element
 * @return a boolean of true if the operation is successful
 */
bool dll_append(DoublyLinkedList *linked_list, void *element);

/**
 * this function inserts an element to the end of a DoublyLinkedList specified in the function parameters
 * @param linked_list a pointer to a DoublyLinkedList structure
 * @param element a void pointer to an element
 * @return a boolean of true if the operation is successful
 */
bool dll_prepend(DoublyLinkedList *linked_list, void *element);

//// ==== Deletion Functions ==== ////

/**
 * this function removes removes an element at an index of a DoublyLinkedList specified in the function parameters
 * @param linked_list a pointer to a DoublyLinkedList structure
 * @param index an index in this DoublyLinkedList
 * @return a boolean of true if the operation is successful
 */
bool dll_remove(DoublyLinkedList *linked_list, int index);

/**
 * this function removes an element at the end of a DoublyLinkedList specified in the function parameters
 * @param linked_list a pointer to a DoublyLinkedList structure
 * @return a boolean of true if the operation is successful
 */
bool dll_pop(DoublyLinkedList *linked_list);

/**
 * this function removes an element from a DoublyLinkedList specified in the function parameters
 * @param linked_list a pointer to a DoublyLinkedList structure
 * @param element a void pointer to an element
 * @return a boolean of true if the operation is successful
 */
bool dll_remove_element(DoublyLinkedList *linked_list, void *element);

/**
 * this function removes all elements from a DoublyLinkedList specified in the function parameters
 * @param linked_list a pointer to a DoublyLinkedList structure
 * @return a boolean of true if the operation is successful
 */
bool dll_clear(DoublyLinkedList *linked_list);

//// ==== Miscellaneous Functions === ////

/**
 * this function checks if a DoublyLinkedList specified in the function parameters is empty
 * @param linked_list a pointer to a DoublyLinkedList structure
 * @return a boolean of true if DoublyLinkedList is empty
 */
bool dll_is_empty(DoublyLinkedList *linked_list);

/**
 * this function checks if an element is in a DoublyLinkedList specified in the function parameters
 * @param linked_list a pointer to a DoublyLinkedList structure
 * @param element a void pointer to an element
 * @return a boolean of true if the element is found in the DoublyLinkedList
 */
bool dll_contains(DoublyLinkedList *linked_list, void *element);

/**
 * this function finds the zero-based index of the element in a DoublyLinkedList specified in the function parameters,
 * where the index is -1 if the element is not found in the DoublyLinkedList
 * @param linked_list a pointer to DoublyLinkedList structure
 * @param element a void pointer to an element
 * @return an integer representing the index of the element in the DoublyLinkedList
 */
int dll_index_of(DoublyLinkedList *linked_list, void *element);

/**
 * this function returns the element in a DoublyLinkedList at the index specified in the function parameters
 * @param linked_list a pointer to DoublyLinkedList structure
 * @param index an index in this DoublyLinkedList
 * @return a void pointer of the element
 */
void *dll_get(DoublyLinkedList *linked_list, int index);

/**
 * this function sets the index in a DoublyLinkedList to the element specified in the function parameters
 * @param linked_list a pointer to DoublyLinkedList structure
 * @param element a void pointer to an element
 * @param index an index in this DoublyLinkedList\
 * @return a boolean of true if the operation is successful
 */
bool dll_set(DoublyLinkedList *linked_list, void *element, int index);
