#include <chrono>
#include <iostream>

int factorial(int n)
{
  if (n == 0) return 1;
  return n * factorial(n - 1);
}

int main()
{
  std::cout << "Factorial of 1 is " << factorial(1) << std::endl;
  std::cout << "Factorial of 5 is " << factorial(5) << std::endl;
  std::cout << "Factorial of 10 is " << factorial(10) << std::endl;

  return 0;
}
