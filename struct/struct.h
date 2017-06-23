#ifndef STRUCT_H
#define STRUCT_H

typedef struct
{
    char ch_a;
    char ch_b;
}s_a_np;

typedef struct
{
    char  ch_a;
    short sh_a;
    short sh_b;
}s_b_np;

typedef struct
{
    char    ch_a[3];
    int     i_a;
    short   sh_a;
    char    ch_b;
}s_c_np;

#pragma pack(push,1)
typedef struct
{
    char ch_a;
    char ch_b;
}s_a_p;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct
{
    char  ch_a;
    short sh_a;
    short sh_b;
}s_b_p;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct
{
    char    ch_a[3];
    int     i_a;
    short   sh_a;
    char    ch_b;
}s_c_p;
#pragma pack(pop)


typedef struct
{
    char  ch;
    short sh;
}s_problem_np;

#pragma pack(push,1)
typedef struct
{
    char  ch;
    short sh;
}s_problem_p;
#pragma pack(pop)

void s_a_print_info();
void s_b_print_info();
void s_c_print_info();

void problem_example();

#endif // STRUCT_H
