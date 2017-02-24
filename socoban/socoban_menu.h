#ifndef SOCOBAN_MENU_H
#define SOCOBAN_MENU_H

typedef enum
{
    MENU_START = 0
   ,MENU_SELECT_LEVEL
   ,MENU_ABOUT
   ,MENU_EXIT
   ,MENU_MAIN_END
   ,MENU_MAIN
}eMenuState;

void socoban_menu_init();
void socoban_menu_processing();
eMenuState socoban_menu_current_state();

#endif // SOCOBAN_MENU_H
