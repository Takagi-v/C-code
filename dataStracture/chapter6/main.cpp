#include <iostream>
using namespace std;

class illegalSize
{
};

template <class elemType>
class staticSearch
{
private:
  elemType *data;
  int len;

public:
  staticSearch(elemType a[], int n);
  ~staticSearch() { delete[] data; }
  int BSearch(const elemType &x) const;
};
template <class elemType>
staticSearch<elemType>::staticSearch(elemType a[], int n)
{
  if (n <= 0)
    throw illegalSize();
  data = new elemType[n + 1];
  if (data == NULL)
    throw illegalSize();
  for (int i = 1; i < n + 1; i++)
    data[i] = a[i - 1];
  len = n;
}
template <class elemType>
int staticSearch<elemType>::BSearch(const elemType &x) const
{
  int mid, low = 0, high = length;
  while (low <= high)
  {
    mid = (low + high) / 2;
    if (x == data[mid])
      break;
    else if (x < data[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }
  if (low <= high)
    return mid;
  return 0;
}

int main()
{
  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int pos, x;
  staticSearch<int> s(a, 10);
  cout << "Enter the number to search: ";
  cin >> x;
  pos = s.BSearch(x);
  if (pos == 0)
    cout << "The number is not in the array." << endl;
  else
    cout << "The number is at position " << pos << endl;
  return 0;
}