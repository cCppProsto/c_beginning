#ifndef EXAMPLE_1_H
#define EXAMPLE_1_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "time_chrono.h"

float calculate(double i)
{
    return (((exp(i) / 0.789651) / exp(i*12.21)) * 3.111122345667) /
           (((exp(i/6745.2)*i) / exp(i/56.6797)) * exp(i * 3214.56787));
}

float calc_optimize(int i)
{
    static int isCalc = 0;
    static float calc_table[360] = {0};
    if(!isCalc)
    {
        int i = 0;
        for(; i < 360; ++i)
            calc_table[i] = calculate(i);

        isCalc = 1;
    }

    return calc_table[i];
}

void not_optimaze_test()
{
    int    i = 0;
    double diff = 0.;

    start_chrono();
    for(; i < 1000000; ++i)
        calculate(rand() % 360);

    diff = elapsed();

    printf("Not optimize = %.5f\n", diff);
}

void optimaze_test()
{
    int    i = 0;
    double diff = 0.;

    start_chrono();
    for(; i < 1000000; ++i)
        calc_optimize(rand() % 360);

    diff = elapsed();

    printf("Optimize = %.5f\n", diff);
}

void main_example_1()
{
    calc_optimize(1);

    not_optimaze_test();
    not_optimaze_test();
    not_optimaze_test();

    printf("\n-------------------------------------------\n");

    optimaze_test();
    optimaze_test();
    optimaze_test();
}


#endif // EXAMPLE_1_H
