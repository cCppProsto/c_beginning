#include <stdio.h>
#include "while.h"

void while_example()
{
    printf("%s: ", __FUNCTION__);

    int i = 0;
    while(i < 10)
    {
        printf("%i,", i);
        if(i == 5)
            break;
        i++;
    }

    printf("\n");
}
