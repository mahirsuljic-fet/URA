#include "find.hpp"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
  std::vector<int> vec;
  vec.reserve(1000);

  for (int i = 0; i < 1000; ++i)
    vec.push_back(i);

  auto result = std::find_if(vec.begin(), vec.end(), [](int n) { return n == 10; });
  if (result != vec.end())
    std::cout << "find_if found " << *result << std::endl;
  else
    std::cout << "find_if did not find anything" << std::endl;

  std::cout << "Loading the vector has finished." << std::endl;
  std::cout << "Enter number: " << std::endl;

  int input;
  while (std::cin >> input)
  {
    auto now = std::chrono::system_clock::now();
    auto it = ura::find(vec.begin(), vec.end(), input);
    auto elapsed = std::chrono::system_clock::now() - now;

    if (it != vec.end())
      std::cout << "Found element " << *it << " in " << (elapsed.count() / 1000) << "ms" << std::endl;
    else
      std::cout << "Element " << input << " is not in the vector" << std::endl;

    now = std::chrono::system_clock::now();
    it = ura::binary_search(vec.begin(), vec.end(), input);
    elapsed = std::chrono::system_clock::now() - now;

    if (it != vec.end())
      std::cout << "Found element " << *it << " in " << (elapsed.count() / 1000) << "ms" << std::endl;
    else
      std::cout << "Element " << input << " is not in the vector" << std::endl;

    now = std::chrono::system_clock::now();
    it = ura::binary_search_iter(vec.begin(), vec.end(), input);
    elapsed = std::chrono::system_clock::now() - now;

    if (it != vec.end())
      std::cout << "Found element " << *it << " in " << (elapsed.count() / 1000) << "ms" << std::endl;
    else
      std::cout << "Element " << input << " is not in the vector" << std::endl;
  }

  return 0;
}
