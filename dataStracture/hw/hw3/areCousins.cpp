#include <iostream>
#include <vector>

using namespace std;
const int MAXN = 1000;
int depth[MAXN];
int parent[MAXN];
bool exists[MAXN];

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

TreeNode *buildTree(const vector<int> &preorder, int &index, int curDepth, int curParent)
{
  if (index >= preorder.size() || preorder[index] == -1)
  {
    index++;
    return nullptr;
  }
  int nodeVal = preorder[index];
  if (nodeVal != -1)
  {
    exists[nodeVal] = true;
    depth[nodeVal] = curDepth;
    parent[nodeVal] = curParent;
  }

  TreeNode *node = new TreeNode(nodeVal);

  index++;
  node->left = buildTree(preorder, index, curDepth + 1, nodeVal);
  node->right = buildTree(preorder, index, curDepth + 1, nodeVal);

  return node;
}

bool areCounsins(TreeNode *root, int x, int y)
{
  if (!exists[x] || !exists[y])
  {
    return false;
  }
  return depth[x] == depth[y] && parent[x] != parent[y];
}
void deleteTree(TreeNode *root)
{
  if (root == nullptr)
  {
    return;
  }
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}
int main()
{
  int num;
  cin >> num;
  vector<pair<int, int>> queries(num);
  for (int i = 0; i < num; i++)
  {
    cin >> queries[i].first >> queries[i].second;
  }
  vector<int> preorder;
  int val;
  while (cin >> val)
  {
    preorder.push_back(val);
  }
  int index = 0;
  fill_n(exists, MAXN, false);
  TreeNode *root = buildTree(preorder, index, 0, -1);

  for (auto &query : queries)
  {
    cout << areCounsins(root, query.first, query.second) << endl;
  }
  deleteTree(root);
  return 0;
}