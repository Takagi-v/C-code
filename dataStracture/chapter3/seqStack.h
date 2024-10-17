class illegalSize
{
};
class outOfBound
{
};

template <class elemType>
class seqStack
{
private:
  elemType *array;
  int Top;
  int maxSize;
  void doubleSpace();

public:
  seqStack(int initSize = 100);
  int isEmpty() { return (Top == -1); };
  int isFull() { return (Top == maxSize - 1); };
  elemType top();
  void push(const elemType &e);
  void pop();
  ~seqStack() { delete[] array; };
};

template <class elemType>
seqStack<elemType>::seqStack(int initSize)
{
  array = new elemType[initSize];
  if (!array)
    throw illegalSize();
  maxSize = initSize;
  Top = -1;
}

template <class elemType>
void seqStack<elemType>::doubleSpace()
{
  elemType *tmp = new elemType[2 * maxSize];
  if (!tmp)
    throw illegalSize();
  for (int i = 0; i <= Top; i++)
    tmp[i] = array[i];
  delete[] array;
  array = tmp;
  maxSize *= 2;
}

template <class elemType>
elemType seqStack<elemType>::top()
{
  if (isEmpty())
    throw outOfBound();
  return array[Top];
}

template <class elemType>
void seqStack<elemType>::push(const elemType &e)
{
  if (isFull())
    doubleSpace();
  array[++Top] = e;
}

template <class elemType>
void seqStack<elemType>::pop()
{
  if (isEmpty())
    throw outOfBound();
  Top--;
}