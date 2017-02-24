#ifndef SORT_TOOL_H
#define SORT_TOOL_H

#include <stdbool.h>


struct sTest
{
    int data;
};

typedef bool (*pfCompare)(struct sTest, struct sTest);

void ia_bubble_sort(struct sTest *, unsigned, pfCompare);

#endif // SORT_TOOL_H
