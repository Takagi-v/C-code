#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverse(string s)
{
  int countzero = 0;
  reverse(s.begin(), s.end());
  for (auto i : s)
  {
    if (i == '0')
    {
      countzero++;
    }
    else
    {
      break;
    }
  }
  s.erase(s.begin(), s.begin() + countzero);
  return (s != "" ? s : "0");
}
string remove_extra_zero(string s)
{
  int countzero = 0;
  for (int i = s.size() - 1; i >= 0; i--)
  {
    if (s[i] == '0')
    {
      countzero++;
    }
    else
    {
      break;
    }
  }
  s.erase(s.end() - countzero, s.end());
  return (s != "" ? s : "0");
}
int main()
{
  string s;
  cin >> s;
  if (s.back() == '%')
  {
    cout << reverse(s.substr(0, s.size() - 1)) << "%";
    return 0;
  }
  for (auto i : s)
  {
    if (i == '.')
    {
      cout << reverse(s.substr(0, s.find('.'))) << "." << reverse(s.substr(s.find('.') + 1));
      return 0;
    }
    if (i == '/')
    {
      cout << reverse(s.substr(0, s.find('/'))) << "/" << reverse(s.substr(s.find('/') + 1));
      return 0;
    }
  }
  cout << reverse(s) << endl;
  return 0;
}