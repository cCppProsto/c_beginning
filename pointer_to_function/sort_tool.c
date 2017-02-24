#include"sort_tool.h"

void ia_bubble_sort(struct sTest *apArray, unsigned aSize, pfCompare pf)
{
    for(unsigned i = 1; i < aSize; ++i)
    {
        for(unsigned j = 0; j < aSize - i; ++j)
        {
            if(pf(apArray[j], apArray[j+1]))
            {
                struct sTest temp   = apArray[j];
                apArray[j]          = apArray[j+1];
                apArray[j+1]        = temp;
            }
        }
    }
}
