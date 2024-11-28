template <class elemType>
void bubbleSort(elemType a[], int n)
{
  elemType tmp;
  bool changeFlag = true;
  for (int j = n - 1; j > 0; j--)
  {
    if (!changeFlag)
      break;
    changeFlag = false;
    for (int i = 0; i < j; i++)
    {
      if (a[i] > a[i + 1])
      {
        tmp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = tmp;
        changeFlag = true;
      }
    }
  }
}