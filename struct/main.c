#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MINE_FOOD_COST_OIL  100
#define MINE_FOOD_COST_FOOD 200
#define MINE_FOOD_COST_GOLD 80

#define MINE_OIL_COST_OIL  100
#define MINE_OIL_COST_FOOD 200
#define MINE_OIL_COST_GOLD 80

#define MINE_GOLD_COST_OIL  300
#define MINE_GOLD_COST_FOOD 600
#define MINE_GOLD_COST_GOLD 200

#define FOOD_COOF 2.8f
#define OIL_COOF  2.2f
#define GOLD_COOF 1.f

typedef enum
{
    FOOD = 0
   ,OIL
   ,GOLD
   ,MINE_END
}eMType;

typedef struct
{
    int    id;
    int    level;
    int    growth;
    float  coof;
    eMType type;
}sMine;


typedef struct
{
    sMine mines[30];
    int   mine_count;
    int   warehouse[MINE_END];
}sResources;

void init_resources(sResources*);
void resources_processing(sResources*);
void print_res_info(sResources*);
void increase_level_mine(sResources*, int);

int main()
{
    sResources resources;
    init_resources(&resources);

    int in_val = 0;

    while(1)
    {
        resources_processing(&resources);
        system("cls");
        print_res_info(&resources);

        in_val = getch();
        switch (in_val)
        {
            case '0':
            {
                increase_level_mine(&resources, 0);
                break;
            }
            case '1':
            {
                increase_level_mine(&resources, 1);
                break;
            }
            case '2':
            {
                increase_level_mine(&resources, 2);
                break;
            }
            case '3':
            {
                increase_level_mine(&resources, 3);
                break;
            }
        }
    }
    return 0;
}


void set_m_gr(sResources *apRes, int index)
{
    apRes->mines[index].growth = FOOD_COOF * apRes->mines[index].level;
}

void init_resources(sResources *apRes)
{
    int i = 0;
    apRes->mine_count      = 0;
    apRes->warehouse[OIL]  = 0;
    apRes->warehouse[FOOD] = 0;
    apRes->warehouse[GOLD] = 0;

    apRes->mines[i].level  = 1;
    apRes->mines[i].id     = i;
    apRes->mines[i].type   = FOOD;
    set_m_gr(apRes, i);
    //apRes->mines[i].growth = FOOD_COOF * apRes->mines[i].level;
    apRes->mines[i].coof   = FOOD_COOF;
    apRes->mine_count = ++i;

    apRes->mines[i].level  = 1;
    apRes->mines[i].id     = i;
    apRes->mines[i].type   = OIL;
    apRes->mines[i].growth = OIL_COOF * apRes->mines[i].level;
    apRes->mines[i].coof   = OIL_COOF;
    apRes->mine_count = ++i;

    apRes->mines[i].level  = 1;
    apRes->mines[i].id     = i;
    apRes->mines[i].type   = GOLD;
    apRes->mines[i].growth = GOLD_COOF * apRes->mines[i].level;
    apRes->mines[i].coof   = GOLD_COOF;
    apRes->mine_count = ++i;
}
//------------------------------------------------------------------------------
void resources_processing(sResources *apResources)
{
    eMType type;
    for(int i = 0; i < apResources->mine_count; ++i)
    {
        type = apResources->mines[i].type;
        apResources->warehouse[type] += apResources->mines[i].growth;
    }
}
//------------------------------------------------------------------------------
void print_res_info(sResources *apResources)
{
    printf("+----------+----------+----------+\n");
    printf("|   food   |    oil   |   gold   |\n");
    printf("+----------+----------+----------+\n");
    printf("|%10i|%10i|%10i|\n",apResources->warehouse[FOOD]
                               ,apResources->warehouse[OIL]
                               ,apResources->warehouse[GOLD]);
    printf("+----------+----------+----------+\n");

    eMType type;
    for(int i = 0; i < apResources->mine_count; ++i)
    {
        type = apResources->mines[i].type;
        switch(type)
        {
            case FOOD:
            {
                printf("food - ");
                break;
            }
            case OIL:
            {
                printf("oil  - ");
                break;
            }
            case GOLD:
            {
                printf("gold - ");
                break;
            }
            case MINE_END:
                break;
        }
        printf("[id]:%2i;", i);
        printf(" [level]:%3i", apResources->mines[i].level);
        printf(" [growth]:%3i\n", apResources->mines[i].growth);
    }
}
//------------------------------------------------------------------------------
void increase_level_mine(sResources *apResources, int aId)
{
    int food  = apResources->warehouse[FOOD];
    int oil   = apResources->warehouse[OIL];
    int gold  = apResources->warehouse[GOLD];

    int n_food = 0;
    int n_oil  = 0;
    int n_gold = 0;

    int isIncreased = 0;

    if(aId < apResources->mine_count)
    {
        switch(apResources->mines[aId].type)
        {
            case FOOD:
            {
                n_food = (apResources->mines[aId].level + 1) * MINE_FOOD_COST_FOOD;
                n_oil  = (apResources->mines[aId].level + 1) * MINE_FOOD_COST_OIL;
                n_gold = (apResources->mines[aId].level + 1) * MINE_FOOD_COST_GOLD;

                if( food >= n_food &&
                    oil  >= n_oil  &&
                    gold >= n_gold)
                    isIncreased = 1;
                break;
            }
            case OIL:
            {
                n_food = (apResources->mines[aId].level + 1) * MINE_OIL_COST_FOOD;
                n_oil  = (apResources->mines[aId].level + 1) * MINE_OIL_COST_OIL;
                n_gold = (apResources->mines[aId].level + 1) * MINE_OIL_COST_GOLD;

                if( food >= n_food &&
                    oil  >= n_oil  &&
                    gold >= n_gold)
                    isIncreased = 1;
                break;
            }
            case GOLD:
            {
                n_food = (apResources->mines[aId].level + 1) * MINE_GOLD_COST_FOOD;
                n_oil  = (apResources->mines[aId].level + 1) * MINE_GOLD_COST_OIL;
                n_gold = (apResources->mines[aId].level + 1) * MINE_GOLD_COST_GOLD;

                if( food >= n_food &&
                    oil  >= n_oil  &&
                    gold >= n_gold)
                    isIncreased = 1;
                break;
            }
            case MINE_END:
                break;
        }

        if(isIncreased)
        {
            apResources->mines[aId].level++;
            apResources->mines[aId].growth = apResources->mines[aId].level *
                                             apResources->mines[aId].coof;

            apResources->warehouse[FOOD] -= n_food;
            apResources->warehouse[OIL]  -= n_oil;
            apResources->warehouse[GOLD] -= n_gold;
        }
    }
}

