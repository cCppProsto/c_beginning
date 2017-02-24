#include <stdio.h>
#include <stdlib.h>
typedef int listData;


struct singleList
{
    listData             pData;
    struct singleList   *pNext;
};
/*
+---------+
|  pData  |
+---------+
|  pNext  |
+---------+

for 5 int elements = (4+4)*5 = 40 bytes

  0x400000
+---------+
|    1    |
+---------+
|   NULL  |
+---------+

  0x400000        0x400004
+---------+     +---------+
|    1    |     |    2    |
+---------+  .->+---------+
| 0x400004|--.  |   NULL  |
+---------+     +---------+

  0x400000        0x400004        0x400008
+---------+     +---------+     +---------+
|    1    |     |    2    |     |    3    |
+---------+  .->+---------+  .->+---------+
| 0x400004|--.  | 0x400008|--.  |   NULL  |
+---------+     +---------+     +---------+
*/

/*
+---------+
|  pData  |
+---------+
|  pNext  |
+---------+
|  pPrev  |
+---------+

for 5 int elements = (4+4+4)*5 = 60 bytes

 0x400000
+---------+
|    1    |
+---------+
|   NULL  |
+---------+
|   NULL  |
+---------+

 0x400000        0x400004
+---------+     +---------+
|    1    |     |    2    |
+---------+  .->+---------+
| 0x400004|--.  |   NULL  |
+---------+<-.  +---------+
|   NULL  |  .--| 0x400000|
+---------+     +---------+

 0x400000           0x400004         0x400008
+---------+       +---------+       +---------+
|    1    |       |    2    |       |    3    |
+---------+    .->+---------+    .->+---------+
| 0x400004|----.  | 0x400008|----.  |   NULL  |
+---------+<-.    +---------+<-.    +---------+
|   NULL  |  .----| 0x400000|  .----| 0x400004|
+---------+       +---------+       +---------+
*/
// дву-связный список

/*
+---------+
| pData[] |
+---------+
|numValues|
+---------+
|  pNext  |
+---------+


for 5 int elements = ((4*5)+4+4) = 28 bytes

  0x400000
+---------+
|1,2,3,4,5|
+---------+
|    5    |
+---------+
|   NULL  |
+---------+

  0x400000          0x400004
+---------+       +----------+
|1,2,3,4,5|       |6,7,8,9,10|
+---------+       +----------+
|    5    |       |     5    |
+---------+   .-->+----------+
| 0x400004|---.   |   NULL   |
+---------+       +----------+

  0x400000         0x400004           0x400008
+---------+      +----------+      +--------------+
|1,2,3,4,5|      |6,7,8,9,10|      |11,12,13,14,15|
+---------+      +----------+      +--------------+
|    5    |      |     5    |      |      5       |
+---------+  .-->+----------+  .-->+--------------+
| 0x400004|--.   | 0x400008 |--.   |     NULL     |
+---------+      +----------+      +--------------+
*/
// Развернутый связный список
/*
списки:
    одно-связный(однонаправленный)
    дву-связный(двунаправленный)
    развернутый
    XOR связанный
    список с пропусками
    ...

также кольцевые и т.д.
*/

int main()
{
    struct singleList *phead;
    struct singleList *plast;

    // init
    phead = NULL;

    // isEmpty
    // return (phead == NULL)

    // append
    int data = 1;

    if(phead == NULL)
    {
        phead = malloc(sizeof(struct singleList));
        phead->pData = data;
        phead->pNext = NULL;
    }
    else
    {
        struct singleList *pnext;
        pnext = phead;
        while(pnext->pNext)
            pnext = pnext->pNext;

        pnext->pNext = malloc(sizeof(struct singleList));
        pnext->pNext->pData = data;
        pnext->pNext->pNext = NULL;
    }

    data = 2;
    if(phead == NULL)
    {
        phead = malloc(sizeof(struct singleList));
        phead->pData = data;
        phead->pNext = NULL;
    }
    else
    {
        struct singleList *pnext;
        pnext = phead;
        while(pnext->pNext)
            pnext = pnext->pNext;

        pnext->pNext = malloc(sizeof(struct singleList));
        pnext->pNext->pData = data;
        pnext->pNext->pNext = NULL;
    }

    data = 3;
    if(phead == NULL)
    {
        phead = malloc(sizeof(struct singleList));
        phead->pData = data;
        phead->pNext = NULL;
    }
    else
    {
        struct singleList *pnext;
        pnext = phead;
        while(pnext->pNext)
            pnext = pnext->pNext;

        pnext->pNext = malloc(sizeof(struct singleList));
        pnext->pNext->pData = data;
        pnext->pNext->pNext = NULL;
    }

    struct singleList *pnext;
    pnext = phead;
    while(pnext->pNext)
    {
        printf("%i,", pnext->pData);
        pnext = pnext->pNext;
    }
    printf("%i\n", pnext->pData);



    return 0;
}











