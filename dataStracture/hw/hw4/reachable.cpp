#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100005;
const int MAXV = 100005;

vector<int> graph[MAXN];
int valueToNode[MAXN]; // 节点值到节点编号
int nodeToValue[MAXN]; // 节点编号到节点值
bool visited[MAXN];    // 记录访问过的节点

bool dfs(int start, int target)
{
  if (visited[start])
    return false;
  if (start == target)
    return true;

  visited[start] = true;
  for (int next : graph[start])
  {
    if (dfs(next, target))
      return true;
  }
  return false;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  fill(valueToNode, valueToNode + MAXN, -1);

  int n;
  cin >> n;
  int nodeCount = 0;
  for (int i = 0; i < n; i++)
  {
    int k;
    cin >> k;
    int treeSize = (1 << k) - 1;
    vector<int> tree(treeSize);
    for (int j = 0; j < treeSize; j++)
    {
      cin >> tree[j];
      valueToNode[tree[j]] = nodeCount + j;
      nodeToValue[nodeCount + j] = tree[j];
    }
    for (int j = 0; j < treeSize; j++)
    {
      if (2 * j + 1 < treeSize)
        graph[nodeCount + j].push_back(nodeCount + 2 * j + 1);
      if (2 * j + 2 < treeSize)
        graph[nodeCount + j].push_back(nodeCount + 2 * j + 2);
    }
    nodeCount += treeSize;
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    int x, y;
    cin >> x >> y;
    graph[valueToNode[x]].push_back(valueToNode[y]);
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    int query;
    cin >> query;
    fill(visited, visited + MAXN, false);

    if (valueToNode[query] == -1)
    {
      cout << "No\n";
      continue;
    }

    bool result = dfs(0, valueToNode[query]);
    cout << (result ? "Yes" : "No") << "\n";
  }
  return 0;
}