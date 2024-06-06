#include <cstddef>
#include <iostream>
#include <vector>

// a(n+1) = a(n) / 2        ako je a(n) parno
// a(n+1) = 3 * a(n) + 1    ako je a(n) neparno

int collatz(size_t n)
{
  static std::vector<int> lookup(1000);

  if (n == 1) return 0;

  if (lookup[n] == 0)
  {
    if (n % 2 == 0)
      lookup[n] = 1 + collatz(n / 2);
    else
      lookup[n] = 1 + collatz(3 * n + 1);
  }

  return lookup[n];
}

int main()
{
  int max_index = 0;
  int max_value = 0;

  for (int i = 2; i <= 100; ++i)
  {
    int current = collatz(i);
    if (current > max_value)
    {
      max_value = current;
      max_index = i;
    }
  }

  std::cout << "Najduzu putanju u intervalu [2, 100] do broja 1 ima broj " << max_index << " sa duzinom " << max_value << "." << std::endl;

  return 0;
}
