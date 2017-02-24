#include <stdio.h>

void print_bits(char aValue)
{
    printf("(%i) : ", aValue);
    for(int i = 7; i >= 0; --i)
    {
        if( (aValue >> i) & 0b00000001)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

int main()
{
    print_bits(2);
    print_bits(1);
    print_bits(0);
    print_bits(-1);
    print_bits(-2);

    // -1 = 11111111 = ~ = (00000000 + 1) = 1
    // -2 = 11111110 = ~ = (00000001 + 1) = 2

    // ~(non_negative - 1) = negative
    // (~negative + 1)     = positive
    //print_bits(-19);
    return 0;
}












