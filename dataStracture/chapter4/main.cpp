#include <iostream>
#include "priotiry_queue.h"
using namespace std;

int main()
{
  try
  {
    // 测试默认构造函数
    cout << "测试1: 默认构造函数和基本操作" << endl;
    priorityQueue<int> pq1;

    // 测试enQueue
    cout << "插入元素: 5, 2, 8, 1, 9" << endl;
    pq1.enQueue(5);
    pq1.enQueue(2);
    pq1.enQueue(8);
    pq1.enQueue(1);
    pq1.enQueue(9);

    // 测试front和deQueue
    cout << "依次取出元素: ";
    while (!pq1.isEmpty())
    {
      cout << pq1.front() << " ";
      pq1.deQueue();
    }
    cout << endl
         << endl;

    // 测试用数组构造
    cout << "测试2: 用数组构造优先队列" << endl;
    int arr[] = {6, 4, 7, 1, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    priorityQueue<int> pq2(arr, size);

    cout << "依次取出元素: ";
    while (!pq2.isEmpty())
    {
      cout << pq2.front() << " ";
      pq2.deQueue();
    }
    cout << endl
         << endl;

    // 测试doubleSpace
    cout << "测试3: 测试自动扩容" << endl;
    priorityQueue<int> pq3(3); // 初始大小为3

    cout << "插入5个元素测试自动扩容: ";
    for (int i = 1; i <= 5; i++)
    {
      pq3.enQueue(i);
      cout << i << " ";
    }
    cout << endl;

    cout << "依次取出元素: ";
    while (!pq3.isEmpty())
    {
      cout << pq3.front() << " ";
      pq3.deQueue();
    }
    cout << endl;
  }
  catch (illegalSize)
  {
    cout << "错误：非法的大小" << endl;
  }
  catch (outOfBound)
  {
    cout << "错误：下标越界" << endl;
  }

  return 0;
}