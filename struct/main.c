#include <stdio.h>
#include <stdlib.h>

#define TEST_4

void print_struct_info();

#ifdef TEST_1
    typedef struct
    {
        char a;
        char b;
    }s_a;

    typedef struct
    {
        char a;
        // char[1]
        short b;
    }s_b;

    typedef struct
    {
        char a;
        // char[3];
        int b;
    }s_c;

    typedef struct
    {
        char a;
        // char[7]
        double b;
    }s_d;

    void print_struct_info()
    {
        printf("size of s_a{char;char}   = %i\n", sizeof(s_a));
        printf("size of s_b{char;short}  = %i\n", sizeof(s_b));
        printf("size of s_c{char;int}    = %i\n", sizeof(s_c));
        printf("size of s_d{char;double} = %i\n", sizeof(s_d));
    }
#elif defined(TEST_2)
    typedef struct
    {
        char a : 1;
        char b : 1;
        // 6
    }s_a;

    typedef struct
    {
        char a : 5;
        char b : 3;
    }s_b;

    typedef struct
    {
        char a : 5;
        char b : 4;
        // 7 unused
    }s_c;

    typedef struct
    {
        char a : 2;
        char   : 0; // 6 bit
        char b : 4;
    }s_d;

    typedef struct
    {
        char a : 4;// 4 bist
        int    : 0;// 28 bit unused
        char b : 4;// 4 bits
                   // 28 bit unused
    }s_e;

    void print_struct_info()
    {
        printf("size of s_a{char a:1;           char b:1} = %i\n", sizeof(s_a));
        printf("size of s_b{char a:5;           char b:3} = %i\n", sizeof(s_b));
        printf("size of s_c{char a:5;           char b:4} = %i\n", sizeof(s_c));
        printf("size of s_d{char a:4; char  :0; char b:4} = %i\n", sizeof(s_d));
        printf("size of s_e{char a:4; int   :0; char b:4} = %i\n", sizeof(s_e));
    }
#elif defined(TEST_3)
    typedef struct
    {
        char a : 1;
        char   : 0;
    }s_a;

    typedef struct
    {
        char a : 5;
        short  : 0;
    }s_b;

    typedef struct
    {
        char a : 5;
        int    : 0;
    }s_c;

    typedef struct
    {
        char      a : 4;
        long long   : 0;
    }s_d;

    void print_struct_info()
    {
        printf("size of s_a{char a:1;           char      :0} = %i\n", sizeof(s_a));
        printf("size of s_b{char a:5;           short     :0} = %i\n", sizeof(s_b));
        printf("size of s_c{char a:5;           int       :0} = %i\n", sizeof(s_c));
        printf("size of s_d{char a:4; char  :0; long long :0} = %i\n", sizeof(s_d));
    }
#elif defined(TEST_4)
    typedef struct
    {
        char a : 1;
        char   : 0;
        char     b;
    }s_a;
    typedef struct
    {
        char a : 5;
        short  : 0;
        char     b;
    }s_b;

    typedef struct
    {
        char a : 5;
        int    : 0;
        char     b;
    }s_c;

    typedef struct
    {
        char a : 1;     // 1
        char   : 0;     // 7 unused
        char b : 2;     // 2
        char   : 4;     // 4 unused
        char c : 2;     // 2
    }s_d;

    typedef struct
    {
        char a : 1;     // 1
        short  : 0;     // 15 unused
        char b : 2;     // 2
        char   : 4;     // 4 unused
        char c : 2;     // 2
    }s_e;

    typedef struct
    {
        char a : 1;         // 1
        int    : 0;         // 31 unused
        char b : 2;         // 2
        char   : 4;         // 4 unused
        char c : 2;         // 2
        // char padding [3] // 24 unused
    }s_f;

    void print_struct_info()
    {
        printf("size of s_a = %i\n", sizeof(s_a));
        printf("size of s_b = %i\n", sizeof(s_b));
        printf("size of s_c = %i\n", sizeof(s_c));
        printf("size of s_d = %i\n", sizeof(s_d));
        printf("size of s_e = %i\n", sizeof(s_e));
        printf("size of s_f = %i\n", sizeof(s_f));
    }
#endif

/*
(C99, 6.7.2.1p4)
"A bit-field shall have a type that is a qualified or
unqualified version of _Bool, signed int, unsigned int, or some other
implementation-defined type."

(C99, 6.7.2.1p10)
"If enough space remains, a bit-field that immediately follows another bit-field
in a structure shall be packed into adjacent bits of the same unit"

(C99, 6.7.2.1p11)
"A bit-field declaration with no declarator, but only a colon and a width, indicates an
unnamed bit-field.As a special case, a bit-field structure member with a width of 0
indicates that no further bit-field is to be packed into the unit in which the previous bitfield,if any, was placed."


The special unnamed bit field of width zero breaks up padding:
it specifies that the next bit field begins at the beginning of the next
allocation unit.
*/

typedef struct
{
    char  ch;   // 1 byte
                // 3 byte padding - UNUSED
    int   *p;   // 4 byte
    short s;    // 2 byte
                // 2 byte padding - UNUSED
}s1;

typedef struct
{
    int *p;     // 4 byte
    short s;    // 2 byte
    char  ch;   // 1 byte
                // 1 byte padding - UNUSED
}s2;

int main()
{
    // BONUS +++
    printf("size of s1 = %i\n", sizeof(s1));
    printf("size of s2 = %i\n\n\n", sizeof(s2)); // 4 byte economy!!
    // BONUS ^^

    print_struct_info();
    return 1;
}











