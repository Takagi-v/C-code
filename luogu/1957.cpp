#include <iostream>
#include <string>
using namespace std;

int main()
{
  int n;
  char m;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    string s, ans;
    int n1, n2;
    cin >> s;
    if (s[0] <= 'z' && s[0] >= 'a')
    {
      m = s[0];
      cin >> n1 >> n2;
    }
    else
    {
      n1 = stod(s);
      cin >> n2;
    }
    if (m == 'a')
    {
      cout << n1 << '+' << n2 << '=' << n1 + n2 << endl;
      ans = ans + to_string(n1) + '+' + to_string(n2) + '=' + to_string(n1 + n2);
      cout << ans.length() << endl;
    }
    if (m == 'b')
    {
      cout << n1 << '-' << n2 << '=' << n1 - n2 << endl;
      ans = ans + to_string(n1) + '-' + to_string(n2) + '=' + to_string(n1 - n2);
      cout << ans.length() << endl;
    }
    if (m == 'c')
    {
      cout << n1 << '*' << n2 << '=' << n1 * n2 << endl;
      ans = ans + to_string(n1) + '*' + to_string(n2) + '=' + to_string(n1 * n2);
      cout << ans.length() << endl;
    }
  }
}