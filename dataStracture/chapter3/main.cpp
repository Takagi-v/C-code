#include <iostream>
#include "seqStack.h"
#include "linkStack.h"
using namespace std;

int main()
{
  // seqStack<char> s;
  linkStack<char> s;
  char ctemp;

  cout << "Input:";
  ctemp = cin.get();
  while (ctemp != '\n')
  {
    s.push(ctemp);
    ctemp = cin.get();
  }
  cout << "Output:";
  while (!s.isEmpty())
  {
    ctemp = s.top();
    s.pop();
    cout << ctemp;
  }
  return 0;
}