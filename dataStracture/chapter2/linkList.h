class outOfBound
{
};

template <class elemType>
class linkList;

template <class elemType>
class node
{
  friend class linkList<elemType>;

private:
  elemType data;
  node *next;

public:
  node(const elemType &x, node *n = NULL)
  {
    data = x;
    next = n;
  }
  node() : next(NULL) {};
};

template <class elemType>
class linkList
{
private:
  node<elemType> *head;

public:
  linkList();
  bool isEmpty() const;
  bool isFull() const { return false; };
  int length() const;
  elemType get(int i) const;
  void insert(int i, const elemType &e);
  void remove(int i, elemType &e);
  int find(const elemType &e) const;
  void reverse();
  void clear();
  ~linkList();
};

template <class elemType>
linkList<elemType>::linkList()
{
  head = new node<elemType>();
}
template <class elemType>
bool linkList<elemType>::isEmpty() const
{
  return head->next == NULL;
}
template <class elemType>
int linkList<elemType>::length() const
{
  int len = 0;
  node<elemType> *p = head->next;
  while (p != NULL)
  {
    len++;
    p = p->next;
  }
  return len;
}
template <class elemType>
elemType linkList<elemType>::get(int i) const
{
  if (i < 1)
    throw outOfBound();
  if (i > length())
    throw outOfBound();
  int j = 1;
  node<elemType> *p = head->next;
  while (p && j < i)
  {
    p = p->next;
    j++;
  }
  if (p)
    return p->data;
  else
    throw outOfBound();
}
template <class elemType>
int linkList<elemType>::find(const elemType &e) const
{
  int i = 1;
  node<elemType> *p = head->next;
  while (p && p->data != e)
  {
    p = p->next;
    i++;
  }
  if (p)
    return i;
  else
    return 0;
}
template <class elemType>
void linkList<elemType>::insert(int i, const elemType &e)
{
  if (i < 1)
    throw outOfBound();
  int j = 0;
  node<elemType> *p = head;

  while (p && j < i - 1)
  {
    j++;
    p = p->next;
  }
  if (!p)
    throw outOfBound();
  node<elemType> *tmp = new node<elemType>(e, p->next);
  p->next = tmp;
}
template <class elemType>
void linkList<elemType>::remove(int i, elemType &e)
{
  if (i < 1)
    throw outOfBound();
  int j = 0;
  node<elemType> *p = head;

  while (p && j < i - 1)
  {
    j++;
    p = p->next;
  }
  if (!p || !p->next)
    throw outOfBound();
  node<elemType> *tmp = p->next;
  e = tmp->data;
  p->next = tmp->next;
  delete tmp;
}
template <class elemType>
void linkList<elemType>::clear()
{
  node<elemType> *p = head->next, *q;
  head->next = NULL;
  while (p)
  {
    q = p->next;
    delete p;
    p = q;
  }
}
template <class elemType>
linkList<elemType>::~linkList()
{
  clear();
  delete head;
}

template <class elemType>
void linkList<elemType>::reverse()
{
  node<elemType> *p = head->next, *q;
  head->next = NULL;
  while (p)
  {
    q = p->next;
    p->next = head->next;
    head->next = p;
    p = q;
  }
}
