#include "../tests/t_list.h"

#include "../include/linked_list.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    LinkedList *flowers = ll_create();
    char *flowers_array[] = {
        "Common Sunflower",
        "Red Spider Lily",
        "White Orchid",
        "Forget Me Not",
        "Mr. Lincoln",
        "White Roses"};

    ll_prepend(flowers, &flowers_array[0]);
    ll_prepend(flowers, &flowers_array[1]);
    ll_prepend(flowers, &flowers_array[2]);
    ll_prepend(flowers, &flowers_array[3]);
    ll_prepend(flowers, &flowers_array[4]);

    return 0;
}