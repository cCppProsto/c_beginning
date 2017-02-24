#include "string_type.h"

#include <stdlib.h>
#include <string.h>

#define STR_SIZE_INIT 1

//------------------------------------------------------------------------------
void st_init(sString *ap_str)
{
    ap_str->p_str = calloc(STR_SIZE_INIT, sizeof(char));
    ap_str->length = 0;
}
//------------------------------------------------------------------------------
void st_free(sString *ap_str)
{
    if(ap_str->p_str != NULL)
        free(ap_str->p_str);

    ap_str->p_str  = NULL;
    ap_str->length = 0;
}
//------------------------------------------------------------------------------
void st_add(sString *ap_str, const char *ap_str_in)
{
    if(ap_str->p_str == NULL)
        return;

    unsigned l = strlen(ap_str_in);

    ap_str->p_str = realloc(ap_str->p_str, ap_str->length + l + 1);

    strcat(ap_str->p_str, ap_str_in);

    ap_str->length += l;
}
//------------------------------------------------------------------------------
char st_at(sString *ap_str, int a_index)
{
    return ap_str->p_str[a_index];
}
//------------------------------------------------------------------------------
void st_set_at(sString *ap_str, unsigned a_index, char a_ch)
{
    if(a_index >= ap_str->length)
        return;

    ap_str->p_str[a_index] = a_ch;
}
//------------------------------------------------------------------------------
unsigned st_length(sString *ap_str)
{
    return ap_str->length;
}

