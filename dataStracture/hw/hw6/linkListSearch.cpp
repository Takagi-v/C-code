#include <iostream>
using namespace std;
struct Node
{
  int data;
  Node *next;
  Node(int x) : data(x), next(nullptr) {}
};

class LinkedList
{
private:
  Node *head;
  int compareCount;

public:
  LinkedList() : head(nullptr), compareCount(0) {}

  void append(int data)
  {
    Node *newNode = new Node(data);
    if (!head)
    {
      head = newNode;
      return;
    }
    Node *current = head;
    while (current->next)
    {
      current = current->next;
    }
    current->next = newNode;
  }
  void search(int target)
  {
    if (!head)
      return;
    compareCount++;

    if (head->data == target)
    {
      return;
    }
    Node *prev = head;
    Node *current = head->next;
    while (current)
    {
      compareCount++;
      if (current->data == target)
      {
        prev->next = current->next;
        current->next = head;
        head = current;
        return;
      }
      prev = current;
      current = current->next;
    }
  }
  int getCompareCount() const
  {
    return compareCount;
  }
  ~LinkedList()
  {
    Node *current = head, *next;
    while (current)
    {
      next = current->next;
      delete current;
      current = next;
    }
  }
};

int main()
{
  int n, m, x, y;
  cin >> n;
  LinkedList lst;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    lst.append(x);
  }
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    int target;
    cin >> target;
    lst.search(target);
  }
  cout << lst.getCompareCount() << endl;
  return 0;
}