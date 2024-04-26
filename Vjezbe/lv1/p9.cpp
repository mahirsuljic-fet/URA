#include <iostream>

int gcm(int a, int b)
{
  if (a == b) return a;
  if (a < b) return gcm(a - b, b);
  return b;
}

int main()
{

  return 0;
}
