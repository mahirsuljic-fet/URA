#include "../tests.hpp"
#include <iostream>
#include <vector>

bool push_unique(std::vector<int>& vec, int value)
{
  for (auto it = vec.begin(); it != vec.end(); ++it)
    if (*it == value) return false;
  vec.push_back(value);
  return true;
}

int main()
{
  Test::push_unique(push_unique);
  return 0;
}
