#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int main()
{
  int n;
  cin >> n;
  priority_queue<long long, vector<long long>, greater<long long>> pq;
  unordered_set<long long> s;
  pq.push(1);
  s.insert(1);

  long long ugly;
  for (int i = 0; i < n; i++)
  {
    ugly = pq.top();
    pq.pop();
    long long next[] = {ugly * 2, ugly * 3, ugly * 5};
    for (int j = 0; j < 3; j++)
    {
      if (!s.count(next[j]))
      {
        pq.push(next[j]);
        s.insert(next[j]);
      }
    }
  }
  cout << ugly << endl;
}