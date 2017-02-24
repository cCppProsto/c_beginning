#include <stdio.h>

int main()
{
    int i  = 0;
    switch(i)
    {
        #include "h_1.h"
        #include "h_2.h"
    }
    #include "c_1.c"
    printf("%i\n", a);
    return 0;
}
