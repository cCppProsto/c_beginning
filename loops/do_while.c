#include <stdio.h>
#include "do_while.h"

void do_while_example()
{
    printf("%s: ", __FUNCTION__);

    int i = 0;
    do
    {
        printf("%i,", i);
        i++;
    }while( i < 10);

    printf("\n");
}


