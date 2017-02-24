#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "socoban_levels.h"

#include "levels_data.c"

#define EMPTY           ' '
#define BOX             219 // '█'(219) | '■'(254)
#define BOX_PLACE       '.'
#define BOX_ON_PLACE    3   // '♥'
#define PLAYER          1   // '☺'

#define DRAW_MAP_SIZE 30*30

unsigned g_s_levels_is_victory = 0;

unsigned g_s_levels_level;
unsigned g_s_levels_width;
unsigned g_s_levels_heigth;
unsigned g_s_levels_count_boxes;
unsigned g_s_levels_count_boxes_on_places;
unsigned g_s_levels_count_moves;
unsigned g_s_levels_player_position;

unsigned char g_s_levels_draw_map[DRAW_MAP_SIZE];
char        **g_s_levels_map;

void map_prepare();

unsigned get_offset(eDirection);

unsigned check_and_move_box(unsigned, eDirection);


//------------------------------------------------------------------------------
void socoban_levels_load(unsigned aLevel)
{
    switch(aLevel)
    {
        case 1:
        {
            g_s_levels_level        = 1;
            g_s_levels_width        = x_l_1 + 1;
            g_s_levels_heigth       = y_l_1;
            g_s_levels_count_boxes  = box_on_places_1;
            g_s_levels_map          = socoban_level_1;
            break;
        }
        case 2:
        {
            g_s_levels_level        = 2;
            g_s_levels_width        = x_l_2 + 1;
            g_s_levels_heigth       = y_l_2;
            g_s_levels_count_boxes  = box_on_places_2;
            g_s_levels_map          = socoban_level_2;
            break;
        }
        case 3:
        {
            g_s_levels_level        = 3;
            g_s_levels_width        = x_l_3 + 1;
            g_s_levels_heigth       = y_l_3;
            g_s_levels_count_boxes  = box_on_places_3;
            g_s_levels_map          = socoban_level_3;
            break;
        }
    }
    map_prepare();

    g_s_levels_is_victory = 0;
}
//------------------------------------------------------------------------------
void socoban_levels_draw()
{
    for(unsigned i = 0; i < g_s_levels_heigth; ++i)
    {
        int j = 0;
        unsigned int pos = i*g_s_levels_width;

        while(g_s_levels_draw_map[i*g_s_levels_width + j])
        {
            if(pos == g_s_levels_player_position)
                printf("%c", PLAYER);
            else
                printf("%c", g_s_levels_draw_map[i*g_s_levels_width + j]);

            pos++;
            j++;
        }
        printf("\n");
    }
}
//------------------------------------------------------------------------------
void socoban_levels_player_move(eDirection aDirection)
{
    unsigned new_position = 0;
    unsigned offset = 0;

    offset       = get_offset(aDirection);
    new_position = g_s_levels_player_position + offset;

    switch (g_s_levels_draw_map[new_position])
    {
        case EMPTY:
        case BOX_PLACE:
        {
            g_s_levels_player_position = new_position;
            break;
        }
        case BOX:
        case BOX_ON_PLACE:
        {
            if(check_and_move_box(new_position, aDirection))
                g_s_levels_player_position = new_position;
            break;
        }
    }
}
//------------------------------------------------------------------------------
unsigned check_and_move_box(unsigned aBoxPos, eDirection aDir)
{
    unsigned new_pos = 0;
    unsigned offset  = 0;

    offset  = get_offset(aDir);
    new_pos = aBoxPos + offset;

    switch(g_s_levels_draw_map[new_pos])
    {
        case EMPTY:
        {
            g_s_levels_draw_map[new_pos] = BOX;
            g_s_levels_draw_map[aBoxPos] = EMPTY;
            return 1;
        }
        case BOX_PLACE:
        {
            g_s_levels_draw_map[new_pos] = BOX_ON_PLACE;
            ++g_s_levels_count_boxes_on_places;

            switch(g_s_levels_draw_map[aBoxPos])
            {
                case BOX_ON_PLACE:
                {
                    g_s_levels_draw_map[aBoxPos] = BOX_PLACE;
                    --g_s_levels_count_boxes_on_places;
                    break;
                }
                case BOX:
                {
                    g_s_levels_draw_map[aBoxPos] = EMPTY;
                    break;
                }
                default:
                    break;
            }

            if(g_s_levels_count_boxes_on_places == g_s_levels_count_boxes)
                g_s_levels_is_victory = 1;

            return 1;
        }
    }
    return 0;
}
//------------------------------------------------------------------------------
unsigned socoban_levels_is_victory()
{
    return g_s_levels_is_victory;
}
//------------------------------------------------------------------------------
void map_prepare()
{
    memset(&g_s_levels_draw_map[0], 0, g_s_levels_width * g_s_levels_heigth);

    for(unsigned i = 0; i < g_s_levels_heigth; ++i)
    {
        int j = 0;
        while(g_s_levels_map[i][j])
        {
            switch(g_s_levels_map[i][j])
            {
                case BOX_DEFAULT:
                {
                    g_s_levels_draw_map[i*g_s_levels_width + j] = BOX;
                    break;
                }
                case BOX_PLACE_DEFAULT:
                {
                    g_s_levels_draw_map[i*g_s_levels_width + j] = BOX_PLACE;
                    break;
                }
                case BOX_ON_PLACE_DEFAULT:
                {
                    g_s_levels_draw_map[i*g_s_levels_width + j] = BOX_ON_PLACE;
                    break;
                }
                case PLAYER_DEFAULT:
                {
                    g_s_levels_player_position = i*g_s_levels_width + j;
                    g_s_levels_draw_map[i*g_s_levels_width + j] = EMPTY;
                    break;
                }
                default:
                {
                    g_s_levels_draw_map[i*g_s_levels_width + j] = g_s_levels_map[i][j];
                    break;
                }
            }
            ++j;
        }
    }
}
//------------------------------------------------------------------------------
unsigned get_offset(eDirection aDir)
{
    switch(aDir)
    {
        case DIR_UP:
            return -g_s_levels_width;
        case DIR_RIGHT:
            return 1;
        case DIR_DOWN:
            return g_s_levels_width;
        case DIR_LEFT:
            return -1;
    }
    return 0;
}

