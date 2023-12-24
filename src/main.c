#include "../tests/test-doubly-linked-list-node.h"
#include "../tests/test-doubly-linked-list.h"
#include "../tests/test-array-list.h"
#include "../tests/test-stack.h"
#include "../tests/test-queue.h"

int main(void)
{
    test_list();
    test_linked_list();
    test_stack();
    test_queue();
    return 0;
}