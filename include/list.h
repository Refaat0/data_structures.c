#include <stdbool.h>

typedef struct List
{
    void **collection;
    int capacity;
    int size;
} List;

#define INITIAL_CAPACITY 32
#define GROWING_RATE 2

//// ==== Helper Functions ==== ////

/**
 * this function increases the capacity of a specified list if it is full
 * @param list a pointer to a list structure
 * @return a boolean of true if the operation is successful
 */
bool _ensure_capacity(List *list);

/**
 * this function reduces the capacity of a specified list to its size
 * @param list a pointer to a list structure
 * @return a boolean of true if the operation is successful
 */
bool _trim_to_size(List *list);

//// ==== List "Life-Cycle" Functions ==== ////

/**
 * this function returns an initialized list
 * @return an initialized list
 */
List *list_create();

/**
 * this function destroys a specified list
 * @param list a pointer to a list structure
 * @return a boolean of true if the operation is successful
 */
bool list_destroy(List *list);

//// ==== Insertion Functions === ////

/**
 * this function inserts an element to an index in a list specified in the function parameters
 * @param list a pointer to a list structure
 * @param element a void pointer to an element
 * @param index an index in the list
 * @return a boolean of true if the operation is successful
 */
bool list_insert(List *list, void *element, int index);

/**
 * this functions inserts a list to an index in another list specified in the function parameters
 * @param list_alpha a pointer to a list structure
 * @param list_bravo a pointer to another list structure
 * @param index an index in the list_alpha
 * @return a boolean of true if the operation is successful
 */
bool list_insert_list(List *list_alpha, List *list_bravo, int index);

/**
 * this function inserts an element to the end of a list specified in the function parameters
 * @param list a pointer to a list structure
 * @param element a void pointer to an element
 * @return a boolean of true if the operation is successful
 */
bool list_append(List *list, void *element);

/**
 * this function inserts an element to the start of a list specified in the function parameters
 * @param list a pointer to a list structure
 * @param element a void pointer to an element
 * @return a boolean of true if the operation is successful
 */
bool list_prepend(List *list, void *element);

//// ==== Deletion Functions ==== ////

/**
 * this function removes removes an element at an index of a list specified in the function parameters
 * @param list a pointer to a list structure
 * @param index an index in this list
 * @return a boolean of true if the operation is successful
 */
bool list_remove(List *list, int index);

/**
 * this function removes an element at the end of a list specified in the function parameters
 * @param list a pointer to a list structure
 * @return a boolean of true if the operation is successful
 */
bool list_pop(List *list);

/**
 * this function removes removes an from a list specified in the function parameters
 * @param list a pointer to a list structure
 * @param element a void pointer to an element
 * @return a boolean of true if the operation is successful
 */
bool list_remove_element(List *list, void *element);

/**
 * this function removes all elements from a list specified in the function parameters
 * @param list a pointer to a list structure
 * @return a boolean of true if the operation is successful
 */
bool list_clear(List *list);

//// ==== Miscellaneous Functions === ////

/**
 * this function checks if a list specified in the function parameters is empty
 * @param list a pointer to a list structure
 * @return a boolean of true if list is empty
 */
bool list_is_empty(List *list);

/**
 * this function checks if a list specified in the function parameters is full
 * @param list a pointer to a list structure
 * @return a boolean of true if list is full
 */
bool list_is_full(List *list);

/**
 * this function checks if an element is in a list specified in the function parameters
 * @param list a pointer to a list structure
 * @param element a void pointer to an element
 * @return a boolean of true if the element is found in the list
 */
bool list_contains(List *list, void *element);

/**
 * this function finds the zero-based index of the element in a list specified in the function parameters,
 * where the index is -1 if the element is not found in the list
 * @param list a pointer to list structure
 * @param element a void pointer to an element
 * @return an integer representing the index of the element in the list.
 */
int list_index_of(List *list, void *element);

/**
 * this function returns the element in a list at the index specified in the function parameters
 */
void *list_get(List *list, int index);

/**
 * this function sets the index in a list to the element specified in the function parameters
 */
bool list_set(List *list, void *element, int index);
