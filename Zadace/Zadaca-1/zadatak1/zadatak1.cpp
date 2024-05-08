#include "../tests.hpp"
#include <functional>
#include <iostream>
#include <stdexcept>

int divide(int a, int b)
{
  if (b == 0) throw std::out_of_range("Dijeljenje s nulom nije dozvoljeno!");
  if (abs(a) < abs(b)) return 0;
  if (a > 0 && b > 0) return 1 + divide(a - b, b);
  if (a < 0 && b < 0) return 1 + divide(-a + b, -b);
  if (a > 0 && b < 0) return -1 - divide(a + b, -b);
  // if (a < 0 && b > 0)
  return -1 - divide(-a - b, b);
}

int main()
{
  Test::divide(divide);
  return 0;
}
