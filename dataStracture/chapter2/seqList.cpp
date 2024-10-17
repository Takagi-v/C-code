#include "seqList.h"

template <class elemType>
seqList<elemType>::seqList(int initSize)
{
  elem = new elemType[initSize];
  if (!elem)
    throw illegalSize();
  maxSize = initSize - 1;
  len = 0;
}

template <class elemType>
void seqList<elemType>::doubleSpace()
{
  elemType *tmp = elem;
  elem = new elemType[2 * (maxSize + 1)];
  for (int i = 0; i <= maxSize; ++i)
    elem[i] = tmp[i];
  maxSize = 2 * (maxSize + 1) - 1;
  delete[] tmp;
}

template <class elemType>
elemType seqList<elemType>::get(int i) const
{
  if (i < 0 || i >= len)
    throw outOfRange();
  return elem[i];
}

template <class elemType>
int seqList<elemType>::find(const elemType &x) const
{
  for (int i = 0; i < len; ++i)
    if (elem[i] == x)
      return i;
  return -1;
}

template <class elemType>
void seqList<elemType>::insert(int i, const elemType &x)
{
  if (i < 0 || i > len)
    throw outOfRange();
  if (len == maxSize + 1)
    doubleSpace();
  for (int j = len; j > i; --j)
    elem[j] = elem[j - 1];
  elem[i] = x;
  ++len;
}

template <class elemType>
void seqList<elemType>::remove(int i)
{
  if (i < 0 || i >= len)
    throw outOfRange();
  for (int j = i; j < len - 1; ++j)
    elem[j] = elem[j + 1];
  --len;
}