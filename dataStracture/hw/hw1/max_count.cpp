#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int a[10000];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  unordered_map<int, int> freq_map;
  for (int i = 0; i < n; i++)
  {
    freq_map[a[i]]++;
  }
  int max_count = 0;
  for (auto it = freq_map.begin(); it != freq_map.end(); it++)
  {
    if (it->second > max_count)
    {
      max_count = it->second;
    }
  }
  cout << max_count << endl;
}