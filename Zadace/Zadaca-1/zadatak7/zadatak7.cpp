#include "../tests.hpp"
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

template <typename It, typename T>
It upper_bound(It begin, It end, const T& element)
{
  size_t size = end - begin;
  auto middle = begin + size / 2;

  if (begin == end) return end;
  if (element == *middle) return middle + 1;
  if (element > *middle)
    return ::upper_bound(middle + 1, end, element);
  else
    return ::upper_bound(begin, middle, element);
}

int main()
{
  Test::upper_bound(::upper_bound<std::vector<int>::iterator, int>);
  return 0;
}
