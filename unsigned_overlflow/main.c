#include <stdio.h>

#include <limits.h>
#include <stdbool.h>

#undef  UINT_MAX
#define UINT_MAX 100

bool addition_check_1(unsigned a, unsigned b)
{
    return (UINT_MAX - a >= b);
}

bool addition_check_2(unsigned a, unsigned b)
{
    unsigned int usum = a + b;
    return (usum >= a);
}

bool subtraction_check_1(unsigned a, unsigned b)
{
    return (a >= b);
}

bool subtraction_check_2(unsigned a, unsigned b)
{
    unsigned int udiff = a - b;
    return (udiff <= a);
}

bool multiply(unsigned a, unsigned b)
{
    unsigned long long res = (unsigned long long)a*b;
    if(res > 0xffffffff)
        return false;
    return true;
}



int main(int argc, char *argv[])
{
    return 0;
}
