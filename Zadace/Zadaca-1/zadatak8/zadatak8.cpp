#include "../tests.hpp"
#include <algorithm>
#include <iostream>
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

template <typename Iter>
Iter swap_parts(Iter begin, Iter middle, Iter end)
{
  if (begin == middle) return end;
  if (middle == end) return begin;

  Iter it_l = begin;
  Iter it_r = middle;
  Iter it_mem = it_r;

  while (it_r != end)
  {
    if (it_l == it_mem) it_mem = it_r;
    std::swap(*it_l++, *it_r++);
  }

  swap_parts(it_l, it_mem, end);

  return it_l;
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
  return swap_parts(part1, middle, part2);
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
