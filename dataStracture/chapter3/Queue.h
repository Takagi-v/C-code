#ifndef LINKQUEUE_H_INCLUDED
#define LINKQUEUE_H_INCLUDED

class illegalSize
{
};
class outOfBound
{
};

template <class elemType>
class linkQueue;

template <class elemType>
class Node
{
  friend class linkQueue<elemType>;

private:
  elemType data;
  Node<elemType> *next;

public:
  Node() { next = NULL; }
  Node(const elemType &x, Node<elemType> *N = NULL) : data(x), next(N) {}
};

template <class elemType>
class linkQueue
{
private:
  Node<elemType> *Front, *Rear;

public:
  linkQueue() { Front = Rear = NULL; };
  bool isEmpty() { return !Front; };
  bool isFull() { return false; };
  elemType front();
  void enQueue(const elemType &x);
  void deQueue();
  ~linkQueue();
};

template <class elemType>
elemType linkQueue<elemType>::front()
{
  if (isEmpty())
    throw outOfBound();
  return Front->data;
}

template <class elemType>
void linkQueue<elemType>::enQueue(const elemType &x)
{
  if (isFull())
    throw outOfBound();
  if (!Rear)
    Front = Rear = new Node<elemType>(x);
  else
  {
    Rear->next = new Node<elemType>(x);
    Rear = Rear->next;
  }
}

template <class elemType>
void linkQueue<elemType>::deQueue()
{
  if (isEmpty())
    throw outOfBound();
  Node<elemType> *tmp = Front;
  Front = Front->next;
  if (!Front)
    Rear = NULL;
  delete tmp;
}

template <class elemType>
linkQueue<elemType>::~linkQueue()
{
  Node<elemType> *tmp = Front;
  while (tmp)
  {
    Front = Front->next;
    delete tmp;
    tmp = Front;
  }
}
#endif // LINKQUEUE_H_INCLUDED
