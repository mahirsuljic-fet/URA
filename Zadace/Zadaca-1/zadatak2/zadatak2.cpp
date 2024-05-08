#include "../tests.hpp"
#include <cstdlib>
#include <functional>
#include <iostream>

int fast_divide(int a, int b)
{
  if (b == 0) throw std::out_of_range("Dijeljenje s nulom nije dozvoljeno!");
  if (abs(a) < abs(b)) return 0;

  int pow_two = 1;
  int val = abs(b);

  while (val << 1 < abs(a))
  {
    val <<= 1;
    pow_two <<= 1;
  }

  if (a > 0 && b > 0) return pow_two + fast_divide(a - val, b);
  if (a < 0 && b < 0) return pow_two + fast_divide(-a - val, -b);
  if (a > 0 && b < 0) return -pow_two - fast_divide(a - val, -b);
  // if (a < 0 && b > 0)
  return -pow_two - fast_divide(-a - val, b);
}

int main()
{
  Test::divide(fast_divide);
  return 0;
}
