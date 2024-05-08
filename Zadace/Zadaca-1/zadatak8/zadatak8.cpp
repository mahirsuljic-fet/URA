#include "../tests.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <type_traits>
#include <vector>

template <typename Iter, typename P>
Iter partition(Iter begin, Iter end, const P& p)
{
  Iter left = begin;

  while (p(*left))
    if (++left == end) return end;

  Iter right = left;
  ++right;

  while (right != end)
  {
    if (p(*right))
    {
      std::swap(*left, *right);
      ++left;
    }
    ++right;
  }

  return left;
}

template <typename Iter, typename P>
Iter stable_partition(Iter begin, Iter end, const P& p)
{
  auto diff = end - begin;

  if (diff == 1)
  {
    if (p(*begin))
      return end;
    return begin;
  }

  auto middle = begin + diff / 2;
  auto part1 = ::stable_partition(begin, middle, p);
  auto part2 = ::stable_partition(middle, end, p);
  return std::rotate(part1, middle, part2);
}

int main()
{
  std::cout << "PARTITION" << std::endl;
  Test::partition<int>(::partition<std::vector<int>::iterator, std::function<bool(int)>>);

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "STABLE PARTITION" << std::endl;
  Test::partition<int>(::stable_partition<std::vector<int>::iterator, std::function<bool(int)>>);
  return 0;
}
