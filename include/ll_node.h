#include <stdbool.h>

typedef struct LLNode
{
    void *element;
    struct LLNode *next;
    struct LLNode *prev;

} LLNode;

/**
 * this function initializes a linked-list Node
 * @return an initalized linked-list Node
 */
LLNode *ll_node_create();

/**
 * this function destroys a linked-list Node
 * @return a boolean of true if the operation is successful
 */
bool *ll_node_destroy();
