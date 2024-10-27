#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool is_valid_pop_sequence(int n, const vector<int> &pop_sequence)
{
  stack<int> s;
  int i = 1;
  for (int num : pop_sequence)
  {
    while (i <= n && (s.empty() || s.top() != num))
    {
      s.push(i++);
    }

    if (!s.empty() && s.top() == num)
    {
      s.pop();
    }
    else
    {
      return false;
    }
  }
  return true;
}

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;
    vector<int> pop_sequence(n);
    for (int i = 0; i < n; i++)
    {
      cin >> pop_sequence[i];
    }
    cout << (is_valid_pop_sequence(n, pop_sequence) ? "Yes" : "No") << endl;
  }
}