#include <stdio.h>
#include <stdlib.h>

#include "sort_tool.h"

#define ARRAY_SIZE 30

void ia_print(struct sTest *apArray, unsigned aSize);

typedef enum
{
    E_SO_ASCENDING = 0
   ,E_SO_DESCENDING
   ,E_SO_CUSTOM
   ,E_SO_END
}eSortOrder;

bool pred_ascending(struct sTest, struct sTest);
bool pred_descending(struct sTest, struct sTest);
bool pred_custom(struct sTest, struct sTest);

int main()
{
    struct sTest iarray[ARRAY_SIZE] = {{0}};

    for(unsigned i = 0; i < ARRAY_SIZE; ++i)
        iarray[i].data = rand() % 1000;

    ia_print(&iarray[0], ARRAY_SIZE);
    printf("\n\n");

    pfCompare pfa[E_SO_END];

    pfa[E_SO_ASCENDING]  = pred_ascending;
    pfa[E_SO_DESCENDING] = pred_descending;
    pfa[E_SO_CUSTOM]     = pred_custom;

    ia_bubble_sort(&iarray[0], ARRAY_SIZE, pred_descending);
    ia_print(&iarray[0], ARRAY_SIZE);
    printf("\n");

    ia_print(&iarray[0], ARRAY_SIZE);
    ia_bubble_sort(&iarray[0], ARRAY_SIZE, pfa[E_SO_DESCENDING]);
    printf("\n");
    ia_print(&iarray[0], ARRAY_SIZE);
    ia_bubble_sort(&iarray[0], ARRAY_SIZE, pfa[E_SO_ASCENDING]);
    printf("\n");
    ia_print(&iarray[0], ARRAY_SIZE);
    return 0;
}

void ia_print(struct sTest *apArray, unsigned aSize)
{
    for(unsigned i = 0; i < aSize; ++i)
        printf("%i,", apArray[i].data);
    printf("\n");
}

bool pred_ascending(struct sTest a, struct sTest b)
{
    return a.data >= b.data;
}

bool pred_descending(struct sTest a, struct sTest b)
{
    return a.data < b.data;
}

bool pred_custom(struct sTest a, struct sTest b)
{
    return a.data > 400;
}
