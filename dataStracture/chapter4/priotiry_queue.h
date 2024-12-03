#ifndef PRIORITY_QUEUE_H_INCLUDED
#define PRIORITY_QUEUE_H_INCLUDED
class illegalSize
{
};
class outOfBound
{
};
template <class elemType>
class priorityQueue
{
private:
  elemType *array;
  int maxSize, currentLen;
  void doubleSpace();
  void adjust(int hole);
  void build(int r);

public:
  priorityQueue(int size = 100);
  priorityQueue(const elemType *items, int size);
  ~priorityQueue() { delete[] array; };
  bool isEmpty() const { return currentLen == 0; };
  bool isFull() const { return currentLen == maxSize - 1; };
  void enQueue(const elemType &x);
  void deQueue();
  elemType front() const;
};

template <class elemType>
priorityQueue<elemType>::priorityQueue(int size)
{
  array = new elemType[size];
  if (array == NULL)
    throw illegalSize();
  maxSize = size;
  currentLen = 0;
}

template <class elemType>
priorityQueue<elemType>::priorityQueue(const elemType *items, int size)
{
  if (size < 1)
    throw illegalSize();
  array = new elemType[size + 10];
  if (!array)
    throw illegalSize();
  maxSize = size + 10;
  currentLen = size;
  for (int i = 1; i <= size; i++)
    array[i] = items[i - 1];
  for (int i = size / 2; i >= 1; i--)
    adjust(i);
}

template <class elemType>
void priorityQueue<elemType>::adjust(int hole)
{
  int minChild;
  elemType x;
  x = array[hole];
  while (true)
  {
    minChild = 2 * hole;
    if (minChild > currentLen)
      break;
    if (minChild + 1 <= currentLen)
      if (array[minChild + 1] < array[minChild])
        minChild++;
    if (x < array[minChild])
      break;
    array[hole] = array[minChild];
    hole = minChild;
  }
  array[hole] = x;
}

template <class elemType>
elemType priorityQueue<elemType>::front() const
{
  if (isEmpty())
    throw outOfBound();
  return array[1];
}

template <class elemType>
void priorityQueue<elemType>::deQueue()
{
  if (isEmpty())
    throw outOfBound();
  array[1] = array[currentLen--];
  adjust(1);
}

template <class elemType>
void priorityQueue<elemType>::enQueue(const elemType &x)
{
  if (isFull())
    doubleSpace();
  int hole = ++currentLen;
  for (; hole > 1 && x < array[hole / 2]; hole /= 2)
    array[hole] = array[hole / 2];
  array[hole] = x;
}

template <class elemType>
void priorityQueue<elemType>::doubleSpace()
{
  elemType *tmp = new elemType[2 * maxSize];
  if (!tmp)
    throw illegalSize();

  for (int i = 1; i <= currentLen; ++i)
    tmp[i] = array[i];

  delete[] array;
  array = tmp;
  maxSize *= 2;
}

#endif // PRIORITY_QUEUE_H_INCLUDED