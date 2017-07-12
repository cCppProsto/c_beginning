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

/*------------------- EXAMPLE 1 ----------------------------------------------*/
void two_dimensional_array_example1()
{
  //   |0|1|2|
  // 0 [ , , ]
  // 1 [ , , ]
  int arr_1[2][3] = { {1,2,3}, {4,5,6} }; // 0x?? 1 2 3 4 5 6
  int arr_2[][3]  = { {1,2,3}, {4,5,6} }; // 0x?? 1 2 3 4 5 6
  //int arr_3[][]  = { {1,2,3}, {4,5,6} }; // error

  void print(int *aArray, int aLines, int aColumns)
  {
    for(int l = 0; l < aLines; ++l)
    {
      for(int c = 0; c < aColumns; ++c)
        printf("%i, ", aArray[l*aColumns+c]);
      printf("\n");
    }
  }

  int get_v(const int *aArray, int aColumns, int aLine, int aColumn)
  {
    return aArray[aLine*aColumns + aColumn];
  }

  void set_v(int *aArray, int aColumns, int aLine, int aColumn, int aValue)
  {
    aArray[aLine*aColumns + aColumn] = aValue;
  }

  //printf("%x\n", &arr_1);
  //printf("%x\n", &arr_1[0]);
  //printf("%x\n", &arr_1[0][0]);

  //print(arr_1, 2, 3);         // warning
  //print(&arr_1[0], 2, 3);     // warning
  print(&arr_1[0][0], 2, 3);

  printf("%i\n", get_v(&arr_1[0][0], 3, 1, 1));
  set_v(&arr_1[0][0], 3, 1, 1, 100);
  printf("%i\n", get_v(&arr_1[0][0], 3, 1, 1));
}

/*------------------- EXAMPLE 2 ----------------------------------------------*/
void two_dimensional_array_example2()
{
  int arr_1[2][3] = { {1,2,3}, {4,5,6} }; // 0x?? 1 2 3 4 5 6
  int arr_2[][3]  = { {1,2,3}, {4,5,6} }; // 0x?? 1 2 3 4 5 6

  void print_a23(int aArray[2][3])
  {
    for(int l = 0; l < 2; ++l)
    {
      for(int c = 0; c < 3; ++c)
        printf("%i, ", aArray[l][c]);
      printf("\n");
    }
  }

  int get_v_a23(const int aArray[2][3], int aLine, int aColumn)
  {
    return aArray[aLine][aColumn];
  }

  void set_v_a23(int aArray[2][3], int aLine, int aColumn, int aValue)
  {
    aArray[aLine][aColumn] = aValue;
  }

  print_a23(arr_1);
  print_a23(arr_2);

  printf("%i\n", get_v_a23(arr_1, 1, 1));
  set_v_a23(arr_1, 1, 1, 100);
  printf("%i\n", get_v_a23(arr_1, 1, 1));
}
/*------------------- EXAMPLE 3 ----------------------------------------------*/
void two_dimensional_array_example3()
{
  int arr_1[2][3] = { {1,2,3}, {4,5,6} };           // 0x?? 1 2 3 4 5 6
  int arr_2[][3]  = { {1,2,3}, {4,5,6}, {7,8,9} };  // 0x?? 1 2 3 4 5 6 7 8 9

  void print_al3(int aArray[][3], int aLines)
  {
    for(int l = 0; l < aLines; ++l)
    {
      for(int c = 0; c < 3; ++c)
        printf("%i, ", aArray[l][c]);
      printf("\n");
    }
  }

  int get_v_al3(const int aArray[][3], int aLine, int aColumn)
  {
    return aArray[aLine][aColumn];
  }

  void set_v_al3(int aArray[][3], int aLine, int aColumn, int aValue)
  {
    aArray[aLine][aColumn] = aValue;
  }

  print_al3(arr_1, 2);
  print_al3(arr_2, 3);

  printf("%i\n", get_v_al3(arr_1, 1, 1));
  set_v_al3(arr_1, 1, 1, 100);
  printf("%i\n", get_v_al3(arr_1, 1, 1));
}
/*------------------- EXAMPLE 4 ----------------------------------------------*/
void two_dimensional_array_example4()
{
  int arr_1[2][3] = { {1,2,3}, {4,5,6} };           // 0x?? 1 2 3 4 5 6

  void print_arr(int **aArray, int aLines, int aColumns)
  {
    for(int l = 0; l < aLines; ++l)
    {
      for(int c = 0; c < aColumns; ++c)
      {
        printf("%i\n", aArray[l*3 + c]);
        printf("%i\n", *(aArray + (l*3 + c)));

        printf("%i\n", aArray[l*3 + c + 1]);
        printf("%i\n", *((int *)aArray + (l*3 + c + 1)));

        printf("%i\n", aArray[l*3 + c + 2]);
        printf("%i\n", *((int *)aArray + (l*3 + c + 2)));

        //int **pp;  // pp++
        //int *p;    // p++

        //printf("%i, ", aArray[l][c]);         // = *(*(aArray+l) + c)
      }
      printf("\n");
    }
  }

  print_arr((int**)arr_1, 2, 3);

  print_arr(&arr_1[0][0], 2, 3);
  print_arr(&arr_1[0], 2, 3);
  print_arr(&arr_1, 2, 3);
  print_arr(arr_1[0], 2, 3);
  print_arr(arr_1[0][0], 2, 3);
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


  two_dimensional_array_example1();
  two_dimensional_array_example2();
  two_dimensional_array_example3();
  two_dimensional_array_example4();

  return 0;
}
