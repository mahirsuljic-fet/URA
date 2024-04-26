#include <chrono>
#include <cmath>
#include <iostream>

double fibonacci(int n)
{
  const static auto sqrt5 = sqrt(5);

  return (1 / sqrt5) * (std::pow((1 + sqrt5) / 2, n) - std::pow((1 - sqrt5) / 2, n));
}

int main()
{
  std::cout << "Fibonacci of 1 is: " << fibonacci(1) << std::endl;
  std::cout << "Fibonacci of 2 is: " << fibonacci(2) << std::endl;
  std::cout << "Fibonacci of 3 is: " << fibonacci(3) << std::endl;
  std::cout << "Fibonacci of 4 is: " << fibonacci(4) << std::endl;

  auto now = std::chrono::system_clock::now();
  long r = fibonacci(40);
  auto elapsed = std::chrono::system_clock::now() - now;

  std::cout << "Fibonacci of 40 is: " << r << std::endl;
  std::cout << "Time elapsed: " << elapsed.count() << "ns" << std::endl;

  return 0;
}
