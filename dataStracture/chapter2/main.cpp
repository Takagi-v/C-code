#include <iostream>
#include "seqList.h"
#include "linkList.h"
using namespace std;

// 测试顺序表的函数模板
template <class List>
void testSeqList(string listName)
{
  cout << "\n测试" << listName << "开始..." << endl;
  List list;

  try
  {
    // 测试插入操作
    cout << "测试插入操作..." << endl;
    for (int i = 0; i < 5; i++)
    {
      list.insert(i, i * 10);
    }

    // 测试获取长度
    cout << "长度为: " << list.length() << endl;

    // 测试获取元素
    cout << "获取元素测试..." << endl;
    for (int i = 0; i < list.length(); i++)
    {
      cout << "位置 " << i << " 的元素为: " << list.get(i) << endl;
    }

    // 测试查找操作
    cout << "查找元素20的位置: " << list.find(20) << endl;
    cout << "查找不存在元素25的位置: " << list.find(25) << endl;

    // 测试删除操作
    cout << "删除位置2的元素..." << endl;
    list.remove(2);
    cout << "删除后长度为: " << list.length() << endl;

    // 测试边界情况
    cout << "测试边界情况..." << endl;
    try
    {
      list.get(-1);
    }
    catch (...)
    {
      cout << "成功捕获负数索引异常" << endl;
    }

    try
    {
      list.get(list.length());
    }
    catch (...)
    {
      cout << "成功捕获越界索引异常" << endl;
    }

    // 测试大量数据（测试扩容）
    cout << "测试大量数据插入..." << endl;
    for (int i = 0; i < 100; i++)
    {
      list.insert(list.length(), i);
    }
    cout << "大量插入后长度为: " << list.length() << endl;
  }
  catch (const exception &e)
  {
    cout << "测试过程中发生异常: " << e.what() << endl;
  }

  cout << listName << "测试完成" << endl;
}

// 测试链表的函数模板
template <class List>
void testLinkList(string listName)
{
  cout << "\n测试" << listName << "开始..." << endl;
  List list;

  try
  {
    // 测试插入操作
    cout << "测试插入操作..." << endl;
    for (int i = 1; i <= 5; i++)
    {
      list.insert(i, i * 10);
    }

    // 测试获取长度
    cout << "长度为: " << list.length() << endl;

    // 测试获取元素
    cout << "获取元素测试..." << endl;
    for (int i = 1; i <= list.length(); i++)
    {
      cout << "位置 " << i << " 的元素为: " << list.get(i) << endl;
    }

    // 测试查找操作
    cout << "查找元素20的位置: " << list.find(20) << endl;
    cout << "查找不存在元素25的位置: " << list.find(25) << endl;

    // 测试删除操作
    cout << "删除位置2的元素..." << endl;
    int removed;
    list.remove(2, removed);
    cout << "删除的元素为: " << removed << endl;
    cout << "删除后长度为: " << list.length() << endl;

    // 测试边界情况
    cout << "测试边界情况..." << endl;
    try
    {
      list.get(-1);
    }
    catch (...)
    {
      cout << "成功捕获负数索引异常" << endl;
    }

    try
    {
      list.get(list.length() + 1);
    }
    catch (...)
    {
      cout << "成功捕获越界索引异常" << endl;
    }
  }
  catch (...)
  {
    cout << "测试过程中发生异常" << endl;
  }

  cout << listName << "测试完成" << endl;
}

// 链表特有功能测试
void testLinkListSpecific()
{
  cout << "\n测试链表特有功能..." << endl;
  linkList<int> list;

  // 测试reverse功能
  cout << "测试reverse功能..." << endl;
  for (int i = 1; i <= 5; i++)
  {
    list.insert(1, i); // 插入到头部，形成5,4,3,2,1
  }

  cout << "反转前: ";
  for (int i = 1; i <= list.length(); i++)
  {
    cout << list.get(i) << " ";
  }
  cout << endl;

  list.reverse();

  cout << "反转后: ";
  for (int i = 1; i <= list.length(); i++)
  {
    cout << list.get(i) << " ";
  }
  cout << endl;
}

int main()
{
  cout << "开始测试..." << endl;

  // 测试顺序表
  testSeqList<seqList<int>>("顺序表");

  // 测试链表
  testLinkList<linkList<int>>("链表");

  // 测试链表特有功能
  testLinkListSpecific();

  cout << "\n所有测试完成!" << endl;
  return 0;
}