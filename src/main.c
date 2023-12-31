#include "../tests/test-doubly-linked-list-node.h"
#include "../tests/test-doubly-linked-list.h"
#include "../tests/test-comparator.h"
#include "../tests/test-array-list.h"
#include "../tests/test-stack.h"
#include "../tests/test-queue.h"

#include "../include/doubly-linked-list.h"
#include "../include/comparator.h"
#include "../include/array-list.h"
#include "../include/stack.h"
#include "../include/queue.h"

#include "../include/binary-search-tree.h"

int main(void)
{

    BinarySearchTree *bst = bst_create();

    int a = 50;  void *pA = &a;    
    int b = 100; void *pB = &b;
    int c = 200; void *pC = &c;
    int d = 300; void *pD = &d;

    int e = 25; void *pE = &e;
    int f = 5 ; void *pF = &f;
    int g = 0 ; void *pG = &g;

    int h = 30; void *pH = &h;
    int i = 75; void *pI = &i;


    bst_insert(bst, pA, compare_int);
    bst_insert(bst, pB, compare_int);
    bst_insert(bst, pC, compare_int);
    bst_insert(bst, pD, compare_int);
    bst_insert(bst, pI, compare_int);

    bst_insert(bst, pE, compare_int);
    bst_insert(bst, pF, compare_int);
    bst_insert(bst, pG, compare_int);
    bst_insert(bst, pH, compare_int);

    ArrayList *results = bst_pre_order(bst);


    bst_destroy(bst);

    return 0;
}
