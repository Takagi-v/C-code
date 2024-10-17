#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "linkList.h"
using namespace std;

struct Type
{
  int coef;
  int exp;
};

template <class elemType>
struct Node
{
  elemType data;
  Node *next;
};

template <class elemType>
struct Polynomial
{
private:
  Node<elemType> *head;
  elemType stop_flag;

public:
  Polynomial(const elemType &stop);
  void addPoly(const Polynomial<elemType> &L1, const Polynomial<elemType> &L2);
  void getPoly();
  void display();
  void clear();
  ~Polynomial();
};

template <class elemType>
void getStop(elemType &stopFlag)
{
  int c, e;
  cout << "请输入系数、指数对作为结束标志";
  cin >> c >> e;
  stopFlag.coef = c;
  stopFlag.exp = e;
}

template <class elemType>
Polynomial<elemType>::Polynomial(const elemType &stop)
{
  head = new Node<elemType>();
  stop_flag.coef = stop.coef;
  stop_flag.exp = stop.exp;
}

template <class elemType>
void Polynomial<elemType>::getPoly()
{
  Node<elemType> *p, *tmp;
  elemType e;
  p = head;
  cout << "请按照指数从小到大输入系数，指数对";
  cin >> e.coef >> e.exp;

  while (true)
  {
    if ((e.coef == stop_flag.coef) && (e.exp == stop_flag.exp))
      break;

    tmp = new Node<elemType>();
    tmp->data.coef = e.coef;
    tmp->data.exp = e.exp;
    tmp->next = NULL;
    p->next = tmp;
    p = tmp;

    cin >> e.coef >> e.exp;
  }
}

template <class elemType>
void Polynomial<elemType>::addPoly(const Polynomial &La, const Polynomial &Lb)
{
  Node<elemType> *pa, *pb, *pc;
  Node<elemType> *tmp;

  pa = La.head->next;
  pb = Lb.head->next;
  pc = head;

  while (pa && pb)
  {
    if (pa->data.exp == pb->data.exp)
    {
      if (pa->data.coef + pb->data.coef == 0)
      {
        pa = pa->next;
        pb = pb->next;
        continue;
      }
      else
      {
        tmp = new Node<elemType>();
        tmp->data.coef = pa->data.coef + pb->data.coef;
        tmp->data.exp = pa->data.exp;
        tmp->next = NULL;
        pa = pa->next;
        pb = pb->next;
      }
    }
    else if (pa->data.exp < pb->data.exp)
    {
      tmp = new Node<elemType>();
      tmp->data.coef = pb->data.coef;
      tmp->data.exp = pb->data.exp;
      tmp->next = NULL;
      pb = pb->next;
    }
    else
    {
      tmp = new Node<elemType>();
      tmp->data.coef = pa->data.coef;
      tmp->data.exp = pa->data.exp;
      tmp->next = NULL;
      pa = pa->next;
    }
    pc->next = tmp;
    pc = tmp;
  }
  while (pa)
  {
    tmp = new Node<elemType>();
    tmp->data.coef = pa->data.coef;
    tmp->data.exp = pa->data.exp;
    tmp->next = NULL;
    pa = pa->next;
    pc->next = tmp;
    pc = tmp;
  }
  while (pb)
  {
    tmp = new Node<elemType>();
    tmp->data.coef = pb->data.coef;
    tmp->data.exp = pb->data.exp;
    tmp->next = NULL;
    pb = pb->next;
    pc->next = tmp;
    pc = tmp;
  }
}

template <class elemType>
void Polynomial<elemType>::display()
{
  Node<elemType> *p = head->next;
  while (p)
  {
    cout << p->data.coef << "x^" << p->data.exp;
    p = p->next;
    if (p)
      cout << " + ";
  }
  cout << endl;
}

template <class elemType>
void Polynomial<elemType>::clear()
{
  Node<elemType> *p = head->next;
  Node<elemType> *tmp;
  while (p)
  {
    tmp = p;
    p = p->next;
    delete tmp;
  }
  head->next = NULL;
}

template <class elemType>
Polynomial<elemType>::~Polynomial()
{
  clear();
  delete head;
}

#endif
