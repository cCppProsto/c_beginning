#include <stdio.h>
#include "struct.h"

//------------------------------------------------------------------------------
/*
not alignment
    +--------+--------+
    |  ch_a  |  ch_b  |
    +--------+--------+
*/
void s_a_print_info()
{
    {
        s_a_np s;

        s.ch_a = 0;
        s.ch_b = 1;
        printf("size of s_a_np = %i\n", sizeof(s_a_p));
        printf("\t+------------+------------+\n");
        printf("\t|    ch_a    |    ch_b    |\n");
        printf("\t+------------+------------+\n");
        printf("\n");

        printf("\t0x%p(ch_a): %x\n", &s.ch_a, *(char*)(&s.ch_a));
        printf("\t0x%p(ch_b): %x\n", &s.ch_b, *(char*)(&s.ch_b));
        printf("----------------------------------------------------\n\n");
    }
    {
        s_a_p s;

        s.ch_a = 0;
        s.ch_b = 1;
        printf("size of s_a_p = %i\n", sizeof(s_a_p));
        printf("\t+------------+------------+\n");
        printf("\t|    ch_a    |    ch_b    |\n");
        printf("\t+------------+------------+\n");
        printf("\n");

        printf("\t0x%p(ch_a): %x\n", &s.ch_a, *(char*)(&s.ch_a));
        printf("\t0x%p(ch_b): %x\n", &s.ch_b, *(char*)(&s.ch_b));
        printf("----------------------------------------------------\n\n");
    }
}
//------------------------------------------------------------------------------
/*
not alignment
    +--------+--------+--------+--------+
    |  ch_a  |      sh_a       |  sh_b  |
    +--------+--------+--------+--------+
    |  sh_b  |
    +--------+
or
    +--------+--------+--------+-----------------+
    |  ch_a  |      sh_a       |      sh_b       |
    +--------+--------+--------+-----------------+

alignment
    +--------+--------+
    |  ch_a  |   ??   |
    +--------+--------+
    |      sh_a       |
    +--------+--------+
    |      sh_b       |
    +--------+--------+
or
    +--------+--------+--------+--------+-----------------+
    |  ch_a  |   ??   |      sh_a       |      sh_b       |
    +--------+--------+--------+--------+-----------------+
*/
void s_b_print_info()
{
    {
        s_b_p s;
        unsigned char *p;

        s.ch_a = 0xB0;
        s.sh_a = 0xACDE;
        s.sh_b = 0xF00E;
        printf("size of s_b_p = %i\n\n", sizeof(s_b_p));
        printf("ch_a - 0x%p\n", &s.ch_a);
        printf("sh_a - 0x%p\n", &s.sh_a);
        printf("sh_b - 0x%p\n", &s.sh_b);

        printf("\t+--------+--------+--------+--------+--------+\n");
        printf("\t|  ch_a  |      sh_a       |      sh_b       |\n");
        printf("\t+--------+--------+--------+--------+--------+\n\n");

        printf("\t+--------+--------+--------+--------+--------+\n");
        p = (unsigned char*)(&s.ch_a);
        printf("\t|   %.2x   |", *p);
        p = (unsigned char*)(&s.sh_a);
        printf("   %.2x   |   %.2x   |", *p, *(p+1));
        p = (unsigned char*)(&s.sh_b);
        printf("   %.2x   |   %.2x   |\n", *p, *(p + 1));
        printf("\t+--------+--------+--------+--------+--------+\n\n");
        printf("\n");
    }

    {
        s_b_np s;
        unsigned char *p;

        s.ch_a = 0xB0;
        s.sh_a = 0xACDE;
        s.sh_b = 0xF00E;
        printf("size of s_b_np = %i\n\n", sizeof(s_b_np));
        printf("ch_a - 0x%p\n", &s.ch_a);
        printf("sh_a - 0x%p\n", &s.sh_a);
        printf("sh_b - 0x%p\n", &s.sh_b);

        printf("\t+--------+--------+--------+--------+--------+--------+\n");
        printf("\t|  ch_a  |   ??   |      sh_a       |      sh_b       |\n");
        printf("\t+--------+--------+--------+--------+--------+--------+\n\n");

        printf("\t+--------+--------+--------+--------+--------+--------+\n");
        p = (unsigned char*)(&s.ch_a);
        printf("\t|   %.2x   |   %.2x   |", *p, *(p+1));
        p = (unsigned char*)(&s.sh_a);
        printf("   %.2x   |   %.2x   |", *p, *(p + 1));
        p = (unsigned char*)(&s.sh_b);
        printf("   %.2x   |   %.2x   |\n", *p, *(p + 1));
        printf("\t+--------+--------+--------+--------+--------+--------+\n\n");
        printf("\n");
    }
}
//------------------------------------------------------------------------------
/*
not alignment
    +--------+--------+--------+--------+
    |  ch_a  |  ch_a  |  ch_a  |   i_a  |
    +--------+--------+--------+--------+
    |           i_a            |  sh_a  |
    +--------+-----------------+--------+
    |  sh_a  |  ch_b  |
    +--------+--------+
or
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+
    |  ch_a  |  ch_a  |  ch_a  |            i_a           |      sh_a       |  ch_b  |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+

alignment
    +--------+--------+--------+--------+
    |  ch_a  |  ch_a  |  ch_a  |   ??   |
    +--------+--------+--------+--------+
    |                i_a                |
    +--------+--------+--------+--------+
    |      sh_a       |  ch_b  |   ??   |
    +--------+--------+--------+--------+
or
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    |  ch_a  |  ch_a  |  ch_a  |   ??   |                i_a                |      sh_a       |  ch_b  |   ??   |
    +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
*/
void s_c_print_info()
{
    {
        s_c_p s;
        unsigned char *p;

        s.ch_a[0] = 0x01;
        s.ch_a[1] = 0x10;
        s.ch_a[2] = 0x11;
        s.i_a     = 0x00000002;
        s.sh_a    = 0x3333;
        s.ch_b    = 0x44;
        printf("size of s_c_p = %i\n\n", sizeof(s_c_p));
        printf("ch_a[0] - 0x%p\n", &s.ch_a[0]);
        printf("ch_a[1] - 0x%p\n", &s.ch_a[1]);
        printf("ch_a[2] - 0x%p\n", &s.ch_a[2]);
        printf("i_a     - 0x%p\n", &s.i_a);
        printf("sh_a    - 0x%p\n", &s.sh_a);
        printf("ch_b    - 0x%p\n", &s.ch_b);

        printf("\t+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+\n");
        printf("\t|  ch_a  |  ch_a  |  ch_a  |                i_a                |      sh_a       |  ch_b  |\n");
        printf("\t+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+\n");
        printf("\n");

        printf("\t+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+\n");
        p = (unsigned char*)(&s.ch_a[0]);
        printf("\t|   %.2x   |   %.2x   |   %.2x   |", *p, *(p + 1), *(p + 2));
        p = (unsigned char*)(&s.i_a);
        printf("   %.2x   |   %.2x   |   %.2x   |   %.2x   |", *p, *(p + 1), *(p + 2), *(p + 3));
        p = (unsigned char*)(&s.sh_a);
        printf("   %.2x   |   %.2x   |", *p, *(p + 1));
        p = (unsigned char*)(&s.ch_b);
        printf("   %.2x   |\n", *p);
        printf("\t+--------+--------+--------+-------+-------+-------+-------+-------+-------+-------+-------+\n");
        printf("\n");

        printf("######################################################################################################\n\n");
    }
    {
        s_c_np s;
        unsigned char *p;

        s.ch_a[0] = 0x01;
        s.ch_a[1] = 0x10;
        s.ch_a[2] = 0x11;
        s.i_a = 0x00000002;
        s.sh_a = 0x3333;
        s.ch_b = 0x44;

        printf("size of s_c_np = %i\n\n", sizeof(s_c_np));
        printf("ch_a[0] - 0x%p\n", &s.ch_a[0]);
        printf("ch_a[1] - 0x%p\n", &s.ch_a[1]);
        printf("ch_a[2] - 0x%p\n", &s.ch_a[2]);
        printf("i_a     - 0x%p\n", &s.i_a);
        printf("sh_a    - 0x%p\n", &s.sh_a);
        printf("ch_b    - 0x%p\n", &s.ch_b);

        printf("\t+--------+--------+--------+--------+\n"); 
        printf("\t|  ch_a  |  ch_a  |  ch_a  |   ??   |\n");
        printf("\t+--------+--------+--------+--------+\n");
        printf("\t|                i_a                |\n");
        printf("\t+--------+--------+--------+ -------+\n");
        printf("\t|       sh_a      |  ch_b  |   ??   |\n");
        printf("\t+--------+--------+--------+ -------+\n");
        printf("\n");

        printf("\t+--------+--------+--------+--------+\n");
        p = (unsigned char*)(&s.ch_a[0]);
        printf("\t|   %.2x   |   %.2x   |   %.2x   |   %.2x   |\n", *p, *(p+1), *(p+2), *(p+3));
        printf("\t+--------+--------+--------+--------+\n");
        p = (unsigned char*)(&s.i_a);
        printf("\t|   %.2x   |   %.2x   |   %.2x   |   %.2x   |\n", *p, *(p + 1), *(p + 2), *(p + 3));
        printf("\t+--------+--------+--------+ -------+\n");
        p = (unsigned char*)(&s.sh_a);
        printf("\t|   %.2x   |   %.2x   |", *p, *(p + 1));
        p = (unsigned char*)(&s.ch_b);
        printf("   %.2x   |   %.2x   |\n", *p, *(p + 1));
        printf("\t+--------+--------+--------+--------+\n");
        printf("\n");
    }
}


void test_data(char *apData)
{
    s_problem_np np;

    np = *((s_problem_np*)(apData));

    printf("ch = %c\n", np.ch);
    printf("sh = %i\n", np.sh);
}

void problem_example()
{
    s_problem_np data;  // one platform
    //s_problem_p  data;// second platform
    char *send_buffer;

    data.ch = 'a';
    data.sh = 0x200; // 512 in dec

    send_buffer = (char*)&(data);

    test_data(send_buffer);
}














