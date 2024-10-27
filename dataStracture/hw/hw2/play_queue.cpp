#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;

  vector<pair<long long, int>> rounds;

  for (int i = 0; i < n; i++)
  {
    long long t;
    cin >> t;
    long long required_rounds = (t + k - 1) / k;
    rounds.push_back({required_rounds, i});
  }

  sort(rounds.begin(), rounds.end());

  for (const auto &p : rounds)
  {
    cout << p.second << " ";
  }
  cout << endl;

  return 0;
}
