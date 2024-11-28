template <class elemType>
void merge(elemType a[], int low, int mid, int high)
{
  int i, j, k;
  elemType *c;

  c = new elemType[high - low + 1];
  i = low;
  j = mid + 1;
  k = 0;
  while ((i <= mid) && (j <= high))
  {
    if (a[i] < a[j])
    {
      c[k] = a[i];
      i = i + 1;
    }
    else
    {
      c[k] = a[j];
      j = j + 1;
    }
    k = k + 1;
  }
  while (i <= mid)
  {
    c[k] = a[i];
    k = k + 1;
    i = i + 1;
  }
  while (j <= high)
  {
    c[k] = a[j];
    k = k + 1;
    j = j + 1;
  }
  for (i = 0; i < high - low + 1; i++)
  {
    a[i + low] = c[i];
  }
  delete[] c;
}

template <class elemType>
void mergeSort(elemType a[], int low, int high)
{
  int mid;
  if (low >= high)
    return;
  mid = (low + high) / 2;
  mergeSort(a, low, mid);
  mergeSort(a, mid + 1, high);
  merge(a, low, mid, high);
}