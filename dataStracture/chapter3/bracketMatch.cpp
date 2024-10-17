#include <iostream>
#include "linkStack.h"
using namespace std;

int main()
{
  char str[20];
  linkStack<char> s;
  char ch;
  cout << "Input:";
  cin.getline(str, 20, '\n');
  cout << "str:" << str << endl;
  int i = 0;
  ch = str[i++];
  while (ch != '\0')
  {
    switch (ch)
    {
    case '(':
      s.push(ch);
      break;
    case ')':
      if (s.isEmpty())
      {
        cout << "Error: unmatched bracket" << endl;
        return 1;
      }
      s.pop();
      break;
    }
    ch = str[i++];
  }
  if (s.isEmpty())
  {
    cout << "Matched bracket" << endl;
  }
  else
  {
    cout << "Error: unmatched bracket" << endl;
  }
}