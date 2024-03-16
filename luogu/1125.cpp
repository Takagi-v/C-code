#include <iostream>
#include <string>
using namespace std;
bool is_prime(int n)
{
  if (n == 0)
  {
    return false;
  }
  if (n == 1)
    return false;
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
      return false;
  }
  return true;
}
int main()
{
  string s;
  cin >> s;
  int n[26] = {0};
  for (char i : s)
  {
    n[i - 'a']++;
  }
  int maxx = 0, minn = 100;
  for (int i = 0; i < 26; i++)
  {
    if (n[i] > maxx)
      maxx = n[i];
    if (n[i] < minn && n[i] != 0)
      minn = n[i];
  }
  if (is_prime(maxx - minn))
    cout << "Lucky Word" << endl
         << maxx - minn << endl;
  else
    cout << "No Answer" << endl
         << 0 << endl;
}