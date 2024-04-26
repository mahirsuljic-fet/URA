#include <chrono>
#include <iostream>

int main()
{
  auto now = std::chrono::system_clock::now();

  auto elapsed = std::chrono::system_clock::now() - now;

  std::cout << elapsed.count() << "ns" << std::endl;
  std::cout << (elapsed.count() / 1000) << "us" << std::endl;

  return 0;
}
