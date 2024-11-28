#include <iostream>
#include <vector>
using namespace std;
class UnionFind
{
private:
  vector<int> parent;
  vector<int> sum;

public:
  UnionFind(int n)
  {
    parent.resize(n);
    sum.resize(n, 0);
    for (int i = 0; i < n; i++)
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
      parent[rootx] = rooty;
      sum[rooty] += sum[rootx];
    }
  }
  int getSum(int x)
  {
    return sum[find(x)];
  }
  void setSum(int x, int val)
  {
    sum[x] = val;
  }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int m, n;
  cin >> m >> n;
  vector<vector<int>> lake(m, vector<int>(n));
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> lake[i][j];
    }
  }
  UnionFind uf(m * n);
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int idx = i * n + j;
      uf.setSum(idx, lake[i][j]);
    }
  }
  const int dx[2] = {0, 1};
  const int dy[2] = {1, 0};
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (lake[i][j] == 0)
        continue;
      int idx = i * n + j;
      for (int k = 0; k < 2; k++)
      {
        int ni = i + dx[k];
        int nj = j + dy[k];

        if (ni < m && nj < n && lake[ni][nj] > 0)
        {
          int nidx = ni * n + nj;
          uf.unite(idx, nidx);
        }
      }
    }
  }
  int maxF = 0;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (lake[i][j] > 0)
      {
        int idx = i * n + j;
        if (uf.find(idx) == idx)
        {
          maxF = max(maxF, uf.getSum(idx));
        }
      }
    }
  }
  cout << maxF;
}