#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class UnionFind
{
public:
  vector<int> parent;
  vector<int> rank;

  UnionFind(int size)
  {
    parent.resize(size);
    rank.resize(size);
    for (int i = 0; i < size; i++)
    {
      parent[i] = i;
    }
  }

  int find(int p)
  {
    if (parent[p] != p)
    {
      parent[p] = find(parent[p]);
    }
    return parent[p];
  }

  void unionSet(int p, int q)
  {
    int rootP = find(p);
    int rootQ = find(q);
    if (rootP != rootQ)
    {
      if (rank[rootP] > rank[rootQ])
      {
        parent[rootQ] = rootP;
      }
      else if (rank[rootP] < rank[rootQ])
      {
        parent[rootP] = rootQ;
      }
      else
      {
        parent[rootQ] = rootP;
        rank[rootP]++;
      }
    }
  }
};

bool isConnect(int x1, int y1, int x2, int y2, int r)
{
  int dx = abs(x1 - x2);
  int dy = abs(y1 - y2);
  return dx * dx + dy * dy <= 4 * r * r;
}

int main()
{
  int n, r, w;
  cin >> n >> r >> w;
  vector<pair<int, int>> lilies(n);
  for (int i = 0; i < n; i++)
  {
    cin >> lilies[i].first >> lilies[i].second;
  }
  UnionFind uf(n + 2);
  int startNode = n;
  int endNode = n + 1;
  for (int i = 0; i < n; i++)
  {
    int x = lilies[i].first;
    int y = lilies[i].second;
    if (y <= r)
      uf.unionSet(i, startNode);
    if (y >= w - r)
      uf.unionSet(i, endNode);
    for (int j = i + 1; j < n; j++)
    {
      int x2 = lilies[j].first;
      int y2 = lilies[j].second;
      if (isConnect(x, y, x2, y2, r))
        uf.unionSet(i, j);
    }
  }
  if (uf.find(startNode) == uf.find(endNode))
    cout << "1" << endl;
  else
    cout << "0" << endl;
}
