#include "tests.hpp"
#include <cstdlib>
#include <ctime>
#include <ostream>
#include <vector>

int get_rand(int min, int max)
{
  return min + (std::rand() % (max - min + 1));
}

template <>
std::vector<int> Test<>::random_vector()
{
  int size = MIN_ARR_SIZE + (std::rand() % (MAX_ARR_SIZE - MIN_ARR_SIZE + 1));
  std::vector<int> arr(size);
  for (auto& el : arr)
    el = MIN_ARR_VALUE + (std::rand() % (MAX_ARR_VALUE - MIN_ARR_VALUE + 1));
  return arr;
}
