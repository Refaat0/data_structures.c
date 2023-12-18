#include "../tests/test-array-list.h"
#include "../tests/test-doubly-linked-list.h"

int main(void)
{
    DoublyLinkedList *flowers = dll_create();
    char *array[] = {"Sunflowers", "Roses", "Tulips", "Orchids"};

    dll_append(flowers, &array[0]);
    dll_append(flowers, &array[1]);
    dll_append(flowers, &array[2]);
    dll_append(flowers, &array[3]);

    dll_pop(flowers);

    while (flowers->head != NULL)
    {
        printf("%s\n", *(char **)flowers->head->element);
        flowers->head = flowers->head->next;
    }

    dll_destroy(flowers);

    return 0;
}