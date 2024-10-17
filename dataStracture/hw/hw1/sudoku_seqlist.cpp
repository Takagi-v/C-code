#include <iostream>
using namespace std;
class illegalSize
{
};
class outOfRange
{
};

template <class elemType>
class seqList
{
private:
  elemType *elem; // 存储元素的数组
  int maxSize;    // 数组的最大容量
  int len;        // 当前线性表的长度

  void doubleSpace(); // 扩展存储空间

public:
  seqList(int initSize = 10); // 构造函数
  ~seqList();                 // 析构函数

  elemType get(int i) const;             // 获取第i个元素
  int find(const elemType &x) const;     // 查找元素x的位置
  void insert(int i, const elemType &x); // 在第i个位置插入元素x
  void remove(int i);                    // 删除第i个位置的元素
  void clear() { len = 0; };
  int length() const { return len; }; // 获取线性表的长度
};

template <class elemType>
seqList<elemType>::seqList(int initSize)
{
  elem = new elemType[initSize];
  if (!elem)
    throw illegalSize();
  maxSize = initSize - 1;
  len = 0;
}

template <class elemType>
void seqList<elemType>::doubleSpace()
{
  elemType *tmp = elem;
  elem = new elemType[2 * (maxSize + 1)];
  for (int i = 0; i <= maxSize; ++i)
    elem[i] = tmp[i];
  maxSize = 2 * (maxSize + 1) - 1;
  delete[] tmp;
}

template <class elemType>
elemType seqList<elemType>::get(int i) const
{
  if (i < 0 || i >= len)
    throw outOfRange();
  return elem[i];
}

template <class elemType>
int seqList<elemType>::find(const elemType &x) const
{
  for (int i = 0; i < len; ++i)
    if (elem[i] == x)
      return i;
  return -1;
}

template <class elemType>
void seqList<elemType>::insert(int i, const elemType &x)
{
  if (i < 0 || i > len)
    throw outOfRange();
  if (len == maxSize + 1)
    doubleSpace();
  for (int j = len; j > i; --j)
    elem[j] = elem[j - 1];
  elem[i] = x;
  ++len;
}

template <class elemType>
void seqList<elemType>::remove(int i)
{
  if (i < 0 || i >= len)
    throw outOfRange();
  for (int j = i; j < len - 1; ++j)
    elem[j] = elem[j + 1];
  --len;
}
template <class elemType>
seqList<elemType>::~seqList()
{
  delete[] elem;
}
bool checkSudoku(int sudoku[9][9])
{
  seqList<int> rowCheck(9), colcheck(9), gridCheck(9);
  for (int i = 0; i < 9; i++)
  {
    rowCheck.clear();
    colcheck.clear();
    for (int j = 0; j < 9; j++)
    {
      if (rowCheck.find(sudoku[i][j]) != -1)
        return false;
      rowCheck.insert(rowCheck.length(), sudoku[i][j]);
      if (colcheck.find(sudoku[j][i]) != -1)
        return false;
      colcheck.insert(colcheck.length(), sudoku[j][i]);
    }
  }
  for (int block = 0; block < 9; block++)
  {
    gridCheck.clear();
    int rowOffset = (block / 3) * 3;
    int colOffset = (block % 3) * 3;
    for (int i = 0; i < 3; ++i)
    {
      for (int j = 0; j < 3; ++j)
      {
        int num = sudoku[rowOffset + i][colOffset + j];
        if (gridCheck.find(num) != -1)
          return false;
        gridCheck.insert(gridCheck.length(), num);
      }
    }
  }
  return true;
}
int main()
{
  int n;
  cin >> n;
  for (int k = 0; k < n; ++k)
  {
    int sudoku[9][9];
    for (int i = 0; i < 9; ++i)
      for (int j = 0; j < 9; ++j)
        cin >> sudoku[i][j];

    if (checkSudoku(sudoku))
      cout << "Right" << endl;
    else
      cout << "Wrong" << endl;
  }

  return 0;
}