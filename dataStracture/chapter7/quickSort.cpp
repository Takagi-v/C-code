template <class elemType>
void quickSort(elemType a[], int start, int end)
{
  int i, j, hole;
  elemType tmp;
  if (end <= start)
    return;
  tmp = a[start];
  hole = start;
  i = start;
  j = end;
  while (i < j)
  {
    while ((j > i) && (a[j]) >= tmp)
      j--;
    if (j == i)
      break;
    a[hole] = a[j];
    hole = j;
    while ((i < j) && (a[i] < tmp))
      i++;
    if (j == i)
      break;
    a[hole] = a[i];
    hole = i;
  }
  a[hole] = tmp;
  quickSort(a, start, hole - 1);
  quickSort(a, hole + 1, end);
}