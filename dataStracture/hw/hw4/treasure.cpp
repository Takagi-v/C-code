#include <iostream>
#include <vector>

using namespace std;
int calculateDepth(const vector<int> &preorder, int &index)
{
  if (index >= preorder.size() || preorder[index] == -1)
  {
    index++; 
    return 0;
  }

  index++;
  int leftDepth = calculateDepth(preorder, index);
  int rightDepth = calculateDepth(preorder, index);

  return 1 + max(leftDepth, rightDepth);
}

int main()
{
  vector<int> preorder;
  int val;
  while (cin >> val)
  {
    preorder.push_back(val);
  }
  int index = 0;
  int depth = calculateDepth(preorder, index);
  cout << depth << endl;
}