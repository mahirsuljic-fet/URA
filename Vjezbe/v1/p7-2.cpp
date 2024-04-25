#include <iostream>

bool odd(int n)
{
  return n & 1;
}

int half(int n)
{
  return n >> 1;
}

int pow(int n, int a)
{
  if (a == 1) return n;
  auto rez = pow(n * n, half(a));
  if (odd(a)) rez *= n;
  return rez;
}

int main()
{
  std::cout << "2^3 = " << pow(2, 3) << std::endl;
  std::cout << "2^5 = " << pow(2, 5) << std::endl;

  return 0;
}
