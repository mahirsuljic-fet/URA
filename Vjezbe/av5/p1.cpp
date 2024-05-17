#include <iostream>
#include <string>
#include <vector>

int fibonacci_rek(int n)
{
  if (n <= 1) return n;
  return fibonacci_rek(n - 1) + fibonacci_rek(n - 2);
}

int fibonacci_mem_impl(int n, std::vector<int>& mem)
{
  if (n <= 1) return n;
  if (mem[n] == 0) mem[n] = fibonacci_mem_impl(n - 1, mem) + fibonacci_mem_impl(n - 2, mem);
  return mem[n];
}

int fibonacci_mem(int n)
{
  std::vector<int> mem;
  mem.resize(n + 1);
  return fibonacci_mem_impl(n, mem);
}

int fibonacci_din(int n)
{
  std::vector<int> mem;
  mem.resize(n + 1);

  mem[0] = 0;
  mem[1] = 1;

  for (int i = 2; i <= n; ++i)
    mem[i] = mem[i - 1] + mem[i - 2];

  return mem[n];
}

int fibonacci_mem_static(int n)
{
  static int mem[1000];
  if (n <= 1) return n;
  if (mem[n] == 0) mem[n] = fibonacci_mem_static(n - 1) + fibonacci_mem_static(n - 2);
  return mem[n];
}

int main(int argc, char* argv[])
{
  int (*fibo)(int) = fibonacci_rek;
  if (argc == 2 && argv[1] == std::string("rek")) fibo = fibonacci_rek;
  if (argc == 2 && argv[1] == std::string("mem")) fibo = fibonacci_mem;
  if (argc == 2 && argv[1] == std::string("din")) fibo = fibonacci_din;

  for (int i = 10; i <= 50; i += 5)
    std::cout << fibo(i) << std::endl;

  return 0;
}
