#ifndef SEQQUEUE_H_INCLUDED
#define SEQQUEUE_H_INCLUDED

// 在类定义前添加异常类
class illegalSize
{
};
class outOfBound
{
};

template <class elemType>
class seqQueue
{
private:
  elemType *array;
  int maxSize;
  int Front, Rear;
  void doubleSpace();

public:
  seqQueue(int size = 10);
  bool isEmpty();
  bool isFull();
  elemType &front();
  void enQueue(const elemType &x);
  void deQueue();
  ~seqQueue();
};

template <class elemType>
seqQueue<elemType>::seqQueue(int size)
{
  array = new elemType[size];
  if (!array)
    throw illegalSize();
  maxSize = size;
  Front = Rear = 0;
}

template <class elemType>
bool seqQueue<elemType>::isEmpty()
{
  return Front == Rear;
}

template <class elemType>
bool seqQueue<elemType>::isFull()
{
  return (Rear + 1) % maxSize == Front;
}

template <class elemType>
elemType &seqQueue<elemType>::front()
{
  if (isEmpty())
    throw outOfBound();
  return array[(Front + 1) % maxSize];
}

template <class elemType>
void seqQueue<elemType>::enQueue(const elemType &x)
{
  if (isFull())
    doubleSpace();
  Rear = (Rear + 1) % maxSize;
  array[Rear] = x;
}

template <class elemType>
void seqQueue<elemType>::deQueue()
{
  if (isEmpty())
    throw outOfBound();
  Front = (Front + 1) % maxSize;
}

template <class elemType>
seqQueue<elemType>::~seqQueue()
{
  delete[] array;
}

template <class elemType>
void seqQueue<elemType>::doubleSpace()
{
  elemType *newArray = new elemType[2 * maxSize];
  int i, j;
  if (!newArray)
    throw illegalSize();
  for (i = 1, j = (Front + 1) % maxSize; j != (Rear + 1) % maxSize; i++, j = (j + 1) % maxSize)
    newArray[i] = array[j];
  delete[] array;
  array = newArray;
  Front = 0;
  Rear = i - 1;
  maxSize *= 2;
}

#endif // SEQQUEUE_H_INCLUDED