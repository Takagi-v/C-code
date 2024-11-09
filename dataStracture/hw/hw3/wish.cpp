#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UnionFind
{
public:
  vector<int> parent, size;
  UnionFind(int n)
  {
    parent.resize(n + 1);
    size.resize(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
      parent[i] = i;
    }
  }
  int find(int x)
  {
    if (parent[x] != x)
    {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }
  void unite(int x, int y)
  {
    int rootx = find(x);
    int rooty = find(y);
    if (rootx != rooty)
    {
      if (size[rootx] < size[rooty])
      {
        swap(rootx, rooty);
      }
      parent[rooty] = rootx;
      size[rootx] += size[rooty];
    }
  }
  int getSize(int x)
  {
    return size[find(x)];
  }
};

int main()
{
  int n, m, a, b;
  cin >> n >> m;
  UnionFind u(n);
  for (int i = 0; i < m; i++)
  {
    cin >> a >> b;
    u.unite(a, b);
  }
  int maxSize = 0;
  for (int i = 1; i <= n; i++)
  {
    if (u.find(i) == i)
    {
      maxSize = max(maxSize, u.getSize(i));
    }
  }
  cout << maxSize << endl;
  return 0;
}