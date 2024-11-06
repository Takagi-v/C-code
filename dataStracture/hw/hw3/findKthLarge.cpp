#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
  int val;
  Node *left, *right;
  Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node *buildTree(Node *root, int val)
{
  if (root == nullptr)
  {
    return new Node(val);
  }
  if (val < root->val)
  {
    root->left = buildTree(root->left, val);
  }
  else
  {
    root->right = buildTree(root->right, val);
  }
  return root;
}

void deleteTree(Node *root)
{
  if (root == nullptr)
  {
    return;
  }
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}
void reverseInorder(Node *node, int &k, int &result)
{
  if (node == nullptr)
    return;
  reverseInorder(node->right, k, result);
  if (--k == 0)
  {
    result = node->val;
    return;
  }
  reverseInorder(node->left, k, result);
}

int main()
{
  vector<int> values(7);
  for (int i = 0; i < 7; i++)
  {
    cin >> values[i];
  }
  int k;
  cin >> k;
  Node *root = nullptr;
  for (int val : values)
  {
    root = buildTree(root, val);
  }
  int result = -1;
  reverseInorder(root, k, result);
  cout << result << endl;
  deleteTree(root);
  return 0;
}
