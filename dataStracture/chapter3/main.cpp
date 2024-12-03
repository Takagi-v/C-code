#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
  // seqStack<char> s;
  linkQueue<int> q;
  int i, x;
  for (i = 0; i < 15; i++)
    q.enQueue(i);
  while (!q.isEmpty())
  {
    cout << q.front() << " ";
    q.deQueue();
  }
}