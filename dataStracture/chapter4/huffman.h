template <class elemType>
struct HuffmanNode
{
  elemType data;
  double weight;
  int parent, leftChild, rightChild;
};
template <class elemType>
int minIndex(HuffmanNode<elemType> Bt[], int k, int m)
{
  int i, min = -1;
  double minWeight = 9999;
  for (i = m - 1; i > k; i--)
  {
    if ((Bt[i].parent == 0) && (Bt[i].weight < minWeight))
    {
      minWeight = Bt[i].weight;
      min = i;
    }
  }
  if (min == -1)
    return k;
  return min;
}

template <class elemType>
HuffmanNode<elemType> *BestBinaryTree(elemType a[], double w[], int n)
{
  HuffmanNode<elemType> *BBTree;
  int first_min, second_min;
  int m = 2 * n;
  int i;
  BBTree = new HuffmanNode<elemType>[m];
  for (int j = 0; j < n; j++)
  {
    i = m - 1 - j;
    BBTree[i].data = a[j];
    BBTree[i].weight = w[j];
    BBTree[i].parent = 0;
    BBTree[i].leftChild = 0;
    BBTree[i].rightChild = 0;
  }
  i = n - 1;
  while (i != 0)
  {
    first_min = minIndex(BBTree, i, m);
    BBTree[first_min].parent = i;
    second_min = minIndex(BBTree, i, m);
    BBTree[second_min].parent = i;
    BBTree[i].weight = BBTree[first_min].weight + BBTree[second_min].weight;
    BBTree[i].leftChild = first_min;
    BBTree[i].rightChild = second_min;
    BBTree[i].parent = 0;
    i--;
  }
  return BBTree;
}

template <class elemType>
char **HuffmanCode(HuffmanNode<elemType> BBTree[], int n)
{
  seqStack<int> stack;
  char **HFCode;
  int m = 2 * n;
  int i, j, child;
  HFCode = new char *[n];
  for (i = 0; i < n; i++)
    HFCode[i] = new char[n + 1];
  if (n == 0)
    return HFCode;
  if (n == 1)
  {
    HFCode[0][0] = '0', HFCode[0][1] = '\0';
    return HFCode;
  }
  for (i = m - 1; i >= n; i--)
  {
    child = i;
    while (BBTree[child].parent != 0)
    {
      stack.push(BBTree[child].parent - child);
      child = BBTree[child].parent;
    }
    j = 0;
    while (!stack.isEmpty())
    {
      HFCode[m - i - 1][j] = (stack.top() == 0) ? '0' : '1';
      stack.pop();
      j++;
    }
    HFCode[m - i - 1][j] = '\0';
  }
  return HFCode;
}

template <class elemType>
void deleteHuffmanTree(HuffmanNode<elemType> *tree, int n)
{
  if (tree != nullptr)
  {
    delete[] tree;
  }
}

template <class elemType>
void deleteHuffmanCode(char **HFCode, int n)
{
  if (HFCode != nullptr)
  {
    for (int i = 0; i < n; i++)
    {
      delete[] HFCode[i];
    }
    delete[] HFCode;
  }
}