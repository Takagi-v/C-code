#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node
{
  long long freq;
  Node *left, *right;
  Node(long long f) : freq(f), left(NULL), right(NULL) {}
};
struct CompareNodes
{
  bool operator()(Node *a, Node *b)
  {
    return a->freq > b->freq;
  }
};

class HuffmanTree
{
private:
  long long calculateWPL(Node *root, int depth)
  {
    if (!root)
      return 0;
    if (!root->left && !root->right)
      return root->freq * depth;
    return calculateWPL(root->left, depth + 1) + calculateWPL(root->right, depth + 1);
  }

public:
  long long build(vector<int> &frequency)
  {
    priority_queue<Node *, vector<Node *>, CompareNodes> pq;

    for (int freq : frequency)
    {
      pq.push(new Node(freq));
    }
    while (pq.size() > 1)
    {
      Node *left = pq.top();
      pq.pop();
      Node *right = pq.top();
      pq.pop();
      Node *parent = new Node(left->freq + right->freq);
      parent->left = left;
      parent->right = right;
      pq.push(parent);
    }
    Node *root = pq.top();
    return calculateWPL(root, 0);
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> frequency(n);
  for (int i = 0; i < n; i++)
  {
    cin >> frequency[i];
  }
  HuffmanTree huffmanTree;
  cout << huffmanTree.build(frequency) << endl;
  return 0;
}