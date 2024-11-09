#ifndef BINARY_SEARCH_TREE_H_INCLUDED
#define BINARY_SEARCH_TREE_H_INCLUDED

#include <iostream>
#include <queue>
using namespace std;

template <class elemType>
class binarySearchTree;

template <class elemType>
class Node
{
  friend class binarySearchTree<elemType>;

private:
  elemType data;
  Node *left, *right;
  int factor; // 平衡因子
public:
  Node() { left = NULL, right = NULL; }
  Node(const elemType &x, Node *l = NULL, Node *r = NULL) : data(x), left(l), right(r) {}
};

template <class elemType>
class binarySearchTree
{
private:
  Node<elemType> *root;
  bool search(const elemType &x, Node<elemType> *t) const;
  void insert(const elemType &x, Node<elemType> *&t);
  void remove(const elemType &x, Node<elemType> *&t);

public:
  binarySearchTree() { root = NULL; }
  bool search(const elemType &x) const;
  void insert(const elemType &x);
  void insertAVL(const elemType &x);
  void remove(const elemType &x);
  void levelTraverse() const;
};

template <class elemType>
bool binarySearchTree<elemType>::search(const elemType &x) const
{
  return search(x, root);
}
template <class elemType>
bool binarySearchTree<elemType>::search(const elemType &x, Node<elemType> *t) const
{
  if (t == NULL)
    return false;
  if (x == t->data)
    return true;
  if (x < t->data)
    return search(x, t->left);
  else
    return search(x, t->right);
}
// template <class elemType>
// bool binarySearchTree<elemType>::search(const elemType &x) const
// {
//   if (!root)
//     return false;
//   Node<elemType> *p = root;
//   while (p)
//   {
//     if (x == p->data)
//       return true;
//     if (x < p->data)
//       p = p->left;
//     else
//       p = p->right;
//   }
//   return false;
// }

template <class elemType>
void binarySearchTree<elemType>::insert(const elemType &x)
{
  insert(x, root);
}
template <class elemType>
void binarySearchTree<elemType>::insert(const elemType &x, Node<elemType> *&t)
{
  if (t == NULL)
    t = new Node<elemType>(x);
  if (x == t->data)
    return;
  if (x < t->data)
    insert(x, t->left);
  else if (x > t->data)
    insert(x, t->right);
}

// template <class elemType>
// void binarySearchTree<elemType>::insert(const elemType &x)
// {
//   Node<elemType> *p = root;
//   if (!root)
//   {
//     root = new Node<elemType>(x);
//     return;
//   }
//   while (p)
//   {
//     if (x == p->data)
//       return;
//     if (x < p->data)
//     {
//       if (!p->left)
//       {
//         p->left = new Node<elemType>(x);
//         return;
//       }
//       p = p->left;
//     }
//     else
//     {
//       if (!p->right)
//       {
//         p->right = new Node<elemType>(x);
//         return;
//       }
//       p = p->right;
//     }
//   }
// }

template <class elemType>
void binarySearchTree<elemType>::remove(const elemType &x)
{
  remove(x, root);
}
template <class elemType>
void binarySearchTree<elemType>::remove(const elemType &x, Node<elemType> *&t)
{
  if (!t)
    return;
  if (x < t->data)
    remove(x, t->left);
  else if (x > t->data)
    remove(x, t->right);
  else
  {
    if (!t->left && !t->right)
    {
      delete t;
      t = NULL;
      return;
    }
    if (!t->left || !t->right)
    {
      Node<elemType> *tmp;
      tmp = t;
      t = (t->left) ? t->left : t->right;
      delete tmp;
      return;
    }

    Node<elemType> *p = t->right, *substitute;
    while (p->left)
      p = p->left;
    substitute = p;
    t->data = substitute->data;
    remove(substitute->data, t->right);
  }
}

template <class elemType>
void binarySearchTree<elemType>::remove(const elemType &x)
{
  if (!root)
    return;
  Node<elemType> *p = root, *parent = NULL;
  int flag = 0; // 0表示左子树，1表示右子树
  while (p)
  {
    if (x < p->data)
    {
      parent = p;
      flag = 0;
      p = p->right;
      continue;
    }
    if (x > p->data)
    {
      parent = p;
      flag = 1;
      p = p->right;
      continue;
    }
    if (!p->left && !p->right)
    {
      delete p;
      if (!parent)
      {
        root = NULL;
        return;
      }
      if (flag == 0)
        parent->left = NULL;
      else
        parent->right = NULL;
    }
    if (!p->left || !p->right)
    {
      Node<elemType> *tmp = p;
      if (!parent)
        root = (p->left) ? p->left : p->right;
      else
      {
        if (flag == 0)
          parent->left = (p->left) ? p->left : p->right;
        else
          parent->right = (p->left) ? p->left : p->right;
      }
      delete tmp;
      return;
    }
    Node<elemType> *q = p->left, *substitute;
    parent = p;
    flag = 0;
    while (q->right)
    {
      parent = q;
      flag = 1;
      q = q->right;
    }
    substitute = q;
    p->data = substitute->data;
    substitute->data = x;
    p = substitute;
  }
}

template <class elemType>
void binarySearchTree<elemType>::insertAVL(const elemType &x)
{
  Node<elemType> *p, *q, *parent;
  Node<elemType> *up, *mid, *low, *tmp;
  char lowerArm = '#', upperArm = '#', parentFlag;
  stack<Node<elemType> *> s;
  const char *pattern = "##"; // 存储类型
  if (!root)
  {
    root = new Node<elemType>(x);
    root->factor = 0;
    return;
  }

  p = root;
  while (p)
  {
    if (x == p->data)
      return;
    s.push(p);
    if (x < p->data)
    {
      if (!p->left)
      {
        p->left = new Node<elemType>(x);
        p->left->factor = 0;
        s.push(p->left);
        break;
      }
      p = p->left;
    }
    else
    {
      if (!p->right)
      {
        p->right = new Node<elemType>(x);
        p->right->factor = 0;
        s.push(p->right);
        break;
      }
      p = p->right;
    }
  }
  q = s.top();
  s.pop();
  // 保证有初值
  low = mid = up = NULL;
  lowerArm = upperArm = '#';

  while (!s.isEmpty())
  {
    p = s.top();
    s.pop();
    if (p->left == q)
    {
      p->factor++;
      lowerArm = upperArm;
      upperArm = 'L';
      low = mid;
      mid = q;
      up = p;
      if (up->factor == 0)
        return;
      if (up->factor == 2)
        break;
    }
    else
    {
      p->factor--;
      lowerArm = upperArm;
      upperArm = 'R';
      low = mid;
      mid = q;
      up = p;
      if (up->factor == 0)
        return;
      if (up->factor == -2)
        break;
    }
    q = p;
  }

  if (up->factor != 2 && up->factor != -2)
    return;

  if (s.isEmpty()) // 冲突节点为根节点
    parent = NULL;
  else
  {
    parent = s.top();
    s.pop();
    if (parent->left == up)
      parentFlag = 'L';
    else
      parentFlag = 'R';
  }

  // 调整
  while (true)
  {
    if (upperArm == 'L' && lowerArm == 'L') // LL型 上臂旋
    {
      if (strcmp(pattern, "##") == 0)
        pattern = "LL";
      up->left = mid->right;
      mid->right = up;
      p = mid;
      break;
    }
    if (upperArm == 'R' && lowerArm == 'R') // RR型 上臂旋
    {
      if (strcmp(pattern, "##") == 0)
        pattern = "RR";
      up->right = mid->left;
      mid->left = up;
      p = mid;
      break;
    }
    if (upperArm == 'L' && lowerArm == 'R') // LR型 下臂旋
    {
      switch (low->factor)
      {
      case 0:
        pattern = 'LR0';
        break;
      case 1:
        pattern = 'LR1';
        break;
      case -1:
        pattern = 'LR2';
        break;
      };
      mid->right = low->left;
      low->left = mid;
      up->left = low;

      lowerArm = 'L';
      tmp = low;
      low = mid;
      mid = tmp;
      continue;
    }
    if (upperArm == 'R' && lowerArm == 'L') // RL型 下臂旋
    {
      switch (low->factor)
      {
      case 0:
        pattern = 'RL0';
        break;
      case 1:
        pattern = 'RL1';
        break;
      case -1:
        pattern = 'RL2';
        break;
      };
      mid->left = low->right;
      low->right = mid;
      up->right = low;

      lowerArm = 'R';
      tmp = low;
      low = mid;
      mid = tmp;
      continue;
    }
  } // 子树调整结束
  // 如果有父节点，将新子树挂到父节点上
  if (!parent)
    root = p;
  else
  {
    if (parentFlag == 'L')
      parent->left = p;
    else
      parent->right = p;
  }
  // 调整平衡因子
  if (strcmp(pattern, "LL") == 0 || strcmp(pattern, "RR") == 0)
  {
    up->factor = 0;
    mid->factor = 0;
    return;
  }
  if (strcmp(pattern, "LR0") == 0)
  {
    up->factor = 0;
    mid->factor = 0;
    low->factor = 0;
    return;
  }
  if (strcmp(pattern, "LR1") == 0)
  {
    up->factor = -1;
    mid->factor = 0;
    low->factor = 0;
    return;
  }
  if (strcmp(pattern, "LR2") == 0)
  {
    up->factor = 0;
    mid->factor = 0;
    low->factor = 1;
    return;
  }
  if (strcmp(pattern, "RL0") == 0)
  {
    up->factor = 0;
    mid->factor = 0;
    low->factor = 0;
    return;
  }
  if (strcmp(pattern, "RL1") == 0)
  {
    up->factor = 0;
    mid->factor = 0;
    low->factor = -1;
    return;
  }
  if (strcmp(pattern, "RL2") == 0)
  {
    up->factor = 1;
    mid->factor = 0;
    low->factor = 0;
    return;
  }
}

#endif // BINARY_SEARCH_TREE_H_INCLUDED