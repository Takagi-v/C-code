template <class elemType>
struct Node
{
  elemType data;
  Node *next;
};

template <class elemType>
struct pocketList
{
  Node<elemType> *front;
  Node<elemType> *rear;
};

template <class elemType>
void pocketSort(elemType a[], int n)
{
  Node<elemType> *collectHead, *collectRear, *tmp;
  pocketList<elemType> list[10];
  elemType max;
  int i, j, k, count = 0; // count为最大值位数
  int base = 1;

  max = a[0];
  for (i = 0; i < n; i++)
    if (max < a[i])
      max = a[i];

  while (max != 0)
  {
    count++;
    max /= 10;
  }

  collectHead = collectRear = NULL;
  for (i = 0; i < n; i++)
  {
    tmp = new Node<elemType>;
    tmp->data = a[i];
    tmp->next = NULL;
    if (!collectHead)
    {
      collectHead = tmp;
      collectRear = tmp;
    }
    else
    {
      collectRear->next = tmp;
      collectRear = tmp;
    }
  }

  for (j = 0; j < count; j++)
  {
    for (i = 0; i < 10; i++)
      list[i].front = list[i].rear = NULL;
    while (collectHead)
    {
      k = collectHead->data;
      k = k / base % 10;
      if (!list[k].front)
      {
        list[k].front = collectHead;
        list[k].rear = collectHead;
      }
      else
      {
        list[k].rear->next = collectHead;
        list[k].rear = collectHead;
      }
      collectHead = collectHead->next;
    }
    collectHead = collectRear = NULL;
    k = 0 while (k < 10)
    {
      if (!list[k].front)
      {
        k++;
        continue;
      }
      if (!collectHead)
      {
        collectHead = list[k].front;
        collectRear = list[k].rear;
      }
      else
      {
        collectRear->next = list[k].front;
        collectRear = list[k].rear;
      }
      k++;
    }
    collectRear->next = NULL;
    base *= 10;
  }

  for (i = 0; i < n; i++)
  {
    a[i] = collectHead->data;
    collectHead = collectHead->next;
  }
}
