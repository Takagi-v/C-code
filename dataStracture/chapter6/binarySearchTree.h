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

template <class elemType>
void binarySearchTree<elemType>::insert(const elemType &x)
{
  Node<elemType> *p = root;
  if (!root)
  {
    root = new Node<elemType>(x);
    return;
  }
  while (p)
  {
    if (x == p->data)
      return;
    if (x < p->data)
    {
      if (!p->left)
      {
        p->left = new Node<elemType>(x);
        return;
      }
      p = p->left;
    }
    else
    {
      if (!p->right)
      {
        p->right = new Node<elemType>(x);
        return;
      }
      p = p->right;
    }
  }
}

#endif // BINARY_SEARCH_TREE_H_INCLUDED