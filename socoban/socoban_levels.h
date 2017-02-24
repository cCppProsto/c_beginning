#ifndef SOCOBAN_LEVELS_H
#define SOCOBAN_LEVELS_H

typedef enum
{
    DIR_UP = 0
   ,DIR_RIGHT
   ,DIR_DOWN
   ,DIR_LEFT
}eDirection;

void socoban_levels_load(unsigned);

void socoban_levels_draw();

void socoban_levels_player_move(eDirection);

unsigned socoban_levels_is_victory();

#endif // SOCOBAN_LEVELS_H
