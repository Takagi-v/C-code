#include <iostream>
#include <string>
#include <vector>
using namespace std;
string multiply(string num1, string num2)
{
  int n = num1.size(), m = num2.size();
  vector<int> pos(n + m, 0);

  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = m - 1; j >= 0; j--)
    {
      int mul = (num1[i] - 'a') * (num2[j] - 'a');
      int sum = mul + pos[i + j + 1];
      pos[i + j + 1] = sum % 26;
      pos[i + j] += sum / 26;
    }
  }
  string result;
  for (int i : pos)
  {
    if (!(result.empty() && i == 0))
    {
      result.push_back((char)'a' + i);
    }
  }
  return result;
}
int main()
{
  string num1, num2;
  getline(cin, num1);
  getline(cin, num2);
  string result = multiply(num1, num2);
  cout << result;
  return 0;
}