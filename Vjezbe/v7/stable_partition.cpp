#include <algorithm>
#include <iostream>
#include <vector>

template <typename It, typename P>
It stable_partition(It begin, It end, P p)
{
  auto n = end - begin;

  if (n == 0) return begin;
  if (n == 1) return begin + p(*begin);

  auto middle = begin + n / 2;
  auto e1 = ::stable_partition(begin, middle, p);
  auto e2 = ::stable_partition(middle, end, p);

  return std::rotate(e1, middle, e2);
}

int main()
{
  std::vector<int> v { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
  ::stable_partition(v.begin(), v.end(), [](int a) { return a % 2; });
  for (const auto& el : v)
    std::cout << el << " ";
  std::cout << std::endl;

  return 0;
}
