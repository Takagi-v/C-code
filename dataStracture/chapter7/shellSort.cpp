template <class elemType>
void shellSort(elemType a[], int n)
{
  elemType tmp;
  int j;
  for (int step = n / 2; step > 0; step /= 2)
  {
    for (int i = step; i < n; i++)
    {
      tmp = a[i];
      j = i;
      while ((j - step) >= 0 && a[j - step] > tmp)
      {
        a[j] = a[j - step];
        j -= step;
      }
      a[j] = tmp;
    }
  }
}