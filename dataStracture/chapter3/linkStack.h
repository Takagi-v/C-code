class outOfBound
{
};
template <class elemType>
class linkStack;

template <class elemType>
class Node
{
  friend class linkStack<elemType>;

private:
  elemType data;
  Node<elemType> *next;

public:
  Node() { next = NULL; }
  Node(const elemType &x, Node *p = NULL)
  {
    data = x;
    next = p;
  }
};

template <class elemType>
class linkStack
{
private:
  Node<elemType> *Top;

public:
  linkStack() { Top = NULL; };
  ~linkStack();
  bool isEmpty() const { return Top == NULL; };
  bool isFull() const { return false; };
  void push(const elemType &e);
  elemType top() const;
  void pop();
};

template <class elemType>
elemType linkStack<elemType>::top() const
{
  if (!Top)
    throw outOfBound();
  return Top->data;
}

template <class elemType>
void linkStack<elemType>::push(const elemType &e)
{
  Node<elemType> *tmp = new Node<elemType>(e, Top);
  if (!tmp)
    throw outOfBound();
  Top = tmp;
}

template <class elemType>
void linkStack<elemType>::pop()
{
  if (!Top)
    throw outOfBound();
  Node<elemType> *tmp = Top;
  Top = Top->next;
  delete tmp;
}

template <class elemType>
linkStack<elemType>::~linkStack()
{
  Node<elemType> *tmp;
  while (Top)
  {
    tmp = Top;
    Top = Top->next;
    delete tmp;
  }
}