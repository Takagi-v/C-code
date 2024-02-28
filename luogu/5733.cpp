#include <iostream>
#include <string>
using namespace std;
int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (char a : s)
  {
    if (a >= 'a' && a <= 'z')
      if (a + n > 'z')
        cout << (char)(a + n - 26);
      else
        cout << (char)(a + n);
  }
}