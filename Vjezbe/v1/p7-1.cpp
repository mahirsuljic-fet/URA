#include <iostream>

bool odd(int n)
{
  return n & 1;
}

int half(int n)
{
  return n >> 1;
}

int fast_multiply(int n, int a)
{
  if (a == 1) return n;
  auto rez = fast_multiply(n << 1, half(a));
  if (odd(a)) rez += n;
  return rez;
}

int main()
{
  std::cout << "5 * 5 = " << fast_multiply(5, 5) << std::endl;
  std::cout << "5 * 11 = " << fast_multiply(5, 11) << std::endl;

  return 0;
}
