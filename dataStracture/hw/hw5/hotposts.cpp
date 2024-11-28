#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Post
{
  int views;
  int id;
  int day;
  bool operator<(const Post &other) const
  {
    if (views != other.views)
      return views < other.views;
    return id < other.id;
  }
};

vector<int> getHotPosts(int T, int D, int P, vector<vector<int>> &views)
{
  vector<int> result;
  priority_queue<Post> pq;

  for (int i = 0; i < D; i++)
  {
    for (int j = 0; j < P; j++)
    {
      pq.push({views[i][j], j, i});
    }
    while (!pq.empty() && pq.top().day < max(0, i - T + 1))
    {
      pq.pop();
    }
    result.push_back(pq.top().id + 1);
  }
  return result;
}
int main()
{
  int T, D, P;
  cin >> T >> D >> P;
  vector<vector<int>> views(D, vector<int>(P));
  for (int i = 0; i < D; i++)
  {
    for (int j = 0; j < P; j++)
    {
      cin >> views[i][j];
    }
  }
  vector<int> result = getHotPosts(T, D, P, views);
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }
  return 0;
}