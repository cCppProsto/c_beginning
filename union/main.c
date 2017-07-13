#include <stdio.h>
#include <string.h>

typedef union
{
  char  ch;
  short sh;
  int   i;
  long  l;
}uExample_a;
// ch : #
// sh : ##
//  i : ####
//  l : ########

typedef union
{
  char  ch;
  short sh;
  int   i;
  long  l;
  char  buffer[9];
}uExample_b;
//       ch : #
//       sh : ##
//        i : ####
//        l : ########
// buffer[9]: ######## #???????

typedef union
{
  char  buffer[9];
  char  ch;
  short sh;
  int   i;
  long  l;
}uExample_c;
// buffer[9]: ######## #???????
//       ch : #
//       sh : ##
//        i : ####
//        l : ########

typedef enum
{
  KeyPressed
 ,MousePressed
}eInputType;

typedef struct
{
  eInputType input_type;
  union
  {
      int key_code;
      struct
      {
        int x;
        int y;
        int key_code;
      }mouse_info;
  }u;
}sInputEvent_a;


typedef struct
{
  eInputType input_type;
  union
  {
      int key_code;
      struct
      {
        int x;
        int y;
        int key_mouse_code;
      };
  };
}sInputEvent_b;


typedef enum
{
  CHAR
 ,INTEGER
 ,FLOAT
}eType;

typedef struct
{
  eType type;
  union
  {
    char  ch;
    int   i;
    float f;
  };
}sVariant;

int main()
{
  printf("%i\n", sizeof(uExample_a));
  printf("%i\n", sizeof(uExample_b));
  printf("%i\n", sizeof(uExample_c));


  {
    sInputEvent_a event;

    // catched mouse input
    event.input_type = MousePressed;
    event.u.mouse_info.x = 10;
    event.u.mouse_info.y = 10;
    event.u.mouse_info.key_code = 1;

    // catched key input
    event.input_type = KeyPressed;
    event.u.key_code = 27;
  }

  {
    sInputEvent_b event;

    // catched mouse input
    event.input_type = MousePressed;
    event.x = 10;
    event.y = 10;
    event.key_mouse_code = 1;

    // catched key input
    event.input_type = KeyPressed;
    event.key_code = 27;
  }

  sVariant var;

  var.type = CHAR;
  var.ch   = 'A';

  if(var.type = CHAR)
  {
    if(var.ch == 'A')
    {
      var.type = FLOAT;
      var.f    = 1.234;
    }
  }

  // ...

  var.type = FLOAT;
  var.f   = 1.1;

  var.type = INTEGER;
  var.i   = 1;

  return 0;
}










