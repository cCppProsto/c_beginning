#include <stdio.h>      /* printf */
#include <stdarg.h>     /* va_list, va_start, va_arg, va_end */


//------------------------------------------------------------------------------
void f_a(int aCount, ...)
{
  int value = 0;
  va_list vl;                 // init variable
  va_start(vl,aCount);        // enable access to the variable argument

  for (int i = 0; i < aCount; i++)
  {
    value = va_arg(vl, int);  // get next value
    printf ("%i ", value);
  }
  va_end(vl);                 // clean all what need
  printf ("\n");
}
void example_a()
{
  f_a(3, 1, 2, 3);
}
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
void f_b(char *apFormat, ...)
{
  va_list ap;             /* point on next unnamed argument */

  va_start(ap, apFormat); /* set 'ap' on 1-st unnamed argument */
  for (char *p = apFormat; *p; p++)
  {
    if (*p !='%')
    {
      putchar(*p);
      continue;
    }
    switch(* (++p))
    {
      case 'd':
      {
        int ival = 0;
        ival = va_arg(ap, int);
        printf ("%d", ival);
        break;
      }
      case 'f':
      {
        double  dval = 0.;
        dval = va_arg(ap, double);
        printf("%f", dval);
        break;
      }
      case 's':
      {
        for(char *sval = va_arg(ap, char *); *sval; sval++)
          putchar(*sval);
        break;
      }
      default:
      {
        putchar(*p);
        break;
      }
    }
  }
  va_end(ap); /* clean all */
}
void example_b()
{
  f_b("%d %f %s %i\n", 11, 12.12f, "Hello", 200);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
typedef enum
{
  UNIT
 ,DATA
 ,END
}eType;

typedef struct
{
  int health;
  int armor;
}sUnit;

typedef struct
{
  int value_a;
  int value_b;
  int value_c;
}sData;

void f_c(eType aArgs[], ...)
{
  int index = 0;

  va_list ap;
  va_start(ap, aArgs);

  while(aArgs[index] != END)
  {
    switch(aArgs[index])
    {
      case UNIT:
      {
        sUnit unit;
        unit = va_arg(ap, sUnit);
        printf("Unit info:\n");
        printf("Armor : %i\n", unit.armor);
        printf("Health: %i\n", unit.health);
        break;
      }
      case DATA:
      {
        sData data;
        data = va_arg(ap, sData);
        printf("Data info:\n");
        printf("value_a : %i\n", data.value_a);
        printf("value_b : %i\n", data.value_b);
        printf("value_c : %i\n", data.value_c);
        break;
      }
      default:
        break;
    }
    ++index;
  }
  va_end(ap);
}
void example_c()
{
  sUnit unit = {100, 200};
  sData data = {1,2,3};

  eType args[] = {UNIT, DATA, END};
  f_c(args, unit, data);
}
//------------------------------------------------------------------------------

int main ()
{
  example_a();
  example_b();
  example_c();
  return 0;
}
