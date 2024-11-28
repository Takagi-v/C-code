template <class elemType>
void heapSort(elemType a[], int n)
{
  int i, j;
  elemType tmp;
  for (i = (n - 1) / 2; i >= 0; i--)
  {
    adjust(a, n, i);
  }
  for (j = n - 1; j > 0; j--)
  {
    tmp = a[0];
    a[0] = a[j];
    a[j] = tmp;
    adjust(a, j, 0);
  }
}
template <class elemType>
void adjust(elemType a[], int n, int i)
{
  int maxChild;
  elemType tmp;
  while (true)
  {
    maxChild = 2 * i + 1;
    if (maxChild >= n)
      return;
    if (maxChild + 1 < n && a[maxChild + 1] > a[maxChild])
      maxChild++;
    if (a[i] >= a[maxChild])
      return;
    tmp = a[i];
    a[i] = a[maxChild];
    a[maxChild] = tmp;
    i = maxChild;
  }
}