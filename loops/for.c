#include "for.h"
#include <stdio.h>
void for_example()
{
    printf("%s: ", __FUNCTION__);

    int i = 0;
    for(i = 0; i < 256; i++)
        printf("%c,", i);

    printf("\n");
}


