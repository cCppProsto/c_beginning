#include <stdio.h>
#include "string_type.h"

int main()
{
    sString str;
    st_init(&str);
    while(1)
    {
        st_add(&str, "Hello");
        st_add(&str, " ");
        st_add(&str, "World!");
        st_set_at(&str, 1, 'A');
        st_free(&str);
    }
    return 0;
}
