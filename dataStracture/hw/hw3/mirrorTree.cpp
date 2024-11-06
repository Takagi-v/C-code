#include <iostream>
#include <vector>

using namespace std;

struct Node
{
  int val;
  Node *left, *right;
  Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node *buildTree(const vector<tuple<int, int, int>> &nodes)
{
  Node *nodeArray[10000] = {nullptr};
  Node *root = nullptr;

  for (const auto &node : nodes)
  {
    int a, b, c;
    tie(a, b, c) = node;

    if (nodeArray[a] == nullptr)
    {
      nodeArray[a] = new Node(a);
    }
    if (b != -1 && !nodeArray[b])
    {
      nodeArray[b] = new Node(b);
    }
    if (c != -1 && !nodeArray[c])
    {
      nodeArray[c] = new Node(c);
    }

    nodeArray[a]->left = (b == -1) ? nullptr : nodeArray[b];
    nodeArray[a]->right = (c == -1) ? nullptr : nodeArray[c];

    if (!root)
      root = nodeArray[a];
  }
  return root;
}

void postorderTraversal(Node *root, vector<int> &result)
{
  if (root)
  {
    postorderTraversal(root->right, result);
    postorderTraversal(root->left, result);
    result.push_back(root->val);
  }
}

int main()
{
  int n;
  cin >> n;
  vector<tuple<int, int, int>> nodes(n);
  for (int i = 0; i < n; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    nodes[i] = make_tuple(a, b, c);
  }

  Node *root = buildTree(nodes);
  vector<int> result;
  postorderTraversal(root, result);
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }
  return 0;
}