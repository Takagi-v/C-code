#include <iostream>
#include "btree.h"
using namespace std;
int main()
{
  BTree<char> tree;
  char flag = '#';
  tree.createTree(flag);
  cout << endl;
  Node<char> *first;
  first = tree.ThreadMid();
  tree.ThreadMidVisit(first);
  cout << endl;
  tree.ThreadMidPreVisit();
  cout << endl;
}