#include <stdio.h>

/*------------------- EXAMPLE 1 ----------------------------------------------*/
void one_dimensional_array_example1()
{
  int arr_1[3] = {1,2,3};
  int arr_2[]  = {1,2,3};
  //int arr_3[]  = {[2] = 3};// 0, 0, 3

  void print(int *aArray, int aLenght)
  {
    for(int i = 0; i < aLenght; ++i)
      printf("%i, ", *(aArray + i));
    printf("\n");
  }

  int get_v(const int *aArray, int aIndex)
  {
    return *(aArray + aIndex);
  }

  void set_v(int *aArray, int aIndex, int aValue)
  {
    *(aArray + aIndex) = aValue;
  }

  printf("------------------ EXAMPLE 1 ----------------------------\n");

  print(arr_1, 3);
  printf("before: [1] = %i, ", get_v(arr_1, 1));
  set_v(arr_1, 1, 0);
  printf("after: [1] = %i\n", get_v(arr_1, 1));
  print(arr_1, 3);
  printf("\n");

  print(arr_2, 3);
  printf("before: [1] = %i, ", get_v(arr_2, 1));
  set_v(arr_2, 1, 0);
  printf("after: [1] = %i\n", get_v(arr_2, 1));
  print(arr_2, 3);
  printf("\n\n");
}

/*------------------- EXAMPLE 2 ----------------------------------------------*/
void one_dimensional_array_example2()
{
  int arr_1[3] = {1,2,3};
  int arr_2[]  = {1,2,3};
  //int arr_3[]  = {[2] = 3};

  void print(int aArray[], int aLenght)
  {
    for(int i = 0; i < aLenght; ++i)
      printf("%i, ", aArray[i]);
    printf("\n");
  }

  int get_v(const int aArray[], int aIndex)
  {
    return aArray[aIndex];
  }

  void set_v(int aArray[], int aIndex, int aValue)
  {
    aArray[aIndex] = aValue;
  }

  printf("------------------ EXAMPLE 2 ----------------------------\n");

  print(arr_1, 3);
  printf("before: [1] = %i, ", get_v(arr_1, 1));
  set_v(arr_1, 1, 0);
  printf("after: [1] = %i\n", get_v(arr_1, 1));
  print(arr_1, 3);
  printf("\n");

  print(arr_2, 3);
  printf("before: [1] = %i, ", get_v(arr_2, 1));
  set_v(arr_2, 1, 0);
  printf("after: [1] = %i\n", get_v(arr_2, 1));
  print(arr_2, 3);
  printf("\n\n");
}

/*------------------- EXAMPLE 3 ----------------------------------------------*/
void one_dimensional_array_example3()
{
  int arr_1[3] = {1,2,3};
  int arr_2[]  = {1,2,3};
  //int arr_3[]  = {[2] = 3};

            //void (*fun_ptr_arr[])() = {f1,f2,f3};
  void print(int (*aArray)[], int aLenght)
  {
    for(int i = 0; i < aLenght; ++i)
      printf("%i, ", *(*aArray + i));
    printf("\n\n");
  }

  int get_v(const int (*aArray)[], int aIndex)
  {
    return *(*aArray + aIndex);
  }

  void set_v(int (*aArray)[], int aIndex, int aValue)
  {
    *(*aArray + aIndex) = aValue;
  }

  printf("------------------ EXAMPLE 3 ----------------------------\n");

  print(&arr_1, 3);
  printf("before: [1] = %i, ", get_v(&arr_1, 1));
  set_v(&arr_1, 1, 0);
  printf("after: [1] = %i\n", get_v(&arr_1, 1));
  print(&arr_1, 3);
  printf("\n");

  print(&arr_2, 3);
  printf("before: [1] = %i, ", get_v(&arr_2, 1));
  set_v(&arr_2, 1, 0);
  printf("after: [1] = %i\n", get_v(&arr_2, 1));
  print(&arr_2, 3);
  printf("\n\n");
}

/*------------------- EXAMPLE 4 ----------------------------------------------*/
void one_dimensional_array_example4()
{
  #define AR1_SIZE 3
  int arr_1[AR1_SIZE + 1] = {AR1_SIZE};

  #define AR2_SIZE 7
  int arr_2[AR2_SIZE + 1] = {AR2_SIZE, 1, 2, 3, 4, 5, 6, 7};

  #define AR3_SIZE 1
  int arr_3[AR3_SIZE + 1] = {AR3_SIZE, 1};

  void print(int aArray[])
  {
    int end = aArray[0] + 1;
    for(int i = 1; i < end; ++i)
      printf("%i, ", aArray[i]);
    printf("\n");
  }

  int get_v(const int aArray[], int aIndex)
  {
    if(aIndex > aArray[0])
      return 0;
    return aArray[aIndex + 1];
  }

  void set_v(int aArray[], int aIndex, int aValue)
  {
    if(aIndex > aArray[0])
      return;
    aArray[aIndex + 1] = aValue;
  }

  set_v(arr_1, 2, 100);
  print(arr_1);

  set_v(arr_2, 1, 100);
  print(arr_2);

  set_v(arr_3, 0, 100);
  print(arr_3);
}


int main()
{
  one_dimensional_array_example1();
  one_dimensional_array_example2();
  one_dimensional_array_example3();

  int tmp     = 0;
  int *a1     = 0;    /* poiner to int or array */
  int *a2[1]  = {0};  /* array of pointers to int */
  int (*a3)[];        /* poiner to array of int */
  int a4[2] = {1,2};  /* arrays of int */

  /* checking */
  //a1 = 1;           /* warrning - incompatible type*/
  a1 = &tmp;        /* OK */

  //a2[0] = 1;        /* warrning - incompatible type*/
  a2[0] = &tmp;     /* OK */

  a3 = &a4;         /* OK */
  tmp = a4[0];
  *(*a3) = 2;       /* OK */
  //*(*a3) = &tmp;    /* warrning - incompatible type*/

  tmp = *(*a3);
  tmp = a4[0];





  one_dimensional_array_example4();

  return 0;
}
