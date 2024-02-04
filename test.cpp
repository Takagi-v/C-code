// This code performs a calculation based on the input values.
// It takes two integers as input and returns their sum.
// The function name is "calculateSum".
// Example usage: int result = calculateSum(5, 3);
#include <iostream>
int calculateSum(int a, int b)
{
  return a + b;
}
int main()
{
  int a = 1;
  int *b = &a;
  std::cout << *b;
}