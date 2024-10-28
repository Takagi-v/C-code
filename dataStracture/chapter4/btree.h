#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED

#include <iostream>
#include "D:\caleb\ccode\dataStracture\chapter3\seqStack.h"
#include "D:\caleb\ccode\dataStracture\chapter3\seqQueue.h"

using namespace std;

template <class elemType>
class bTree;

template <class elemType>
class Node
{
  friend class bTree<elemType>;

public:
  elemType data;
  Node<elemType> *left, *right;
  int leftFlag;
  int rightFlag;
  Node()
  {
    left = right = NULL;
    leftFlag = rightFlag = 0;
  };
  Node(const elemType &x, Node<elemType> *L = NULL, Node<elemType> *R = NULL)
  {
    data = x;
    left = L;
    right = R;
    leftFlag = rightFlag = 0;
  };
};
template <class elemType>
class BTree
{
private:
  Node<elemType> *root;
  elemType stopFlag;
  int Size(Node<elemType> *t);
  int Height(Node<elemType> *t);
  void DelTree(Node<elemType> *t);
  void PreOrder(Node<elemType> *t);
  void InOrder(Node<elemType> *t);
  void PostOrder(Node<elemType> *t);

public:
  BTree() { root = NULL; };
  void createTree(const elemType &flag);
  int isEmpty() { return root == NULL; };
  Node<elemType> *GetRoot() { return root; };

  int size() { return Size(root); };
  int height() { return Height(root); };
  void DelTree();
  void preOrder() { PreOrder(root); };
  void inOrder() { InOrder(root); };
  void postOrder() { PostOrder(root); };
  void levelOrder();
  Node<elemType> *ThreadMid();
  void ThreadMidVisit(Node<elemType> *first);
  void ThreadMidPreVisit();
  int priOver(const char ch1, const char ch2);
  void buildExpTree(const char *exp);
  int calExpTree();
  Node<elemType> *buildTree(elemType pre[], int pl, int pr, elemType mid[], int ml, int mr);
};
template <class elemType>
void BTree<elemType>::createTree(const elemType &flag)
{
  seqQueue<Node<elemType> *> que;
  elemType e, el, er;
  Node<elemType> *p, *pl, *pr;

  stopFlag = flag;
  cout << "Input root:";
  cin >> e;
  if (e == flag)
  {
    root = NULL;
    return;
  }
  p = new Node<elemType>(e);
  root = p;
  que.enQueue(p);
  while (!que.isEmpty())
  {
    p = que.front();
    que.deQueue();

    cout << "Input" << p->data << "left and right child:";
    cin >> el >> er;
    if (el != flag)
    {
      pl = new Node<elemType>(el);
      p->left = pl;
      que.enQueue(pl);
    }
    if (er != flag)
    {
      pr = new Node<elemType>(er);
      p->right = pr;
      que.enQueue(pr);
    }
  }
}

template <class elemType>
int BTree<elemType>::Size(Node<elemType> *t)
{
  {
    if (!t)
      return 0;
    return 1 + Size(t->left) + Size(t->right);
  }
}

template <class elemType>
int BTree<elemType>::Height(Node<elemType> *t)
{
  if (!t)
    return 0;
  int hl = Height(t->left);
  int hr = Height(t->right);
  if (hl >= hr)
    return hl + 1;
  return hr + 1;
}

template <class elemType>
void BTree<elemType>::DelTree()
{
  DelTree(root);
  root = NULL;
}

template <class elemType>
void BTree<elemType>::DelTree(Node<elemType> *t)
{
  if (!t)
    return;
  DelTree(t->left);
  DelTree(t->right);
  delete t;
}

// template<class elemType>
// void BTree<elemType>::PreOrder(Node<elemType> *t){
//   if(!t)return;
//   cout<<t->data<<' ';
//   PreOrder(t->left);
//   PreOrder(t->right);
// }

template <class elemType>
void BTree<elemType>::PreOrder(Node<elemType> *t)
{
  if (!t)
    return;
  Node<elemType> *p;
  seqStack<Node<elemType> *> s;
  s.push(t);
  while (!s.isEmpty())
  {
    p = s.top();
    s.pop();
    cout << p->data << ' ';
    if (p->right)
      s.push(p->right);
    if (p->left)
      s.push(p->left);
  }
  cout << endl;
}

// template <class elemType>
// void BTree<elemType>::InOrder(Node<elemType> *t)
// {
//   if (!t)
//     return;
//   InOrder(t->left);
//   cout << t->data << ' ';
//   InOrder(t->right);
// }

template <class elemType>
void BTree<elemType>::InOrder(Node<elemType> *t)
{
  if (!t)
    return;
  seqStack<Node<elemType> *> s1;
  seqStack<int> s2;
  Node<elemType> *p = t;
  int flag;
  int zero = 0, one = 1;
  s1.push(p);
  s2.push(zero);
  while (!s1.isEmpty())
  {
    flag = s2.top();
    s2.pop();
    p = s1.top();
    if (flag == 1)
    {
      s1.pop();
      cout << p->data;
      if (!p->right)
        continue;
      s1.push(p->right);
      s2.push(zero);
    }
    else
    {
      s2.push(one);
      if (p->left)
      {
        s1.push(p->left);
        s2.push(zero);
      }
    }
  }
  cout << endl;
}

// template <class elemType>
// void BTree<elemType>::PostOrder(Node<elemType> *t)
// {
//   if (!t)
//     return;
//   PostOrder(t->left);
//   PostOrder(t->right);
//   cout << t->data << ' ';
// }

template <class elemType>
void BTree<elemType>::PostOrder(Node<elemType> *t)
{
  if (!t)
    return;

  Node<elemType> *p = t;
  seqStack<Node<elemType> *> s1;
  seqStack<int> s2;
  int zero = 0, one = 1, two = 2;
  int flag;
  s1.push(p);
  s2.push(zero);
  while (!s1.isEmpty())
  {
    flag = s2.top();
    s2.pop();
    p = s1.top();
    switch (flag)
    {
    case 2:
      s1.pop();
      cout << p->data << ' ';
      break;
    case 1:
      s2.push(two);
      if (p->right)
      {
        s1.push(p->right);
        s2.push(zero);
      }
      break;
    case 0:
      s2.push(one);
      if (p->left)
      {
        s1.push(p->left);
        s2.push(zero);
      }
      break;
    };
  }
}

template <class elemType>
void BTree<elemType>::levelOrder()
{
  seqQueue<Node<elemType> *> que;
  Node<elemType> *p;
  if (!root)
    return;
  while (!que.isEmpty())
  {
    p = que.front();
    que.deQueue();
    cout << p->data << " ";
    if (p->left)
      que.enQueue(p->left);
    if (p->right)
      que.enQueue(p->right);
  }
  cout << endl;
}

template <class elemType>
Node<elemType> *BTree<elemType>::ThreadMid()
{
  if (!root)
    return NULL;
  seqStack<Node<elemType> *> s1;
  seqStack<int> s2;
  Node<elemType> *first;
  Node<elemType> *p = root, *pre;
  int flag;
  int zero = 0, one = 1;
  pre = NULL;
  first = NULL;
  s1.push(p);
  s2.push(zero);
  while (!s1.isEmpty())
  {
    flag = s2.top();
    s2.pop();
    p = s1.top();
    if (flag == 1)
    {
      s1.pop();
      if (!first)
        first = p;
      if ((p->rightFlag == 0) && p->right)
      {
        s1.push(p->right);
        s2.push(zero);
      }
      // 加中序遍历线索
      if (!p->left)
      {
        p->leftFlag = 1;
        p->left = pre;
      }
      if (pre && (!pre->right))
      {
        pre->rightFlag = 1;
        pre->right = p;
      }
      pre = p;
    }
    else
    {
      s2.push(one);
      if ((p->leftFlag == 0) && p->left)
      {
        s1.push(p->left);
        s2.push(zero);
      }
    }
  }
  p->rightFlag = 1;
  return first;
}

template <class elemType>
void BTree<elemType>::ThreadMidVisit(Node<elemType> *first)
{
  if (!first)
    return;
  Node<elemType> *p = first;
  while (p)
  {
    cout << p->data << ' ';
    if (p->rightFlag == 0)
    {
      p = p->right;
      while ((p->leftFlag == 0) && p->left)
        p = p->left;
    }
    else
      p = p->right;
  }
  cout << endl;
}

template <class elemType>
void BTree<elemType>::ThreadMidPreVisit()
{
  Node<elemType> *p = root;
  while (p)
  {
    cout << p->data << ' ';
    if (p->leftFlag == 0)
      p = p->left;
    else
    {
      if (p->rightFlag == 0)
        p = p->right;
      else
      {
        while (p && (p->rightFlag == 1))
          p = p->right;
        if (!p)
          return;
        p = p->right;
      }
    }
  }
}

template <class elemType>
Node<elemType> *BTree<elemType>::buildTree(elemType pre[], int pl, int pr, elemType mid[], int ml, int mr)
{
  Node<elemType> *p, *leftRoot, *rightRoot;
  int i, pos, num;
  int lol, lor, lml, lmr;
  int rpl, rpr, rml, rmr;

  if (pl > pr)
    return NULL;
  p = new Node<elemType>(pre[pl]);
  if (!root)
    root = p;
  for (i = ml; i < mr; i++)
    if (mid[i] == pre[pl])
      break;
  pos = i;
  num = pos - ml;

  lpl = pl + 1;
  lpr = pl + num;
  lml = ml;
  lmr = pos - 1;
  leftRoot = buildTree(pre, lpl, lpr, mid, lml, lmr);

  rpl = pl + num + 1;
  rpr = pr;
  rml = pos + 1;
  rmr = mr;
  rightRoot = buildTree(pre, rpl, rpr, mid, rml, rmr);
  p->left = leftRoot;
  p->right = rightRoot;
  return p;
}

template <class elemType>
int BTree<elemType>::priOver(const char ch1, const char ch2)
{
  // ch1为新读入操作符，ch2为栈顶操作符
  switch (ch1)
  {
  case '(':
    return 1;
  case ')':
    if (ch2 != '(')
      return -1;
    else
      return 0;
  case '*':
  case '/':
    if (ch2 == '*' || ch2 == '/')
      return -1;
    else
      return 1;
  case '+':
  case '-':
    if (ch2 == '#' || ch2 == '(')
      return 1;
    else
      return -1;
  };
}

template <class elemType>
void BTree<elemType>::buildExpTree(const char *exp)
{
  seqStack<char> opStack;
  seqStack<Node<elemType> *> subStack;
  Node<elemType> *p, *left, *right;
  char hash = '#';
  opStack.push(hash);
  while (*exp)
  {
    if ((*exp >= '0') && (*exp <= '9'))
    {
      p = new Node<elemType>(*exp);
      subStack.push(p);
    }
    else
    {
      ch = opStack.top();
      while (priOver(*exp, ch) == -1)
      {
        opStack.pop();
        right = subStack.top();
        subStack.pop();
        left = subStack.top();
        subStack.pop();
        p = new Node<elemType>(ch, left, right);
        subStack.push(p);
        ch = opStack.top();
      }

      if (priOver(*exp, ch) == 0)
        opStack.pop();
      else
        opStack.push(*exp);
    }
    exp++;
  }

  ch = opStack.top();
  while (ch != hash)
  {
    opStack.pop();
    right = subStack.top();
    subStack.pop();
    left = subStack.top();
    subStack.pop();
    p = new Node<elemType>(ch, left, right);
    subStack.push(p);
    ch = opStack.top();
  }
  root = subStack.top();
  subStack.pop();
}

template <class elemType>
int BTree<elemType>::calExpTree()
{
  if (!root)
    return 0;
  Node<elemType> *p;
  seqStack<Node<elemType> *> s1;
  seqStack<int> s2;
  seqStack<int> numStack;
  int flag, num, num1, num2;
  s1.push(root);
  s2.push(0);
  while (!s1.isEmpty())
  {
    flag = s2.top();
    s2.pop();
    switch (flag)
    {
    case 2:
      s1.pop();
      if (p->data >= '0' && p->data <= '9')
        numStack.push(p->data - '0');
      else
      {
        num2 = numStack.top();
        numStack.pop();
        num1 = numStack.top();
        numStack.pop();
        switch (p->data)
        {
        case '+':
          num = num1 + num2;
          break;
        case '-':
          num = num1 - num2;
          break;
        case '*':
          num = num1 * num2;
          break;
        case '/':
          num = num1 / num2;
          break;
        }
        numStack.push(num);
      }
      break;
    case 1:
      s2.push(2);
      if (p->right)
      {
        s1.push(p->right);
        s2.push(0);
      }
      break;
    case 0:
      s2.push(1);
      if (p->left)
      {
        s1.push(p->left);
        s2.push(0);
      }
      break;
    };
  }
  num = numStack.top();
  numStack.pop();
  return num;
}
#endif // BTREE_H_INCLUDED