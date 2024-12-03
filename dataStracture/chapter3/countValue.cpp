#include <iostream>
#include "linkStack.h"
using namespace std;

void inToSufForm(char *inStr, char *sufStr)
{
  linkStack<char> s;
  int i, j;
  char topCh;
  s.push('#');
  i = 0;
  j = 0;
  while (inStr[i] != '\0')
  {
    if (isdigit(inStr[i]))
    {
      while (isdigit(inStr[i]))
      {
        sufStr[j++] = inStr[i++];
      }
      sufStr[j++] = '#';
    }
    else
    {
      switch (inStr[i])
      {
      case '(':
        s.push(inStr[i]);
        break;
      case ')':
        topCh = s.top();
        s.pop();
        while (topCh != '(')
        {
          sufStr[j++] = topCh;
          topCh = s.top();
          s.pop();
        }
        break;
      case '*':
      case '/':
        topCh = s.top();
        while ((topCh == '*') || (topCh == '/'))
        {
          sufStr[j++] = topCh;
          s.pop();
          topCh = s.top();
        }
        s.push(inStr[i]);
        break;
      case '+':
      case '-':
        topCh = s.top();
        while ((topCh == '*') || (topCh == '/') || (topCh == '+') || (topCh == '-'))
        {
          sufStr[j++] = topCh;
          s.pop();
          topCh = s.top();
        }
        s.push(inStr[i]);
        break;
      }
      i++;
    }
  }
  topCh = s.top();
  while (topCh != '#')
  {
    sufStr[j++] = topCh;
    s.pop();
    topCh = s.top();
  }
  sufStr[j] = '\0';
}

int calcPost(char *sufStr)
{
  int op1, op2, op;
  int i = 0;
  linkStack<int> s;

  while (sufStr[i] != '\0')
  {
    if (isdigit(sufStr[i]))
    {
      int num = 0;
      while (isdigit(sufStr[i]))
      {
        num = num * 10 + (sufStr[i] - '0');
        i++;
      }
      s.push(num);
      if (sufStr[i] == '#')
        i++;
    }
    else
    {
      op2 = s.top();
      s.pop();
      op1 = s.top();
      s.pop();
      switch (sufStr[i])
      {
      case '+':
        op = op1 + op2;
        break;
      case '-':
        op = op1 - op2;
        break;
      case '*':
        op = op1 * op2;
        break;
      case '/':
        if (op2 == 0)
        {
          cout << "Error: Division by zero" << endl;
          return 0;
        }
        op = op1 / op2;
        break;
      }
      s.push(op);
      i++;
    }
  }
  op = s.top();
  s.pop();
  return op;
}

int main()
{
  char inStr[80];
  char sufStr[80];
  int result;
  cout << "Input:";
  if (cin.getline(inStr, 80))
  {
    for (int i = 0; inStr[i]; i++)
    {
      if (!isdigit(inStr[i]) &&
          inStr[i] != '+' && inStr[i] != '-' &&
          inStr[i] != '*' && inStr[i] != '/' &&
          inStr[i] != '(' && inStr[i] != ')')
      {
        cout << "Invalid input" << endl;
        return 1;
      }
    }
  }
  inToSufForm(inStr, sufStr);
  result = calcPost(sufStr);
  cout << "suffix form:" << sufStr << endl;
  cout << "Output:" << result << endl;
}