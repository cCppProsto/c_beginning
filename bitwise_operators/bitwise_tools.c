#include "bitwise_tools.h"
#include <stdio.h>
void print_bits_state(unsigned char aCh)
{
    printf("%i: ",  aCh);
    printf("%i",   (aCh & BIT_8) ? 1 : 0);
    printf("%i",   (aCh & BIT_7) ? 1 : 0);
    printf("%i",   (aCh & BIT_6) ? 1 : 0);
    printf("%i",   (aCh & BIT_5) ? 1 : 0);
    printf("%i",   (aCh & BIT_4) ? 1 : 0);
    printf("%i",   (aCh & BIT_3) ? 1 : 0);
    printf("%i",   (aCh & BIT_2) ? 1 : 0);
    printf("%i\n", (aCh & BIT_1) ? 1 : 0);
}

void print_bits_state_shift(unsigned char aCh)
{
    //int i = 0;
    printf("%i: ",  aCh);
    //for(i = 7; i>=0; --i)
    //    printf("%i", ((aCh >> i) & BIT_1) ? 1 : 0);
    printf("%i", ((aCh >> 7) & BIT_1) ? 1 : 0);
    printf("%i", ((aCh >> 6) & BIT_1) ? 1 : 0);
    printf("%i", ((aCh >> 5) & BIT_1) ? 1 : 0);
    printf("%i", ((aCh >> 4) & BIT_1) ? 1 : 0);
    printf("%i", ((aCh >> 3) & BIT_1) ? 1 : 0);
    printf("%i", ((aCh >> 2) & BIT_1) ? 1 : 0);
    printf("%i", ((aCh >> 1) & BIT_1) ? 1 : 0);
    printf("%i\n", ((aCh >> 0) & BIT_1) ? 1 : 0);
//    /printf("\n");
}

unsigned char set_bit(unsigned char aCh, unsigned char aN)
{
    return (aCh | ( 1 << (aN-1)));
}

unsigned char clear_bit(unsigned char aCh, unsigned char aN)
{
    return (aCh & ~( 1 << (aN-1)));
}

unsigned char invert_bit(unsigned char aCh, unsigned char aN)
{
    return (aCh ^ ( 1 << (aN-1)));
}

unsigned char test_bit(unsigned char aCh, unsigned char aN)
{
    return aCh & (1 << (aN - 1));
}



