#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_1()
{
  #define ALLOC_SIZE 200

  unsigned index = 0;
  void *p[10] = {0};
  void *offset = 0;

  p[index] = malloc(ALLOC_SIZE);
  printf("%p\n", p[index]);

  offset = p[index];
  index++;
  p[index] = malloc(ALLOC_SIZE);
  offset = p[index] - offset;
  printf("%p - %u\n", p[index], offset);

  offset = p[index];
  index++;
  p[index] = malloc(ALLOC_SIZE);
  offset = p[index] - offset;
  printf("%p - %u\n", p[index], offset);

  offset = p[index];
  index++;
  p[index] = malloc(ALLOC_SIZE);
  offset = p[index] - offset;
  printf("%p - %u\n", p[index], offset);

  offset = p[index];
  index++;
  p[index] = malloc(ALLOC_SIZE);
  offset = p[index] - offset;
  printf("%p - %u\n", p[index], offset);
}

void test_2()
{
  #define ALLOC_SIZE 200

  unsigned index = 0;
  void *p[10] = {0};
  void *offset = 0;

  p[index] = malloc(ALLOC_SIZE);
  printf("%p\n", p[index]);

  offset = p[index];
  index++;
  p[index] = malloc(ALLOC_SIZE);
  offset = p[index] - offset;
  printf("%p - %u\n", p[index], offset);

  offset = p[index];
  index++;
  p[index] = malloc(ALLOC_SIZE);
  offset = p[index] - offset;
  printf("%p - %u\n", p[index], offset);

  offset = p[index];
  index++;
  p[index] = malloc(ALLOC_SIZE);
  offset = p[index] - offset;
  printf("%p - %u\n", p[index], offset);

  offset = p[index];
  index++;
  p[index] = malloc(ALLOC_SIZE);
  offset = p[index] - offset;
  printf("%p - %u\n", p[index], offset);

  printf("free last(%p)\n",p[index]);
  offset = p[index-1];
  free(p[index]);
  p[index] = malloc(ALLOC_SIZE);
  offset = p[index] - offset;
  printf("%p - %u\n", p[index], offset);

  printf("free last(%p) - 2\n", p[index - 2]);
  offset = p[index-3];
  free(p[index - 2]);
  p[index - 2] = malloc(ALLOC_SIZE);
  offset = p[index - 2] - offset;
  printf("%p - %u\n", p[index - 2], offset);
}

void test_3()
{
  #define ALLOC_SIZE 200

  unsigned index = 0;
  void *p[10] = {0};
  void *offset = 0;

  p[index] = malloc(ALLOC_SIZE);
  printf("%p\n", p[index]);

  offset = p[index];
  index++;
  p[index] = malloc(ALLOC_SIZE);
  offset = p[index] - offset;
  printf("%p - %u\n", p[index], offset);

  offset = p[index];
  index++;
  p[index] = malloc(ALLOC_SIZE);
  offset = p[index] - offset;
  printf("%p - %u\n", p[index], offset);

  offset = p[index];
  index++;
  p[index] = malloc(ALLOC_SIZE);
  offset = p[index] - offset;
  printf("%p - %u\n", p[index], offset);
  offset = p[index];
  index++;
  p[index] = malloc(ALLOC_SIZE);
  offset = p[index] - offset;
  printf("%p - %u\n", p[index], offset);

  printf("free last(%p)\n",p[index]);
  offset = p[index-1];
  free(p[index]);
  p[index] = malloc(ALLOC_SIZE + 1);
  offset = p[index] - offset;
  printf("%p - %u\n", p[index], offset);

  printf("free last(%p) - 2\n", p[index - 2]);
  offset = p[index-3];
  free(p[index - 2]);
  p[index - 2] = malloc(ALLOC_SIZE + 1);
  printf("%p\n", p[index - 2]);
}

void test_4()
{
  #define ALLOC_SIZE_A 200
  #define ALLOC_SIZE_B 200

  malloc(ALLOC_SIZE_A);

  void *p_a = 0;
  void *p_b = 0;

  for(int i = 0; i < 5; ++i)
  {
    p_a = malloc(ALLOC_SIZE_A);
    p_b = malloc(ALLOC_SIZE_B);

    printf("p_a = %p\n", p_a);
    printf("p_b = %p\n", p_b);

    free(p_b);
    free(p_a);
  }
}

/*
 *
1)
  |    |
  |mm  |  - allocate for message
  |mm|n|  - allocate for node 1
  |  |n|  - free for message
  |n |n|  - allocate for node 2
2)
  |n |n|
  |n |n|mm  |  - allocate for message
  |n |n|mm|n|  - allocate for node 1
  |n |n|  |n|  - free for message
  |n |n|n |n|  - allocate for node 2
*/
void test_5()
{
  #define ALLOC_SIZE_MESSAGE 190
  #define ALLOC_SIZE_NODE    100

  malloc(ALLOC_SIZE_MESSAGE);

  void *p_m  = 0;
  void *p_n1 = 0;
  void *p_n2 = 0;

  for(int i = 0; i < 5; ++i)
  {
    p_m  = malloc(ALLOC_SIZE_MESSAGE);
    printf("p_m = %p\n", p_m);

    p_n1 = malloc(ALLOC_SIZE_NODE);
    // ...
    free(p_m);
    // ...
    p_n2 = malloc(ALLOC_SIZE_NODE);

    printf("p_n1 = %p\n", p_n1);
    printf("p_n2 = %p\n", p_n2);
  }
}

/*
1)
  |      |
  |n|    |  - allocate for node1
  |n|n|  |  - allocate for node2
  |n|n|mm|  - allocate for message
  |n|n|     - free for message

2)
  |n|n|      |
  |n|n|n|    |  - allocate for node1
  |n|n|n|n|  |  - allocate for node2
  |n|n|n|n|mm|  - allocate for message
  |n|n|n|n|     - free for message
*/

void test_6()
{
  #define ALLOC_SIZE_MESSAGE 190
  #define ALLOC_SIZE_NODE    100

  malloc(ALLOC_SIZE_MESSAGE);

  void *p_m  = 0;
  void *p_n1 = 0;
  void *p_n2 = 0;

  for(int i = 0; i < 5; ++i)
  {
    p_n1 = malloc(ALLOC_SIZE_NODE);
    p_n2 = malloc(ALLOC_SIZE_NODE);

    p_m  = malloc(ALLOC_SIZE_MESSAGE);
    // ...
    printf("p_m = %p\n", p_m);
    printf("p_n1 = %p\n", p_n1);
    printf("p_n2 = %p\n", p_n2);
    // ...
    free(p_m);
  }
}

int main()
{
//  test_1();
//  printf("\n\n");

//  test_2();
//  printf("\n\n");

//  test_3();
//  printf("\n\n");

//  test_4();
//  printf("\n\n");

//  test_5();
//  printf("\n\n");

//  test_6();
//  printf("\n\n");

  return 0;
}
