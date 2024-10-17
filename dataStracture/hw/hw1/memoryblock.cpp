#include <iostream>
using namespace std;

class MemoryBlock
{
public:
  int start;
  int size;
  MemoryBlock *next;
  MemoryBlock(int start, int size) : start(start), size(size) {}
};

class FreeList
{
public:
  MemoryBlock *head;
  FreeList() : head(nullptr) {}

  void init(int start_list[], int size_list[], int n)
  {
    for (int i = 0; i < n; i++)
    {
      insert_block(start_list[i], size_list[i]);
    }
  }
  void insert_block(int start, int size)
  {
    MemoryBlock *tmp = new MemoryBlock(start, size);
    if (!head || head->start > start)
    {
      tmp->next = head;
      head = tmp;
    }
    else
    {
      MemoryBlock *current = head;
      while (current->next && current->next->start < start)
      {
        current = current->next;
      }
      tmp->next = current->next;
      current->next = tmp;
    }
  }

  int allocate(int request_size)
  {
    MemoryBlock *current = head;
    MemoryBlock *prev = nullptr;

    while (current)
    {
      if (current->size >= request_size)
      {
        int allo_start = current->start;
        current->start += request_size;
        current->size -= request_size;
        if (current->size == 0)
        {
          if (prev)
          {
            prev->next = current->next;
          }
          else
          {
            head = current->next;
          }
          delete current;
        }
        return allo_start;
      }
      prev = current;
      current = current->next;
    }
    return -1;
  }

  void release(int start, int size)
  {
    insert_block(start, size);
    MemoryBlock *current = head;
    while (current && current->next)
    {
      if (current->start + current->size == current->next->start)
      {
        current->size += current->next->size;
        MemoryBlock *tmp = current->next;
        current->next = current->next->next;
        delete tmp;
      }
      else
      {
        current = current->next;
      }
    }
  }
  void print_list()
  {
    MemoryBlock *current = head;
    while (current)
    {
      cout << "(" << current->start << "," << current->size << ") ";
      current = current->next;
    }
  }
};

int main()
{
  int n;
  cin >> n;
  int start_list[1000], size_list[1000];

  for (int i = 0; i < n; i++)
  {
    cin >> start_list[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> size_list[i];
  }
  FreeList free_list;
  free_list.init(start_list, size_list, n);

  int m;
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    int op;
    cin >> op;
    if (op == 1)
    {
      int request_size;
      cin >> request_size;
      int result = free_list.allocate(request_size);
    }
    else if (op == 2)
    {
      int start, size;
      cin >> start >> size;
      free_list.release(start, size);
    }
  }
  free_list.print_list();
  return 0;
}