#include "../tests.hpp"
#include <algorithm>
#include <vector>

template <typename It>
void insertionsort(It begin, It end)
{
  It it_next = begin;
  It it_current = it_next++;
  It it_memory;
  It it_previous;

  while (it_next != end)
  {
    if (*it_next < *it_current)
    {
      it_memory = it_current;
      std::iter_swap(it_current, it_next);

      it_previous = it_current;
      --it_previous;
      while (it_current != begin && *it_current < *it_previous)
        std::iter_swap(it_previous--, it_current--);

      it_current = it_next = it_memory;
      ++it_next;
    }

    it_current = it_next++;
  }
}

template <typename It>
void quicksort(It begin, It end)
{
  auto n = end - begin;

  if (n <= 1) return;
  if (n <= 16)
  {
    insertionsort(begin, end);
    return;
  }

  auto middle = begin + n / 2;
  auto last = end - 1;

  std::iter_swap(middle, last);

  const auto comp = [&last](const typename It::value_type& el) { return el < *last; };

  auto part_it = std::partition(begin, end - 1, comp);
  std::iter_swap(part_it, last);

  quicksort(begin, part_it);
  quicksort(part_it + 1, end);
}

int main()
{
  Test<>::test_nocomp(quicksort<std::vector<int>::iterator>);
  return 0;
}
