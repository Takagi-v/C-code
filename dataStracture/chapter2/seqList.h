#ifndef seqList_H
#define seqList_H

template <class elemType>
class seqList
{
private:
  elemType *elem; // 存储元素的数组
  int maxSize;    // 数组的最大容量
  int len;        // 当前线性表的长度

  void doubleSpace(); // 扩展存储空间

public:
  seqList(int initSize = 10); // 构造函数
  ~seqList();                 // 析构函数

  elemType get(int i) const;             // 获取第i个元素
  int find(const elemType &x) const;     // 查找元素x的位置
  void insert(int i, const elemType &x); // 在第i个位置插入元素x
  void remove(int i);                    // 删除第i个位置的元素
  int length() const;                    // 获取线性表的长度
};
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
#include "seqList.cpp"

#endif
