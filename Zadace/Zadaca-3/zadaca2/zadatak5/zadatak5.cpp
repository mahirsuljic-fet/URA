#include "../tests.hpp"
#include <algorithm>
#include <vector>

template <typename It>
void merge(It begin, It middle, It end)
{
  It it_left = begin;
  It it_right = middle;

  while (it_left < middle && it_right < end)
  {
    if (*it_left >= *it_right)
    {
      It it_previous = it_right;
      It it_current = it_previous--;

      while (it_current > it_left)
        std::iter_swap(it_current--, it_previous--);

      ++it_right;
      ++middle;
    }

    ++it_left;
  }
}

template <typename It>
void mergesort(It begin, It end)
{
  auto n = end - begin;
  if (n <= 1) return;

  auto middle = begin + n / 2;
  mergesort(begin, middle);
  mergesort(middle, end);
  merge(begin, middle, end);
}

int main()
{
  Test<>::test_nocomp(mergesort<std::vector<int>::iterator>);
  return 0;
}
