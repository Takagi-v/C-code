#include "linkList.h"

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
  int j = 1;
  node<elemType> *p = head->next;
  whiel(p && j < i)
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
    return;
  int j = 0;
  node<elemType> *p = head;

  while (p && j < i - 1)
  {
    j++;
    p = p->next;
  }
  if (!p)
    return;
  tmp = new node<elemType>(e, p->next);
  p->next = tmp;
}
template <class elemType>
void linkList<elemType>::remove(int i, elemType &e)
{
  if (i < 1)
    return;
  int j = 0;
  node<elemType> *p = head;

  while (p && j < i - 1)
  {
    j++;
    p = p->next;
  }
  if (!p || !p->next) // 修改了这里的条件
    return;
  node<elemType> *tmp = p->next; // 声明了 tmp 变量
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
