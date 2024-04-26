#include <chrono>
#include <iostream>

int fibonacci(int n)
{
  if (n == 0) return 1;
  if (n == 1) return 1;
  return fibonacci(n - 1) + fibonacci(n - 2);
}

unsigned long fibonacci_iter(unsigned long n)
{
  int n1 = 1;
  int n2 = 1;
  for (int i = 3; i <= n; ++i)
  {
    auto pom = n1;
    n1 = n1 + n2;
    n2 = pom;
  }

  return n1;
}

int main(int argc, char* argv[])
{
  auto now = std::chrono::system_clock::now();
  int r = fibonacci(40);
  std::cout << "Fibonacci of 40 is " << r << std::endl;
  auto elapsed = std::chrono::system_clock::now() - now;

  std::cout << "Time elapsed: " << (elapsed.count() / 1000000) << "ms" << std::endl;

  now = std::chrono::system_clock::now();
  r = fibonacci_iter(40);
  std::cout << "Fibonacci of 40 is " << r << std::endl;
  elapsed = std::chrono::system_clock::now() - now;

  std::cout << "Time elapsed: " << (elapsed.count() / 1000) << "us" << std::endl;

  return 0;
}
