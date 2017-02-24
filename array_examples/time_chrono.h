#ifndef TIME_CHRONO_H
#define TIME_CHRONO_H

#include <time.h>

struct timespec tstart = {0, 0};
struct timespec tend   = {0, 0};

void start_chrono()
{
    clock_gettime(CLOCK_MONOTONIC, &tstart);
}

double elapsed()
{
    static double res = 0.0;
    clock_gettime(CLOCK_MONOTONIC, &tend);
    res = ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) -
          ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec);
    return res;
}

#endif // TIME_CHRONO_H
