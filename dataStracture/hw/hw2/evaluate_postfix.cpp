#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluatePostfix(const string &expression)
{
  stack<int> s;
  int i = 0;
  while (i < expression.length())
  {
    if (isdigit(expression[i]))
    {
      int num = 0;
      while (i < expression.length() && isdigit(expression[i]))
      {
        num = num * 10 + expression[i] - '0';
        i++;
      }
      s.push(num);
    }
    else if (expression[i] == '.')
    {
      i++;
    }
    else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
    {
      int a = s.top();
      s.pop();
      int b = s.top();
      s.pop();
      if (expression[i] == '+')
      {
        s.push(b + a);
      }
      else if (expression[i] == '-')
      {
        s.push(b - a);
      }
      else if (expression[i] == '*')
      {
        s.push(b * a);
      }
      else if (expression[i] == '/')
      {
        s.push(b / a);
      }
      i++;
    }
    else if (expression[i] == '@')
    {
      break;
    }
  }
  return s.top();
}
int main()
{
  string expression;
  cin >> expression;
  cout << evaluatePostfix(expression) << endl;
  return 0;
}