#define BUFFER_SIZE 5

/*
  in  = 0
  out = 0
  [] [] [] []

  put(1)
    [1] [] [] []
    in++;

  put(2)
    [1] [2] [] []
    in++;

  put(3)
    [1] [2] [3] []
    in++;

  put(4)
    [1] [2] [3] [4]
    in++;

  put(5)
    [1] [2] [3] [4]

  get() = 1
    out++;
    [] [2] [3] [4]

  get() = 2
    out++;
    [] [] [3] [4]

  get() = 3
    out++;
    [] [] [] [4]

  get() = 4
    [] [] [] []

  put(5)
    in++;
    [5] [] [] []

  put(6)
    in++;
    [5] [6] [] []

*/

typedef struct
{
  int readIndex;
  int writeIndex;
  int isEmpty;
  int isFull;
  int data[BUFFER_SIZE];
}sCircularBuffer;

void init(sCircularBuffer *apArray)
{
  apArray->readIndex  = 0;
  apArray->writeIndex = 0;
  apArray->isEmpty    = 1;
  apArray->isFull     = 0;
}
//------------------------------------------------------------------------------
int put(sCircularBuffer *apArray, int aValue)
{
  if(apArray->isFull)
    return -1;

  if(apArray->writeIndex >= BUFFER_SIZE)
    apArray->writeIndex = 0;

  if(apArray->isEmpty)
  {
    apArray->isEmpty = 0;
    apArray->data[apArray->writeIndex++] = aValue;

    if (apArray->writeIndex == apArray->readIndex)
      apArray->isFull  = 1;
    return 1;
  }

  apArray->data[apArray->writeIndex++] = aValue;

  if (apArray->writeIndex == apArray->readIndex)
    apArray->isFull  = 1;

  return 1;
}
//------------------------------------------------------------------------------
int get(sCircularBuffer *apArray)
{
  if(apArray->isEmpty)
    return -1;

  apArray->isFull = 0;

  if(apArray->readIndex >= BUFFER_SIZE)
    apArray->readIndex = 0;

  int res = apArray->data[apArray->readIndex++];

  if(apArray->readIndex == apArray->writeIndex)
    apArray->isEmpty = 1;

  return  res;
}
//------------------------------------------------------------------------------
void clear(sCircularBuffer *apArray)
{
  apArray->isEmpty    = 1;
  apArray->isFull     = 0;
  apArray->writeIndex = 0;
  apArray->readIndex  = 0;
}
//------------------------------------------------------------------------------
int isEmpty(sCircularBuffer *apArray)
{
  return apArray->isEmpty;
}
//------------------------------------------------------------------------------
int isFull(sCircularBuffer *apArray)
{
  return apArray->isFull;
}

//------------------------------------------------------------------------------
int main()
{
  sCircularBuffer buff;
  int r;

  init(&buff);

  put(&buff, 1);
  r = get(&buff);

  put(&buff, 2);
  r = get(&buff);

  put(&buff, 3);
  r = get(&buff);

  put(&buff, 4);
  r = get(&buff);

  put(&buff, 5);
  r = get(&buff);

  clear(&buff);

  r = get(&buff);
  r = get(&buff);
  r = get(&buff);

  put(&buff, 1);
  put(&buff, 2);
  put(&buff, 3);

  r = get(&buff);
  r = get(&buff);
  r = get(&buff);
  r = get(&buff);
  r = get(&buff);
  r = get(&buff);

  put(&buff, 4);
  put(&buff, 5);
  put(&buff, 6);
  put(&buff, 7);
  put(&buff, 8);
  put(&buff, 9);
  r = get(&buff);
  r = get(&buff);
  r = get(&buff);
  r = get(&buff);
  r = get(&buff);
  r = get(&buff);
  return 0;
}




















