#ifndef EXAMPLE_3_H
#define EXAMPLE_3_H

#include <stdio.h>
#include <math.h>
#include <unistd.h>


#define COUNT_FOOD_FARM 5
#define COUNT_OIL_FARM  5
#define FARM_COOF       1.2


unsigned short food_farm[COUNT_FOOD_FARM] = {0};
unsigned short oil_farm[COUNT_OIL_FARM]   = {0};

unsigned int food_warehouse = 0;
unsigned int oil_warehouse  = 0;

void resource_processing()
{
    float food_produce = 0.0f;
    float oil_produce  = 0.0f;

    for(int i = 0; i < COUNT_FOOD_FARM; ++i)
    {
        if( (rand() % 30) == 5)
            food_farm[i]++;
    }

    for(int i = 0; i < COUNT_OIL_FARM; ++i)
    {
        if( (rand() % 30) == 5)
            oil_farm[i]++;
    }

    for(int i = 0; i < COUNT_FOOD_FARM; ++i)
        food_produce += food_farm[i] * FARM_COOF;

    for(int i = 0; i < COUNT_OIL_FARM; ++i)
        oil_produce += oil_farm[i] * FARM_COOF;

    food_warehouse += food_produce;
    oil_warehouse  += oil_produce;

    system("cls");


    printf("food produce/h: %0.f\n", food_produce * 3600.f);
    printf("oil produce/h:  %0.f\n", oil_produce * 3600.f);

    printf("food warehouse: %i\n", food_warehouse);
    printf("oil warehouse:  %i\n", oil_warehouse);
}

void main_example_3()
{
    while(1)
    {
        // ...
        // ...
        resource_processing();
        sleep(1);
    }
}

#endif // EXAMPLE_3_H
