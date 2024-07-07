#include <iostream>
#include <vector>

int fibonacci_rek(int n)
{
  if (n <= 1)
    return n;
  return fibonacci_rek(n - 1) + fibonacci_rek(n - 2);
}

int fibonacci_mem_impl(int n, std::vector<int>& mem)
{
  if (n <= 1)
    return n;
  if (mem[n] != 0)
    return mem[n];
  mem[n] = fibonacci_mem_impl(n - 1, mem) + fibonacci_mem_impl(n - 2, mem);
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
  for (int i = 2; i <= n; i++)
    mem[i] = mem[i - 1] + mem[i - 2];
  return mem[n];
}

// pokretanje:
// ./a.out
// ./a.out mem
// ./a.out din
int main(int argc, char* argv[])
{
  int (*fibo)(int) = fibonacci_rek;
  if (argc == 2 && argv[1] == std::string("mem"))
    fibo = fibonacci_mem;
  else if (argc == 2 && argv[1] == std::string("din"))
    fibo = fibonacci_din;

  std::cout << "10: " << fibo(10) << std::endl;
  std::cout << "15: " << fibo(15) << std::endl;
  std::cout << "20: " << fibo(20) << std::endl;
  std::cout << "25: " << fibo(25) << std::endl;
  std::cout << "30: " << fibo(30) << std::endl;
  std::cout << "35: " << fibo(35) << std::endl;
  std::cout << "40: " << fibo(40) << std::endl;
  std::cout << "45: " << fibo(45) << std::endl;
  std::cout << "50: " << fibo(50) << std::endl;
}
