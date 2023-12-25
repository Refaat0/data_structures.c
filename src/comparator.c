#include <string.h>
#include <stdio.h>

int compare(void *alpha, void *bravo, int (*comparator)(void *, void *))
{
    if (alpha == NULL || bravo == NULL || comparator == NULL)
    {
        return -100;
    }

    return comparator(alpha, bravo); 
}

int compare_int(void *alpha, void *bravo)
{
    if (alpha == NULL || bravo == NULL) return -100;
    
    if (*(int*)alpha >  *(int*)bravo) return 1;
    if (*(int*)alpha <  *(int*)bravo) return -1;
    return 0;
}

int compare_double(void *alpha, void *bravo)
{
    if (alpha == NULL || bravo == NULL) return -100;

    if (*(double*)alpha >  *(double*)bravo) return 1;
    if (*(double*)alpha <  *(double*)bravo) return -1;

    return 0;
}

int compare_string(void *alpha, void *bravo)
{
    return strcmp(*(char**)alpha, *(char**)bravo);
}

int compare_float(void *alpha, void *bravo)
{
    if (alpha == NULL || bravo == NULL) return -100;

    if (*(float*)alpha >  *(float*)bravo) return 1;
    if (*(float*)alpha <  *(float*)bravo) return -1;

    return 0;
}

int compare_char(void *alpha, void *bravo)
{
    if (alpha == NULL || bravo == NULL) return -100;

    if (*(char*)alpha >  *(char*)bravo) return 1;
    if (*(char*)alpha <  *(char*)bravo) return -1;

    return 0;
}