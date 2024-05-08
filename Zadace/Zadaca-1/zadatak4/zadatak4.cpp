#include "../tests.hpp"
#include <iostream>

int sum(const int* array, int n)
{
  if (n <= 0) return 0;
  return array[0] + sum(array + 1, n - 1);
}

int main()
{
  Test::sum(sum);
  return 0;
}
