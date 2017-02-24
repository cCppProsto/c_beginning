#include "pin_encrypt.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// 1 2 3 A
// 4 5 6 B
// 7 8 9 C
// D 0 E F

// ABCD - [1010][1011][1100][1101] = 2 bytes
//          0     1      2     3

//        [1011][1101][1010][1100]
//          1     3     0     2

// 4 bytes - 2 = 2

// input  = 2 bytes - pwd
// output = 4 bytes - encrypt pwd

// [A][B][C][D]
// [00011011] - order

//1
// [D][B][A][C] - 2 bytes [pwd]   [1101][1011][1010][1100]
// [11010010]   - 1 bytes [order]
// [10111001]   - 1 byte  [?]


//2
// [A][D][C][B] - 2 bytes [pwd]   [1010][1101][1100][1011]
// [00111001]   - 1 bytes [order]

// input    = [1101101110101100]

// output 1 = [11010010][1101101110101100][10111001]
// output 2 = [00111001][1010110111001011][11000000]


// A   B   C   D
// 0   1   2   3
// 00 01  10  11 = 00011011

// D   B   A   C
// 3   1   0   2
// 11 01  00  10 = 11010010

// B   C   D   A
// 1   2   3   0
// 01  10  11  00 = 01101100 (108)

//    00000011
// << 6
//    11000000
//  |
//    00000001
// << 4
//    00010000
//  |
//    00000000
// << 2
//    00000000
//  |
//    00000010
//  = 11010010

ubyte order_pack(ubyte a0, ubyte a1, ubyte a2, ubyte a3)
{
    return (a0 << 6) | (a1 << 4) | (a2 << 2) | a3;
}

ushort pwd_pack(ubyte a0, ubyte a1, ubyte a2, ubyte a3)
{
    return (a0 << 12) | (a1 << 8) | (a2 << 4) | a3;
}

ushort get_order_pwd(ubyte aOrder, ubyte a0, ubyte a1, ubyte a2, ubyte a3)
{
    switch(aOrder)
    {
        case 27:  return pwd_pack(a0, a1, a2, a3); // 0123
        case 30:  return pwd_pack(a0, a1, a3, a2); // 0132
        case 39:  return pwd_pack(a0, a2, a1, a3); // 0213
        case 45:  return pwd_pack(a0, a2, a3, a1); // 0231
        case 54:  return pwd_pack(a0, a3, a1, a2); // 0312
        case 57:  return pwd_pack(a0, a3, a2, a1); // 0321
        case 75:  return pwd_pack(a1, a0, a2, a3); // 1023
        case 78:  return pwd_pack(a1, a0, a3, a2); // 1032
        case 99:  return pwd_pack(a1, a2, a0, a3); // 1203
        case 108: return pwd_pack(a1, a2, a3, a0); // 1230
        case 114: return pwd_pack(a1, a3, a0, a2); // 1302
        case 120: return pwd_pack(a1, a3, a2, a0); // 1320
        case 135: return pwd_pack(a2, a0, a1, a3); // 2013
        case 141: return pwd_pack(a2, a0, a3, a1); // 2031
        case 147: return pwd_pack(a2, a1, a0, a3); // 2103
        case 156: return pwd_pack(a2, a1, a3, a0); // 2130
        case 177: return pwd_pack(a2, a3, a0, a1); // 2301
        case 180: return pwd_pack(a2, a3, a1, a0); // 2310
        case 198: return pwd_pack(a3, a0, a1, a2); // 3012
        case 201: return pwd_pack(a3, a0, a2, a1); // 3021
        case 210: return pwd_pack(a3, a1, a0, a2); // 3102
        case 216: return pwd_pack(a3, a1, a2, a0); // 3120
        case 225: return pwd_pack(a3, a2, a0, a1); // 3201
        case 228: return pwd_pack(a3, a2, a1, a0); // 3210
    }
    return 0;
}

ubyte get_random_order()
{
    switch(rand() % 24)
    {
        case 0:  return order_pack(0, 1, 2, 3); // 0123
        case 1:  return order_pack(0, 1, 3, 2); // 0132
        case 2:  return order_pack(0, 2, 1, 3); // 0213
        case 3:  return order_pack(0, 2, 3, 1); // 0231
        case 4:  return order_pack(0, 3, 1, 2); // 0312
        case 5:  return order_pack(0, 3, 2, 1); // 0321
        case 6:  return order_pack(1, 0, 2, 3); // 1023
        case 7:  return order_pack(1, 0, 3, 2); // 1032
        case 8:  return order_pack(1, 2, 0, 3); // 1203
        case 9:  return order_pack(1, 2, 3, 0); // 1230
        case 10: return order_pack(1, 3, 0, 2); // 1302
        case 11: return order_pack(1, 3, 2, 0); // 1320
        case 12: return order_pack(2, 0, 1, 3); // 2013
        case 13: return order_pack(2, 0, 3, 1); // 2031
        case 14: return order_pack(2, 1, 0, 3); // 2103
        case 15: return order_pack(2, 1, 3, 0); // 2130
        case 16: return order_pack(2, 3, 0, 1); // 2301
        case 17: return order_pack(2, 3, 1, 0); // 2310
        case 18: return order_pack(3, 0, 1, 2); // 3012
        case 19: return order_pack(3, 0, 2, 1); // 3021
        case 20: return order_pack(3, 1, 0, 2); // 3102
        case 21: return order_pack(3, 1, 2, 0); // 3120
        case 22: return order_pack(3, 2, 0, 1); // 3201
        case 23: return order_pack(3, 2, 1, 0); // 3210
    }
    return 0;
}

uint_32 encrypt(ubyte a1, ubyte a2, ubyte a3, ubyte a4)
{
    uint_32 res = 0;
    ubyte   order   = 0;
    ushort  pwd     = 0;
    ubyte   garbage = 0;

    //srand(time(0));
    order   = get_random_order();
    //printf("order = %i", order);
    pwd     = get_order_pwd(order, a1, a2, a3, a4);
    garbage = 229 + (rand()% 27);
    //printf("garbage = %i", garbage);

    if(rand()%2) // [g][][][o]
        res = (garbage << 24) | (pwd << 8) | order;
    else         // [o][][][g]
        res = (order << 24) | (pwd << 8) | garbage;

    return res;
}

