template <class elemType>
void insertSort(elemType a[], int n, const elemType &x)
{
  for (int i = n - 1; i >= 0; i--)
  {
    if (a[i] <= x)
      break;
    else
      a[i + 1] = a[i];
  }
  a[i + 1] = x;
}
template <class elemType>
void insertSort(elemType a[], int n)
{
  elemType tmp;
  for (int i = 1; i < n; i++)
  {
    tmp = a[i];
    insertSort(a, i, tmp);
  }
}