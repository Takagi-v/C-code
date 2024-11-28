template <class elemType>
void selectSort(elemType a[], int n)
{
  int i, j, minIndex;
  elemType tmp;
  for (i = 0; i < n; i++)
  {
    minIndex = i;
    for (j = i + 1; j < n; j++)
    {
      if (a[j] < a[minIndex])
      {
        minIndex = j;
      }
    }
    if (minIndex == i)
      continue;
    tmp = a[i];
    a[i] = a[minIndex];
    a[minIndex] = tmp;
  }
}