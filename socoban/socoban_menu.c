#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "socoban_menu.h"

#include "../../tools_src/input_tools.h"

//------------------------------------------------------------------------------
eMenuState g_s_menu_state = MENU_MAIN;
unsigned   g_s_menu_index = MENU_START;

char *g_s_menu_items[MENU_MAIN_END] =
{
    "Start"
   ,"Select Level"
   ,"About"
   ,"Exit"
};
//------------------------------------------------------------------------------

void s_m_draw();

//------------------------------------------------------------------------------
void socoban_menu_init()
{
    g_s_menu_state = MENU_MAIN;
}
//------------------------------------------------------------------------------
void socoban_menu_processing()
{
  it_clrscr();
  s_m_draw();

  switch(it_get_key())
  {
      case IT_KEY_ENTER:
      {
          g_s_menu_state = g_s_menu_index;
          break;
      }
      case IT_KEY_UP:
      {
          if(g_s_menu_index > 0)
              --g_s_menu_index;
          else
              g_s_menu_index = MENU_EXIT;
          break;
      }
      case IT_KEY_DOWN:
      {
          if(g_s_menu_index < (MENU_MAIN_END - 1))
              ++g_s_menu_index;
          else
              g_s_menu_index = MENU_START;
          break;
      }
      case IT_KEY_ESC:
      {
          g_s_menu_state = MENU_EXIT;
          break;
      }
      case IT_KEY_UNKNOWN:
      case IT_KEY_SPACE:
      case IT_KEY_RIGTH:
      case IT_KEY_LEFT:
          break;
  }
}
//------------------------------------------------------------------------------
eMenuState socoban_menu_current_state()
{
  return g_s_menu_state;
}
//------------------------------------------------------------------------------
void s_m_draw()
{
  for(unsigned i = 0; i < MENU_MAIN_END; ++i)
  {
    if(i == g_s_menu_index)
    {
      IT_PRINTF("[%s]", g_s_menu_items[i]);
    }
    else
    {
      IT_PRINTF("%s", g_s_menu_items[i]);
    }
    IT_PRINTF("%s","\n");
  }
}




















