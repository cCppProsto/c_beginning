#ifndef EXAMPLE_2_H
#define EXAMPLE_2_H

#include <stdio.h>
#include <math.h>


#define POWER        0
#define ARMOR        1
#define INTELLIGENCE 2
#define POWER_2      3
#define PARAM_COUNT  4

unsigned short player_params[PARAM_COUNT] = {0};

void print_common_power()
{
    unsigned short i = 0;
    unsigned int   res = 0;
    for(; i < PARAM_COUNT; ++i)
        res += player_params[i];

    printf("common power = %i\n", res);
}

void print_params()
{
    unsigned short i = 0;
    for(; i < PARAM_COUNT; ++i)
    {
        switch (i)
        {
            case POWER:
            {
                printf("Power: %i\n", player_params[POWER]);
                break;
            }
            case ARMOR:
            {
                printf("Armor: %i\n", player_params[ARMOR]);
                break;
            }
            case INTELLIGENCE:
            {
                printf("Intelligence: %i\n", player_params[INTELLIGENCE]);
                break;
            }
            case POWER_2:
            {
                printf("Power 2: %i\n", player_params[POWER_2]);
                break;
            }
        }
    }
}

void init_param_values()
{
    unsigned short i = 0;
    for(; i < PARAM_COUNT; ++i)
        player_params[i] = rand() % 40;
}

void main_example_2()
{
    init_param_values();


    print_params();
}

#endif // EXAMPLE_2_H
