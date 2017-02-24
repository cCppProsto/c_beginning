#include <stdio.h>

#include "pin_encrypt.h"

int main()
{
    uint_32 res = 0;
    res = encrypt(0x0A,0x0B,0x01,0x00);
    printf("%u\n", res);
    res = encrypt(0x0A,0x0B,0x01,0x00);
    printf("%u\n", res);
    res = encrypt(0x0A,0x0B,0x01,0x00);
    printf("%u\n", res);
    res = encrypt(0x0A,0x0B,0x01,0x00);
    printf("%u\n", res);
    res = encrypt(0x0A,0x0B,0x01,0x00);
    printf("%u\n", res);
    res = encrypt(0x0A,0x0B,0x01,0x00);
    printf("%u\n", res);

    return 0;
}
